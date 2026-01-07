/*
 * @lc app=leetcode.cn id=2583 lang=cpp
 * @lcpr version=30204
 *
 * [2583] 二叉树中的第 K 大层和
 *
 * https://leetcode.cn/problems/kth-largest-sum-in-a-binary-tree/description/
 *
 * algorithms
 * Medium (53.91%)
 * Likes:    46
 * Dislikes: 0
 * Total Accepted:    31.9K
 * Total Submissions: 59.1K
 * Testcase Example:  '[5,8,9,2,1,3,7,4,6]\n2'
 *
 * 给你一棵二叉树的根节点 root 和一个正整数 k 。
 * 
 * 树中的 层和 是指 同一层 上节点值的总和。
 * 
 * 返回树中第 k 大的层和（不一定不同）。如果树少于 k 层，则返回 -1 。
 * 
 * 注意，如果两个节点与根节点的距离相同，则认为它们在同一层。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：root = [5,8,9,2,1,3,7,4,6], k = 2
 * 输出：13
 * 解释：树中每一层的层和分别是：
 * - Level 1: 5
 * - Level 2: 8 + 9 = 17
 * - Level 3: 2 + 1 + 3 + 7 = 13
 * - Level 4: 4 + 6 = 10
 * 第 2 大的层和等于 13 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：root = [1,2,null,3], k = 1
 * 输出：3
 * 解释：最大的层和是 3 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的节点数为 n
 * 2 <= n <= 10^5
 * 1 <= Node.val <= 10^6
 * 1 <= k <= n
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> res;
        while (!q.empty()) {
            long long s = 0;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                s += node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(s);
        }
        int n = res.size();
        if (k > n) {
            return -1;
        }
        ranges::sort(res);
        return res[n - k];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,8,9,2,1,3,7,4,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,null,3]\n1\n
// @lcpr case=end

 */

