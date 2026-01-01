/*
 * @lc app=leetcode.cn id=2265 lang=cpp
 * @lcpr version=30204
 *
 * [2265] 统计值等于子树平均值的节点数
 *
 * https://leetcode.cn/problems/count-nodes-equal-to-average-of-subtree/description/
 *
 * algorithms
 * Medium (83.60%)
 * Likes:    54
 * Dislikes: 0
 * Total Accepted:    16.2K
 * Total Submissions: 19.4K
 * Testcase Example:  '[4,8,5,0,1,null,6]'
 *
 * 给你一棵二叉树的根节点 root ，找出并返回满足要求的节点数，要求节点的值等于其 子树 中值的 平均值 。
 * 
 * 注意：
 * 
 * 
 * n 个元素的平均值可以由 n 个元素 求和 然后再除以 n ，并 向下舍入 到最近的整数。
 * root 的 子树 由 root 和它的所有后代组成。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：root = [4,8,5,0,1,null,6]
 * 输出：5
 * 解释：
 * 对值为 4 的节点：子树的平均值 (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4 。
 * 对值为 5 的节点：子树的平均值 (5 + 6) / 2 = 11 / 2 = 5 。
 * 对值为 0 的节点：子树的平均值 0 / 1 = 0 。
 * 对值为 1 的节点：子树的平均值 1 / 1 = 1 。
 * 对值为 6 的节点：子树的平均值 6 / 1 = 6 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：root = [1]
 * 输出：1
 * 解释：对值为 1 的节点：子树的平均值 1 / 1 = 1。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [1, 1000] 内
 * 0 <= Node.val <= 1000
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
    int res = 0;
    pair<int, int> dfs(TreeNode* node) {
        if (node == nullptr) return {0, 0};
        pair<int, int> l = dfs(node->left), r = dfs(node->right);
        int cnt = l.first + r.first + 1, sm = l.second + r.second + node->val;
        if (sm / cnt == node->val) {
            res++;
        }
        return {cnt, sm};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,8,5,0,1,null,6]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

