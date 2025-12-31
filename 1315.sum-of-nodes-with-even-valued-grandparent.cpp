/*
 * @lc app=leetcode.cn id=1315 lang=cpp
 * @lcpr version=30204
 *
 * [1315] 祖父节点值为偶数的节点和
 *
 * https://leetcode.cn/problems/sum-of-nodes-with-even-valued-grandparent/description/
 *
 * algorithms
 * Medium (82.57%)
 * Likes:    111
 * Dislikes: 0
 * Total Accepted:    26.1K
 * Total Submissions: 31.6K
 * Testcase Example:  '[6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]'
 *
 * 给你一棵二叉树，请你返回满足以下条件的所有节点的值之和：
 * 
 * 
 * 该节点的祖父节点的值为偶数。（一个节点的祖父节点是指该节点的父节点的父节点。）
 * 
 * 
 * 如果不存在祖父节点值为偶数的节点，那么返回 0 。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 
 * 输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
 * 输出：18
 * 解释：图中红色节点的祖父节点的值为偶数，蓝色节点为这些红色节点的祖父节点。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目在 1 到 10^4 之间。
 * 每个节点的值在 1 到 100 之间。
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
    void dfs(TreeNode* grandparent, TreeNode* parent, TreeNode* node) {
        if (!node) return;
        if (grandparent->val % 2 == 0) {
            res += node->val;
        }
        dfs(parent, node, node->left);
        dfs(parent, node, node->right);

    }
    int sumEvenGrandparent(TreeNode* root) {
        if (root->left) {
            dfs(root, root->left, root->left->left);
            dfs(root, root->left, root->left->right);
        }
        if (root->right) {
            dfs(root, root->right, root->right->left);
            dfs(root, root->right, root->right->right);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]\n
// @lcpr case=end

 */

