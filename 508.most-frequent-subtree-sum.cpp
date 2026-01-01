/*
 * @lc app=leetcode.cn id=508 lang=cpp
 * @lcpr version=30204
 *
 * [508] 出现次数最多的子树元素和
 *
 * https://leetcode.cn/problems/most-frequent-subtree-sum/description/
 *
 * algorithms
 * Medium (76.40%)
 * Likes:    269
 * Dislikes: 0
 * Total Accepted:    56.9K
 * Total Submissions: 74.5K
 * Testcase Example:  '[5,2,-3]'
 *
 * 给你一个二叉树的根结点 root ，请返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。
 * 
 * 一个结点的 「子树元素和」 定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入: root = [5,2,-3]
 * 输出: [2,-3,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入: root = [5,2,-5]
 * 输出: [2]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 节点数在 [1, 10^4] 范围内
 * -10^5 <= Node.val <= 10^5
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
    unordered_map<int, int> cnt;
    int maxCnt = 0;
    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        int sum = node->val + dfs(node->left) + dfs(node->right);
        maxCnt = max(maxCnt, ++cnt[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> res;
        for (auto& [s, c] : cnt) {
            if (c == maxCnt) {
                res.push_back(s);
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,2,-3]\n
// @lcpr case=end

// @lcpr case=start
// [5,2,-5]\n
// @lcpr case=end

 */

