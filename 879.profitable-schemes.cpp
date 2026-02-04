/*
 * @lc app=leetcode.cn id=879 lang=cpp
 * @lcpr version=30204
 *
 * [879] 盈利计划
 *
 * https://leetcode.cn/problems/profitable-schemes/description/
 *
 * algorithms
 * Hard (54.52%)
 * Likes:    351
 * Dislikes: 0
 * Total Accepted:    40.4K
 * Total Submissions: 74.2K
 * Testcase Example:  '5\n3\n[2,2]\n[2,3]'
 *
 * 集团里有 n 名员工，他们可以完成各种各样的工作创造利润。
 * 
 * 第 i 种工作会产生 profit[i] 的利润，它要求 group[i] 名成员共同参与。如果成员参与了其中一项工作，就不能参与另一项工作。
 * 
 * 工作的任何至少产生 minProfit 利润的子集称为 盈利计划 。并且工作的成员总数最多为 n 。
 * 
 * 有多少种计划可以选择？因为答案很大，所以 返回结果模 10^9 + 7 的值。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 5, minProfit = 3, group = [2,2], profit = [2,3]
 * 输出：2
 * 解释：至少产生 3 的利润，该集团可以完成工作 0 和工作 1 ，或仅完成工作 1 。
 * 总的来说，有两种计划。
 * 
 * 示例 2：
 * 
 * 输入：n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
 * 输出：7
 * 解释：至少产生 5 的利润，只要完成其中一种工作就行，所以该集团可以完成任何工作。
 * 有 7 种可能的计划：(0)，(1)，(2)，(0,1)，(0,2)，(1,2)，以及 (0,1,2) 。
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 100
 * 0 <= minProfit <= 100
 * 1 <= group.length <= 100
 * 1 <= group[i] <= 100
 * profit.length == group.length
 * 0 <= profit[i] <= 100
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
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int MOD = 1e9 + 7;
        int N = group.size();
        vector<vector<int>> f(n + 1, vector<int>(minProfit + 1, 0));
        f[0][0] = 1;
        for (int i = 0; i < N; i++) {
            int g = group[i], p = profit[i];
            for (int j = n; j >= g; j--) {
                for (int k = minProfit; k >= 0; k--) {
                    f[j][k] += f[j - g][max(0, k - p)];
                    if (f[j][k] > MOD) {
                        f[j][k] -= MOD;
                    }
                }
            }
        }

        int sum = 0;
        for (int i = 0; i <= n; i++) {
            sum += f[i][minProfit];
            if (sum > MOD) {
                sum -= MOD;
            }
        }
        return sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n3\n[2,2]\n[2,3]\n
// @lcpr case=end

// @lcpr case=start
// 10\n5\n[2,3,5]\n[6,7,8]\n
// @lcpr case=end

 */

