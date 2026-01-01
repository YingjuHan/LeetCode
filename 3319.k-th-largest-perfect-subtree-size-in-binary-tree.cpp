/*
 * @lc app=leetcode.cn id=3319 lang=cpp
 * @lcpr version=30204
 *
 * [3319] 第 K 大的完美二叉子树的大小
 *
 * https://leetcode.cn/problems/k-th-largest-perfect-subtree-size-in-binary-tree/description/
 *
 * algorithms
 * Medium (63.30%)
 * Likes:    11
 * Dislikes: 0
 * Total Accepted:    5.7K
 * Total Submissions: 9K
 * Testcase Example:  '[5,3,6,5,2,5,7,1,8,null,null,6,8]\n2'
 *
 * 给你一棵 二叉树 的根节点 root 和一个整数k。
 * 
 * 返回第 k 大的 完美二叉子树 的大小，如果不存在则返回 -1。
 * 
 * 完美二叉树 是指所有叶子节点都在同一层级的树，且每个父节点恰有两个子节点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： root = [5,3,6,5,2,5,7,1,8,null,null,6,8], k = 2
 * 
 * 输出： 3
 * 
 * 解释：
 * 
 * 
 * 
 * 完美二叉子树的根节点在图中以黑色突出显示。它们的大小按非递增顺序排列为 [3, 3, 1, 1, 1, 1, 1, 1]。
 * 第 2 大的完美二叉子树的大小是 3。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： root = [1,2,3,4,5,6,7], k = 1
 * 
 * 输出： 7
 * 
 * 解释：
 * 
 * 
 * 
 * 完美二叉子树的大小按非递增顺序排列为 [7, 3, 3, 1, 1, 1, 1]。最大的完美二叉子树的大小是 7。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入： root = [1,2,3,null,4], k = 3
 * 
 * 输出： -1
 * 
 * 解释：
 * 
 * 
 * 
 * 完美二叉子树的大小按非递增顺序排列为 [1, 1]。完美二叉子树的数量少于 3。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的节点数目在 [1, 2000] 范围内。
 * 1 <= Node.val <= 2000
 * 1 <= k <= 1024
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
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> hs;
        auto dfs = [&](auto&& dfs, TreeNode* node) -> int {
            if (node == nullptr) return 0;
            int left_h = dfs(dfs, node->left), right_h = dfs(dfs, node->right);
            if (left_h < 0 || left_h != right_h) return -1;
            hs.push_back(left_h + 1);
            return left_h + 1;
        };
        dfs(dfs, root);
        if (k > hs.size()) return -1;
        ranges::nth_element(hs, hs.end() - k);
        return (1 << hs[hs.size() - k]) - 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,3,6,5,2,5,7,1,8,null,null,6,8]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,null,4]\n3\n
// @lcpr case=end

 */

