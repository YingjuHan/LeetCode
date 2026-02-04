/*
 * @lc app=leetcode.cn id=2787 lang=cpp
 * @lcpr version=30204
 *
 * [2787] 将一个数字表示成幂的和的方案数
 *
 * https://leetcode.cn/problems/ways-to-express-an-integer-as-sum-of-powers/description/
 *
 * algorithms
 * Medium (54.43%)
 * Likes:    72
 * Dislikes: 0
 * Total Accepted:    29.9K
 * Total Submissions: 54.9K
 * Testcase Example:  '10\n2'
 *
 * 给你两个 正 整数 n 和 x 。
 * 
 * 请你返回将 n 表示成一些 互不相同 正整数的 x 次幂之和的方案数。换句话说，你需要返回互不相同整数 [n1, n2, ..., nk]
 * 的集合数目，满足 n = n1^x + n2^x + ... + nk^x 。
 * 
 * 由于答案可能非常大，请你将它对 10^9 + 7 取余后返回。
 * 
 * 比方说，n = 160 且 x = 3 ，一个表示 n 的方法是 n = 2^3 + 3^3 + 5^3^ 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 10, x = 2
 * 输出：1
 * 解释：我们可以将 n 表示为：n = 3^2 + 1^2 = 10 。
 * 这是唯一将 10 表达成不同整数 2 次方之和的方案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 4, x = 1
 * 输出：2
 * 解释：我们可以将 n 按以下方案表示：
 * - n = 4^1 = 4 。
 * - n = 3^1 + 1^1 = 4 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 300
 * 1 <= x <= 5
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
    // 把 n 看成背包容量，1x,2x,3x,… 看成物品，恰好装满型 0-1 背包的方案数
    int numberOfWays(int n, int x) {
        vector<long long> f(n + 1);
        f[0] = 1;
        for (int i = 1; pow(i, x) <= n; i++) {
            int v = pow(i, x);
            for (int s = n; s >= v; s--) {
                f[s] = f[s] + f[s - v];
            }
        }
        return f[n] % (long long)(1e9 + 7);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n2\n
// @lcpr case=end

// @lcpr case=start
// 4\n1\n
// @lcpr case=end

 */

