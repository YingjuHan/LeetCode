/*
 * @lc app=leetcode.cn id=1358 lang=cpp
 * @lcpr version=30204
 *
 * [1358] 包含所有三种字符的子字符串数目
 *
 * https://leetcode.cn/problems/number-of-substrings-containing-all-three-characters/description/
 *
 * algorithms
 * Medium (65.48%)
 * Likes:    151
 * Dislikes: 0
 * Total Accepted:    29K
 * Total Submissions: 44.3K
 * Testcase Example:  '"abcabc"'
 *
 * 给你一个字符串 s ，它只包含三种字符 a, b 和 c 。
 * 
 * 请你返回 a，b 和 c 都 至少 出现过一次的子字符串数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "abcabc"
 * 输出：10
 * 解释：包含 a，b 和 c 各至少一次的子字符串为 "abc", "abca", "abcab", "abcabc", "bca", "bcab",
 * "bcabc", "cab", "cabc" 和 "abc" (相同字符串算多次)。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "aaacb"
 * 输出：3
 * 解释：包含 a，b 和 c 各至少一次的子字符串为 "aaacb", "aacb" 和 "acb" 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "abc"
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= s.length <= 5 x 10^4
 * s 只包含字符 a，b 和 c 。
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
    int numberOfSubstrings(string s) {
        unordered_map<char, int> cnt;
        int left = 0, right = 0, res = 0;

        while (right < s.length()) {
            char in_win = s[right];
            cnt[in_win]++;
            right++;

            while (cnt['a'] > 0 && cnt['b'] > 0 && cnt['c'] > 0) {
                cnt[s[left]]--;
                left++;
            }

            res += left;
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcabc"\n
// @lcpr case=end

// @lcpr case=start
// "aaacb"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

 */

