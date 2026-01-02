/*
 * @lc app=leetcode.cn id=687 lang=cpp
 * @lcpr version=30204
 *
 * [687] 最长同值路径
 *
 * https://leetcode.cn/problems/longest-univalue-path/description/
 *
 * algorithms
 * Medium (48.92%)
 * Likes:    847
 * Dislikes: 0
 * Total Accepted:    97.7K
 * Total Submissions: 199.7K
 * Testcase Example:  '[5,4,5,1,1,null,5]'
 *
 * 给定一个二叉树的 root ，返回 最长的路径的长度 ，这个路径中的 每个节点具有相同值 。 这条路径可以经过也可以不经过根节点。
 * 
 * 两个节点之间的路径长度 由它们之间的边数表示。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 输入：root = [5,4,5,1,1,5]
 * 输出：2
 * 
 * 
 * 示例 2:
 * 
 * 
 * 
 * 输入：root = [1,4,5,4,4,5]
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 树的节点数的范围是 [0, 10^4] 
 * -1000 <= Node.val <= 1000
 * 树的深度将不超过 1000 
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
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            if (node == nullptr) return -1;
            int l_len = dfs(node->left) + 1;
            int r_len = dfs(node->right) + 1;
            if (node->left && node->left->val != node->val) l_len = 0;
            if (node->right && node->right->val != node->val) r_len = 0;
            res = max(res, l_len + r_len);
            return max(l_len, r_len); 
        };
        dfs(root);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,5,1,1,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,4,5,4,4,5]\n
// @lcpr case=end

 */

