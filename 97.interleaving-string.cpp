/*
 * @lc app=leetcode.cn id=97 lang=cpp
 * @lcpr version=30204
 *
 * [97] 交错字符串
 *
 * https://leetcode.cn/problems/interleaving-string/description/
 *
 * algorithms
 * Medium (46.57%)
 * Likes:    1173
 * Dislikes: 0
 * Total Accepted:    211.6K
 * Total Submissions: 453.6K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * 给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。
 * 
 * 两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：
 * 
 * 
 * s = s1 + s2 + ... + sn
 * t = t1 + t2 + ... + tm
 * |n - m| <= 1
 * 交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 +
 * ...
 * 
 * 
 * 注意：a + b 意味着字符串 a 和 b 连接。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 输入：s1 = "", s2 = "", s3 = ""
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s1.length, s2.length <= 100
 * 0 <= s3.length <= 200
 * s1、s2、和 s3 都由小写英文字母组成
 * 
 * 
 * 
 * 
 * 进阶：您能否仅使用 O(s2.length) 额外的内存空间来解决它?
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
    bool isInterleave1(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if (n + m != s3.size()) {
            return false;
        }

        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1)); // -1 表示没有计算过
        auto dfs = [&](this auto&& dfs, int i, int j) -> bool {
            if (i < 0 && j < 0) {
                return true;
            }
            int &res = memo[i + 1][j + 1];
            if (res != -1) {
                return res;
            }
            res = (i >= 0 && s1[i] == s3[i + j + 1] && dfs(i - 1, j))
               || (j >= 0 && s2[j] == s3[i + j + 1] && dfs(i, j - 1));
            return res;
        };
        return dfs(n - 1, m - 1);
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if (n + m != s3.size()) {
            return false;
        }

        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        f[0][0] = 1;
        for (int j = 0; j < m; j++) {
            f[0][j + 1] = s2[j] == s3[j] && f[0][j];
        }
        for (int i = 0; i < n; i++) {
            f[i + 1][0] = s1[i] == s3[i] && f[i][0];
            for (int j = 0; j < m; j++) {
                f[i + 1][j + 1] = s1[i] == s3[i + j + 1] && f[i][j + 1] ||
                                  s2[j] == s3[i + j + 1] && f[i + 1][j];
            }
        }
        return f[n][m];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aabcc"\n"dbbca"\n"aadbbcbcac"\n
// @lcpr case=end

// @lcpr case=start
// "aabcc"\n"dbbca"\n"aadbbbaccc"\n
// @lcpr case=end

// @lcpr case=start
// ""\n""\n""\n
// @lcpr case=end

 */

