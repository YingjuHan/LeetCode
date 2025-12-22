/*
 * @lc app=leetcode.cn id=147 lang=cpp
 * @lcpr version=30204
 *
 * [147] 对链表进行插入排序
 *
 * https://leetcode.cn/problems/insertion-sort-list/description/
 *
 * algorithms
 * Medium (70.45%)
 * Likes:    727
 * Dislikes: 0
 * Total Accepted:    193.2K
 * Total Submissions: 274.1K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给定单个链表的头 head ，使用 插入排序 对链表进行排序，并返回 排序后链表的头 。
 * 
 * 插入排序 算法的步骤:
 * 
 * 
 * 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
 * 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
 * 重复直到所有输入数据插入完为止。
 * 
 * 
 * 
 * 下面是插入排序算法的一个图形示例。部分排序的列表(黑色)最初只包含列表中的第一个元素。每次迭代时，从输入数据中删除一个元素(红色)，并就地插入已排序的列表中。
 * 
 * 对链表进行插入排序。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入: head = [4,2,1,3]
 * 输出: [1,2,3,4]
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入: head = [-1,5,3,4,0]
 * 输出: [-1,0,3,4,5]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 
 * 列表中的节点数在 [1, 5000]范围内
 * -5000 <= Node.val <= 5000
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode *dummyNode = new ListNode(0, head);
        ListNode *lastSorted = head, *cur = head->next;
        while (cur) {
            if (lastSorted->val <= cur->val) {
                lastSorted = lastSorted->next;
            } else {
                ListNode *prev = dummyNode;
                while (prev->next->val <= cur->val) {
                    prev = prev->next;
                }
                lastSorted->next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
            }
            cur = lastSorted->next;
        }
        return dummyNode->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,5,3,4,0]\n
// @lcpr case=end

 */

