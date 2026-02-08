/*
 * @lc app=leetcode.cn id=1639 lang=cpp
 * @lcpr version=30204
 *
 * [1639] 通过给定词典构造目标字符串的方案数
 *
 * https://leetcode.cn/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/
 *
 * algorithms
 * Hard (51.52%)
 * Likes:    61
 * Dislikes: 0
 * Total Accepted:    5.9K
 * Total Submissions: 11.5K
 * Testcase Example:  '["acca","bbbb","caca"]\n"aba"'
 *
 * 给你一个字符串列表 words 和一个目标字符串 target 。words 中所有字符串都 长度相同  。
 * 
 * 你的目标是使用给定的 words 字符串列表按照下述规则构造 target ：
 * 
 * 
 * 从左到右依次构造 target 的每一个字符。
 * 为了得到 target 第 i 个字符（下标从 0 开始），当 target[i] = words[j][k] 时，你可以使用 words 列表中第 j
 * 个字符串的第 k 个字符。
 * 一旦你使用了 words 中第 j 个字符串的第 k 个字符，你不能再使用 words 字符串列表中任意单词的第 x 个字符（x <=
 * k）。也就是说，所有单词下标小于等于 k 的字符都不能再被使用。
 * 请你重复此过程直到得到目标字符串 target 。
 * 
 * 
 * 请注意， 在构造目标字符串的过程中，你可以按照上述规定使用 words 列表中 同一个字符串 的 多个字符 。
 * 
 * 请你返回使用 words 构造 target 的方案数。由于答案可能会很大，请对 10^9 + 7 取余 后返回。
 * 
 * （译者注：此题目求的是有多少个不同的 k 序列，详情请见示例。）
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：words = ["acca","bbbb","caca"], target = "aba"
 * 输出：6
 * 解释：总共有 6 种方法构造目标串。
 * "aba" -> 下标为 0 ("acca")，下标为 1 ("bbbb")，下标为 3 ("caca")
 * "aba" -> 下标为 0 ("acca")，下标为 2 ("bbbb")，下标为 3 ("caca")
 * "aba" -> 下标为 0 ("acca")，下标为 1 ("bbbb")，下标为 3 ("acca")
 * "aba" -> 下标为 0 ("acca")，下标为 2 ("bbbb")，下标为 3 ("acca")
 * "aba" -> 下标为 1 ("caca")，下标为 2 ("bbbb")，下标为 3 ("acca")
 * "aba" -> 下标为 1 ("caca")，下标为 2 ("bbbb")，下标为 3 ("caca")
 * 
 * 
 * 示例 2：
 * 
 * 输入：words = ["abba","baab"], target = "bab"
 * 输出：4
 * 解释：总共有 4 种不同形成 target 的方法。
 * "bab" -> 下标为 0 ("baab")，下标为 1 ("baab")，下标为 2 ("abba")
 * "bab" -> 下标为 0 ("baab")，下标为 1 ("baab")，下标为 3 ("baab")
 * "bab" -> 下标为 0 ("baab")，下标为 2 ("baab")，下标为 3 ("baab")
 * "bab" -> 下标为 1 ("abba")，下标为 2 ("baab")，下标为 3 ("baab")
 * 
 * 
 * 示例 3：
 * 
 * 输入：words = ["abcd"], target = "abcd"
 * 输出：1
 * 
 * 
 * 示例 4：
 * 
 * 输入：words = ["abab","baba","abba","baab"], target = "abba"
 * 输出：16
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 1000
 * words 中所有单词长度相同。
 * 1 <= target.length <= 1000
 * words[i] 和 target 都仅包含小写英文字母。
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
    int numWays1(vector<string>& words, string target) {
        const int MOD = 1e9 + 7;
        int n = words[0].size(), m = target.size();
        vector<vector<long long>> memo(n, vector<long long>(m, -1));
        int cnt[n][26];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) {
            for (string &word : words) {
                cnt[i][word[i] - 'a']++;
            }
        }
        auto dfs = [&](this auto&& dfs, int i, int j) -> long long {
            if (j < 0) {
                return 1;
            }
            if (i < 0) {
                return 0;
            }
            long long &res = memo[i][j];
            if (res != -1) {
                return res;
            }
            res = (dfs(i - 1, j - 1) * cnt[i][target[j] - 'a'] + dfs(i - 1, j)) % MOD;
            return res;
        };
        return dfs(n - 1, m - 1);
    }

    int numWays(vector<string>& words, string target) {
        const int MOD = (int)1e9 + 7;
        int n = words[0].size(),m = target.size(),f[n + 1][m + 1];
        memset(f,0,sizeof(f));
        for (int i = 0; i <= n; i++) {
            f[i][0] = 1;
        }
        int cnt[n][26];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) {
            for (string &word : words) {
                cnt[i][word[i] - 'a']++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                f[i + 1][j + 1] = (int)(((long)cnt[i][target[j] - 'a'] * f[i][j] + f[i][j + 1]) % MOD);
            }
        }
        return f[n][m];
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["acca","bbbb","caca"]\n"aba"\n
// @lcpr case=end

// @lcpr case=start
// ["abba","baab"]\n"bab"\n
// @lcpr case=end

// @lcpr case=start
// ["abcd"]\n"abcd"\n
// @lcpr case=end

// @lcpr case=start
// ["abab","baba","abba","baab"]\n"abba"\n
// @lcpr case=end

 */

