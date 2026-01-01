/*
 * @lc app=leetcode.cn id=1339 lang=cpp
 * @lcpr version=30204
 *
 * [1339] 分裂二叉树的最大乘积
 *
 * https://leetcode.cn/problems/maximum-product-of-splitted-binary-tree/description/
 *
 * algorithms
 * Medium (43.76%)
 * Likes:    125
 * Dislikes: 0
 * Total Accepted:    19.5K
 * Total Submissions: 44.6K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * 给你一棵二叉树，它的根为 root 。请你删除 1 条边，使二叉树分裂成两棵子树，且它们子树和的乘积尽可能大。
 * 
 * 由于答案可能会很大，请你将结果对 10^9 + 7 取模后再返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：root = [1,2,3,4,5,6]
 * 输出：110
 * 解释：删除红色的边，得到 2 棵子树，和分别为 11 和 10 。它们的乘积是 110 （11*10）
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：root = [1,null,2,3,4,null,null,5,6]
 * 输出：90
 * 解释：移除红色的边，得到 2 棵子树，和分别是 15 和 6 。它们的乘积为 90 （15*6）
 * 
 * 
 * 示例 3：
 * 
 * 输入：root = [2,3,9,10,7,8,6,5,4,11,1]
 * 输出：1025
 * 
 * 
 * 示例 4：
 * 
 * 输入：root = [1,1]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每棵树最多有 50000 个节点，且至少有 2 个节点。
 * 每个节点的值在 [1, 10000] 之间。
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
    int maxProduct(TreeNode* root) {
        auto dfs1 = [&](this auto&& dfs1, TreeNode* node) -> int {
            if (node == nullptr) {
                return 0;
            }
            return node->val + dfs1(node->left) + dfs1(node->right);
        };
        long long total = dfs1(root);

        long long res = 0;

        auto dfs2 = [&](this auto&& dfs2, TreeNode* node) -> int {
            if (node == nullptr) {
                return 0;
            }
            int s = node->val + dfs2(node->left) + dfs2(node->right);
            res = max(res, s * (total - s));
            return s;
        };
        dfs2(root);
        return res % 1'000'000'007;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2,3,4,null,null,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,9,10,7,8,6,5,4,11,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */

