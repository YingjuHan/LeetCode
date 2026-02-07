/*
 * @lc app=leetcode.cn id=1155 lang=cpp
 * @lcpr version=30204
 *
 * [1155] 掷骰子等于目标和的方法数
 *
 * https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/description/
 *
 * algorithms
 * Medium (65.53%)
 * Likes:    312
 * Dislikes: 0
 * Total Accepted:    54.4K
 * Total Submissions: 83K
 * Testcase Example:  '1\n6\n3'
 *
 * 这里有 n 个一样的骰子，每个骰子上都有 k 个面，分别标号为 1 到 k 。
 * 
 * 给定三个整数 n、k 和 target，请返回投掷骰子的所有可能得到的结果（共有 k^n 种方式），使得骰子面朝上的数字总和等于 target。
 * 
 * 由于答案可能很大，你需要对 10^9 + 7 取模。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 1, k = 6, target = 3
 * 输出：1
 * 解释：你掷了一个有 6 个面的骰子。
 * 得到总和为 3 的结果的方式只有一种。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 2, k = 6, target = 7
 * 输出：6
 * 解释：你掷了两个骰子，每个骰子有 6 个面。
 * 有 6 种方式得到总和为 7 的结果: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1。
 * 
 * 
 * 示例 3：
 * 
 * 输入：n = 30, k = 30, target = 500
 * 输出：222616187
 * 解释：返回的结果必须对 10^9 + 7 取模。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n, k <= 30
 * 1 <= target <= 1000
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
    int numRollsToTarget1(int n, int k, int target) {
        if (target < n || target > n * k) {
            return 0; // 无法组成 target
        }
        const int MOD = 1'000'000'007;
        vector<vector<int>> memo(n + 1, vector<int>(target - n + 1, -1));
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i == 0) {
                return j == 0;
            }
            int &res = memo[i][j];
            if (res != -1) {
                return res;
            }
            res = 0;
            for (int x = 0; x < k && x <= j; x++) { // 掷出了 x
                res = (res + dfs(i - 1, j - x)) % MOD;
            }
            return res;
        };
        return dfs(n, target - n);
    }

    int numRollsToTarget2(int n, int k, int target) {
        if (target < n || target > n * k) {
            return 0; // 无法组成 target
        }
        const int MOD = 1'000'000'007;
        vector<vector<int>> f(n + 1, vector<int>(target - n + 1, 0));
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target - n; j++) {
                for (int x = 0; x < k && x <= j; x++) {
                    f[i][j] = (f[i][j] + f[i - 1][j - x]) % MOD;
                }
            }
        }
        return f[n][target - n];
    }

    int numRollsToTarget(int n, int k, int target) {
        if (target < n || target > n * k) {
            return 0; // 无法组成 target
        }
        const int MOD = 1'000'000'007;
        vector<long long> f(target - n + 1, 0);
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            int max_j = min(i * (k - 1), target - n); // i 个骰子至多掷出 i*(k-1)
            for (int j = 1; j <= max_j; j++) {
                f[j] += f[j - 1];
            }
            for (int j = max_j; j >= k; j--) {
                f[j] = (f[j] - f[j - k]) % MOD;
            }
        }
        return f[target - n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n6\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n6\n7\n
// @lcpr case=end

// @lcpr case=start
// 30\n30\n500\n
// @lcpr case=end

 */

