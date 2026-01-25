/*
 * @lc app=leetcode.cn id=417 lang=cpp
 * @lcpr version=30204
 *
 * [417] 太平洋大西洋水流问题
 *
 * https://leetcode.cn/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (57.71%)
 * Likes:    795
 * Dislikes: 0
 * Total Accepted:    126.3K
 * Total Submissions: 218.8K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * 有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。
 * 
 * 这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c)
 * 上单元格 高于海平面的高度 。
 * 
 * 岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。
 * 
 * 返回网格坐标 result 的 2D 列表 ，其中 result[i] = [ri, ci] 表示雨水从单元格 (ri, ci) 流动
 * 既可流向太平洋也可流向大西洋 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
 * 输出: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
 * 
 * 
 * 示例 2：
 * 
 * 输入: heights = [[2,1],[1,2]]
 * 输出: [[0,0],[0,1],[1,0],[1,1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == heights.length
 * n == heights[r].length
 * 1 <= m, n <= 200
 * 0 <= heights[r][c] <= 10^5
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
    static constexpr int DIRS[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        auto dfs = [&](this auto&& dfs, int i, int j, vector<vector<uint8_t>>& vis) -> void {
            if (vis[i][j]) {
                return;
            }
            vis[i][j] = 1;
            for (auto& [dx, dy] : DIRS) {
                int x = i + dx, y = j + dy;
                if (x >= 0 && x < m && y >= 0 && y < n && heights[x][y] >= heights[i][j]) {
                    dfs(x, y, vis);
                }
            }
        };

        vector<vector<uint8_t>> pacdific_vis(m, vector<uint8_t>(n));
        for (int j = 0; j < n; j++) {
            dfs(0, j, pacdific_vis);
        }
        for (int i = 1; i < m; i++) {
            dfs(i, 0, pacdific_vis);
        }

        vector<vector<uint8_t>> atlantic_vis(m, vector<uint8_t>(n));
        for (int j = 0; j < n; j++) {
            dfs(m - 1, j, atlantic_vis);
        }
        for (int i = 0; i < m - 1; i++) {
            dfs(i, n - 1, atlantic_vis);
        }

        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacdific_vis[i][j] && atlantic_vis[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,1],[1,2]]\n
// @lcpr case=end

 */

