/*
 * @lc app=leetcode.cn id=72 lang=cpp
 * @lcpr version=30204
 *
 * [72] 编辑距离
 *
 * https://leetcode.cn/problems/edit-distance/description/
 *
 * algorithms
 * Medium (64.02%)
 * Likes:    3842
 * Dislikes: 0
 * Total Accepted:    800.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '"horse"\n"ros"'
 *
 * 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
 * 
 * 你可以对一个单词进行如下三种操作：
 * 
 * 
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：word1 = "horse", word2 = "ros"
 * 输出：3
 * 解释：
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 * 
 * 
 * 示例 2：
 * 
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 * 解释：
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= word1.length, word2.length <= 500
 * word1 和 word2 由小写英文字母组成
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
    int minDistance1(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> memo(n, vector<int>(m, -1));

        auto dfs = [&](this auto&& dfs, int i, int j) {
            if (i < 0) {
                return j + 1;
            }
            if (j < 0) {
                return i + 1;
            }
            int& res = memo[i][j];
            if (res != -1) {
                return res;
            }
            if (word1[i] == word2[j]) {
                res = dfs(i - 1, j - 1);
                return res;
            }
            res = min({dfs(i - 1, j), dfs(i, j - 1), dfs(i - 1, j - 1)}) + 1;
            return res;
        };
        return dfs(n - 1, m - 1);
    }

    int minDistance2(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        for (int j = 0; j < m; j++) {
            f[0][j + 1] = j + 1;
        }

        for (int i = 0; i < n; i++) {
            f[i + 1][0] = i + 1;
            for (int j = 0; j < m; j++) {
                f[i + 1][j + 1] = word1[i] == word2[j] ? f[i][j] : min({f[i][j + 1], f[i + 1][j], f[i][j]}) + 1;
            }
        }
        return f[n][m];
    }

    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> f(2, vector<int>(m + 1, 0));
        for (int j = 0; j < m; j++) {
            f[0][j + 1] = j + 1;
        }
        for (int i = 0; i < n; i++) {
            f[(i + 1) % 2][0] = i + 1;
            for (int j = 0; j < m; j++) {
                f[(i + 1) % 2][j + 1] = word1[i] == word2[j] ? f[i % 2][j] : min({f[i % 2][j + 1], f[(i + 1) % 2][j], f[i % 2][j]}) + 1;
            }
        }
        return f[n % 2][m];
    }

};
// @lc code=end



/*
// @lcpr case=start
// "horse"\n"ros"\n
// @lcpr case=end

// @lcpr case=start
// "intention"\n"execution"\n
// @lcpr case=end

 */

