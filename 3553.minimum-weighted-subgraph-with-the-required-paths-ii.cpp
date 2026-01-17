/*
 * @lc app=leetcode.cn id=3553 lang=cpp
 * @lcpr version=30204
 *
 * [3553] 包含给定路径的最小带权子树 II
 *
 * https://leetcode.cn/problems/minimum-weighted-subgraph-with-the-required-paths-ii/description/
 *
 * algorithms
 * Hard (56.28%)
 * Likes:    9
 * Dislikes: 0
 * Total Accepted:    1.4K
 * Total Submissions: 2.5K
 * Testcase Example:  '[[0,1,2],[1,2,3],[1,3,5],[1,4,4],[2,5,6]]\n[[2,3,4],[0,2,5]]'
 *
 * 给你一个 无向带权 树，共有 n 个节点，编号从 0 到 n - 1。这棵树由一个二维整数数组 edges 表示，长度为 n - 1，其中
 * edges[i] = [ui, vi, wi] 表示存在一条连接节点 ui 和 vi 的边，权重为 wi。
 * 
 * 此外，给你一个二维整数数组 queries，其中 queries[j] = [src1j, src2j, destj]。
 * 
 * 返回一个长度等于 queries.length 的数组 answer，其中 answer[j] 表示一个子树的 最小总权重 ，使用该子树的边可以从
 * src1j 和 src2j 到达 destj 。
 * 
 * 这里的 子树 是指原树中任意节点和边组成的连通子集形成的一棵有效树。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： edges = [[0,1,2],[1,2,3],[1,3,5],[1,4,4],[2,5,6]], queries =
 * [[2,3,4],[0,2,5]]
 * 
 * 输出： [12,11]
 * 
 * 解释：
 * 
 * 蓝色边表示可以得到最优答案的子树之一。
 * 
 * 
 * 
 * 
 * 
 * answer[0]：在选出的子树中，从 src1 = 2 和 src2 = 3 到 dest = 4 的路径总权重为 3 + 5 + 4 =
 * 12。
 * 
 * 
 * answer[1]：在选出的子树中，从 src1 = 0 和 src2 = 2 到 dest = 5 的路径总权重为 2 + 3 + 6 =
 * 11。
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： edges = [[1,0,8],[0,2,7]], queries = [[0,1,2]]
 * 
 * 输出： [15]
 * 
 * 解释：
 * 
 * 
 * 
 * 
 * answer[0]：选出的子树中，从 src1 = 0 和 src2 = 1 到 dest = 2 的路径总权重为 8 + 7 = 15。
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= n <= 10^5
 * edges.length == n - 1
 * edges[i].length == 3
 * 0 <= ui, vi < n
 * 1 <= wi <= 10^4
 * 1 <= queries.length <= 10^5
 * queries[j].length == 3
 * 0 <= src1j, src2j, destj < n
 * src1j、src2j 和 destj 互不不同。
 * 输入数据保证 edges 表示的是一棵有效的树。
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
class LcaBinaryLifting {
    vector<int> depth, dis;
    vector<vector<int>> pa;
public:
    LcaBinaryLifting(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        int m = bit_width((unsigned)n);
        vector<vector<pair<int, int>>> g(n);
        for (auto& e : edges) {
            int x = e[0], y = e[1], w = e[2];
            g[x].emplace_back(y, w);
            g[y].emplace_back(x, w);
        }

        depth.resize(n);
        dis.resize(n);
        pa.resize(n, vector<int>(m, -1));
        auto dfs = [&](this auto&& dfs, int x, int fa) -> void {
            pa[x][0] = fa;
            for (auto& [y, w] : g[x]) {
                if (y == fa) continue;
                depth[y] = depth[x] + 1;
                dis[y] = dis[x] + w;
                dfs(y, x);
            }
        };
        dfs(0, -1);

        for (int i = 0; i < m - 1; i++) {
            for (int x = 0; x < n; x++) {
                int p = pa[x][i];
                if (p != -1) {
                    pa[x][i + 1] = pa[p][i];
                }
            }
        }
    }

    int GetKthAncestor(int node, int k) {
        int LOG = pa[0].size();
        for (int i = 0; i < LOG && node != -1; ++i) {
            if (k & (1 << i)) {
                node = pa[node][i];
            }
        }
        return node;
    }

    int GetLca(int x, int y) {
        if (depth[x] > depth[y]) {
            swap(x, y);
        }

        y = GetKthAncestor(y, depth[y] - depth[x]);
        if (x == y) return x;

        for (int i = pa[x].size() - 1; i >= 0; i--) {
            int px = pa[x][i], py = pa[y][i];
            if (px != py) {
                x = px;
                y = py;
            }
        }
        return pa[x][0];
    }

    int GetDis(int x, int y) {
        return dis[x] + dis[y] - dis[GetLca(x, y)] * 2;
    }
};
class Solution {
public:
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        LcaBinaryLifting g(edges);
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            vector<int>& q = queries[i];
            int a = q[0], b = q[1], c = q[2];
            res[i] = (g.GetDis(a, b) + g.GetDis(b, c) + g.GetDis(a, c)) / 2;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,2],[1,2,3],[1,3,5],[1,4,4],[2,5,6]]\n[[2,3,4],[0,2,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,8],[0,2,7]]\n[[0,1,2]]\n
// @lcpr case=end

 */

