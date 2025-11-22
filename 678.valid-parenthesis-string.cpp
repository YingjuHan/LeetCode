/*
 * @lc app=leetcode.cn id=678 lang=cpp
 * @lcpr version=30204
 *
 * [678] 有效的括号字符串
 *
 * https://leetcode.cn/problems/valid-parenthesis-string/description/
 *
 * algorithms
 * Medium (39.52%)
 * Likes:    681
 * Dislikes: 0
 * Total Accepted:    86.9K
 * Total Submissions: 216.3K
 * Testcase Example:  '"()"'
 *
 * 给你一个只包含三种字符的字符串，支持的字符类型分别是 '('、')' 和 '*'。请你检验这个字符串是否为有效字符串，如果是 有效 字符串返回 true
 * 。
 * 
 * 有效 字符串符合如下规则：
 * 
 * 
 * 任何左括号 '(' 必须有相应的右括号 ')'。
 * 任何右括号 ')' 必须有相应的左括号 '(' 。
 * 左括号 '(' 必须在对应的右括号之前 ')'。
 * '*' 可以被视为单个右括号 ')' ，或单个左括号 '(' ，或一个空字符串 ""。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "()"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "(*)"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "(*))"
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 100
 * s[i] 为 '('、')' 或 '*'
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
    bool checkValidString(string s) {
        stack<int> star;
        stack<int> left;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') {
                left.push(i);
            }
            if (c == '*') {
                star.push(i);
            }
            if (c == ')') {
                if (!left.empty()) {
                    left.pop();
                } else if (!star.empty()) {
                    star.pop();
                } else {
                    return false;
                }
            }
        }

        while (!left.empty()) {
            
            if (star.empty()) {
                return false;
            }
            int posL = left.top();
            int posS = star.top();
            if (posS > posL) {
                star.pop();
                left.pop();
            } else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "(*)"\n
// @lcpr case=end

// @lcpr case=start
// "(*))"\n
// @lcpr case=end

 */

