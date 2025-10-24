/*
 * @lc app=leetcode.cn id=2904 lang=cpp
 * @lcpr version=30204
 *
 * [2904] 最短且字典序最小的美丽子字符串
 *
 * https://leetcode.cn/problems/shortest-and-lexicographically-smallest-beautiful-string/description/
 *
 * algorithms
 * Medium (46.09%)
 * Likes:    35
 * Dislikes: 0
 * Total Accepted:    19.5K
 * Total Submissions: 42.1K
 * Testcase Example:  '"100011001"\n3'
 *
 * 给你一个二进制字符串 s 和一个正整数 k 。
 * 
 * 如果 s 的某个子字符串中 1 的个数恰好等于 k ，则称这个子字符串是一个 美丽子字符串 。
 * 
 * 令 len 等于 最短 美丽子字符串的长度。
 * 
 * 返回长度等于 len 且字典序 最小 的美丽子字符串。如果 s 中不含美丽子字符串，则返回一个 空 字符串。
 * 
 * 对于相同长度的两个字符串 a 和 b ，如果在 a 和 b 出现不同的第一个位置上，a 中该位置上的字符严格大于 b 中的对应字符，则认为字符串 a
 * 字典序 大于 字符串 b 。
 * 
 * 
 * 例如，"abcd" 的字典序大于 "abcc" ，因为两个字符串出现不同的第一个位置对应第四个字符，而 d 大于 c 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "100011001", k = 3
 * 输出："11001"
 * 解释：示例中共有 7 个美丽子字符串：
 * 1. 子字符串 "100011001" 。
 * 2. 子字符串 "100011001" 。
 * 3. 子字符串 "100011001" 。
 * 4. 子字符串 "100011001" 。
 * 5. 子字符串 "100011001" 。
 * 6. 子字符串 "100011001" 。
 * 7. 子字符串 "100011001" 。
 * 最短美丽子字符串的长度是 5 。
 * 长度为 5 且字典序最小的美丽子字符串是子字符串 "11001" 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "1011", k = 2
 * 输出："11"
 * 解释：示例中共有 3 个美丽子字符串：
 * 1. 子字符串 "1011" 。
 * 2. 子字符串 "1011" 。
 * 3. 子字符串 "1011" 。
 * 最短美丽子字符串的长度是 2 。
 * 长度为 2 且字典序最小的美丽子字符串是子字符串 "11" 。 
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "000", k = 1
 * 输出：""
 * 解释：示例中不存在美丽子字符串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 100
 * 1 <= k <= s.length
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
    string shortestBeautifulSubstring(string s, int k) {
        // 恰好有 k 个 1 的子字符串
        // 如果窗口内的 1 的个数超过 k，或者窗口端点是 0，就可以缩小窗口

        int n_1 = 0;
        for (char c : s) {
            if (c == '1') {
                n_1++;
            }
        }
        if (n_1 < k) {
            return "";
        }

        string res(s);
        int cnt1 = 0, left = 0, right = 0;
        while (right < s.length()) {
            cnt1 += s[right] - '0';
            right++;
            while (cnt1 > k || s[left] == '0') {
                cnt1 -= s[left] - '0';
                left++;
            }
            if (cnt1 == k) {
                string t = s.substr(left, right - left);
                if (t.length() < res.length() || t.length() == res.length() && t < res) {
                    res = t;
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "100011001"\n3\n
// @lcpr case=end

// @lcpr case=start
// "1011"\n2\n
// @lcpr case=end

// @lcpr case=start
// "000"\n1\n
// @lcpr case=end

 */

