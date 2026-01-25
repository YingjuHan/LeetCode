/*
 * @lc app=leetcode.cn id=1391 lang=cpp
 * @lcpr version=30204
 *
 * [1391] 检查网格中是否存在有效路径
 *
 * https://leetcode.cn/problems/check-if-there-is-a-valid-path-in-a-grid/description/
 *
 * algorithms
 * Medium (45.79%)
 * Likes:    103
 * Dislikes: 0
 * Total Accepted:    13.4K
 * Total Submissions: 29.2K
 * Testcase Example:  '[[2,4,3],[6,5,2]]'
 *
 * 给你一个 m x n 的网格 grid。网格里的每个单元都代表一条街道。grid[i][j] 的街道可以是：
 * 
 * 
 * 1 表示连接左单元格和右单元格的街道。
 * 2 表示连接上单元格和下单元格的街道。
 * 3 表示连接左单元格和下单元格的街道。
 * 4 表示连接右单元格和下单元格的街道。
 * 5 表示连接左单元格和上单元格的街道。
 * 6 表示连接右单元格和上单元格的街道。
 * 
 * 
 * 
 * 
 * 你最开始从左上角的单元格 (0,0) 开始出发，网格中的「有效路径」是指从左上方的单元格 (0,0) 开始、一直到右下方的 (m-1,n-1)
 * 结束的路径。该路径必须只沿着街道走。
 * 
 * 注意：你 不能 变更街道。
 * 
 * 如果网格中存在有效的路径，则返回 true，否则返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：grid = [[2,4,3],[6,5,2]]
 * 输出：true
 * 解释：如图所示，你可以从 (0, 0) 开始，访问网格中的所有单元格并到达 (m - 1, n - 1) 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：grid = [[1,2,1],[1,2,1]]
 * 输出：false
 * 解释：如图所示，单元格 (0, 0) 上的街道没有与任何其他单元格上的街道相连，你只会停在 (0, 0) 处。
 * 
 * 
 * 示例 3：
 * 
 * 输入：grid = [[1,1,2]]
 * 输出：false
 * 解释：你会停在 (0, 1)，而且无法到达 (0, 2) 。
 * 
 * 
 * 示例 4：
 * 
 * 输入：grid = [[1,1,1,1,1,1,3]]
 * 输出：true
 * 
 * 
 * 示例 5：
 * 
 * 输入：grid = [[2],[2],[2],[2],[2],[2],[6]]
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * 1 <= grid[i][j] <= 6
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
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //0下、1右、2上、3左
    int pipe[7][4] = {
        {-1,-1,-1,-1},
        {-1,1,-1,3},
        {0,-1,2,-1},
        {-1,0,3,-1},
        {-1,-1,1,0},
        {3,2,-1,-1},
        {1,-1,-1,2}
    };
    bool vis[302][302];
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int start = grid[0][0];
        memset(vis, false, sizeof(vis));

        auto dfs = [&](this auto&& dfs, int x, int y, int dir) -> bool {
            vis[x][y] = true;
            if (x == m - 1 && y == n - 1) {
                return true;
            }
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                return false;
            }

            int nxt = grid[nx][ny];
            if (pipe[nxt][dir] != -1 && vis[nx][ny] == false) {
                return dfs(nx, ny, pipe[nxt][dir]);
            }
            return false;
        };

        for (int i = 0; i < 4; i++) {
            if (pipe[start][i] != -1) {
                if (dfs(0, 0, pipe[start][i])) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,4,3],[6,5,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1],[1,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1,1,1,1,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[2],[2],[2],[2],[2],[2],[6]]\n
// @lcpr case=end

 */

