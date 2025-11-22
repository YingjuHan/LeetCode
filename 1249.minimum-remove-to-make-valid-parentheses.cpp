/*
 * @lc app=leetcode.cn id=1249 lang=cpp
 * @lcpr version=30204
 *
 * [1249] 移除无效的括号
 *
 * https://leetcode.cn/problems/minimum-remove-to-make-valid-parentheses/description/
 *
 * algorithms
 * Medium (60.23%)
 * Likes:    282
 * Dislikes: 0
 * Total Accepted:    56.4K
 * Total Submissions: 92.2K
 * Testcase Example:  '"lee(t(c)o)de)"'
 *
 * 给你一个由 '('、')' 和小写字母组成的字符串 s。
 * 
 * 你需要从字符串中删除最少数目的 '(' 或者 ')' （可以删除任意位置的括号)，使得剩下的「括号字符串」有效。
 * 
 * 请返回任意一个合法字符串。
 * 
 * 有效「括号字符串」应当符合以下 任意一条 要求：
 * 
 * 
 * 空字符串或只包含小写字母的字符串
 * 可以被写作 AB（A 连接 B）的字符串，其中 A 和 B 都是有效「括号字符串」
 * 可以被写作 (A) 的字符串，其中 A 是一个有效的「括号字符串」
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "lee(t(c)o)de)"
 * 输出："lee(t(c)o)de"
 * 解释："lee(t(co)de)" , "lee(t(c)ode)" 也是一个可行答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "a)b(c)d"
 * 输出："ab(c)d"
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "))(("
 * 输出：""
 * 解释：空字符串也是有效的
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] 可能是 '('、')' 或英文小写字母
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
class Solution {
public:
    /**
     * 将所有的括号和它们的索引以pair<char,int>依次入栈，
     * 同时将配对的有效括号出栈，最后剩下的就是无效括号以及其索引，
     * 再利用剩下的索引在原字符串中删除对应的括号
     */
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> stk;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (!stk.empty()) {
                if (stk.top().first == '(' && c ==')') {
                    stk.pop();
                    continue;
                }
                if (c == '(') {
                    stk.push({c, i});
                    continue;
                }
            }
            if (c == '(' || c == ')') {
                stk.push({c, i});
            }
        }
        while (!stk.empty()) {
            s.erase(s.begin() + stk.top().second);
            stk.pop();
        }
        return s;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "lee(t(c)o)de)"\n
// @lcpr case=end

// @lcpr case=start
// "a)b(c)d"\n
// @lcpr case=end

// @lcpr case=start
// "))(("\n
// @lcpr case=end

 */

