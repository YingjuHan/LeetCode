/*
 * @lc app=leetcode.cn id=2476 lang=cpp
 * @lcpr version=30204
 *
 * [2476] 二叉搜索树最近节点查询
 *
 * https://leetcode.cn/problems/closest-nodes-queries-in-a-binary-search-tree/description/
 *
 * algorithms
 * Medium (52.33%)
 * Likes:    95
 * Dislikes: 0
 * Total Accepted:    29.1K
 * Total Submissions: 55.5K
 * Testcase Example:  '[6,2,13,1,4,9,15,null,null,null,null,null,null,14]\n[2,5,16]'
 *
 * 给你一个 二叉搜索树 的根节点 root ，和一个由正整数组成、长度为 n 的数组 queries 。
 * 
 * 请你找出一个长度为 n 的 二维 答案数组 answer ，其中 answer[i] = [mini, maxi] ：
 * 
 * 
 * mini 是树中小于等于 queries[i] 的 最大值 。如果不存在这样的值，则使用 -1 代替。
 * maxi 是树中大于等于 queries[i] 的 最小值 。如果不存在这样的值，则使用 -1 代替。
 * 
 * 
 * 返回数组 answer 。
 * 
 * 
 * 
 * 示例 1 ：
 * 
 * 
 * 
 * 输入：root = [6,2,13,1,4,9,15,null,null,null,null,null,null,14], queries =
 * [2,5,16]
 * 输出：[[2,2],[4,6],[15,-1]]
 * 解释：按下面的描述找出并返回查询的答案：
 * - 树中小于等于 2 的最大值是 2 ，且大于等于 2 的最小值也是 2 。所以第一个查询的答案是 [2,2] 。
 * - 树中小于等于 5 的最大值是 4 ，且大于等于 5 的最小值是 6 。所以第二个查询的答案是 [4,6] 。
 * - 树中小于等于 16 的最大值是 15 ，且大于等于 16 的最小值不存在。所以第三个查询的答案是 [15,-1] 。
 * 
 * 
 * 示例 2 ：
 * 
 * 
 * 
 * 输入：root = [4,null,9], queries = [3]
 * 输出：[[-1,4]]
 * 解释：树中不存在小于等于 3 的最大值，且大于等于 3 的最小值是 4 。所以查询的答案是 [-1,4] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目在范围 [2, 10^5] 内
 * 1 <= Node.val <= 10^6
 * n == queries.length
 * 1 <= n <= 10^5
 * 1 <= queries[i] <= 10^6
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
    vector<int> a;
    void inorder(TreeNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        a.push_back(node->val);
        inorder(node->right);
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        inorder(root);
        int n = a.size();
        vector<vector<int>> res;
        for (int q : queries) {
            int j = ranges::lower_bound(a, q) - a.begin();
            int mx = j < n ? a[j] : -1;
            if (j == n || a[j] != q) { // a[j]>q, a[j-1]<q
                j--;
            }
            int mn = j >= 0 ? a[j] : -1;
            res.push_back({mn, mx});
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [6,2,13,1,4,9,15,null,null,null,null,null,null,14]\n[2,5,16]\n
// @lcpr case=end

// @lcpr case=start
// [4,null,9]\n[3]\n
// @lcpr case=end

 */

