/*
 * @lc app=leetcode.cn id=3552 lang=cpp
 * @lcpr version=30204
 *
 * [3552] 网格传送门旅游
 *
 * https://leetcode.cn/problems/grid-teleportation-traversal/description/
 *
 * algorithms
 * Medium (28.20%)
 * Likes:    10
 * Dislikes: 0
 * Total Accepted:    2.9K
 * Total Submissions: 10.2K
 * Testcase Example:  '["A..",".A.","..."]'
 *
 * 给你一个大小为 m x n 的二维字符网格 matrix，用字符串数组表示，其中 matrix[i][j] 表示第 i 行和第 j
 * 列处的单元格。每个单元格可以是以下几种字符之一：
 * 
 * 
 * '.' 表示一个空单元格。
 * '#' 表示一个障碍物。
 * 一个大写字母（'A' 到 'Z'）表示一个传送门。
 * 
 * 
 * 你从左上角单元格 (0, 0) 出发，目标是到达右下角单元格 (m - 1, n -
 * 1)。你可以从当前位置移动到相邻的单元格（上、下、左、右），移动后的单元格必须在网格边界内且不是障碍物。
 * 
 * 
 * 如果你踏入一个包含传送门字母的单元格，并且你之前没有使用过该传送门字母，你可以立即传送到网格中另一个具有相同字母的单元格。这次传送不计入移动次数，但每个字母对应的传送门在旅程中
 * 最多 只能使用一次。
 * 
 * 返回到达右下角单元格所需的 最少 移动次数。如果无法到达目的地，则返回 -1。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： matrix = ["A..",".A.","..."]
 * 
 * 输出： 2
 * 
 * 解释：
 * 
 * 
 * 
 * 
 * 在第一次移动之前，从 (0, 0) 传送到 (1, 1)。
 * 第一次移动，从 (1, 1) 移动到 (1, 2)。
 * 第二次移动，从 (1, 2) 移动到 (2, 2)。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： matrix = [".#...",".#.#.",".#.#.","...#."]
 * 
 * 输出： 13
 * 
 * 解释：
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= m == matrix.length <= 10^3
 * 1 <= n == matrix[i].length <= 10^3
 * matrix[i][j] 是 '#'、'.' 或一个大写英文字母。
 * matrix[0][0] 不是障碍物。
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
    int minMoves(vector<string>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if (matrix[m - 1][n - 1] == '#') {
            return -1;
        }

        vector<pair<int, int>> pos[26]{};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = matrix[i][j];
                if (isupper(c)) {
                    pos[c - 'A'].emplace_back(i, j);
                }
            }
        }

        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        dis[0][0] = 0;
        deque<pair<int, int>> q{{0, 0}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop_front();
            int d = dis[x][y];
            if (x == m - 1 && y == n - 1) {
                return d;
            }

            char c = matrix[x][y];
            if (c != '.') {
                for (auto& [px, py] : pos[c - 'A']) {
                    if (d < dis[px][py]) {
                        dis[px][py] = d;
                        q.emplace_front(px, py);
                    }
                }
                pos[c - 'A'].clear();
            }

            for (auto& [dx, dy] : DIRS) {
                int nx = x + dx, ny = y + dy;
                if (0 <= nx && nx < m && 0 <= ny && ny < n && matrix[nx][ny] != '#' && d + 1 < dis[nx][ny]) {
                    dis[nx][ny] = d + 1;
                    q.emplace_back(nx, ny);
                }
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["A..",".A.","..."]\n
// @lcpr case=end

// @lcpr case=start
// [".#...",".#.#.",".#.#.","...#."]\n
// @lcpr case=end

 */

