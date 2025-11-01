// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3620 lang=cpp
 * @lcpr version=30204
 *
 * [3620] 恢复网络路径
 *
 * https://leetcode.cn/problems/network-recovery-pathways/description/
 *
 * algorithms
 * Hard (37.05%)
 * Likes:    6
 * Dislikes: 0
 * Total Accepted:    1.8K
 * Total Submissions: 4.8K
 * Testcase Example:  '[[0,1,5],[1,3,10],[0,2,3],[2,3,4]]\n[true,true,true,true]\n10'
 *
 * 给你一个包含 n 个节点（编号从 0 到 n - 1）的有向无环图。图由长度为 m 的二维数组 edges 表示，其中 edges[i] = [ui,
 * vi, costi] 表示从节点 ui 到节点 vi 的单向通信，恢复成本为 costi。
 *
 * 一些节点可能处于离线状态。给定一个布尔数组 online，其中 online[i] = true 表示节点 i 在线。节点 0 和 n - 1
 * 始终在线。
 *
 * 从 0 到 n - 1 的路径如果满足以下条件，那么它是 有效 的：
 *
 *
 * 路径上的所有中间节点都在线。
 * 路径上所有边的总恢复成本不超过 k。
 *
 *
 * 对于每条有效路径，其 分数 定义为该路径上的最小边成本。
 *
 * 返回所有有效路径中的 最大 路径分数（即最大 最小 边成本）。如果没有有效路径，则返回 -1。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: edges = [[0,1,5],[1,3,10],[0,2,3],[2,3,4]], online =
 * [true,true,true,true], k = 10
 *
 * 输出: 3
 *
 * 解释:
 *
 *
 *
 *
 *
 * 图中有两条从节点 0 到节点 3 的可能路线：
 *
 *
 *
 * 路径 0 → 1 → 3
 *
 *
 *
 * 总成本 = 5 + 10 = 15，超过了 k (15 >
 * 10)，因此此路径无效。
 *
 *
 *
 *
 * 路径 0 → 2 → 3
 *
 *
 *
 * 总成本 = 3 + 4 = 7 <= k，因此此路径有效。
 *
 *
 * 此路径上的最小边成本为 min(3, 4) = 3。
 *
 *
 *
 *
 *
 *
 * 没有其他有效路径。因此，所有有效路径分数中的最大值为 3。
 *
 *
 *
 *
 * 示例 2:
 *
 *
 * 输入: edges = [[0,1,7],[1,4,5],[0,2,6],[2,3,6],[3,4,2],[2,4,6]], online =
 * [true,true,true,false,true], k = 12
 *
 * 输出: 6
 *
 * 解释:
 *
 *
 *
 *
 *
 * 节点 3 离线，因此任何通过 3 的路径都是无效的。
 *
 *
 * 考虑从 0 到 4 的其余路线：
 *
 *
 *
 * 路径 0 → 1 → 4
 *
 *
 *
 * 总成本 = 7 + 5 = 12 <= k，因此此路径有效。
 *
 *
 * 此路径上的最小边成本为 min(7, 5) = 5。
 *
 *
 *
 *
 * 路径 0 → 2 → 3 → 4
 *
 *
 *
 * 节点 3 离线，因此无论成本多少，此路径无效。
 *
 *
 *
 *
 * 路径 0 → 2 → 4
 *
 *
 *
 * 总成本 = 6 + 6 = 12 <= k，因此此路径有效。
 *
 *
 * 此路径上的最小边成本为 min(6, 6) = 6。
 *
 *
 *
 *
 *
 *
 * 在两条有效路径中，它们的分数分别为 5 和 6。因此，答案是 6。
 *
 *
 *
 *
 *
 *
 * 提示:
 *
 *
 * n == online.length
 * 2 <= n <= 5 * 10^4
 * 0 <= m == edges.length <= min(10^5, n * (n - 1) / 2)
 * edges[i] = [ui, vi, costi]
 * 0 <= ui, vi < n
 * ui != vi
 * 0 <= costi <= 10^9
 * 0 <= k <= 5 * 10^13
 * online[i] 是 true 或 false，且 online[0] 和 online[n - 1] 均为 true。
 * 给定的图是一个有向无环图。
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
class Solution
{
public:
    int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online, long long k)
    {
        // 记忆化搜索

        int n = online.size();

        // 邻接表：存储在线节点之间的边（目标节点，权重）
        vector<vector<pair<int, int>>> g(n);

        int max_wt = -1; // 记录起点（0）出发的边的最大权重（用于二分右边界）

        for (auto &edge : edges)
        {
            int x = edge[0], y = edge[1], wt = edge[2];
            if (online[x] && online[y])
            {
                g[x].push_back({y, wt});
                if (x == 0)
                { // 特别记录起点（0）出发的边的最大权重max_wt，作为二分搜索的右边界参考
                    max_wt = max(max_wt, wt);
                }
            }
        }

        vector<long long> memo(n, -1);
        auto check = [&](int lower) -> bool
        {
            fill(memo.begin(), memo.end(), -1);

            auto dfs = [&](this auto &&dfs, int x) -> long long
            {
                if (x == n - 1)
                {
                    return 0;
                }
                auto &res = memo[x];
                if (res != -1)
                {
                    return res;
                }

                res = LLONG_MAX / 2;
                for (auto &[y, wt] : g[x])
                {
                    if (wt >= lower)
                    {
                        res = min(res, dfs(y) + wt);
                    }
                }
                return res;
            };

            return dfs(0) <= k;
        };
        int left = -1, right = max_wt + 1;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            (check(mid) ? left : right) = mid;
        }
        return left;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=findMaxPathScore
// paramTypes= ["number[][]","try_arg_error","number"]
// @lcpr-div-debug-arg-end


/*
// @lcpr case=start
// [[0,1,5],[1,3,10],[0,2,3],[2,3,4]]\n[true,true,true,true]\n10\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,7],[1,4,5],[0,2,6],[2,3,6],[3,4,2],[2,4,6]]\n[true,true,true,false,true]\n12\n
// @lcpr case=end

 */
