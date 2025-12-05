/*
 * @lc app=leetcode.cn id=984 lang=cpp
 * @lcpr version=30204
 *
 * [984] 不含 AAA 或 BBB 的字符串
 *
 * https://leetcode.cn/problems/string-without-aaa-or-bbb/description/
 *
 * algorithms
 * Medium (45.54%)
 * Likes:    106
 * Dislikes: 0
 * Total Accepted:    17.5K
 * Total Submissions: 38.5K
 * Testcase Example:  '1\n2'
 *
 * 给定两个整数 a 和 b ，返回 任意 字符串 s ，要求满足：
 * 
 * 
 * s 的长度为 a + b，且正好包含 a 个 'a' 字母与 b 个 'b' 字母；
 * 子串 'aaa' 没有出现在 s 中；
 * 子串 'bbb' 没有出现在 s 中。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：a = 1, b = 2
 * 输出："abb"
 * 解释："abb", "bab" 和 "bba" 都是正确答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：a = 4, b = 1
 * 输出："aabaa"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= a, b <= 100
 * 对于给定的 a 和 b，保证存在满足要求的 s 
 * 
 * ​​​
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
    string strWithout3a3b(int a, int b) {
        string res;
        res.reserve(a + b);
        while (a > 0 && b > 0) {
            if (a == b) {
                res += "ab";
                a--;
                b--;
            } else if (a > b) {
                res += "aab";
                a -= 2;
                b--;
            } else {
                res += "bba";
                a--;
                b -= 2;
            }
        }
        if (a > 0) {
            res += string(a, 'a');
        }
        if (b > 0) {
            res += string(b, 'b');
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n2\n
// @lcpr case=end

// @lcpr case=start
// 4\n1\n
// @lcpr case=end

 */

