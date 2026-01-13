/*
 * @lc app=leetcode.cn id=2973 lang=cpp
 * @lcpr version=30204
 *
 * [2973] 树中每个节点放置的金币数目
 *
 * https://leetcode.cn/problems/find-number-of-coins-to-place-in-tree-nodes/description/
 *
 * algorithms
 * Hard (46.27%)
 * Likes:    8
 * Dislikes: 0
 * Total Accepted:    2.6K
 * Total Submissions: 5.6K
 * Testcase Example:  '[[0,1],[0,2],[0,3],[0,4],[0,5]]\n[1,2,3,4,5,6]'
 *
 * 给你一棵 n 个节点的 无向 树，节点编号为 0 到 n - 1 ，树的根节点在节点 0 处。同时给你一个长度为 n - 1 的二维整数数组 edges
 * ，其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间有一条边。
 * 
 * 给你一个长度为 n 下标从 0 开始的整数数组 cost ，其中 cost[i] 是第 i 个节点的 开销 。
 * 
 * 你需要在树中每个节点都放置金币，在节点 i 处的金币数目计算方法如下：
 * 
 * 
 * 如果节点 i 对应的子树中的节点数目小于 3 ，那么放 1 个金币。
 * 否则，计算节点 i 对应的子树内 3 个不同节点的开销乘积的 最大值 ，并在节点 i 处放置对应数目的金币。如果最大乘积是 负数 ，那么放置 0
 * 个金币。
 * 
 * 
 * 请你返回一个长度为 n 的数组 coin ，coin[i]是节点 i 处的金币数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：edges = [[0,1],[0,2],[0,3],[0,4],[0,5]], cost = [1,2,3,4,5,6]
 * 输出：[120,1,1,1,1,1]
 * 解释：在节点 0 处放置 6 * 5 * 4 = 120 个金币。所有其他节点都是叶子节点，子树中只有 1 个节点，所以其他每个节点都放 1
 * 个金币。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：edges = [[0,1],[0,2],[1,3],[1,4],[1,5],[2,6],[2,7],[2,8]], cost =
 * [1,4,2,3,5,7,8,-4,2]
 * 输出：[280,140,32,1,1,1,1,1,1]
 * 解释：每个节点放置的金币数分别为：
 * - 节点 0 处放置 8 * 7 * 5 = 280 个金币。
 * - 节点 1 处放置 7 * 5 * 4 = 140 个金币。
 * - 节点 2 处放置 8 * 2 * 2 = 32 个金币。
 * - 其他节点都是叶子节点，子树内节点数目为 1 ，所以其他每个节点都放 1 个金币。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：edges = [[0,1],[0,2]], cost = [1,2,-2]
 * 输出：[0,1,1]
 * 解释：节点 1 和 2 都是叶子节点，子树内节点数目为 1 ，各放置 1 个金币。节点 0 处唯一的开销乘积是 2 * 1 * -2 = -4
 * 。所以在节点 0 处放置 0 个金币。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= n <= 2 * 10^4
 * edges.length == n - 1
 * edges[i].length == 2
 * 0 <= ai, bi < n
 * cost.length == n
 * 1 <= |cost[i]| <= 10^4
 * edges 一定是一棵合法的树。
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
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        vector<vector<int>> g(n);
        for (auto& e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<long long> res(n, 1);

        auto dfs = [&](this auto&& dfs, int x, int fa) -> vector<int> {
            vector<int> a = {cost[x]};
            for (int y : g[x]) {
                if (y != fa) {
                    auto res = dfs(y, x);
                    a.insert(a.begin(), res.begin(), res.end());
                }
            }

            sort(a.begin(), a.end());
            int m = a.size();
            if (m >= 3) {
                res[x] = max({
                    0LL,
                    (long long) a[0] * a[1] * a[m - 1],
                    (long long) a[m - 3] * a[m - 2] * a[m - 1]
                });
            }
            if (m > 5) {
                a = {a[0], a[1], a[m - 3], a[m - 2], a[m - 1]};
            }
            return a;
        };

        dfs(0, -1);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1],[0,2],[0,3],[0,4],[0,5]]\n[1,2,3,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[0,2],[1,3],[1,4],[1,5],[2,6],[2,7],[2,8]]\n[1,4,2,3,5,7,8,-4,2]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[0,2]]\n[1,2,-2]\n
// @lcpr case=end

 */

