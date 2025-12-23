/*
 * @lc app=leetcode.cn id=1721 lang=cpp
 * @lcpr version=30204
 *
 * [1721] 交换链表中的节点
 *
 * https://leetcode.cn/problems/swapping-nodes-in-a-linked-list/description/
 *
 * algorithms
 * Medium (65.11%)
 * Likes:    120
 * Dislikes: 0
 * Total Accepted:    31.8K
 * Total Submissions: 49K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你链表的头节点 head 和一个整数 k 。
 * 
 * 交换 链表正数第 k 个节点和倒数第 k 个节点的值后，返回链表的头节点（链表 从 1 开始索引）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：head = [1,2,3,4,5], k = 2
 * 输出：[1,4,3,2,5]
 * 
 * 
 * 示例 2：
 * 
 * 输入：head = [7,9,6,6,7,8,3,0,9,5], k = 5
 * 输出：[7,9,6,6,8,7,3,0,9,5]
 * 
 * 
 * 示例 3：
 * 
 * 输入：head = [1], k = 1
 * 输出：[1]
 * 
 * 
 * 示例 4：
 * 
 * 输入：head = [1,2], k = 1
 * 输出：[2,1]
 * 
 * 
 * 示例 5：
 * 
 * 输入：head = [1,2,3], k = 2
 * 输出：[1,2,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目是 n
 * 1 <= k <= n <= 10^5
 * 0 <= Node.val <= 100
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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }

        ListNode *dummy = new ListNode(0, head), *slow = dummy, *fast = dummy, *cur = dummy;
        for (int i = 0; i < k && cur; i++) {
            cur = cur->next;
        }
        while (k--) {
            fast = fast->next;
        }
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        swap(cur->val, slow->next->val);
        return dummy->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [7,9,6,6,7,8,3,0,9,5]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n2\n
// @lcpr case=end

 */

