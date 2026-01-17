/*
 * @lc app=leetcode.cn id=2646 lang=cpp
 * @lcpr version=30204
 *
 * [2646] 最小化旅行的价格总和
 *
 * https://leetcode.cn/problems/minimize-the-total-price-of-the-trips/description/
 *
 * algorithms
 * Hard (69.63%)
 * Likes:    129
 * Dislikes: 0
 * Total Accepted:    15.9K
 * Total Submissions: 22.8K
 * Testcase Example:  '4\n[[0,1],[1,2],[1,3]]\n[2,2,10,6]\n[[0,3],[2,1],[2,3]]'
 *
 * 现有一棵无向、无根的树，树中有 n 个节点，按从 0 到 n - 1 编号。给你一个整数 n 和一个长度为 n - 1 的二维整数数组 edges
 * ，其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条边。
 * 
 * 每个节点都关联一个价格。给你一个整数数组 price ，其中 price[i] 是第 i 个节点的价格。
 * 
 * 给定路径的 价格总和 是该路径上所有节点的价格之和。
 * 
 * 另给你一个二维整数数组 trips ，其中 trips[i] = [starti, endi] 表示您从节点 starti 开始第 i
 * 次旅行，并通过任何你喜欢的路径前往节点 endi 。
 * 
 * 在执行第一次旅行之前，你可以选择一些 非相邻节点 并将价格减半。
 * 
 * 返回执行所有旅行的最小价格总和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 4, edges = [[0,1],[1,2],[1,3]], price = [2,2,10,6], trips =
 * [[0,3],[2,1],[2,3]]
 * 输出：23
 * 解释：
 * 上图表示将节点 2 视为根之后的树结构。第一个图表示初始树，第二个图表示选择节点 0 、2 和 3 并使其价格减半后的树。
 * 第 1 次旅行，选择路径 [0,1,3] 。路径的价格总和为 1 + 2 + 3 = 6 。
 * 第 2 次旅行，选择路径 [2,1] 。路径的价格总和为 2 + 5 = 7 。
 * 第 3 次旅行，选择路径 [2,1,3] 。路径的价格总和为 5 + 2 + 3 = 10 。
 * 所有旅行的价格总和为 6 + 7 + 10 = 23 。可以证明，23 是可以实现的最小答案。
 * 
 * 示例 2：
 * 
 * 输入：n = 2, edges = [[0,1]], price = [2,2], trips = [[0,0]]
 * 输出：1
 * 解释：
 * 上图表示将节点 0 视为根之后的树结构。第一个图表示初始树，第二个图表示选择节点 0 并使其价格减半后的树。 
 * 第 1 次旅行，选择路径 [0] 。路径的价格总和为 1 。 
 * 所有旅行的价格总和为 1 。可以证明，1 是可以实现的最小答案。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 50
 * edges.length == n - 1
 * 0 <= ai, bi <= n - 1
 * edges 表示一棵有效的树
 * price.length == n
 * price[i] 是一个偶数
 * 1 <= price[i] <= 1000
 * 1 <= trips.length <= 100
 * 0 <= starti, endi <= n - 1
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
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> g(n);
        for (auto& edge : edges) {
            int x = edge[0], y = edge[1];
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        vector<int> cnt(n);
        for (auto& t : trips) {
            int end = t[1];
            function<bool(int, int)> dfs = [&](int x, int fa) -> bool {
                if (x == end) {
                    cnt[x]++;
                    return true;
                }
                for (int y : g[x]) {
                    if (y != fa) {
                        bool flag = dfs(y, x);
                        if (flag) {
                            cnt[x]++;
                            return true;
                        }
                    }
                }
                return false;
            };

            dfs(t[0], -1);
        }

        function<pair<int, int>(int, int)> dfs = [&](int x, int fa) -> pair<int, int> {
            int no_halve = price[x] * cnt[x];
            int halve = no_halve / 2;
            for (int y : g[x]) {
                if (y != fa) {
                    auto [nh, h] = dfs(y, x); // 计算 y 不变/减半的最小价值总和
                    no_halve += min(nh, h); // x 不变，那么 y 可以不变，可以减半，取这两种情况的最小值
                    halve += nh; // x 减半，那么 y 只能不变
                }
            }
            return {no_halve, halve};
        };
        auto [nh, h] = dfs(0, -1);
        return min(nh, h);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n[[0,1],[1,2],[1,3]]\n[2,2,10,6]\n[[0,3],[2,1],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[0,1]]\n[2,2]\n[[0,0]]\n
// @lcpr case=end

 */

