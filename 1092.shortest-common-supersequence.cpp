/*
 * @lc app=leetcode.cn id=1092 lang=cpp
 * @lcpr version=30204
 *
 * [1092] 最短公共超序列
 *
 * https://leetcode.cn/problems/shortest-common-supersequence/description/
 *
 * algorithms
 * Hard (56.02%)
 * Likes:    299
 * Dislikes: 0
 * Total Accepted:    24.5K
 * Total Submissions: 43.9K
 * Testcase Example:  '"abac"\n"cab"'
 *
 * 给你两个字符串 str1 和 str2，返回同时以 str1 和 str2 作为 子序列 的最短字符串。如果答案不止一个，则可以返回满足条件的 任意一个
 * 答案。
 * 
 * 如果从字符串 t 中删除一些字符（也可能不删除），可以得到字符串 s ，那么 s 就是 t 的一个子序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：str1 = "abac", str2 = "cab"
 * 输出："cabac"
 * 解释：
 * str1 = "abac" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 的第一个 "c"得到 "abac"。 
 * str2 = "cab" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 末尾的 "ac" 得到 "cab"。
 * 最终我们给出的答案是满足上述属性的最短字符串。
 * 
 * 
 * 示例 2：
 * 
 * 输入：str1 = "aaaaaaaa", str2 = "aaaaaaaa"
 * 输出："aaaaaaaa"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= str1.length, str2.length <= 1000
 * str1 和 str2 都由小写英文字母组成。
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
    string shortestCommonSupersequence1(string str1, string str2) {
        if (str1.empty()) {
            return str2;
        }
        if (str2.empty()) {
            return str1;
        }
        int n = str1.length(), m = str2.length();
        string s1 = str1.substr(0, n - 1), s2 = str2.substr(0, m - 1);
        if (str1.back() == str2.back()) {
            return shortestCommonSupersequence1(s1, s2) + str1.back();
        }
        string ans1 = shortestCommonSupersequence1(s1, str2);
        string ans2 = shortestCommonSupersequence1(str1, s2);
        if (ans1.length() < ans2.length()) {
            return ans1 + str1.back();
        }
        return ans2 + str2.back();
    }

    string shortestCommonSupersequence2(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<string>> memo(n, vector<string>(m));
        // dfs(i,j) 返回 s 的前缀 [0,i] 和 t 的前缀 [0,j] 的最短公共超序列
        function<string(int, int)> dfs = [&](int i, int j) -> string {
            if (i < 0) return t.substr(0, j + 1); // s 是空串，返回剩余的 t
            if (j < 0) return s.substr(0, i + 1); // t 是空串，返回剩余的 s
            string &res = memo[i][j];
            if (!res.empty()) return res; // 避免重复计算 dfs 的结果
            if (s[i] == t[j]) // 最短公共超序列一定包含 s[i]
                return res = dfs(i - 1, j - 1) + s[i];
            auto ans1 = dfs(i - 1, j);
            auto ans2 = dfs(i, j - 1);
            if (ans1.length() < ans2.length()) // 取 ans1 和 ans2 中更短的组成答案
                return res = ans1 + s[i];
            return res = ans2 + t[j];
        };
        return dfs(n - 1, m - 1);
    }

    string shortestCommonSupersequence3(string &s, string &t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        // dfs(i,j) 返回 s 的前缀 [0,i] 和 t 的前缀 [0,j] 的最短公共超序列的长度
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i < 0) return j + 1; // s 是空串，返回剩余的 t 的长度
            if (j < 0) return i + 1; // t 是空串，返回剩余的 s 的长度
            int &res = memo[i][j];
            if (res != -1) return res; // 避免重复计算 dfs 的结果
            if (s[i] == t[j]) // 最短公共超序列一定包含 s[i]
                return res = dfs(i - 1, j - 1) + 1;
            return res = min(dfs(i - 1, j), dfs(i, j - 1)) + 1;
        };

        // make_ans(i,j) 返回 s 的前缀 [0,i] 和 t 的前缀 [0,j] 的最短公共超序列
        // 看上去和 dfs 没啥区别，但是末尾的递归是 if-else
        // make_ans(i-1,j) 和 make_ans(i,j-1) 不会都调用
        // 所以 make_ans 的递归树仅仅是一条链
        function<string(int, int)> make_ans = [&](int i, int j) -> string {
            if (i < 0) return t.substr(0, j + 1); // s 是空串，返回剩余的 t
            if (j < 0) return s.substr(0, i + 1); // t 是空串，返回剩余的 s
            if (s[i] == t[j]) // 最短公共超序列一定包含 s[i]
                return make_ans(i - 1, j - 1) + s[i];
            // 如果下面 if 成立，说明上面 dfs 中的 min 取的是 dfs(i - 1, j)
            // 说明 dfs(i - 1, j) 对应的公共超序列更短
            // 那么就在 make_ans(i - 1, j) 的结果后面加上 s[i]
            // 否则说明 dfs(i, j - 1) 对应的公共超序列更短
            // 那么就在 make_ans(i, j - 1) 的结果后面加上 t[j]
            if (dfs(i, j) == dfs(i - 1, j) + 1)
                return make_ans(i - 1, j) + s[i];
            return make_ans(i, j - 1) + t[j];
        };

        return make_ans(n - 1, m - 1);
    }

    string shortestCommonSupersequence(string &s, string &t) {
        // f[i+1][j+1] 表示 s 的前缀 [0,i] 和 t 的前缀 [0,j] 的最短公共超序列的长度
        int n = s.length(), m = t.length(), f[n + 1][m + 1];
        for (int j = 0; j <= m; ++j) f[0][j] = j; // 递归边界
        for (int i = 1; i <= n; ++i) f[i][0] = i; // 递归边界
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (s[i] == t[j]) // 最短公共超序列一定包含 s[i]
                    f[i + 1][j + 1] = f[i][j] + 1;
                else // 取更短的组成答案
                    f[i + 1][j + 1] = min(f[i][j + 1], f[i + 1][j]) + 1;

        string ans;
        int i = n - 1, j = m - 1;
        while (i >= 0 && j >= 0) {
            if (s[i] == t[j]) { // 公共超序列一定包含 s[i]
                ans += s[i];
                --i;
                --j; // 相当于继续递归 make_ans(i - 1, j - 1)
            } else if (f[i + 1][j + 1] == f[i][j + 1] + 1)
                ans += s[i--]; // 相当于继续递归 make_ans(i - 1, j)
            else
                ans += t[j--]; // 相当于继续递归 make_ans(i, j - 1)
        }
        reverse(ans.begin(), ans.end());
        // 补上前面的递归边界
        return s.substr(0, i + 1) + t.substr(0, j + 1) + ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abac"\n"cab"\n
// @lcpr case=end

// @lcpr case=start
// "aaaaaaaa"\n"aaaaaaaa"\n
// @lcpr case=end

 */

