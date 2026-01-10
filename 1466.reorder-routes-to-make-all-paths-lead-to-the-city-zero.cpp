/*
 * @lc app=leetcode.cn id=1466 lang=cpp
 * @lcpr version=30204
 *
 * [1466] 重新规划路线
 *
 * https://leetcode.cn/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/
 *
 * algorithms
 * Medium (61.03%)
 * Likes:    260
 * Dislikes: 0
 * Total Accepted:    45.8K
 * Total Submissions: 75K
 * Testcase Example:  '6\n[[0,1],[1,3],[2,3],[4,0],[4,5]]'
 *
 * n 座城市，从 0 到 n-1 编号，其间共有 n-1
 * 条路线。因此，要想在两座不同城市之间旅行只有唯一一条路线可供选择（路线网形成一颗树）。去年，交通运输部决定重新规划路线，以改变交通拥堵的状况。
 * 
 * 路线用 connections 表示，其中 connections[i] = [a, b] 表示从城市 a 到 b 的一条有向路线。
 * 
 * 今年，城市 0 将会举办一场大型比赛，很多游客都想前往城市 0 。
 * 
 * 请你帮助重新规划路线方向，使每个城市都可以访问城市 0 。返回需要变更方向的最小路线数。
 * 
 * 题目数据 保证 每个城市在重新规划路线方向后都能到达城市 0 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
 * 输出：3
 * 解释：更改以红色显示的路线的方向，使每个城市都可以到达城市 0 。
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
 * 输出：2
 * 解释：更改以红色显示的路线的方向，使每个城市都可以到达城市 0 。
 * 
 * 示例 3：
 * 
 * 输入：n = 3, connections = [[1,0],[2,0]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= n <= 5 * 10^4
 * connections.length == n-1
 * connections[i].length == 2
 * 0 <= connections[i][0], connections[i][1] <= n-1
 * connections[i][0] != connections[i][1]
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
    int dfs(int x, int parent, vector<vector<pair<int, int>>>& e) {
        int res = 0;
        for (auto& edge : e[x]) {
            if (edge.first == parent) {
                continue;
            }
            res += edge.second + dfs(edge.first, x, e);
        }
        return res;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> e(n);
        for (auto edge : connections) {
            e[edge[0]].push_back({edge[1], 1});
            e[edge[1]].push_back({edge[0], 0});
        }
        return dfs(0, -1, e);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 6\n[[0,1],[1,3],[2,3],[4,0],[4,5]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[1,0],[1,2],[3,2],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[1,0],[2,0]]\n
// @lcpr case=end

 */

