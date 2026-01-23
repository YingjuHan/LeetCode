/*
 * @lc app=leetcode.cn id=3669 lang=cpp
 * @lcpr version=30204
 *
 * [3669] K 因数分解
 *
 * https://leetcode.cn/problems/balanced-k-factor-decomposition/description/
 *
 * algorithms
 * Medium (39.08%)
 * Likes:    8
 * Dislikes: 0
 * Total Accepted:    2.6K
 * Total Submissions: 6.5K
 * Testcase Example:  '100\n2'
 *
 * 给你两个整数 n 和 k，将数字 n 恰好分割成 k 个正整数，使得这些整数的 乘积 等于 n。
 * 
 * 返回一个分割方案，使得这些数字中 最大值 和 最小值 之间的 差值 最小化。结果可以以 任意顺序 返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 100, k = 2
 * 
 * 输出：[10,10]
 * 
 * 解释：
 * 
 * 分割方案 [10, 10] 的结果是 10 * 10 = 100，且最大值与最小值的差值为 0，这是最小可能值。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 44, k = 3
 * 
 * 输出：[2,2,11]
 * 
 * 解释：
 * 
 * 
 * 分割方案 [1, 1, 44] 的差值为 43
 * 分割方案 [1, 2, 22] 的差值为 21
 * 分割方案 [1, 4, 11] 的差值为 10
 * 分割方案 [2, 2, 11] 的差值为 9
 * 
 * 
 * 因此，[2, 2, 11] 是最优分割方案，其差值最小，为 9。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 4 <= n <= 10^5
 * 2 <= k <= 5
 * k 严格小于 n 的正因数的总数。
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
const int MX = 100001;
vector<int> divisors[MX];
int init = [] {
    for (int i = 1; i < MX; i++) {
        for (int j = i; j < MX; j += i) { // 枚举 i 的倍数 j
            divisors[j].push_back(i); // i 是 j的因子
        }
    }
    return 0;
}();

class Solution {
public:
    vector<int> minDifference(int n, int k) {
        int min_diff = INT_MAX;
        vector<int> path(k), res;

        auto dfs = [&](this auto&& dfs, int i, int n, int mn, int mx) -> void {
            if (i == k - 1) {
                int d = max(mx, n) - min(mn, n);
                if (d < min_diff) {
                    min_diff = d;
                    path[i] = n;
                    res = path;
                }
                return;
            }

            for (int d : divisors[n]) {
                path[i] = d;
                dfs(i + 1, n / d, min(mn, d), max(mx, d));
            }
        };

        dfs(0, n, INT_MAX, 0);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 100\n2\n
// @lcpr case=end

// @lcpr case=start
// 44\n3\n
// @lcpr case=end

 */

