/*
 * @lc app=leetcode.cn id=2767 lang=cpp
 * @lcpr version=30204
 *
 * [2767] 将字符串分割为最少的美丽子字符串
 *
 * https://leetcode.cn/problems/partition-string-into-minimum-beautiful-substrings/description/
 *
 * algorithms
 * Medium (61.97%)
 * Likes:    25
 * Dislikes: 0
 * Total Accepted:    6.7K
 * Total Submissions: 10.8K
 * Testcase Example:  '"1011"'
 *
 * 给你一个二进制字符串 s ，你需要将字符串分割成一个或者多个 子字符串  ，使每个子字符串都是 美丽 的。
 * 
 * 如果一个字符串满足以下条件，我们称它是 美丽 的：
 * 
 * 
 * 它不包含前导 0 。
 * 它是 5 的幂的 二进制 表示。
 * 
 * 
 * 请你返回分割后的子字符串的 最少 数目。如果无法将字符串 s 分割成美丽子字符串，请你返回 -1 。
 * 
 * 子字符串是一个字符串中一段连续的字符序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "1011"
 * 输出：2
 * 解释：我们可以将输入字符串分成 ["101", "1"] 。
 * - 字符串 "101" 不包含前导 0 ，且它是整数 5^1 = 5 的二进制表示。
 * - 字符串 "1" 不包含前导 0 ，且它是整数 5^0 = 1 的二进制表示。
 * 最少可以将 s 分成 2 个美丽子字符串。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "111"
 * 输出：3
 * 解释：我们可以将输入字符串分成 ["1", "1", "1"] 。
 * - 字符串 "1" 不包含前导 0 ，且它是整数 5^0 = 1 的二进制表示。
 * 最少可以将 s 分成 3 个美丽子字符串。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "0"
 * 输出：-1
 * 解释：无法将给定字符串分成任何美丽子字符串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 15
 * s[i] 要么是 '0' 要么是 '1' 。
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
    int minimumBeautifulSubstrings(string s) {
        int max_five_pow = 15625;
        int n = s.size();
        vector<int> memo(n, INT_MAX / 2);
        auto dfs = [&](this auto&& dfs, int j) -> int {
            if (j < 0) {
                return 0;
            }
            auto &res = memo[j];
            if (res != INT_MAX / 2) {
                return res;
            }
            for (int i = 0; i <= j; i++) {
                if (s[i] == '0') {
                    continue;
                }
                int temp = stoi(s.substr(i, j - i + 1), 0, 2);
                if (max_five_pow % temp == 0) {
                    res = min(res, 1 + dfs(i - 1));
                }
            }
            return res;
        };
        int ans = dfs(n - 1);
        return ans == INT_MAX / 2 ? -1 : ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "1011"\n
// @lcpr case=end

// @lcpr case=start
// "111"\n
// @lcpr case=end

// @lcpr case=start
// "0"\n
// @lcpr case=end

 */

