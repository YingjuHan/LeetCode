/*
 * @lc app=leetcode.cn id=856 lang=cpp
 * @lcpr version=30204
 *
 * [856] 括号的分数
 *
 * https://leetcode.cn/problems/score-of-parentheses/description/
 *
 * algorithms
 * Medium (68.58%)
 * Likes:    549
 * Dislikes: 0
 * Total Accepted:    61.2K
 * Total Submissions: 88.9K
 * Testcase Example:  '"()"'
 *
 * 给定一个平衡括号字符串 S，按下述规则计算该字符串的分数：
 * 
 * 
 * () 得 1 分。
 * AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
 * (A) 得 2 * A 分，其中 A 是平衡括号字符串。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入： "()"
 * 输出： 1
 * 
 * 
 * 示例 2：
 * 
 * 输入： "(())"
 * 输出： 2
 * 
 * 
 * 示例 3：
 * 
 * 输入： "()()"
 * 输出： 2
 * 
 * 
 * 示例 4：
 * 
 * 输入： "(()(()))"
 * 输出： 6
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * S 是平衡括号字符串，且只含有 ( 和 ) 。
 * 2 <= S.length <= 50
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
    int scoreOfParentheses(string s) {
        int res = 0;
        stack<int> stk;
        for (char c : s) {
            if (c == '(') { // 遇到左括号入栈, 0模拟
                stk.push(0);
            } else {
                if (stk.top() == 0) { // 栈顶为0, 栈顶为做括号, 此时为()情况,得1分,入栈1
                    stk.pop();
                    stk.push(1);
                } else { // 栈顶不是左括号,(ABC)情况, 得分 (A+B) * 2,入栈(A+B) * 2
                    int inScore = 0; 
                    while (stk.top() != 0) {
                        inScore += stk.top();
                        stk.pop();
                    }
                    stk.pop();
                    stk.push(inScore * 2);
                }
            }
        }
        while (!stk.empty()) {// 所有分数加起来
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "(())"\n
// @lcpr case=end

// @lcpr case=start
// "()()"\n
// @lcpr case=end

// @lcpr case=start
// "(()(()))"\n
// @lcpr case=end

 */

