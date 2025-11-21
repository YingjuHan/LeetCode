/*
 * @lc app=leetcode.cn id=1717 lang=cpp
 * @lcpr version=30204
 *
 * [1717] 删除子字符串的最大得分
 *
 * https://leetcode.cn/problems/maximum-score-from-removing-substrings/description/
 *
 * algorithms
 * Medium (48.56%)
 * Likes:    70
 * Dislikes: 0
 * Total Accepted:    18.1K
 * Total Submissions: 29.5K
 * Testcase Example:  '"cdbcbbaaabab"\n4\n5'
 *
 * 给你一个字符串 s 和两个整数 x 和 y 。你可以执行下面两种操作任意次。
 * 
 * 
 * 删除子字符串 "ab" 并得到 x 分。
 * 
 * 
 * 比方说，从 "cabxbae" 删除 ab ，得到 "cxbae" 。
 * 
 * 
 * 删除子字符串"ba" 并得到 y 分。
 * 
 * 比方说，从 "cabxbae" 删除 ba ，得到 "cabxe" 。
 * 
 * 
 * 
 * 
 * 请返回对 s 字符串执行上面操作若干次能得到的最大得分。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "cdbcbbaaabab", x = 4, y = 5
 * 输出：19
 * 解释：
 * - 删除 "cdbcbbaaabab" 中加粗的 "ba" ，得到 s = "cdbcbbaaab" ，加 5 分。
 * - 删除 "cdbcbbaaab" 中加粗的 "ab" ，得到 s = "cdbcbbaa" ，加 4 分。
 * - 删除 "cdbcbbaa" 中加粗的 "ba" ，得到 s = "cdbcba" ，加 5 分。
 * - 删除 "cdbcba" 中加粗的 "ba" ，得到 s = "cdbc" ，加 5 分。
 * 总得分为 5 + 4 + 5 + 5 = 19 。
 * 
 * 示例 2：
 * 
 * 输入：s = "aabbaaxybbaabb", x = 5, y = 4
 * 输出：20
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * 1 <= x, y <= 10^4
 * s 只包含小写英文字母。
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
    int maximumGain(string s, int x, int y) {
        stack<char> a, b;
        int num = 0;
        if (x > y) {
            swap(x, y);
            reverse(s.begin(), s.end());
        }
        for (char c : s) {
            if (c != 'a') {
                a.push(c);
            } else {
                if (!a.empty() && a.top() == 'b') {
                    a.pop();
                    num += y;
                } else {
                    a.push(c);
                }
            }
        }

        while (!a.empty()) {
            char c = a.top();
            a.pop();
            if (c != 'a') {
                b.push(c);
            } else {
                if (!b.empty() && b.top() == 'b') {
                    b.pop();
                    num += x;
                } else {
                    b.push(c);
                }
            }
        }
        return num;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "cdbcbbaaabab"\n4\n5\n
// @lcpr case=end

// @lcpr case=start
// "aabbaaxybbaabb"\n5\n4\n
// @lcpr case=end

 */

