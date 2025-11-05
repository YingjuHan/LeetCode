/*
 * @lc app=leetcode.cn id=1930 lang=cpp
 * @lcpr version=30204
 *
 * [1930] 长度为 3 的不同回文子序列
 *
 * https://leetcode.cn/problems/unique-length-3-palindromic-subsequences/description/
 *
 * algorithms
 * Medium (58.38%)
 * Likes:    70
 * Dislikes: 0
 * Total Accepted:    15.6K
 * Total Submissions: 26.6K
 * Testcase Example:  '"aabca"'
 *
 * 给你一个字符串 s ，返回 s 中 长度为 3 的不同回文子序列 的个数。
 * 
 * 即便存在多种方法来构建相同的子序列，但相同的子序列只计数一次。
 * 
 * 回文 是正着读和反着读一样的字符串。
 * 
 * 子序列 是由原字符串删除其中部分字符（也可以不删除）且不改变剩余字符之间相对顺序形成的一个新字符串。
 * 
 * 
 * 例如，"ace" 是 "abcde" 的一个子序列。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "aabca"
 * 输出：3
 * 解释：长度为 3 的 3 个回文子序列分别是：
 * - "aba" ("aabca" 的子序列)
 * - "aaa" ("aabca" 的子序列)
 * - "aca" ("aabca" 的子序列)
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "adc"
 * 输出：0
 * 解释："adc" 不存在长度为 3 的回文子序列。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "bbcbaba"
 * 输出：4
 * 解释：长度为 3 的 4 个回文子序列分别是：
 * - "bbb" ("bbcbaba" 的子序列)
 * - "bcb" ("bbcbaba" 的子序列)
 * - "bab" ("bbcbaba" 的子序列)
 * - "aba" ("bbcbaba" 的子序列)
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= s.length <= 10^5
 * s 仅由小写英文字母组成
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
    int countPalindromicSubsequence(string s) {
        int res = 0;
        unordered_map<char, int> pre, suf;
        // mark[首字符索引][中间字符索引] = 是否已统计（首字符 = 尾字符，所以只需记录首和中间）
        vector<vector<bool>> mark(26, vector<bool>(26, false));

        // 初始化后缀哈希表：统计每个字符在整个字符串中的总个数
        for (char c : s) {
            suf[c]++;
        }

        // 遍历每个字符 c，将其作为「中间字符」
        for (char c : s) {
            suf[c]--; // 后缀计数：移除当前字符（当前字符作为中间，后缀是右侧字符）
            
            // 遍历所有可能的「首尾字符」（a-z）
            for (int i = 0; i < 26; i++) {
                char head_tail = 'a' + i;
                // 条件：1. 前缀（左侧）有该首尾字符；2. 后缀（右侧）有该首尾字符；3. 该组合未统计过
                if (pre[head_tail] > 0 && suf[head_tail] > 0 && !mark[i][c - 'a']) {
                    res++;
                    mark[i][c - 'a'] = true; // 标记该组合已统计，避免重复
                }
            }
            
            pre[c]++; // 前缀计数：加入当前字符（下一轮循环时，当前字符成为左侧前缀）
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aabca"\n
// @lcpr case=end

// @lcpr case=start
// "adc"\n
// @lcpr case=end

// @lcpr case=start
// "bbcbaba"\n
// @lcpr case=end

 */

