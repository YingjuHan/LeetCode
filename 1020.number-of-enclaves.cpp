/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 * @lcpr version=30204
 *
 * [1020] 飞地的数量
 *
 * https://leetcode.cn/problems/number-of-enclaves/description/
 *
 * algorithms
 * Medium (62.14%)
 * Likes:    305
 * Dislikes: 0
 * Total Accepted:    98.9K
 * Total Submissions: 159.1K
 * Testcase Example:  '[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]'
 *
 * 给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1 表示一个陆地单元格。
 * 
 * 一次 移动 是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid 的边界。
 * 
 * 返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
 * 输出：3
 * 解释：有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。
 * 
 * 
 * 示例 2：
 * 
 * 输入：grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
 * 输出：0
 * 解释：所有 1 都在边界上或可以到达边界。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 500
 * grid[i][j] 的值为 0 或 1
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
    int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        
        auto dfs = [&](this auto&& dfs, int i, int j, int& area, bool& isBorder) -> void {
            if (i < 0 || j < 0 || i >= m || j >= n) {
                isBorder = true;
                return;
            }
            if (grid[i][j] == 0) {
                return;
            }
            grid[i][j] = 0;
            area++;
            for (auto [dx, dy] : DIRS) {
                dfs(i + dx, j + dy, area, isBorder);
            }
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    bool isBorder = false;
                    dfs(i, j, area, isBorder);
                    ans += isBorder ? 0 : area;
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]\n
// @lcpr case=end

 */

