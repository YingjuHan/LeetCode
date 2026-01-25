/*
 * @lc app=leetcode.cn id=3619 lang=cpp
 * @lcpr version=30204
 *
 * [3619] 总价值可以被 K 整除的岛屿数目
 *
 * https://leetcode.cn/problems/count-islands-with-total-value-divisible-by-k/description/
 *
 * algorithms
 * Medium (60.71%)
 * Likes:    6
 * Dislikes: 0
 * Total Accepted:    4.3K
 * Total Submissions: 7.1K
 * Testcase Example:  '[[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]]\n5'
 *
 * 给你一个 m x n 的矩阵 grid 和一个正整数 k。一个 岛屿 是由 正 整数（表示陆地）组成的，并且陆地间 四周 连通（水平或垂直）。
 * 
 * 一个岛屿的总价值是该岛屿中所有单元格的值之和。
 * 
 * 返回总价值可以被 k 整除 的岛屿数量。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k
 * = 5
 * 
 * 输出: 2
 * 
 * 解释:
 * 
 * 网格中包含四个岛屿。蓝色高亮显示的岛屿的总价值可以被 5 整除，而红色高亮显示的岛屿则不能。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: grid = [[3,0,3,0], [0,3,0,3], [3,0,3,0]], k = 3
 * 
 * 输出: 6
 * 
 * 解释:
 * 
 * 网格中包含六个岛屿，每个岛屿的总价值都可以被 3 整除。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 1000
 * 1 <= m * n <= 10^5
 * 0 <= grid[i][j] <= 10^6
 * 1 <= k < = 10^6
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
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        auto dfs = [&](this auto&& dfs, int i, int j) -> long long {
            long long area = grid[i][j];
            grid[i][j] = 0;
            for (auto [dx, dy] : DIRS) {
                int x = i + dx, y = j + dy;
                if (0 <= x && x < m && 0 <= y && y < n && grid[x][y]) {
                    area += dfs(x, y);
                }
            }
            return area;
        };

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] && dfs(i, j) % k == 0) {
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]]\n5\n
// @lcpr case=end

// @lcpr case=start
// [[3,0,3,0], [0,3,0,3], [3,0,3,0]]\n3\n
// @lcpr case=end

 */

