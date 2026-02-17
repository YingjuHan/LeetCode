/*
 * @lc app=leetcode.cn id=132 lang=cpp
 * @lcpr version=30204
 *
 * [132] 分割回文串 II
 *
 * https://leetcode.cn/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (51.11%)
 * Likes:    850
 * Dislikes: 0
 * Total Accepted:    118.8K
 * Total Submissions: 232.4K
 * Testcase Example:  '"aab"'
 *
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文串。
 * 
 * 返回符合要求的 最少分割次数 。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "aab"
 * 输出：1
 * 解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "a"
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "ab"
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 2000
 * s 仅由小写英文字母组成
 * 
 * 
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
    int minCut1(string s) {
        int n = s.length();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        auto is_palindrome = [&](this auto&& is_palindrome, int l, int r) -> bool {
            if (l >= r) {
                return true;
            }
            int &res = memo[l][r];
            if (res != -1) {
                return res;
            }
            res = s[l] == s[r] && is_palindrome(l + 1, r - 1);
            return res;
        };

        vector<int> dfs_memo(n, INT_MAX);
        auto dfs = [&](this auto&& dfs, int r) -> int {
            if (is_palindrome(0, r)) {
                return 0;
            }
            int &res = dfs_memo[r];
            if (res != INT_MAX) {
                return res;
            }
            for (int l = 1; l <= r; l++) {
                if (is_palindrome(l, r)) {
                    res = min(res, dfs(l - 1) + 1);
                }
            }
            return res;
        };
        return dfs(n - 1);
    }

    int minCut(string s) {
        int n = s.size();
        // is_palindrome[l][r] 表示 s[l] 到 s[r] 是否为回文串
        vector<vector<int>> is_palindrome(n, vector<int>(n, true));
        for (int l = n - 2; l >= 0; l--) {
            for (int r = l + 1; r < n; r++) {
                is_palindrome[l][r] = s[l] == s[r] && is_palindrome[l + 1][r - 1];
            }
        }

        vector<int> f(n);
        for (int r = 0; r < n; r++) {
            if (is_palindrome[0][r]) {
                continue;
            }
            int res = INT_MAX;
            for (int l = 1; l <= r; l++) {
                if (is_palindrome[l][r]) {
                    res = min(res, f[l - 1] + 1);
                }
            }
            f[r] = res;
        }
        return f[n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n
// @lcpr case=end

 */

