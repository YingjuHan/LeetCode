/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 * @lcpr version=30204
 *
 * [1123] 最深叶节点的最近公共祖先
 *
 * https://leetcode.cn/problems/lowest-common-ancestor-of-deepest-leaves/description/
 *
 * algorithms
 * Medium (79.18%)
 * Likes:    354
 * Dislikes: 0
 * Total Accepted:    53.2K
 * Total Submissions: 67.2K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]'
 *
 * 给你一个有根节点 root 的二叉树，返回它 最深的叶节点的最近公共祖先 。
 * 
 * 回想一下：
 * 
 * 
 * 叶节点 是二叉树中没有子节点的节点
 * 树的根节点的 深度 为 0，如果某一节点的深度为 d，那它的子节点的深度就是 d+1
 * 如果我们假定 A 是一组节点 S 的 最近公共祖先，S 中的每个节点都在以 A 为根节点的子树中，且 A 的深度达到此条件下可能的最大值。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4]
 * 输出：[2,7,4]
 * 解释：我们返回值为 2 的节点，在图中用黄色标记。
 * 在图中用蓝色标记的是树的最深的节点。
 * 注意，节点 6、0 和 8 也是叶节点，但是它们的深度是 2 ，而节点 7 和 4 的深度是 3 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：root = [1]
 * 输出：[1]
 * 解释：根节点是树中最深的节点，它是它本身的最近公共祖先。
 * 
 * 
 * 示例 3：
 * 
 * 输入：root = [0,1,3,null,2]
 * 输出：[2]
 * 解释：树中最深的叶节点是 2 ，最近公共祖先是它自己。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的节点数将在 [1, 1000] 的范围内。
 * 0 <= Node.val <= 1000
 * 每个节点的值都是 独一无二 的。
 * 
 * 
 * 
 * 
 * 注意：本题与力扣 865
 * 重复：https://leetcode.cn/problems/smallest-subtree-with-all-the-deepest-nodes/
 * 
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode* res = nullptr;
        int max_depth = -1;
        function<int(TreeNode*, int)> dfs = [&](TreeNode* node, int depth) {
            if (node == nullptr) {
                max_depth = max(max_depth, depth);
                return depth;
            }
            int left_max_depth = dfs(node->left, depth + 1);
            int right_max_depth = dfs(node->right, depth + 1);
            if (left_max_depth == right_max_depth && left_max_depth == max_depth) {
                res = node;
            }
            return max(left_max_depth, right_max_depth);
        };
        dfs(root, 0);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,3,null,2]\n
// @lcpr case=end

 */

