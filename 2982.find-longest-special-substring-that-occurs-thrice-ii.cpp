/*
 * @lc app=leetcode.cn id=2982 lang=cpp
 * @lcpr version=30204
 *
 * [2982] 找出出现至少三次的最长特殊子字符串 II
 *
 * https://leetcode.cn/problems/find-longest-special-substring-that-occurs-thrice-ii/description/
 *
 * algorithms
 * Medium (51.90%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    24.3K
 * Total Submissions: 46.8K
 * Testcase Example:  '"aaaa"'
 *
 * 给你一个仅由小写英文字母组成的字符串 s 。
 * 
 * 如果一个字符串仅由单一字符组成，那么它被称为 特殊 字符串。例如，字符串 "abc" 不是特殊字符串，而字符串 "ddd"、"zz" 和 "f"
 * 是特殊字符串。
 * 
 * 返回在 s 中出现 至少三次 的 最长特殊子字符串 的长度，如果不存在出现至少三次的特殊子字符串，则返回 -1 。
 * 
 * 子字符串 是字符串中的一个连续 非空 字符序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "aaaa"
 * 输出：2
 * 解释：出现三次的最长特殊子字符串是 "aa" ：子字符串 "aaaa"、"aaaa" 和 "aaaa"。
 * 可以证明最大长度是 2 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "abcdef"
 * 输出：-1
 * 解释：不存在出现至少三次的特殊子字符串。因此返回 -1 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "abcaba"
 * 输出：1
 * 解释：出现三次的最长特殊子字符串是 "a" ：子字符串 "abcaba"、"abcaba" 和 "abcaba"。
 * 可以证明最大长度是 1 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= s.length <= 5 * 10^5
 * s 仅由小写英文字母组成。
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
     * 1
     * 设字母a的最长特殊子串的长度为L1
     * 可以选择选3个长度为L1-2的相同的特殊子串
     * 
     * 2
     * 设字母a的第2长特殊子串的长度为L2
     * 如果L1=L2，选3个长为L1-1的
     * 如果L1>L2，选3个长为L2的
     * min(L1-1, L2)
     * 
     * 3
     * 设字母a的第3长特殊子串的长度为L3
     * 可以选择选3个长度为L3的相同的特殊子串
     * 
     * max(l1-2, min(L1 - 1, L2), L3)
     */
    int maximumLength(string s) {
        vector<int> groups[26];
        int cnt = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            cnt++;
            if (i + 1 == n || s[i] != s[i + 1]) {
                groups[s[i] - 'a'].push_back(cnt); // 统计连续字符长度
                cnt = 0;
            }
        }

        int res = 0;
        for (auto& a : groups) {
            if (a.empty()) continue;
            sort(a.begin(), a.end(), greater());
            a.push_back(0);
            a.push_back(0);
            res = max({res, a[0] - 2, min(a[0] - 1, a[1]), a[2]});
        }
        return res ? res : -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aaaa"\n
// @lcpr case=end

// @lcpr case=start
// "abcdef"\n
// @lcpr case=end

// @lcpr case=start
// "abcaba"\n
// @lcpr case=end

 */

