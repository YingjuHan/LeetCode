/*
 * @lc app=leetcode.cn id=2074 lang=cpp
 * @lcpr version=30204
 *
 * [2074] 反转偶数长度组的节点
 *
 * https://leetcode.cn/problems/reverse-nodes-in-even-length-groups/description/
 *
 * algorithms
 * Medium (51.77%)
 * Likes:    48
 * Dislikes: 0
 * Total Accepted:    11.1K
 * Total Submissions: 21.3K
 * Testcase Example:  '[5,2,6,3,9,1,7,3,8,4]'
 *
 * 给你一个链表的头节点 head 。
 * 
 * 链表中的节点 按顺序 划分成若干 非空 组，这些非空组的长度构成一个自然数序列（1, 2, 3, 4, ...）。一个组的 长度
 * 就是组中分配到的节点数目。换句话说：
 * 
 * 
 * 节点 1 分配给第一组
 * 节点 2 和 3 分配给第二组
 * 节点 4、5 和 6 分配给第三组，以此类推
 * 
 * 
 * 注意，最后一组的长度可能小于或者等于 1 + 倒数第二组的长度 。
 * 
 * 反转 每个 偶数 长度组中的节点，并返回修改后链表的头节点 head 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：head = [5,2,6,3,9,1,7,3,8,4]
 * 输出：[5,6,2,3,9,1,4,8,3,7]
 * 解释：
 * - 第一组长度为 1 ，奇数，没有发生反转。
 * - 第二组长度为 2 ，偶数，节点反转。
 * - 第三组长度为 3 ，奇数，没有发生反转。
 * - 最后一组长度为 4 ，偶数，节点反转。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：head = [1,1,0,6]
 * 输出：[1,0,1,6]
 * 解释：
 * - 第一组长度为 1 ，没有发生反转。
 * - 第二组长度为 2 ，节点反转。
 * - 最后一组长度为 1 ，没有发生反转。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：head = [2,1]
 * 输出：[2,1]
 * 解释：
 * - 第一组长度为 1 ，没有发生反转。
 * - 最后一组长度为 1 ，没有发生反转。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目范围是 [1, 10^5]
 * 0 <= Node.val <= 10^5
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
    ListNode* reverseList(ListNode* head, ListNode* end) {
        ListNode* pre = nullptr, *cur = head;
        while (cur != end) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int groupSize = 1;
        ListNode* dummy = new ListNode(0, head);
        ListNode* preTail = dummy, *cur = head;
        while (cur) {
            int cnt = 0;
            ListNode* start = cur, *pre = nullptr;
            while (cnt < groupSize && cur) {
                pre = cur;
                cur = cur->next;
                cnt++;
            }
            if (cnt % 2 == 0) {
                ListNode* rehead = reverseList(start, cur);
                preTail->next = rehead;
                start->next = cur;
                preTail = start;
            } else {
                preTail = pre;
            }
            groupSize++;
        }
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,2,6,3,9,1,7,3,8,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,0,6]\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n
// @lcpr case=end

 */

