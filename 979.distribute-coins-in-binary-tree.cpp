/*
 * @lc app=leetcode.cn id=979 lang=cpp
 * @lcpr version=30204
 *
 * [979] 在二叉树中分配硬币
 *
 * https://leetcode.cn/problems/distribute-coins-in-binary-tree/description/
 *
 * algorithms
 * Medium (77.04%)
 * Likes:    581
 * Dislikes: 0
 * Total Accepted:    34.8K
 * Total Submissions: 45.1K
 * Testcase Example:  '[3,0,0]'
 *
 * 给你一个有 n 个结点的二叉树的根结点 root ，其中树中每个结点 node 都对应有 node.val 枚硬币。整棵树上一共有 n 枚硬币。
 * 
 * 在一次移动中，我们可以选择两个相邻的结点，然后将一枚硬币从其中一个结点移动到另一个结点。移动可以是从父结点到子结点，或者从子结点移动到父结点。
 * 
 * 返回使每个结点上 只有 一枚硬币所需的 最少 移动次数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：root = [3,0,0]
 * 输出：2
 * 解释：一枚硬币从根结点移动到左子结点，一枚硬币从根结点移动到右子结点。
 * 
 * 
 * 示例 2：
 * 
 * 输入：root = [0,3,0]
 * 输出：3
 * 解释：将两枚硬币从根结点的左子结点移动到根结点（两次移动）。然后，将一枚硬币从根结点移动到右子结点。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目为 n
 * 1 <= n <= 100
 * 0 <= Node.val <= n
 * 所有 Node.val 的值之和是 n
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
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
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
        auto [coins_l, node_l] = dfs(node->left);
        auto [coins_r, node_r] = dfs(node->right);
        int coins = coins_l + coins_r + node->val;
        int nodes = node_l + node_r + 1;
        res += abs(coins - nodes);
        return {coins, nodes};
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,0,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,3,0]\n
// @lcpr case=end

 */

