/*
 * @lc app=leetcode.cn id=2130 lang=cpp
 * @lcpr version=30204
 *
 * [2130] 链表最大孪生和
 *
 * https://leetcode.cn/problems/maximum-twin-sum-of-a-linked-list/description/
 *
 * algorithms
 * Medium (79.68%)
 * Likes:    87
 * Dislikes: 0
 * Total Accepted:    39.6K
 * Total Submissions: 49.6K
 * Testcase Example:  '[5,4,2,1]'
 *
 * 在一个大小为 n 且 n 为 偶数 的链表中，对于 0 <= i <= (n / 2) - 1 的 i ，第 i 个节点（下标从 0
 * 开始）的孪生节点为第 (n-1-i) 个节点 。
 * 
 * 
 * 比方说，n = 4 那么节点 0 是节点 3 的孪生节点，节点 1 是节点 2 的孪生节点。这是长度为 n = 4 的链表中所有的孪生节点。
 * 
 * 
 * 孪生和 定义为一个节点和它孪生节点两者值之和。
 * 
 * 给你一个长度为偶数的链表的头节点 head ，请你返回链表的 最大孪生和 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：head = [5,4,2,1]
 * 输出：6
 * 解释：
 * 节点 0 和节点 1 分别是节点 3 和 2 的孪生节点。孪生和都为 6 。
 * 链表中没有其他孪生节点。
 * 所以，链表的最大孪生和是 6 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：head = [4,2,2,3]
 * 输出：7
 * 解释：
 * 链表中的孪生节点为：
 * - 节点 0 是节点 3 的孪生节点，孪生和为 4 + 3 = 7 。
 * - 节点 1 是节点 2 的孪生节点，孪生和为 2 + 2 = 4 。
 * 所以，最大孪生和为 max(7, 4) = 7 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：head = [1,100000]
 * 输出：100001
 * 解释：
 * 链表中只有一对孪生节点，孪生和为 1 + 100000 = 100001 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表的节点数目是 [2, 10^5] 中的 偶数 。
 * 1 <= Node.val <= 10^5
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
    ListNode* findMid(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr, *cur = head;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
    int pairSum(ListNode* head) {
        ListNode *head2 = findMid(head);
        head2 = reverseList(head2);

        int res = 0;
        while (head2) {
            res = max(res, head->val + head2->val);
            head = head->next;
            head2 = head2->next;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,100000]\n
// @lcpr case=end

 */

