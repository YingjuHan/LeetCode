/*
 * @lc app=leetcode.cn id=3325 lang=cpp
 * @lcpr version=30204
 *
 * [3325] 字符至少出现 K 次的子字符串 I
 *
 * https://leetcode.cn/problems/count-substrings-with-k-frequency-characters-i/description/
 *
 * algorithms
 * Medium (70.81%)
 * Likes:    14
 * Dislikes: 0
 * Total Accepted:    12.6K
 * Total Submissions: 17.7K
 * Testcase Example:  '"abacb"\n2'
 *
 * 给你一个字符串 s 和一个整数 k，在 s 的所有子字符串中，请你统计并返回 至少有一个 字符 至少出现 k 次的子字符串总数。
 * 
 * 子字符串 是字符串中的一个连续、 非空 的字符序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： s = "abacb", k = 2
 * 
 * 输出： 4
 * 
 * 解释：
 * 
 * 符合条件的子字符串如下：
 * 
 * 
 * "aba"（字符 'a' 出现 2 次）。
 * "abac"（字符 'a' 出现 2 次）。
 * "abacb"（字符 'a' 出现 2 次）。
 * "bacb"（字符 'b' 出现 2 次）。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： s = "abcde", k = 1
 * 
 * 输出： 15
 * 
 * 解释：
 * 
 * 所有子字符串都有效，因为每个字符至少出现一次。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 3000
 * 1 <= k <= s.length
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
    int numberOfSubstrings(string s, int k) {
        int ans = 0, left = 0, right = 0, cnt[26]{};
        
        while (right < s.length()) {
            char in_win = s[right];
            cnt[in_win - 'a']++;
            right++;

            while (cnt[in_win - 'a'] >= k) {
                char out_win = s[left];
                cnt[out_win - 'a']--;
                left++;
            }

            ans += left;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abacb"\n2\n
// @lcpr case=end

// @lcpr case=start
// "abcde"\n1\n
// @lcpr case=end

 */

