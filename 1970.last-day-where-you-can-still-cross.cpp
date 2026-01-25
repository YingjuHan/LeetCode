/*
 * @lc app=leetcode.cn id=1970 lang=cpp
 * @lcpr version=30204
 *
 * [1970] 你能穿过矩阵的最后一天
 *
 * https://leetcode.cn/problems/last-day-where-you-can-still-cross/description/
 *
 * algorithms
 * Hard (62.57%)
 * Likes:    90
 * Dislikes: 0
 * Total Accepted:    12.6K
 * Total Submissions: 19.6K
 * Testcase Example:  '2\n2\n[[1,1],[2,1],[1,2],[2,2]]'
 *
 * 给你一个下标从 1 开始的二进制矩阵，其中 0 表示陆地，1 表示水域。同时给你 row 和 col 分别表示矩阵中行和列的数目。
 * 
 * 一开始在第 0 天，整个 矩阵都是 陆地 。但每一天都会有一块新陆地被 水 淹没变成水域。给你一个下标从 1 开始的二维数组 cells ，其中
 * cells[i] = [ri, ci] 表示在第 i 天，第 ri 行 ci 列（下标都是从 1 开始）的陆地会变成 水域 （也就是 0 变成 1
 * ）。
 * 
 * 你想知道从矩阵最 上面 一行走到最 下面 一行，且只经过陆地格子的 最后一天 是哪一天。你可以从最上面一行的 任意 格子出发，到达最下面一行的 任意
 * 格子。你只能沿着 四个 基本方向移动（也就是上下左右）。
 * 
 * 请返回只经过陆地格子能从最 上面 一行走到最 下面 一行的 最后一天 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
 * 输出：2
 * 解释：上图描述了矩阵从第 0 天开始是如何变化的。
 * 可以从最上面一行到最下面一行的最后一天是第 2 天。
 * 
 * 
 * 示例 2：
 * 
 * 输入：row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
 * 输出：1
 * 解释：上图描述了矩阵从第 0 天开始是如何变化的。
 * 可以从最上面一行到最下面一行的最后一天是第 1 天。
 * 
 * 
 * 示例 3：
 * 
 * 输入：row = 3, col = 3, cells =
 * [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
 * 输出：3
 * 解释：上图描述了矩阵从第 0 天开始是如何变化的。
 * 可以从最上面一行到最下面一行的最后一天是第 3 天。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= row, col <= 2 * 10^4
 * 4 <= row * col <= 2 * 10^4
 * cells.length == row * col
 * 1 <= ri <= row
 * 1 <= ci <= col
 * cells 中的所有格子坐标都是 唯一 的。
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
    static constexpr int DIRS[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // 左右上下

public:
    int latestDayToCross(int m, int n, vector<vector<int>>& cells) {
        // 0：水
        // 1：陆地（未被感染）
        // 2：陆地（已被感染）
        vector state(m, vector<int8_t>(n));

        auto can_reach_from_top = [&](int r, int c) -> bool {
            if (r == 0) { // 已经是第一行
                return true;
            }
            for (auto& d : DIRS) {
                int x = r + d[0], y = c + d[1];
                if (0 <= x && x < m && 0 <= y && y < n && state[x][y] == 2) {
                    return true;
                }
            }
            return false;
        };

        auto dfs = [&](this auto&& dfs, int r, int c) -> bool {
            if (r == m - 1) {
                return true;
            }
            state[r][c] = 2; // 感染
            for (auto& d : DIRS) {
                int x = r + d[0], y = c + d[1];
                // 传播病毒到未被感染的陆地
                if (0 <= x && x < m && 0 <= y && y < n && state[x][y] == 1 && dfs(x, y)) {
                    return true;
                }
            }
            return false;
        };

        for (int day = cells.size() - 1; ; day--) {
            auto& cell = cells[day];
            int r = cell[0] - 1; // 改成从 0 开始的下标
            int c = cell[1] - 1;
            state[r][c] = 1; // 未被感染的陆地
            if (can_reach_from_top(r, c) && dfs(r, c)) {
                return day;
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n2\n[[1,1],[2,1],[1,2],[2,2]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n2\n[[1,1],[1,2],[2,1],[2,2]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n[[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]\n
// @lcpr case=end

 */

