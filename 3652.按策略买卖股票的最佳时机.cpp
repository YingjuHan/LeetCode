/*
 * @lc app=leetcode.cn id=3652 lang=cpp
 * @lcpr version=30203
 *
 * [3652] 按策略买卖股票的最佳时机
 */

// @lc code=start
#include <vector>

using namespace std;
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long total = 0; // 原始的总利润
        long long sum = 0;   // 修改后对总利润的增量（>0增，<0减）
        // 计算第一个窗口
        for (int i = 0; i < k / 2; i++) {
            int p = prices[i], s = strategy[i];
            total += p * s;
            sum -= p * s;
        }
        for (int i = k / 2; i < k; i++) {
            int p = prices[i], s = strategy[i];
            total += p * s;
            sum += p * (1 - s);
        }
        long long max_sum = max(sum, 0LL);

        for (int i = k; i < prices.size(); i++) {
            int p = prices[i], s = strategy[i];
            total += p * s;
            sum += p * (1 - s) - prices[i - k / 2] + prices[i - k] * strategy[i - k];
            max_sum = max(max_sum, sum);
        }
        return total + max_sum;
    }
}; 
// @lc code=end



/*
// @lcpr case=start
// [4,2,8]\n[-1,0,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [5,4,3]\n[1,1,0]\n2\n
// @lcpr case=end

 */

