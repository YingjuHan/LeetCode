/*
 * @lc app=leetcode.cn id=1367 lang=cpp
 * @lcpr version=30204
 *
 * [1367] 二叉树中的链表
 *
 * https://leetcode.cn/problems/linked-list-in-binary-tree/description/
 *
 * algorithms
 * Medium (47.62%)
 * Likes:    233
 * Dislikes: 0
 * Total Accepted:    45.1K
 * Total Submissions: 94.7K
 * Testcase Example:  '[4,2,8]\n[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]'
 *
 * 给你一棵以 root 为根的二叉树和一个 head 为第一个节点的链表。
 * 
 * 如果在二叉树中，存在一条一直向下的路径，且每个点的数值恰好一一对应以 head 为首的链表中每个节点的值，那么请你返回 True ，否则返回 False
 * 。
 * 
 * 一直向下的路径的意思是：从树中某个节点开始，一直连续向下的路径。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：head = [4,2,8], root =
 * [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 * 输出：true
 * 解释：树中蓝色的节点构成了与链表对应的子路径。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：head = [1,4,2,6], root =
 * [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 输入：head = [1,4,2,6,8], root =
 * [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 * 输出：false
 * 解释：二叉树中不存在一一对应链表的路径。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 二叉树和链表中的每个节点的值都满足 1 <= node.val <= 100 。
 * 链表包含的节点数目在 1 到 100 之间。
 * 二叉树包含的节点数目在 1 到 2500 之间。
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};;
// @lcpr-template-end
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        auto dfs = [&](this auto&& dfs, ListNode* s, TreeNode* t) {
            if (s == nullptr) return true;
        
            if (t == nullptr) return false;
            return (s->val == t->val && (dfs(s->next, t->left) || dfs(s->next, t->right))) ||
                   (s == head && (dfs(head, t->left) || dfs(head, t->right)));
        };
        return dfs(head, root);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,8]\n[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,4,2,6]\n[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,4,2,6,8]\n[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]\n
// @lcpr case=end

 */

