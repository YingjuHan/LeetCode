/*
 * @lc app=leetcode.cn id=3144 lang=cpp
 * @lcpr version=30204
 *
 * [3144] 分割字符频率相等的最少子字符串
 *
 * https://leetcode.cn/problems/minimum-substring-partition-of-equal-character-frequency/description/
 *
 * algorithms
 * Medium (65.39%)
 * Likes:    47
 * Dislikes: 0
 * Total Accepted:    16.7K
 * Total Submissions: 25.6K
 * Testcase Example:  '"fabccddg"'
 *
 * 给你一个字符串 s ，你需要将它分割成一个或者更多的 平衡 子字符串。比方说，s == "ababcc" 那么 ("abab", "c", "c")
 * ，("ab", "abc", "c") 和 ("ababcc") 都是合法分割，但是 ("a", "bab", "cc") ，("aba", "bc",
 * "c") 和 ("ab", "abcc") 不是，不平衡的子字符串用粗体表示。
 * 
 * 请你返回 s 最少 能分割成多少个平衡子字符串。
 * 
 * 注意：一个 平衡 字符串指的是字符串中所有字符出现的次数都相同。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "fabccddg"
 * 
 * 输出：3
 * 
 * 解释：
 * 
 * 我们可以将 s 分割成 3 个子字符串：("fab, "ccdd", "g") 或者 ("fabc", "cd", "dg") 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "abababaccddb"
 * 
 * 输出：2
 * 
 * 解释：
 * 
 * 我们可以将 s 分割成 2 个子字符串：("abab", "abaccddb") 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 只包含小写英文字母。
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
    int minimumSubstringsInPartition1(string s) {
        int n = s.size();
        vector<int> memo(n, -1);
        function<int(int)> dfs = [&](int i) -> int {
            if (i < 0) {
                return 0;
            }
            int &res = memo[i];
            if (res != -1) {
                return res;
            }
            res = INT_MAX;
            int cnt[26]{}, k = 0, max_cnt = 0;
            for (int j = i; j >= 0; j--) {
                int c = s[j] - 'a';
                if (cnt[c] == 0) {
                    k++;
                }
                cnt[c]++;
                max_cnt = max(max_cnt, cnt[c]);
                if (i - j + 1 == k * max_cnt) {
                    res = min(res, dfs(j - 1) + 1);
                }
            }
            return res;
        };
        return dfs(n - 1);
    }

    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> f(n + 1, INT_MAX);
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            int cnt[26]{}, k = 0, max_cnt = 0;
            for (int j = i; j >= 0; j--) {
                int c = s[j] - 'a';
                if (cnt[c]++ == 0) {
                    k++;
                }
                max_cnt = max(max_cnt, cnt[c]);
                if (i - j + 1 == k * max_cnt) {
                    f[i + 1] = min(f[i + 1], f[j] + 1);
                }
            }
        }
        return f[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "fabccddg"\n
// @lcpr case=end

// @lcpr case=start
// "abababaccddb"\n
// @lcpr case=end

 */

