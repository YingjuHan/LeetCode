/*
 * @lc app=leetcode.cn id=2328 lang=cpp
 * @lcpr version=30204
 *
 * [2328] 网格图中递增路径的数目
 *
 * https://leetcode.cn/problems/number-of-increasing-paths-in-a-grid/description/
 *
 * algorithms
 * Hard (54.22%)
 * Likes:    68
 * Dislikes: 0
 * Total Accepted:    11.5K
 * Total Submissions: 21.2K
 * Testcase Example:  '[[1,1],[3,4]]'
 *
 * 给你一个 m x n 的整数网格图 grid ，你可以从一个格子移动到 4 个方向相邻的任意一个格子。
 * 
 * 请你返回在网格图中从 任意 格子出发，达到 任意 格子，且路径中的数字是 严格递增 的路径数目。由于答案可能会很大，请将结果对 10^9 + 7 取余
 * 后返回。
 * 
 * 如果两条路径中访问过的格子不是完全相同的，那么它们视为两条不同的路径。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：grid = [[1,1],[3,4]]
 * 输出：8
 * 解释：严格递增路径包括：
 * - 长度为 1 的路径：[1]，[1]，[3]，[4] 。
 * - 长度为 2 的路径：[1 -> 3]，[1 -> 4]，[3 -> 4] 。
 * - 长度为 3 的路径：[1 -> 3 -> 4] 。
 * 路径数目为 4 + 3 + 1 = 8 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：grid = [[1],[2]]
 * 输出：3
 * 解释：严格递增路径包括：
 * - 长度为 1 的路径：[1]，[2] 。
 * - 长度为 2 的路径：[1 -> 2] 。
 * 路径数目为 2 + 1 = 3 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 1000
 * 1 <= m * n <= 10^5
 * 1 <= grid[i][j] <= 10^5
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
    int countPaths(vector<vector<int>>& grid) {
        const int mod = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> f(m, vector<int>(n, 1));
        vector<array<int, 3>> vp;
        vp.reserve(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vp.push_back({i, j, grid[i][j]});
            }
        }
        sort(vp.begin(), vp.end(), [](const array<int, 3>& a, const array<int, 3>& b) {
            return a[2] > b[2];
        });

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        long long ans = 0;
        for (auto &c : vp) {
            int x = c[0], y = c[1], v = c[2];
            long long ways = 1;
            for (auto& [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if (grid[nx][ny] > v) {
                    ways += f[nx][ny];
                    if (ways >= mod) {
                        ways -= mod;
                    }
                }
            }
            f[x][y] = ways % mod;
            ans += f[x][y];
            ans %= mod;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[1],[2]]\n
// @lcpr case=end

 */

