/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 * @lcpr version=30204
 *
 * [1302] 层数最深叶子节点的和
 *
 * https://leetcode.cn/problems/deepest-leaves-sum/description/
 *
 * algorithms
 * Medium (85.68%)
 * Likes:    186
 * Dislikes: 0
 * Total Accepted:    75.3K
 * Total Submissions: 87.9K
 * Testcase Example:  '[1,2,3,4,5,null,6,7,null,null,null,null,8]'
 *
 * 给你一棵二叉树的根节点 root ，请你返回 层数最深的叶子节点的和 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
 * 输出：15
 * 
 * 
 * 示例 2：
 * 
 * 输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
 * 输出：19
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [1, 10^4] 之间。
 * 1 <= Node.val <= 100
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
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> qu;
        qu.emplace(root);
        while (!qu.empty()) {
            sum = 0;
            int size = qu.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = qu.front();
                qu.pop();
                sum += node->val;
                if (node->left != nullptr) {
                    qu.emplace(node->left);
                }
                if (node->right != nullptr) {
                    qu.emplace(node->right);
                }
            }
        }
        return sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,null,6,7,null,null,null,null,8]\n
// @lcpr case=end

// @lcpr case=start
// [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]\n
// @lcpr case=end

 */

