/*
 * @lc app=leetcode.cn id=2846 lang=cpp
 * @lcpr version=30204
 *
 * [2846] 边权重均等查询
 *
 * https://leetcode.cn/problems/minimum-edge-weight-equilibrium-queries-in-a-tree/description/
 *
 * algorithms
 * Hard (61.03%)
 * Likes:    65
 * Dislikes: 0
 * Total Accepted:    11.4K
 * Total Submissions: 18.6K
 * Testcase Example:  '7\n' +
  '[[0,1,1],[1,2,1],[2,3,1],[3,4,2],[4,5,2],[5,6,2]]\n' +
  '[[0,3],[3,6],[2,6],[0,6]]'
 *
 * 现有一棵由 n 个节点组成的无向树，节点按从 0 到 n - 1 编号。给你一个整数 n 和一个长度为 n - 1 的二维整数数组 edges ，其中
 * edges[i] = [ui, vi, wi] 表示树中存在一条位于节点 ui 和节点 vi 之间、权重为 wi 的边。
 * 
 * 另给你一个长度为 m 的二维整数数组 queries ，其中 queries[i] = [ai, bi] 。对于每条查询，请你找出使从 ai 到 bi
 * 路径上每条边的权重相等所需的 最小操作次数 。在一次操作中，你可以选择树上的任意一条边，并将其权重更改为任意值。
 * 
 * 注意：
 * 
 * 
 * 查询之间 相互独立 的，这意味着每条新的查询时，树都会回到 初始状态 。
 * 从 ai 到 bi的路径是一个由 不同 节点组成的序列，从节点 ai 开始，到节点 bi 结束，且序列中相邻的两个节点在树中共享一条边。
 * 
 * 
 * 返回一个长度为 m 的数组 answer ，其中 answer[i] 是第 i 条查询的答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 7, edges = [[0,1,1],[1,2,1],[2,3,1],[3,4,2],[4,5,2],[5,6,2]], queries
 * = [[0,3],[3,6],[2,6],[0,6]]
 * 输出：[0,0,1,3]
 * 解释：第 1 条查询，从节点 0 到节点 3 的路径中的所有边的权重都是 1 。因此，答案为 0 。
 * 第 2 条查询，从节点 3 到节点 6 的路径中的所有边的权重都是 2 。因此，答案为 0 。
 * 第 3 条查询，将边 [2,3] 的权重变更为 2 。在这次操作之后，从节点 2 到节点 6 的路径中的所有边的权重都是 2 。因此，答案为 1 。
 * 第 4 条查询，将边 [0,1]、[1,2]、[2,3] 的权重变更为 2 。在这次操作之后，从节点 0 到节点 6 的路径中的所有边的权重都是 2
 * 。因此，答案为 3 。
 * 对于每条查询 queries[i] ，可以证明 answer[i] 是使从 ai 到 bi 的路径中的所有边的权重相等的最小操作次数。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 8, edges = [[1,2,6],[1,3,4],[2,4,6],[2,5,3],[3,6,6],[3,0,8],[7,0,2]],
 * queries = [[4,6],[0,4],[6,5],[7,4]]
 * 输出：[1,2,2,3]
 * 解释：第 1 条查询，将边 [1,3] 的权重变更为 6 。在这次操作之后，从节点 4 到节点 6 的路径中的所有边的权重都是 6 。因此，答案为 1
 * 。
 * 第 2 条查询，将边 [0,3]、[3,1] 的权重变更为 6 。在这次操作之后，从节点 0 到节点 4 的路径中的所有边的权重都是 6 。因此，答案为
 * 2 。
 * 第 3 条查询，将边 [1,3]、[5,2] 的权重变更为 6 。在这次操作之后，从节点 6 到节点 5 的路径中的所有边的权重都是 6 。因此，答案为
 * 2 。
 * 第 4 条查询，将边 [0,7]、[0,3]、[1,3] 的权重变更为 6 。在这次操作之后，从节点 7 到节点 4 的路径中的所有边的权重都是 6
 * 。因此，答案为 3 。
 * 对于每条查询 queries[i] ，可以证明 answer[i] 是使从 ai 到 bi 的路径中的所有边的权重相等的最小操作次数。 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 10^4
 * edges.length == n - 1
 * edges[i].length == 3
 * 0 <= ui, vi < n
 * 1 <= wi <= 26
 * 生成的输入满足 edges 表示一棵有效的树
 * 1 <= queries.length == m <= 2 * 10^4
 * queries[i].length == 2
 * 0 <= ai, bi < n
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
#include <bit>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> g(n);
        for (auto &e: edges) {
            int x = e[0], y = e[1], w = e[2] - 1;
            g[x].emplace_back(y, w);
            g[y].emplace_back(x, w);
        }
        int m = 32 - __builtin_clz(n);
        vector<vector<int>> pa(n, vector<int>(m, -1));
        vector<vector<array<int, 26>>> cnt(n, vector<array<int, 26>>(m));
        vector<int> depth(n);

        function<void(int, int)> dfs = [&](int x, int fa) {
            pa[x][0] = fa;
            for (auto [y, w] : g[x]) {
                if (y == fa) continue;
                cnt[y][0][w] = 1;
                depth[y] = depth[x] + 1;
                dfs(y, x);
            }
        };
        dfs(0, -1);

        for (int i = 0; i < m - 1; i++) {
            for (int x = 0; x < n; x++) {
                int p = pa[x][i];
                if (p != -1) {
                    pa[x][i + 1] = pa[p][i];
                    for (int j = 0; j < 26; j++) {
                        cnt[x][i + 1][j] = cnt[x][i][j] + cnt[p][i][j];
                    } 
                }
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            int x = q[0], y = q[1];
            int path_len = depth[x] + depth[y];
            int cw[26]{};
            if (depth[x] > depth[y]) {
                swap(x, y);
            }

            // 令y和x在同一深度
            for (int k = depth[y] - depth[x]; k; k &= k - 1) {
                int m = __builtin_ctz(k); // 最低位 1 的位置
                int p = pa[y][m];

                // y 向上跳 2^i 步, 这段路径上的所有边，都属于查询路径的一部分, 所以必须把这些边权统计进 cw
                for (int j = 0; j < 26; j++) {
                    cw[j] += cnt[y][m][j]; 
                }
                y = p;
            }

            if (y != x) {
                for (int i = m - 1; i >= 0; i--) {
                    int px = pa[x][i], py = pa[y][i];
                    if (px != py) {
                        for (int j = 0; j < 26; j++) {
                            // cnt[x][i][j]：从 x 往上走 2^i 步这段路径里，权值 j 出现次数
                            // cnt[y][i][j]：从 y 往上走 2^i 步这段路径里，权值 j 出现次数
                            cw[j] += cnt[x][i][j] + cnt[y][i][j];
                        }
                        x = px;
                        y = py;
                    }
                }
                // 循环结束后：x、y 已经在 LCA 的“正下方一层”, 还差最后两条边（x->parent 和 y->parent）没统计, 补上
                for (int j = 0; j < 26; j++) {
                    cw[j] += cnt[x][0][j] + cnt[y][0][j];
                }
                x = pa[x][0];
            }

            int lca = x;
            path_len -= depth[lca] * 2;
            ans.push_back(path_len - *max_element(cw, cw + 26));
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n[[0,1,1],[1,2,1],[2,3,1],[3,4,2],[4,5,2],[5,6,2]]\n[[0,3],[3,6],[2,6],[0,6]]\n
// @lcpr case=end

// @lcpr case=start
// 8\n[[1,2,6],[1,3,4],[2,4,6],[2,5,3],[3,6,6],[3,0,8],[7,0,2]]\n[[4,6],[0,4],[6,5],[7,4]]\n
// @lcpr case=end

 */

