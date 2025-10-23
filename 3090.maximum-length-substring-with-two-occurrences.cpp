/*
 * @lc app=leetcode.cn id=3090 lang=cpp
 * @lcpr version=30204
 *
 * [3090] 每个字符最多出现两次的最长子字符串
 *
 * https://leetcode.cn/problems/maximum-length-substring-with-two-occurrences/description/
 *
 * algorithms
 * Easy (71.14%)
 * Likes:    35
 * Dislikes: 0
 * Total Accepted:    32.2K
 * Total Submissions: 45K
 * Testcase Example:  '"bcbbbcba"'
 *
 * 给你一个字符串 s ，请找出满足每个字符最多出现两次的最长子字符串，并返回该子字符串的 最大 长度。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： s = "bcbbbcba"
 * 
 * 输出： 4
 * 
 * 解释：
 * 
 * 以下子字符串长度为 4，并且每个字符最多出现两次："bcbbbcba"。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： s = "aaaa"
 * 
 * 输出： 2
 * 
 * 解释：
 * 
 * 以下子字符串长度为 2，并且每个字符最多出现两次："aaaa"。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= s.length <= 100
 * 
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
    int maximumLengthSubstring(string s) {
        int left = 0, right = 0, res = 0;
        unordered_map<char, int> window;
        while (right < s.length()) {
            char in_win = s[right];
            window[in_win]++;
            right++;

            while (window[in_win] > 2) {
                char out_win = s[left];
                window[out_win]--;
                left++;
            }

            res = max(res, right - left);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "bcbbbcba"\n
// @lcpr case=end

// @lcpr case=start
// "aaaa"\n
// @lcpr case=end

 */

