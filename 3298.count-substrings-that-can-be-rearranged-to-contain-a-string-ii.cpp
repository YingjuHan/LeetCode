/*
 * @lc app=leetcode.cn id=3298 lang=cpp
 * @lcpr version=30204
 *
 * [3298] 统计重新排列后包含另一个字符串的子字符串数目 II
 *
 * https://leetcode.cn/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii/description/
 *
 * algorithms
 * Hard (67.73%)
 * Likes:    46
 * Dislikes: 0
 * Total Accepted:    21.8K
 * Total Submissions: 32.2K
 * Testcase Example:  '"bcca"\n"abc"'
 *
 * 给你两个字符串 word1 和 word2 。
 * 
 * 如果一个字符串 x 重新排列后，word2 是重排字符串的 前缀 ，那么我们称字符串 x 是 合法的 。
 * 
 * 请你返回 word1 中 合法 子字符串 的数目。
 * 
 * 注意 ，这个问题中的内存限制比其他题目要 小 ，所以你 必须 实现一个线性复杂度的解法。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：word1 = "bcca", word2 = "abc"
 * 
 * 输出：1
 * 
 * 解释：
 * 
 * 唯一合法的子字符串是 "bcca" ，可以重新排列得到 "abcc" ，"abc" 是它的前缀。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：word1 = "abcabc", word2 = "abc"
 * 
 * 输出：10
 * 
 * 解释：
 * 
 * 除了长度为 1 和 2 的所有子字符串都是合法的。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：word1 = "abcabc", word2 = "aaabc"
 * 
 * 输出：0
 * 
 * 
 * 
 * 
 * 解释：
 * 
 * 
 * 1 <= word1.length <= 10^6
 * 1 <= word2.length <= 10^4
 * word1 和 word2 都只包含小写英文字母。
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
    long long validSubstringCount(string word1, string word2) {
        if (word1.length() < word2.length()) {
            return 0;
        }

        int diff[26]{};
        for (char c : word2) {
            diff[c - 'a']++;
        }

        // 统计窗口内有多少个字母的出现次数比 t 的少
        int less = 0;
        for (int d : diff) {
            if (d > 0) {
                less++;
            }
        }

        int left = 0;
        long long res = 0;
        for (char c : word1) {
            diff[c - 'a']--;
            if (diff[c - 'a'] == 0) {
                less--;
            }

            while (less == 0) {
                char out_char = word1[left] - 'a';
                left++;
                if (diff[out_char] == 0) {
                    less++;
                }
                diff[out_char]++;
            }

            res += left;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "bcca"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abcabc"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abcabc"\n"aaabc"\n
// @lcpr case=end

 */

