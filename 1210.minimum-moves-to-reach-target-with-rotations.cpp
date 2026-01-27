/*
 * @lc app=leetcode.cn id=1210 lang=cpp
 * @lcpr version=30204
 *
 * [1210] 穿过迷宫的最少移动次数
 *
 * https://leetcode.cn/problems/minimum-moves-to-reach-target-with-rotations/description/
 *
 * algorithms
 * Hard (63.48%)
 * Likes:    163
 * Dislikes: 0
 * Total Accepted:    18K
 * Total Submissions: 28.4K
 * Testcase Example:  '[[0,0,0,0,0,1],[1,1,0,0,1,0],[0,0,0,0,1,1],[0,0,1,0,1,0],[0,1,1,0,0,0],[0,1,1,0,0,0]]\r'
 *
 * 你还记得那条风靡全球的贪吃蛇吗？
 * 
 * 我们在一个 n*n 的网格上构建了新的迷宫地图，蛇的长度为 2，也就是说它会占去两个单元格。蛇会从左上角（(0, 0) 和 (0,
 * 1)）开始移动。我们用 0 表示空单元格，用 1 表示障碍物。蛇需要移动到迷宫的右下角（(n-1, n-2) 和 (n-1, n-1)）。
 * 
 * 每次移动，蛇可以这样走：
 * 
 * 
 * 如果没有障碍，则向右移动一个单元格。并仍然保持身体的水平／竖直状态。
 * 如果没有障碍，则向下移动一个单元格。并仍然保持身体的水平／竖直状态。
 * 如果它处于水平状态并且其下面的两个单元都是空的，就顺时针旋转 90 度。蛇从（(r, c)、(r, c+1)）移动到 （(r, c)、(r+1,
 * c)）。
 * 
 * 如果它处于竖直状态并且其右面的两个单元都是空的，就逆时针旋转 90 度。蛇从（(r, c)、(r+1, c)）移动到（(r, c)、(r,
 * c+1)）。
 * 
 * 
 * 
 * 返回蛇抵达目的地所需的最少移动次数。
 * 
 * 如果无法到达目的地，请返回 -1。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：grid = [[0,0,0,0,0,1],
 * ⁠              [1,1,0,0,1,0],
 * [0,0,0,0,1,1],
 * [0,0,1,0,1,0],
 * [0,1,1,0,0,0],
 * [0,1,1,0,0,0]]
 * 输出：11
 * 解释：
 * 一种可能的解决方案是 [右, 右, 顺时针旋转, 右, 下, 下, 下, 下, 逆时针旋转, 右, 下]。
 * 
 * 
 * 示例 2：
 * 
 * 输入：grid = [[0,0,1,1,1,1],
 * [0,0,0,0,1,1],
 * [1,1,0,0,0,1],
 * [1,1,1,0,0,1],
 * [1,1,1,0,0,1],
 * [1,1,1,0,0,0]]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= n <= 100
 * 0 <= grid[i][j] <= 1
 * 蛇保证从空单元格开始出发。
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
    // 水平状态：向下移动／向右移动／顺时针旋转 90 度
    // 竖直状态：向下移动／向右移动／逆时针旋转 90 度

    // 向下移动：x 增加 1，y 和 s 不变。用三元组 (1,0,0) 表示
    // 向右移动：y 增加 1，x 和 s 不变。用三元组 (0,1,0) 表示
    // 旋转：s 切换，即 0 变为 1，1 变为 0；x 和 y 不变。用三元组 (0,0,1) 表示

    static constexpr int DIRS[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int minimumMoves(vector<vector<int>>& g) {
        int n = g.size();
        bool vis[n][n][2]; memset(vis, 0, sizeof(vis));
        vis[0][0][0] = true;
        vector<tuple<int, int, int>> q = {{0, 0, 0}}; // 初始位置
        for (int step = 1; !q.empty(); ++step) {
            vector<tuple<int, int, int>> nxt;
            for (const auto &[x, y, s] : q) {
                for (const auto &d : DIRS) {
                    int nx = x + d[0], ny = y + d[1], ns = s ^ d[2];
                    int x2 = nx + ns, y2 = ny + (ns ^ 1); // 蛇头
                    if (x2 < n && y2 < n && !vis[nx][ny][ns] && g[nx][ny] == 0 && g[x2][y2] == 0 && (d[2] == 0 || g[nx + 1][ny + 1] == 0)) {
                        if (nx == n - 1 && ny == n - 2) return step; // 此时蛇头一定在 (n-1,n-1)
                        vis[nx][ny][ns] = true;
                        nxt.emplace_back(nx, ny, ns);
                    }
                }
            }
            q = move(nxt);
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0,0,0,0,1],[1,1,0,0,1,0],[0,0,0,0,1,1],[0,0,1,0,1,0],[0,1,1,0,0,0],[0,1,1,0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,1,1,1,1],[0,0,0,0,1,1],[1,1,0,0,0,1],[1,1,1,0,0,1],[1,1,1,0,0,1],[1,1,1,0,0,0]]\n
// @lcpr case=end

 */

