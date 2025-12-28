/*
 * @lc app=leetcode.cn id=1171 lang=cpp
 * @lcpr version=30204
 *
 * [1171] 从链表中删去总和值为零的连续节点
 *
 * https://leetcode.cn/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/
 *
 * algorithms
 * Medium (53.68%)
 * Likes:    352
 * Dislikes: 0
 * Total Accepted:    40.9K
 * Total Submissions: 76K
 * Testcase Example:  '[1,2,-3,3,1]'
 *
 * 给你一个链表的头节点 head，请你编写代码，反复删去链表中由 总和 值为 0 的连续节点组成的序列，直到不存在这样的序列为止。
 * 
 * 删除完毕后，请你返回最终结果链表的头节点。
 * 
 * 
 * 
 * 你可以返回任何满足题目要求的答案。
 * 
 * （注意，下面示例中的所有序列，都是对 ListNode 对象序列化的表示。）
 * 
 * 示例 1：
 * 
 * 输入：head = [1,2,-3,3,1]
 * 输出：[3,1]
 * 提示：答案 [1,2,1] 也是正确的。
 * 
 * 
 * 示例 2：
 * 
 * 输入：head = [1,2,3,-3,4]
 * 输出：[1,2,4]
 * 
 * 
 * 示例 3：
 * 
 * 输入：head = [1,2,3,-3,-2]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给你的链表中可能有 1 到 1000 个节点。
 * 对于链表中的每个节点，节点的值：-1000 <= node.val <= 1000.
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        unordered_map<int, ListNode*> last;
        ListNode* cur = dummy;
        int s = 0;
        while (cur) {
            s += cur->val;
            last[s] = cur;
            cur = cur->next;
        }
        s = 0;
        cur = dummy;
        while (cur) {
            s += cur->val;
            cur->next = last[s]->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,-3,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,-3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,-3,-2]\n
// @lcpr case=end

 */

