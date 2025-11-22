/*
 * @lc app=leetcode.cn id=1190 lang=cpp
 * @lcpr version=30204
 *
 * [1190] 反转每对括号间的子串
 *
 * https://leetcode.cn/problems/reverse-substrings-between-each-pair-of-parentheses/description/
 *
 * algorithms
 * Medium (65.24%)
 * Likes:    315
 * Dislikes: 0
 * Total Accepted:    73.2K
 * Total Submissions: 111.5K
 * Testcase Example:  '"(abcd)"'
 *
 * 给出一个字符串 s（仅含有小写英文字母和括号）。
 * 
 * 请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。
 * 
 * 注意，您的结果中 不应 包含任何括号。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "(abcd)"
 * 输出："dcba"
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "(u(love)i)"
 * 输出："iloveu"
 * 解释：先反转子字符串 "love" ，然后反转整个字符串。
 * 
 * 示例 3：
 * 
 * 输入：s = "(ed(et(oc))el)"
 * 输出："leetcode"
 * 解释：先反转子字符串 "oc" ，接着反转 "etco" ，然后反转整个字符串。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 2000
 * s 中只有小写英文字母和括号
 * 题目测试用例确保所有括号都是成对出现的
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
    string reverseParentheses(string s) {
        vector<int> idx;
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                idx.push_back(i);
            } else if (s[i] == ')') {
                int start = idx.back(), end = i;
                reverse(s.begin() + start, s.begin() + end);
                idx.pop_back();
            }
        }
        for (char c : s) {
            if (c != '(' && c != ')') {
                res.push_back(c);
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "(abcd)"\n
// @lcpr case=end

// @lcpr case=start
// "(u(love)i)"\n
// @lcpr case=end

// @lcpr case=start
// "(ed(et(oc))el)"\n
// @lcpr case=end

 */

