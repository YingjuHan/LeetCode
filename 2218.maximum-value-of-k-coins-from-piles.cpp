/*
 * @lc app=leetcode.cn id=2218 lang=cpp
 * @lcpr version=30204
 *
 * [2218] 从栈中取出 K 个硬币的最大面值和
 *
 * https://leetcode.cn/problems/maximum-value-of-k-coins-from-piles/description/
 *
 * algorithms
 * Hard (66.84%)
 * Likes:    152
 * Dislikes: 0
 * Total Accepted:    24.3K
 * Total Submissions: 36.4K
 * Testcase Example:  '[[1,100,3],[7,8,9]]\n2'
 *
 * 一张桌子上总共有 n 个硬币 栈 。每个栈有 正整数 个带面值的硬币。
 * 
 * 每一次操作中，你可以从任意一个栈的 顶部 取出 1 个硬币，从栈中移除它，并放入你的钱包里。
 * 
 * 给你一个列表 piles ，其中 piles[i] 是一个整数数组，分别表示第 i 个栈里 从顶到底 的硬币面值。同时给你一个正整数 k ，请你返回在
 * 恰好 进行 k 次操作的前提下，你钱包里硬币面值之和 最大为多少 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：piles = [[1,100,3],[7,8,9]], k = 2
 * 输出：101
 * 解释：
 * 上图展示了几种选择 k 个硬币的不同方法。
 * 我们可以得到的最大面值为 101 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：piles = [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]], k = 7
 * 输出：706
 * 解释：
 * 如果我们所有硬币都从最后一个栈中取，可以得到最大面值和。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == piles.length
 * 1 <= n <= 1000
 * 1 <= piles[i][j] <= 10^5
 * 1 <= k <= sum(piles[i].length) <= 2000
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
    int maxValueOfCoins1(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> memo(n, vector<int>(k + 1, -1));
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i < 0) {
                return 0;
            }
            int& res = memo[i][j];
            if (res != -1) {
                return res;
            }
            res = dfs(i - 1, j); // 不选
            
            // 选
            int v = 0;
            for (int w = 1; w <= min(j, (int)piles[i].size()); w++) {
                v += piles[i][w - 1];
                // 物品体积为w
                res = max(res, dfs(i - 1, j - w) + v);
            }
            return res;
        };
        return dfs(n - 1, k);
    }

    int maxValueOfCoins2(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> f(n + 1, vector<int>(k + 1, 0));
        for (int i = 0; i < n; i++) {
            auto& pile = piles[i];
            for (int j = 0; j <= k; j++) {
                // 不选
                f[i + 1][j] = f[i][j];
                
                // 选
                int v = 0;
                for (int w = 1; w <= min(j, (int)pile.size()); w++) {
                    v += pile[w - 1];
                    f[i + 1][j] = max(f[i + 1][j], f[i][j - w] + v);
                }
            }
        }
        return f[n][k];
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<int> f(k + 1, 0);
        int sum_n = 0;
        for (auto& pile : piles) {
            partial_sum(pile.begin(), pile.end(), pile.begin()); // 提前计算 pile 的前缀和
            int n = pile.size();
            sum_n = min(sum_n + n, k);
            for (int j = sum_n; j >= 0; j--) {
                for (int w = 1; w <= min(n, j); w++) {
                    f[j] = max(f[j], f[j - w] + pile[w - 1]);
                }
            }
        }
        return f[k];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,100,3],[7,8,9]]\n2\n
// @lcpr case=end

// @lcpr case=start
// [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]]\n7\n
// @lcpr case=end

 */

