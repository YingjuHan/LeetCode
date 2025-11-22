/*
 * @lc app=leetcode.cn id=1541 lang=cpp
 * @lcpr version=30204
 *
 * [1541] 平衡括号字符串的最少插入次数
 *
 * https://leetcode.cn/problems/minimum-insertions-to-balance-a-parentheses-string/description/
 *
 * algorithms
 * Medium (49.33%)
 * Likes:    85
 * Dislikes: 0
 * Total Accepted:    26K
 * Total Submissions: 52.4K
 * Testcase Example:  '"(()))"'
 *
 * 给你一个括号字符串 s ，它只包含字符 '(' 和 ')' 。一个括号字符串被称为平衡的当它满足：
 * 
 * 
 * 任何左括号 '(' 必须对应两个连续的右括号 '))' 。
 * 左括号 '(' 必须在对应的连续两个右括号 '))' 之前。
 * 
 * 
 * 比方说 "())"， "())(())))" 和 "(())())))" 都是平衡的， ")()"， "()))" 和 "(()))" 都是不平衡的。
 * 
 * 你可以在任意位置插入字符 '(' 和 ')' 使字符串平衡。
 * 
 * 请你返回让 s 平衡的最少插入次数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "(()))"
 * 输出：1
 * 解释：第二个左括号有与之匹配的两个右括号，但是第一个左括号只有一个右括号。我们需要在字符串结尾额外增加一个 ')' 使字符串变成平衡字符串
 * "(())))" 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "())"
 * 输出：0
 * 解释：字符串已经平衡了。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "))())("
 * 输出：3
 * 解释：添加 '(' 去匹配最开头的 '))' ，然后添加 '))' 去匹配最后一个 '(' 。
 * 
 * 
 * 示例 4：
 * 
 * 输入：s = "(((((("
 * 输出：12
 * 解释：添加 12 个 ')' 得到平衡字符串。
 * 
 * 
 * 示例 5：
 * 
 * 输入：s = ")))))))"
 * 输出：5
 * 解释：在字符串开头添加 4 个 '(' 并在结尾添加 1 个 ')' ，字符串变成平衡字符串 "(((())))))))" 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s 只包含 '(' 和 ')' 。
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
    /**
     * https://leetcode.cn/problems/minimum-insertions-to-balance-a-parentheses-string/solutions/2844850/fen-lei-tao-lun-by-yi-cheng-8i-3m5s/
     * 
     * 
     */
class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int leftCount = 0;
        int length = s.size();
        int index = 0;
        while (index < length) {
            char c = s[index];
            if (c == '(') {
                leftCount++;
                index++;
            } else {
                if (leftCount > 0) {
                    leftCount--;
                } else {
                    insertions++;
                }
                if (index < length - 1 && s[index + 1] == ')') {
                    index += 2;
                } else {
                    insertions++;
                    index++;
                }
            }
        }
        insertions += leftCount * 2;
        return insertions;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "(()))"\n
// @lcpr case=end

// @lcpr case=start
// "())"\n
// @lcpr case=end

// @lcpr case=start
// "))())("\n
// @lcpr case=end

// @lcpr case=start
// "(((((("\n
// @lcpr case=end

// @lcpr case=start
// ")))))))"\n
// @lcpr case=end

 */

