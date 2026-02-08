/*
 * @lc app=leetcode.cn id=3628 lang=cpp
 * @lcpr version=30204
 *
 * [3628] 插入一个字母的最大子序列数
 *
 * https://leetcode.cn/problems/maximum-number-of-subsequences-after-one-inserting/description/
 *
 * algorithms
 * Medium (37.07%)
 * Likes:    8
 * Dislikes: 0
 * Total Accepted:    3K
 * Total Submissions: 8.1K
 * Testcase Example:  '"LMCT"'
 *
 * 给你一个由大写英文字母组成的字符串 s。
 * 
 * 你可以在字符串的 任意 位置（包括字符串的开头或结尾）最多插入一个 大写英文字母。
 * 
 * 返回在 最多插入一个字母 后，字符串中可以形成的 "LCT" 子序列的 最大 数量。
 * 
 * 子序列 是从另一个字符串中删除某些字符（可以不删除）且不改变剩余字符顺序后得到的一个 非空 字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： s = "LMCT"
 * 
 * 输出： 2
 * 
 * 解释：
 * 
 * 可以在字符串 s 的开头插入一个 "L"，变为 "LLMCT"，其中包含 2 个子序列，分别位于下标 [0, 3, 4] 和 [1, 3, 4]。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： s = "LCCT"
 * 
 * 输出： 4
 * 
 * 解释：
 * 
 * 可以在字符串 s 的开头插入一个 "L"，变为 "LLCCT"，其中包含 4 个子序列，分别位于下标 [0, 2, 4]、[0, 3, 4]、[1,
 * 2, 4] 和 [1, 3, 4]。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入： s = "L"
 * 
 * 输出： 0
 * 
 * 解释：
 * 
 * 插入一个字母无法获得子序列 "LCT"，结果为 0。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s 仅由大写英文字母组成。
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
    /*
    插入字母，分类讨论：

    插入 L，插在 s 的最左边最优，额外产生的 LCT 子序列个数就是 s 中的 CT 子序列个数。复用 115 题代码即可。
    插入 T，插在 s 的最右边最优，额外产生的 LCT 子序列个数就是 s 中的 LC 子序列个数。复用 115 题代码即可。
    插入 C，我们枚举插在 s[i] 和 s[i+1] 之间，根据乘法原理，产生的额外 LCT 子序列个数，等于 s[0] 到 s[i] 中的 L 的个数，乘以 s[i+1] 到 s[n−1] 中的 T 的个数。取所有插入位置的最大值。
    三种情况取最大值，即为插入字母所产生的额外 LCT 子序列个数。
    */
public:
    long long numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        if (n < m) {
            return 0;
        }
        vector<long long> f(m + 1);
        f[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = min(i, m - 1); j >= max(0, m - n + i); j--) {
                if (s[i] == t[j]) {
                    f[j + 1] += f[j];
                }
            }
        }
        return f[m];
    }
    
    // 计算插入 C 额外产生的 LCT 子序列个数的最大值
    // 枚举在s[i]和s[i + 1]之间的插入C,根据乘法原理，
    // 产生的额外 LCT 子序列个数，等于 s[0] 到 s[i] 中的 L 的个数，
    // 乘以 s[i+1] 到 s[n−1] 中的 T 的个数。取所有插入位置的最大值。
    long long calcInsertC(string s) {
        int cnt_t = ranges::count(s, 'T');
        int cnt_l = 0;
        long long res = 0;
        for (char c : s) {
            if (c == 'T') {
                cnt_t--;
            } else if (c == 'L') {
                cnt_l++;
            }
            res = max(res, 1LL * cnt_l * cnt_t);
        }
        return res;
    }


    long long numOfSubsequences(string s) {
        long long extra = max({
            numDistinct(s, "CT"),
            numDistinct(s, "LC"),
            calcInsertC(s)
        });
        return numDistinct(s, "LCT") + extra;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "LMCT"\n
// @lcpr case=end

// @lcpr case=start
// "LCCT"\n
// @lcpr case=end

// @lcpr case=start
// "L"\n
// @lcpr case=end

 */

