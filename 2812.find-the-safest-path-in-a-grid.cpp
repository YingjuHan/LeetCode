// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2812 lang=cpp
 * @lcpr version=30204
 *
 * [2812] 找出最安全路径
 *
 * https://leetcode.cn/problems/find-the-safest-path-in-a-grid/description/
 *
 * algorithms
 * Medium (31.31%)
 * Likes:    75
 * Dislikes: 0
 * Total Accepted:    7.2K
 * Total Submissions: 21.8K
 * Testcase Example:  '[[1,0,0],[0,0,0],[0,0,1]]'
 *
 * 给你一个下标从 0 开始、大小为 n x n 的二维矩阵 grid ，其中 (r, c) 表示：
 * 
 * 
 * 如果 grid[r][c] = 1 ，则表示一个存在小偷的单元格
 * 如果 grid[r][c] = 0 ，则表示一个空单元格
 * 
 * 
 * 你最开始位于单元格 (0, 0) 。在一步移动中，你可以移动到矩阵中的任一相邻单元格，包括存在小偷的单元格。
 * 
 * 矩阵中路径的 安全系数 定义为：从路径中任一单元格到矩阵中任一小偷所在单元格的 最小 曼哈顿距离。
 * 
 * 返回所有通向单元格 (n - 1, n - 1) 的路径中的 最大安全系数 。
 * 
 * 单元格 (r, c) 的某个 相邻 单元格，是指在矩阵中存在的 (r, c + 1)、(r, c - 1)、(r + 1, c) 和 (r - 1,
 * c) 之一。
 * 
 * 两个单元格 (a, b) 和 (x, y) 之间的 曼哈顿距离 等于 | a - x | + | b - y | ，其中 |val| 表示 val
 * 的绝对值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：grid = [[1,0,0],[0,0,0],[0,0,1]]
 * 输出：0
 * 解释：从 (0, 0) 到 (n - 1, n - 1) 的每条路径都经过存在小偷的单元格 (0, 0) 和 (n - 1, n - 1) 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：grid = [[0,0,1],[0,0,0],[0,0,0]]
 * 输出：2
 * 解释：
 * 上图所示路径的安全系数为 2：
 * - 该路径上距离小偷所在单元格（0，2）最近的单元格是（0，0）。它们之间的曼哈顿距离为 | 0 - 0 | + | 0 - 2 | = 2 。
 * 可以证明，不存在安全系数更高的其他路径。
 * 
 * 
 * 示例 3：
 * 
 * 输入：grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
 * 输出：2
 * 解释：
 * 上图所示路径的安全系数为 2：
 * - 该路径上距离小偷所在单元格（0，3）最近的单元格是（1，2）。它们之间的曼哈顿距离为 | 0 - 1 | + | 3 - 2 | = 2 。
 * - 该路径上距离小偷所在单元格（3，0）最近的单元格是（3，2）。它们之间的曼哈顿距离为 | 3 - 3 | + | 0 - 2 | = 2 。
 * 可以证明，不存在安全系数更高的其他路径。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= grid.length == n <= 400
 * grid[i].length == n
 * grid[i][j] 为 0 或 1
 * grid 至少存在一个小偷
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
class Solution1 {
public:
    static constexpr int DIRS[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> safe(n, vector<int>(n, -1));
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<tuple<int, int, int>> q; // x, y, d

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    vis[i][j] = 1;
                    safe[i][j] = 0;
                    q.emplace(i, j, 0);
                }
            }
        }

        while (!q.empty()) {
            auto [x, y, d] = q.front();
            q.pop();

            for (auto& [dx, dy] : DIRS) {
                int new_x = x + dx, new_y = y + dy;
                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && !vis[new_x][new_y]) {
                    vis[new_x][new_y] = 1;
                    safe[new_x][new_y] = d + 1;
                    q.emplace(new_x, new_y, d + 1);
                }

            }
        }

        auto check = [&](int mx) -> bool {
            std::function<bool(int, int, int)> dfs = [&](int i, int j, int safesize) -> bool {
                if (i == n - 1 && j == n - 1) {
                    return true;
                }

                vis[i][j] = 1;
                for (auto& [dx, dy] : DIRS) {
                    int x = i + dx, y = i + dy;
                    if (x >= 0 && x < n && y >= 0 && y < n && vis[x][y] != 1 && safe[x][y] >= safesize && dfs(x, y, safesize)) {
                        return true;
                    }
                }
                return false;
            };
            return dfs(0, 0, mx);
        };

        int left = 0, right = n * 2 + 1; 
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            fill(vis.begin(), vis.end(), vector<int>(n, 0));
            if (check(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

class Solution {
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int maximumSafenessFactor(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<pair<int, int>> q;
        vector<vector<int>> dis(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push_back({i, j});
                    dis[i][j] = 0;
                }
            }
        }

        vector<vector<pair<int, int>>> groups = {q};
        while (!q.empty()) {
            vector<pair<int, int>> nq;
            for (auto& [i, j] : q) {
                for (auto& [dx, dy] : dirs) {
                    int nx = i + dx, ny = j + dy;
                    if (0 <= nx && nx < n && 0 <= ny && ny < n && dis[nx][ny] < 0) {
                        nq.push_back({nx, ny});
                        dis[nx][ny] = groups.size();
                    }
                }
            }
            groups.push_back(nq);
            q = std::move(nq);
        }

        // 并查集模板
        vector<int> fa(n * n);
        iota(fa.begin(), fa.end(), 0);
        function<int(int)> find = [&](int x) -> int { return fa[x] == x ? x : fa[x] = find(fa[x]); };

        for (int ans = (int) groups.size() - 2; ans > 0; ans--) {
            for (auto &[i, j]: groups[ans]) {
                for (auto& [dx, dy] : dirs) {
                    int nx = i + dx, ny = j + dy;
                    if (0 <= nx && nx < n && 0 <= ny && ny < n && dis[nx][ny] >= dis[i][j])
                        fa[find(nx * n + ny)] = find(i * n + j);
                }
            }
            if (find(0) == find(n * n - 1)) // 写这里判断更快些
                return ans;
        }
        return 0;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maximumSafenessFactor
// paramTypes= ["number[][]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [[1,0,0],[0,0,0],[0,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,1],[0,0,0],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]\n
// @lcpr case=end

 */

