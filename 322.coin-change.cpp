/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=30204
 *
 * [322] 零钱兑换
 *
 * https://leetcode.cn/problems/coin-change/description/
 *
 * algorithms
 * Medium (52.25%)
 * Likes:    3192
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 2.5M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
 * 
 * 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
 * 
 * 你可以认为每种硬币的数量是无限的。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：coins = [1, 2, 5], amount = 11
 * 输出：3 
 * 解释：11 = 5 + 5 + 1
 * 
 * 示例 2：
 * 
 * 输入：coins = [2], amount = 3
 * 输出：-1
 * 
 * 示例 3：
 * 
 * 输入：coins = [1], amount = 0
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
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
    int coinChange1(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> memo(n, vector<int>(amount + 1, -1)); // -1 表示没有计算过
        auto dfs = [&](this auto&& dfs, int i, int c) {
            if (i < 0) {
                return c == 0 ? 0 : INT_MAX / 2;
            }
            int& res = memo[i][c];
            if (res != -1) {
                return res;
            }
            if (c < coins[i]) {
                res = dfs(i - 1, c);
                return res;
            }
            res = min(dfs(i - 1, c), dfs(i, c - coins[i]) + 1);
            return res;
        };
        int ans = dfs(n - 1, amount);
        return ans < INT_MAX / 2 ? ans : -1;
    }

    int coinChange2(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> f(n + 1, vector<int>(amount + 1, INT_MAX / 2));
        f[0][0] = 0;
        for (int i = 0; i < n; i++) {
            int x = coins[i];
            for (int c = 0; c <= amount; c++) {
                if (c < x) {
                    f[i + 1][c] = f[i][c];
                } else {
                    f[i + 1][c] = min(f[i][c], f[i + 1][c - x] + 1);
                }
            }
        }
        int res = f[n][amount];
        return res < INT_MAX / 2 ? res : -1;
    }

    int coinChange3(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> f(2, vector<int>(amount + 1, INT_MAX / 2));
        f[0][0] = 0;
        for (int i = 0; i < n; i++) {
            int x = coins[i];
            for (int c = 0; c <= amount; c++) {
                if (c < x) {
                    f[(i + 1) % 2][c] = f[i % 2][c];
                } else {
                    f[(i + 1) % 2][c] = min(f[i % 2][c], f[(i + 1) % 2][c - x] + 1);
                }
            }
        }
        int res = f[n % 2][amount];
        return res < INT_MAX / 2 ? res : -1;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> f(amount + 1, INT_MAX / 2);
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            int x = coins[i];
            for (int c = x; c <= amount; c++) {
                f[c] = min(f[c], f[c - x] + 1);
            }
        }
        int res = f[amount];
        return res < INT_MAX / 2 ? res : -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 2, 5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

