/*
 * @lc app=leetcode.cn id=1034 lang=cpp
 * @lcpr version=30204
 *
 * [1034] 边界着色
 *
 * https://leetcode.cn/problems/coloring-a-border/description/
 *
 * algorithms
 * Medium (55.04%)
 * Likes:    193
 * Dislikes: 0
 * Total Accepted:    42.3K
 * Total Submissions: 76.9K
 * Testcase Example:  '[[1,1],[1,2]]\n0\n0\n3'
 *
 * 给你一个大小为 m x n 的整数矩阵 grid ，表示一个网格。另给你三个整数 row、col 和 color
 * 。网格中的每个值表示该位置处的网格块的颜色。
 * 
 * 如果两个方块在任意 4 个方向上相邻，则称它们 相邻 。
 * 
 * 如果两个方块具有相同的颜色且相邻，它们则属于同一个 连通分量 。
 * 
 * 连通分量的边界 是指连通分量中满足下述条件之一的所有网格块：
 * 
 * 
 * 在上、下、左、右任意一个方向上与不属于同一连通分量的网格块相邻
 * 在网格的边界上（第一行/列或最后一行/列）
 * 
 * 
 * 请你使用指定颜色 color 为所有包含网格块 grid[row][col] 的 连通分量的边界 进行着色。
 * 
 * 并返回最终的网格 grid 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
 * 输出：[[3,3],[3,2]]
 * 
 * 示例 2：
 * 
 * 输入：grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
 * 输出：[[1,3,3],[2,3,3]]
 * 
 * 示例 3：
 * 
 * 输入：grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
 * 输出：[[2,2,2],[2,1,2],[2,2,2]]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 50
 * 1 <= grid[i][j], color <= 1000
 * 0 <= row < m
 * 0 <= col < n
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
    static constexpr int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int original = grid[row][col];
        vector<pair<int, int>> border;
        auto dfs = [&](this auto&& dfs, int x, int y) -> void {
            vis[x][y] = 1;
            bool isBorder = false;
            for (auto [dx, dy] : DIRS) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    isBorder = true;
                    continue;
                }
                if (grid[nx][ny] != original) {
                    isBorder = true;
                    continue;
                }
                if (vis[nx][ny] == 0) {
                    dfs(nx, ny);
                }
            }
            if (isBorder) {
                border.emplace_back(x, y);
            }
        };
        dfs(row, col);
        for (auto& [i, j] : border) {
            grid[i][j] = color;
        }
        return grid;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1],[1,2]]\n0\n0\n3\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,2],[2,3,2]]\n0\n1\n3\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1],[1,1,1],[1,1,1]]\n1\n1\n2\n
// @lcpr case=end

 */

