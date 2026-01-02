/*
 * @lc app=leetcode.cn id=1325 lang=cpp
 * @lcpr version=30204
 *
 * [1325] 删除给定值的叶子节点
 *
 * https://leetcode.cn/problems/delete-leaves-with-a-given-value/description/
 *
 * algorithms
 * Medium (74.27%)
 * Likes:    143
 * Dislikes: 0
 * Total Accepted:    24.8K
 * Total Submissions: 33.4K
 * Testcase Example:  '[1,2,3,2,null,2,4]\n2'
 *
 * 给你一棵以 root 为根的二叉树和一个整数 target ，请你删除所有值为 target 的 叶子节点 。
 * 
 * 注意，一旦删除值为 target 的叶子节点，它的父节点就可能变成叶子节点；如果新叶子节点的值恰好也是 target ，那么这个节点也应该被删除。
 * 
 * 也就是说，你需要重复此过程直到不能继续删除。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：root = [1,2,3,2,null,2,4], target = 2
 * 输出：[1,null,3,null,4]
 * 解释：
 * 上面左边的图中，绿色节点为叶子节点，且它们的值与 target 相同（同为 2 ），它们会被删除，得到中间的图。
 * 有一个新的节点变成了叶子节点且它的值与 target 相同，所以将再次进行删除，从而得到最右边的图。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：root = [1,3,3,3,2], target = 3
 * 输出：[1,3,null,null,2]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：root = [1,2,null,2,null,2], target = 2
 * 输出：[1]
 * 解释：每一步都删除一个绿色的叶子节点（值为 2）。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数量的范围是 [1, 3000]。
 * 1 <= Node.val, target <= 1000
 * 
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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == nullptr) return nullptr;
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if (root->left == nullptr && root->right == nullptr && root->val == target) {
            return nullptr;
        }
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,2,null,2,4]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,3,3,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,null,2,null,2]\n2\n
// @lcpr case=end

 */

