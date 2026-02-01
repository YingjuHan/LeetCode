/*
 * @lc app=leetcode.cn id=3603 lang=cpp
 * @lcpr version=30204
 *
 * [3603] 交替方向的最小路径代价 II
 *
 * https://leetcode.cn/problems/minimum-cost-path-with-alternating-directions-ii/description/
 *
 * algorithms
 * Medium (63.43%)
 * Likes:    9
 * Dislikes: 0
 * Total Accepted:    3.4K
 * Total Submissions: 5.3K
 * Testcase Example:  '1\n2\n[[1,2]]'
 *
 * 给你两个整数 m 和 n，分别表示网格的行数和列数。
 * 
 * 进入单元格 (i, j) 的成本定义为 (i + 1) * (j + 1)。
 * 
 * 另外给你一个二维整数数组 waitCost，其中 waitCost[i][j] 定义了在该单元格 等待 的成本。
 * 
 * 路径始终从第 1 步进入单元格 (0, 0) 并支付入场花费开始。
 * 
 * 每一步，你都遵循交替模式：
 * 
 * 
 * 在 奇数秒 ，你必须向 右 或向 下 移动到 相邻 的单元格，并支付其进入成本。
 * 在 偶数秒 ，你必须原地 等待恰好 1 秒并在 1 秒期间支付 waitCost[i][j]。
 * 
 * 
 * 返回到达 (m - 1, n - 1) 所需的 最小 总成本。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：m = 1, n = 2, waitCost = [[1,2]]
 * 
 * 输出：3
 * 
 * 解释：
 * 
 * 最佳路径为：
 * 
 * 
 * 从第 1 秒开始在单元格 (0, 0)，进入成本为 (0 + 1) * (0 + 1) = 1。
 * 第 1 秒：向右移动到单元格 (0, 1)，进入成本为 (0 + 1) * (1 + 1) = 2。
 * 
 * 
 * 因此，总成本为 1 + 2 = 3。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：m = 2, n = 2, waitCost = [[3,5],[2,4]]
 * 
 * 输出：9
 * 
 * 解释：
 * 
 * 最佳路径为：
 * 
 * 
 * 从第 1 秒开始在单元格 (0, 0)，进入成本为 (0 + 1) * (0 + 1) = 1。
 * 第 1 秒：向下移动到单元格 (1, 0)，进入成本为 (1 + 1) * (0 + 1) = 2。
 * 第 2 秒：在单元格 (1, 0) 等待，支付 waitCost[1][0] = 2。
 * 第 3 秒：向右移动到单元格 (1, 1)，进入成本为 (1 + 1) * (1 + 1) = 4。
 * 
 * 
 * 因此，总成本为 1 + 2 + 2 + 4 = 9。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：m = 2, n = 3, waitCost = [[6,1,4],[3,2,5]]
 * 
 * 输出：16
 * 
 * 解释：
 * 
 * 最佳路径为：
 * 
 * 
 * 从第 1 秒开始在单元格 (0, 0)，进入成本为 (0 + 1) * (0 + 1) = 1。
 * 第 1 秒：向右移动到单元格 (0, 1)，进入成本为 (0 + 1) * (1 + 1) = 2。
 * 第 2 秒：在单元格 (0, 1) 等待，支付 waitCost[0][1] = 1。
 * 第 3 秒：向下移动到单元格 (1, 1)，进入成本为 (1 + 1) * (1 + 1) = 4。
 * 第 4 秒：在单元格 (1, 1) 等待，支付 waitCost[1][1] = 2。
 * 第 5 秒：向右移动到单元格 (1, 2)，进入成本为 (1 + 1) * (2 + 1) = 6。
 * 
 * 
 * 因此，总成本为 1 + 2 + 1 + 4 + 2 + 6 = 16。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= m, n <= 10^5
 * 2 <= m * n <= 10^5
 * waitCost.length == m
 * waitCost[0].length == n
 * 0 <= waitCost[i][j] <= 10^5
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
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        const long long INF = (1LL<<60);
        vector<vector<long long>> f(m + 1, vector<long long>(n + 1, INF));

        // 位置代价是 i*j（1-index）
        // 起点 (1,1) 不计 waitCost[0][0]，只计位置代价 1*1
        f[1][1] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) continue;
                long long cell = 1LL * i * j + waitCost[i - 1][j - 1];
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + cell;
            }
        }

        // 终点不等待：减去 waitCost[m-1][n-1]
        return f[m][n] - waitCost[m - 1][n - 1];
    }
};

// @lc code=end



/*
// @lcpr case=start
// 1\n2\n[[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n2\n[[3,5],[2,4]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n3\n[[6,1,4],[3,2,5]]\n
// @lcpr case=end

 */

