/*
 * @lc app=leetcode.cn id=2290 lang=cpp
 * @lcpr version=30204
 *
 * [2290] 到达角落需要移除障碍物的最小数目
 *
 * https://leetcode.cn/problems/minimum-obstacle-removal-to-reach-corner/description/
 *
 * algorithms
 * Hard (62.63%)
 * Likes:    71
 * Dislikes: 0
 * Total Accepted:    12K
 * Total Submissions: 19.2K
 * Testcase Example:  '[[0,1,1],[1,1,0],[1,1,0]]'
 *
 * 给你一个下标从 0 开始的二维整数数组 grid ，数组大小为 m x n 。每个单元格都是两个值之一：
 * 
 * 
 * 0 表示一个 空 单元格，
 * 1 表示一个可以移除的 障碍物 。
 * 
 * 
 * 你可以向上、下、左、右移动，从一个空单元格移动到另一个空单元格。
 * 
 * 现在你需要从左上角 (0, 0) 移动到右下角 (m - 1, n - 1) ，返回需要移除的障碍物的 最小 数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：grid = [[0,1,1],[1,1,0],[1,1,0]]
 * 输出：2
 * 解释：可以移除位于 (0, 1) 和 (0, 2) 的障碍物来创建从 (0, 0) 到 (2, 2) 的路径。
 * 可以证明我们至少需要移除两个障碍物，所以返回 2 。
 * 注意，可能存在其他方式来移除 2 个障碍物，创建出可行的路径。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
 * 输出：0
 * 解释：不移除任何障碍物就能从 (0, 0) 到 (2, 4) ，所以返回 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10^5
 * 2 <= m * n <= 10^5
 * grid[i][j] 为 0 或 1
 * grid[0][0] == grid[m - 1][n - 1] == 0
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
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        dis[0][0] = 0;
        deque<pair<int, int>> q;
        q.emplace_front(0, 0);
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop_front();
            for (auto& [dx, dy] : DIRS) {
                int nx = x + dx, ny = y + dy;
                if (0 <= nx && nx < m && 0 <= ny && ny < n) {
                    int g = grid[nx][ny];
                    if (dis[x][y] + g < dis[nx][ny]) {
                        dis[nx][ny] = dis[x][y] + g;
                        g == 0 ? q.emplace_front(nx, ny) : q.emplace_back(nx, ny);
                    }
                }
            }
        }
        return dis[m - 1][n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,1],[1,1,0],[1,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]\n
// @lcpr case=end

 */

