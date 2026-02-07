/*
 * @lc app=leetcode.cn id=712 lang=cpp
 * @lcpr version=30204
 *
 * [712] 两个字符串的最小ASCII删除和
 *
 * https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/description/
 *
 * algorithms
 * Medium (73.12%)
 * Likes:    465
 * Dislikes: 0
 * Total Accepted:    77.4K
 * Total Submissions: 104K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * 给定两个字符串s1 和 s2，返回 使两个字符串相等所需删除字符的 ASCII 值的最小和 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: s1 = "sea", s2 = "eat"
 * 输出: 231
 * 解释: 在 "sea" 中删除 "s" 并将 "s" 的值(115)加入总和。
 * 在 "eat" 中删除 "t" 并将 116 加入总和。
 * 结束时，两个字符串相等，115 + 116 = 231 就是符合条件的最小和。
 * 
 * 
 * 示例 2:
 * 
 * 输入: s1 = "delete", s2 = "leet"
 * 输出: 403
 * 解释: 在 "delete" 中删除 "dee" 字符串变成 "let"，
 * 将 100[d]+101[e]+101[e] 加入总和。在 "leet" 中删除 "e" 将 101[e] 加入总和。
 * 结束时，两个字符串都等于 "let"，结果即为 100+101+101+101 = 403 。
 * 如果改为将两个字符串转换为 "lee" 或 "eet"，我们会得到 433 或 417 的结果，比答案更大。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s1.length, s2.length <= 1000
 * s1 和 s2 由小写英文字母组成
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int total = reduce(s1.begin(), s1.end(), 0) + reduce(s2.begin(), s2.end(), 0);
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                f[i + 1][j + 1] = s1[i] == s2[j] ? f[i][j] + s1[i] : max(f[i][j + 1], f[i + 1][j]);
            }
        }
        return total - f[n][m] * 2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "sea"\n"eat"\n
// @lcpr case=end

// @lcpr case=start
// "delete"\n"leet"\n
// @lcpr case=end

 */

