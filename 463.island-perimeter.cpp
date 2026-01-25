/*
 * @lc app=leetcode.cn id=463 lang=cpp
 * @lcpr version=30204
 *
 * [463] 岛屿的周长
 *
 * https://leetcode.cn/problems/island-perimeter/description/
 *
 * algorithms
 * Easy (71.07%)
 * Likes:    836
 * Dislikes: 0
 * Total Accepted:    197.1K
 * Total Submissions: 277.3K
 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
 *
 * 给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。
 * 
 * 网格中的格子 水平和垂直 方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
 * 
 * 岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100
 * 。计算这个岛屿的周长。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
 * 输出：16
 * 解释：它的周长是上面图片中的 16 个黄色的边
 * 
 * 示例 2：
 * 
 * 输入：grid = [[1]]
 * 输出：4
 * 
 * 
 * 示例 3：
 * 
 * 输入：grid = [[1,0]]
 * 输出：4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * row == grid.length
 * col == grid[i].length
 * 1 <= row, col <= 100
 * grid[i][j] 为 0 或 1
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
    // 枚举陆地格子上下左右四个方向的相邻格子，如果出界或者是水，那么就找到了一条黄色的边
    int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
                return 1;
            }
            if (grid[i][j] == 2) {
                return 0;
            }
            grid[i][j] = 2;
            int sum = 0;
            for (auto [dx, dy] : DIRS) {
                sum += dfs(i + dx, j + dy);
            }
            return sum;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return dfs(i, j);
                }
            }
        }
        return 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0]]\n
// @lcpr case=end

 */

