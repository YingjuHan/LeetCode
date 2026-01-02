/*
 * @lc app=leetcode.cn id=2385 lang=cpp
 * @lcpr version=30204
 *
 * [2385] 感染二叉树需要的总时间
 *
 * https://leetcode.cn/problems/amount-of-time-for-binary-tree-to-be-infected/description/
 *
 * algorithms
 * Medium (51.91%)
 * Likes:    124
 * Dislikes: 0
 * Total Accepted:    28.5K
 * Total Submissions: 54.9K
 * Testcase Example:  '[1,5,3,null,4,10,6,9,2]\n3'
 *
 * 给你一棵二叉树的根节点 root ，二叉树中节点的值 互不相同 。另给你一个整数 start 。在第 0 分钟，感染 将会从值为 start
 * 的节点开始爆发。
 * 
 * 每分钟，如果节点满足以下全部条件，就会被感染：
 * 
 * 
 * 节点此前还没有感染。
 * 节点与一个已感染节点相邻。
 * 
 * 
 * 返回感染整棵树需要的分钟数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：root = [1,5,3,null,4,10,6,9,2], start = 3
 * 输出：4
 * 解释：节点按以下过程被感染：
 * - 第 0 分钟：节点 3
 * - 第 1 分钟：节点 1、10、6
 * - 第 2 分钟：节点5
 * - 第 3 分钟：节点 4
 * - 第 4 分钟：节点 9 和 2
 * 感染整棵树需要 4 分钟，所以返回 4 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：root = [1], start = 1
 * 输出：0
 * 解释：第 0 分钟，树中唯一一个节点处于感染状态，返回 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目在范围 [1, 10^5] 内
 * 1 <= Node.val <= 10^5
 * 每个节点的值 互不相同
 * 树中必定存在值为 start 的节点
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
    int ans = 0, start;

    pair<int, bool> dfs(TreeNode* node) {
        if (node == nullptr) {
            return {0, false};
        }
        auto [l_len, l_found] = dfs(node->left);
        auto [r_len, r_found] = dfs(node->right);
        if (node->val == start) {
            // 计算子树 start 的最大深度
            // 注意这里和方法一的区别，max 后面没有 +1，所以算出的也是最大深度
            ans = max(l_len, r_len);
            return {1, true}; // 找到了 start
        }
        if (l_found || r_found) {
            // 只有在左子树或右子树包含 start 时，才能更新答案
            ans = max(ans, l_len + r_len); // 两条链拼成直径
            // 保证 start 是直径端点
            return {(l_found ? l_len : r_len) + 1, true};
        }
        return {max(l_len, r_len) + 1, false};
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        this->start = start;
        dfs(root);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,5,3,null,4,10,6,9,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

