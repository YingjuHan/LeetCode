/*
 * @lc app=leetcode.cn id=1297 lang=cpp
 * @lcpr version=30204
 *
 * [1297] 子串的最大出现次数
 *
 * https://leetcode.cn/problems/maximum-number-of-occurrences-of-a-substring/description/
 *
 * algorithms
 * Medium (55.18%)
 * Likes:    145
 * Dislikes: 0
 * Total Accepted:    28.2K
 * Total Submissions: 51K
 * Testcase Example:  '"aababcaab"\n2\n3\n4'
 *
 * 给你一个字符串 s ，请你返回满足以下条件且出现次数最大的 任意 子串的出现次数：
 * 
 * 
 * 子串中不同字母的数目必须小于等于 maxLetters 。
 * 子串的长度必须大于等于 minSize 且小于等于 maxSize 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
 * 输出：2
 * 解释：子串 "aab" 在原字符串中出现了 2 次。
 * 它满足所有的要求：2 个不同的字母，长度为 3 （在 minSize 和 maxSize 范围内）。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
 * 输出：2
 * 解释：子串 "aaa" 在原字符串中出现了 2 次，且它们有重叠部分。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3
 * 输出：3
 * 
 * 
 * 示例 4：
 * 
 * 输入：s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * 1 <= maxLetters <= 26
 * 1 <= minSize <= maxSize <= min(26, s.length)
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
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> cnt_str;
        int cnt_char[26] {};
        int kinds = 0;
        int res = 0;
        
        for (int i = 0; i < s.size(); i++) {
            int in = s[i] - 'a';
            if (cnt_char[in] == 0) {
                kinds++;
            }
            cnt_char[in]++;

            int left = i - minSize + 1;
            if (left < 0) {
                continue;
            }

            if (kinds <= maxLetters) {
                cnt_str[s.substr(left, minSize)]++;
                int cur = cnt_str[s.substr(left, minSize)];
                res = max(res, cur);
            }

            int out = s[left] - 'a';
            cnt_char[out]--;
            if (cnt_char[out] == 0) {
                kinds--;
            }
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aababcaab"\n2\n3\n4\n
// @lcpr case=end

// @lcpr case=start
// "aaaa"\n1\n3\n3\n
// @lcpr case=end

// @lcpr case=start
// "aabcabcab"\n2\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// "abcde"\n2\n3\n3\n
// @lcpr case=end

 */

