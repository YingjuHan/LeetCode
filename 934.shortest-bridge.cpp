/*
 * @lc app=leetcode.cn id=934 lang=cpp
 * @lcpr version=30204
 *
 * [934] 最短的桥
 *
 * https://leetcode.cn/problems/shortest-bridge/description/
 *
 * algorithms
 * Medium (53.53%)
 * Likes:    572
 * Dislikes: 0
 * Total Accepted:    84.3K
 * Total Submissions: 157.4K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * 给你一个大小为 n x n 的二元矩阵 grid ，其中 1 表示陆地，0 表示水域。
 * 
 * 岛 是由四面相连的 1 形成的一个最大组，即不会与非组内的任何其他 1 相连。grid 中 恰好存在两座岛 。
 * 
 * 
 * 
 * 你可以将任意数量的 0 变为 1 ，以使两座岛连接起来，变成 一座岛 。
 * 
 * 返回必须翻转的 0 的最小数目。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：grid = [[0,1],[1,0]]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 输入：grid = [[0,1,0],[0,0,0],[0,0,1]]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 输入：grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == grid.length == grid[i].length
 * 2 <= n <= 100
 * grid[i][j] 为 0 或 1
 * grid 中恰有两个岛
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
    static constexpr int DIRS[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // 左右上下
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;

        bool found_first = false;

        auto dfs = [&](this auto&& dfs, int i, int j) -> void {
            if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= 0){
                return;
            }
            q.push({i, j});
            grid[i][j] = -1;
            for (auto& [dx, dy] : DIRS) {
                dfs(i + dx, j + dy);
            }
        };
        
        for (int i = 0; i < m && !found_first; i++) {
            for (int j = 0; j < n && !found_first; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                    found_first = true;
                }
            }
        }
        int ans = 0;
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto& [dx, dy] : DIRS) {
                    int nx = x + dx, ny = y + dy;
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n){
                        continue;
                    }
                    if (grid[nx][ny] == 1) {
                        return ans;
                    } else if (grid[nx][ny] == 0) {
                        q.push({nx, ny});
                        grid[nx][ny] = -1;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,0],[0,0,0],[0,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]\n
// @lcpr case=end

 */

