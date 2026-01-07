/*
 * @lc app=leetcode.cn id=863 lang=cpp
 * @lcpr version=30204
 *
 * [863] 二叉树中所有距离为 K 的结点
 *
 * https://leetcode.cn/problems/all-nodes-distance-k-in-binary-tree/description/
 *
 * algorithms
 * Medium (61.95%)
 * Likes:    751
 * Dislikes: 0
 * Total Accepted:    65.3K
 * Total Submissions: 105.4K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n2'
 *
 * 给定一个二叉树（具有根结点 root）， 一个目标结点 target ，和一个整数值 k ，返回到目标结点 target 距离为 k
 * 的所有结点的值的数组。
 * 
 * 答案可以以 任何顺序 返回。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
 * 输出：[7,4,1]
 * 解释：所求结点为与目标结点（值为 5）距离为 2 的结点，值分别为 7，4，以及 1
 * 
 * 
 * 示例 2:
 * 
 * 输入: root = [1], target = 1, k = 3
 * 输出: []
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 节点数在 [1, 500] 范围内
 * 0 <= Node.val <= 500
 * Node.val 中所有值 不同
 * 目标结点 target 是树上的结点。
 * 0 <= k <= 1000
 * 
 * 
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
  unordered_map<TreeNode *, TreeNode *> parent;

public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
    dfs(root, NULL); //记录父结点
    queue<TreeNode *> Q;
    unordered_set<TreeNode *> visited;
    Q.push(target); // target结点入队，从 target 结点开始向外延伸
    visited.insert(target);
    while (!Q.empty()) {
      if (K-- == 0) { // 延伸 K 次，队中全部结点即为所求
        vector<int> ret;
        while (!Q.empty()) {
          ret.push_back(Q.front()->val);
          Q.pop();
        }
        return ret;
      } else {
        int n = Q.size(); // 将当前队中所有结点向外延伸 1 个结点
        for (int i = 0; i < n; i++) {
          TreeNode *node = Q.front();
          Q.pop();
          if (node->left && visited.find(node->left) == visited.end()) {
            Q.push(node->left);
            visited.insert(node->left);
          }
          if (node->right && visited.find(node->right) == visited.end()) {
            Q.push(node->right);
            visited.insert(node->right);
          }
          if (parent[node] != NULL &&
              visited.find(parent[node]) == visited.end()) {
            Q.push(parent[node]);
            visited.insert(parent[node]);
          }
        }
      }
    }
    return vector<int>();
  }
  void dfs(TreeNode *root, TreeNode *pre) {
    if (root) {
      parent.insert({root, pre});
      dfs(root->left, root);
      dfs(root->right, root);
    }
  }
};

// @lc code=end



/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n3\n
// @lcpr case=end

 */

