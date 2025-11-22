/*
 * @lc app=leetcode.cn id=1614 lang=cpp
 * @lcpr version=30204
 *
 * [1614] 括号的最大嵌套深度
 *
 * https://leetcode.cn/problems/maximum-nesting-depth-of-the-parentheses/description/
 *
 * algorithms
 * Easy (81.66%)
 * Likes:    158
 * Dislikes: 0
 * Total Accepted:    85.7K
 * Total Submissions: 105.2K
 * Testcase Example:  '"(1+(2*3)+((8)/4))+1"'
 *
 * 给定 有效括号字符串 s，返回 s 的 嵌套深度。嵌套深度是嵌套括号的 最大 数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "(1+(2*3)+((8)/4))+1"
 * 
 * 输出：3
 * 
 * 解释：数字 8 在嵌套的 3 层括号中。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "(1)+((2))+(((3)))"
 * 
 * 输出：3
 * 
 * 解释：数字 3 在嵌套的 3 层括号中。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "()(())((()()))"
 * 
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 100
 * s 由数字 0-9 和字符 '+'、'-'、'*'、'/'、'('、')' 组成
 * 题目数据保证括号字符串 s 是 有效的括号字符串
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
    int maxDepth(string s) {
        int leftCount = 0;
        int res = 0;
        for (char c : s) {
            if (c == '(') {
                leftCount++;
            } else if (c == ')') {
                leftCount--;
            }
            res = max(leftCount, res);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "(1+(2*3)+((8)/4))+1"\n
// @lcpr case=end

// @lcpr case=start
// "(1)+((2))+(((3)))"\n
// @lcpr case=end

// @lcpr case=start
// "()(())((()()))"\n
// @lcpr case=end

 */

