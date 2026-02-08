/*
 * @lc app=leetcode.cn id=115 lang=cpp
 * @lcpr version=30204
 *
 * [115] 不同的子序列
 *
 * https://leetcode.cn/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (53.59%)
 * Likes:    1396
 * Dislikes: 0
 * Total Accepted:    248.2K
 * Total Submissions: 463K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * 给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。
 * 
 * 测试用例保证结果在 32 位有符号整数范围内。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "rabbbit", t = "rabbit"
 * 输出：3
 * 解释：
 * 如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
 * rabbbit
 * rabbbit
 * rabbbit
 * 
 * 示例 2：
 * 
 * 输入：s = "babgbag", t = "bag"
 * 输出：5
 * 解释：
 * 如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length, t.length <= 1000
 * s 和 t 由英文字母组成
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
    int numDistinct1(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i < j) {
                return 0;
            }
            if (j < 0) {
                return 1;
            }
            int &res = memo[i][j];
            if (res != -1) {
                return res;
            }
            if (s[i] == t[j]) {
                res = dfs(i - 1, j) + dfs(i - 1, j - 1);
            } else {
                res = dfs(i - 1, j);
            }
            return res;
        };
        return dfs(m - 1, n - 1);
    }

    int numDistinct2(string s, string t) {
        int n = s.length(), m = t.length();
        if (n < m) {
            return 0;
        }
        vector<vector<unsigned>> f(n + 1, vector<unsigned>(m + 1, 0));
        f[0][0] = 1;
        for (int i = 0; i < n; i++) {
            f[i + 1][0] = 1;
            // for (int j = 0; j < m; j++) {
            //     if (s[i] == t[j]) {
            //         f[i + 1][j + 1] = f[i][j + 1] + f[i][j];
            //     } else {
            //         f[i + 1][j + 1] = f[i][j + 1];
            //     }
            // }

            for (int j = max(m - n + i, 0); j < min(i + 1, m); j++) {
                f[i + 1][j + 1] = f[i][j + 1];
                if (s[i] == t[j]) {
                    f[i + 1][j + 1] += f[i][j];
                }
            }
        }
        return f[n][m];
    }

    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        if (n < m) {
            return 0;
        }

        vector<unsigned> f(m + 1, 0);
        f[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = min(i, m - 1); j >= max(m - n + i, 0); j--) {
                if (s[i] == t[j]) {
                    f[j + 1] += f[j];
                }
            }
        }
        return f[m];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "rabbbit"\n"rabbit"\n
// @lcpr case=end

// @lcpr case=start
// "babgbag"\n"bag"\n
// @lcpr case=end

 */

