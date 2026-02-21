/*
 * @lc app=leetcode.cn id=437 lang=cpp
 * @lcpr version=
 *
 * [437] 路径总和 III
 *
 * https://leetcode.cn/problems/path-sum-iii/description/
 *
 * algorithms
 * Medium (48.10%)
 * Likes:    2172
 * Dislikes: 0
 * Total Accepted:    525.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * 给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
 * 
 * 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
 * 输出：3
 * 解释：和等于 8 的路径有 3 条，如图所示。
 * 
 * 
 * 示例 2：
 * 
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 二叉树的节点个数的范围是 [0,1000]
 * -10^9 <= Node.val <= 10^9 
 * -1000 <= targetSum <= 1000 
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
    int pathSum(TreeNode* root, int targetSum) {
        // key：从根到 node 的节点值之和
        // value：节点值之和的出现次数
        // 注意在递归过程中，哈希表只保存根到 node 的路径的前缀的节点值之和
        unordered_map<long long, int> cnt = {{0, 1}};
        int ans = 0;

        // lambda 递归
        // s 表示从根到 node 的父节点的节点值之和（node 的节点值尚未计入）
        auto dfs = [&](this auto&& dfs, TreeNode* node, long long s) {
            if (node == nullptr) {
                return;
            }

            s += node->val;
            // 把 node 当作路径的终点，统计有多少个起点
            ans += cnt[s - targetSum]; // 注意这样写会把 s-targetSum 插入哈希表，介意的话可以特判

            cnt[s]++;
            dfs(node->left, s);
            dfs(node->right, s);
            cnt[s]--; // 恢复现场（撤销 cnt[s]++）
        };

        dfs(root, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,5,-3,3,2,null,11,3,-2,null,1]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

 */

