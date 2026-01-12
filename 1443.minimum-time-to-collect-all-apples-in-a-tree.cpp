/*
 * @lc app=leetcode.cn id=1443 lang=cpp
 * @lcpr version=30204
 *
 * [1443] 收集树上所有苹果的最少时间
 *
 * https://leetcode.cn/problems/minimum-time-to-collect-all-apples-in-a-tree/description/
 *
 * algorithms
 * Medium (46.77%)
 * Likes:    113
 * Dislikes: 0
 * Total Accepted:    11.3K
 * Total Submissions: 24.1K
 * Testcase Example:  '7\n' +
  '[[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]\n' +
  '[false,false,true,false,true,true,false]'
 *
 * 给你一棵有 n 个节点的无向树，节点编号为 0 到 n-1 ，它们中有一些节点有苹果。通过树上的一条边，需要花费 1 秒钟。你从 节点 0
 * 出发，请你返回最少需要多少秒，可以收集到所有苹果，并回到节点 0 。
 * 
 * 无向树的边由 edges 给出，其中 edges[i] = [fromi, toi] ，表示有一条边连接 from 和 toi
 * 。除此以外，还有一个布尔数组 hasApple ，其中 hasApple[i] = true 代表节点 i 有一个苹果，否则，节点 i
 * 没有苹果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple =
 * [false,false,true,false,true,true,false]
 * 输出：8 
 * 解释：上图展示了给定的树，其中红色节点表示有苹果。一个能收集到所有苹果的最优方案由绿色箭头表示。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple =
 * [false,false,true,false,false,true,false]
 * 输出：6
 * 解释：上图展示了给定的树，其中红色节点表示有苹果。一个能收集到所有苹果的最优方案由绿色箭头表示。
 * 
 * 
 * 示例 3：
 * 
 * 输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple =
 * [false,false,false,false,false,false,false]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 10^5
 * edges.length == n - 1
 * edges[i].length == 2
 * 0 <= ai < bi <= n - 1
 * hasApple.length == n
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
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> g(n);
        for (auto& edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        return dfs(0, g, hasApple, visited);
    }

    int dfs(int node, const vector<vector<int>>& g, const vector<bool>& hasApple, vector<bool>& visited) {
        visited[node] = true;
        int time = 0;
        for (int child : g[node]) {
            if (!visited[child]) {
                time += dfs(child, g, hasApple, visited);
            }
        }
        if (node != 0 && (hasApple[node] || time > 0)) {
            time += 2;
        }
        return time;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n[[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]\n[false,false,true,false,true,true,false]\n
// @lcpr case=end

// @lcpr case=start
// 7\n[[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]\n[false,false,true,false,false,true,false]\n
// @lcpr case=end

// @lcpr case=start
// 7\n[[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]\n[false,false,false,false,false,false,false]\n
// @lcpr case=end

 */

