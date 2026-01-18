/*
 * @lc app=leetcode.cn id=2002 lang=cpp
 * @lcpr version=30204
 *
 * [2002] 两个回文子序列长度的最大乘积
 *
 * https://leetcode.cn/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/description/
 *
 * algorithms
 * Medium (63.09%)
 * Likes:    69
 * Dislikes: 0
 * Total Accepted:    8.2K
 * Total Submissions: 12.9K
 * Testcase Example:  '"leetcodecom"'
 *
 * 给你一个字符串 s ，请你找到 s 中两个 不相交回文子序列 ，使得它们长度的 乘积最大 。两个子序列在原字符串中如果没有任何相同下标的字符，则它们是
 * 不相交 的。
 * 
 * 请你返回两个回文子序列长度可以达到的 最大乘积 。
 * 
 * 子序列
 * 指的是从原字符串中删除若干个字符（可以一个也不删除）后，剩余字符不改变顺序而得到的结果。如果一个字符串从前往后读和从后往前读一模一样，那么这个字符串是一个
 * 回文字符串 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：s = "leetcodecom"
 * 输出：9
 * 解释：最优方案是选择 "ete" 作为第一个子序列，"cdc" 作为第二个子序列。
 * 它们的乘积为 3 * 3 = 9 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "bb"
 * 输出：1
 * 解释：最优方案为选择 "b" （第一个字符）作为第一个子序列，"b" （第二个字符）作为第二个子序列。
 * 它们的乘积为 1 * 1 = 1 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "accbcaxxcxx"
 * 输出：25
 * 解释：最优方案为选择 "accca" 作为第一个子序列，"xxcxx" 作为第二个子序列。
 * 它们的乘积为 5 * 5 = 25 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= s.length <= 12
 * s 只含有小写英文字母。
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
    int res = 0;
    int maxProduct(string& s) {
        string s1, s2;
        dfs(s, s1, s2, 0);
        return res;
    }
    void dfs(string&s, string& s1, string& s2, int i) {
        if (check(s1) && check(s2)) {
            res = max(res, (int)(s1.length() * s2.length()));
        }
        if (i == s.size()) return;
        string s1_new = s1 + s[i];
        string s2_new = s2 + s[i];
        dfs(s, s1_new, s2, i + 1);
        dfs(s, s1, s2_new, i + 1);
        dfs(s, s1, s2, i + 1);
    }

    bool check(string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "leetcodecom"\n
// @lcpr case=end

// @lcpr case=start
// "bb"\n
// @lcpr case=end

// @lcpr case=start
// "accbcaxxcxx"\n
// @lcpr case=end

 */

