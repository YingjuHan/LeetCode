/*
 * @lc app=leetcode.cn id=700 lang=cpp
 * @lcpr version=30204
 *
 * [700] 二叉搜索树中的搜索
 *
 * https://leetcode.cn/problems/search-in-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (79.23%)
 * Likes:    518
 * Dislikes: 0
 * Total Accepted:    411.7K
 * Total Submissions: 519.6K
 * Testcase Example:  '[4,2,7,1,3]\n2'
 *
 * 给定二叉搜索树（BST）的根节点 root 和一个整数值 val。
 * 
 * 你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 输入：root = [4,2,7,1,3], val = 2
 * 输出：[2,1,3]
 * 
 * 
 * 示例 2:
 * 
 * 输入：root = [4,2,7,1,3], val = 5
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数在 [1, 5000] 范围内
 * 1 <= Node.val <= 10^7
 * root 是二叉搜索树
 * 1 <= val <= 10^7
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return root;
        if (val < root->val) return searchBST(root->left, val);
        if (val > root->val) return searchBST(root->right, val);
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,7,1,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [4,2,7,1,3]\n5\n
// @lcpr case=end

 */

