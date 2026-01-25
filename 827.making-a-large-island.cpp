/*
 * @lc app=leetcode.cn id=827 lang=cpp
 * @lcpr version=30204
 *
 * [827] 最大人工岛
 *
 * https://leetcode.cn/problems/making-a-large-island/description/
 *
 * algorithms
 * Hard (48.52%)
 * Likes:    478
 * Dislikes: 0
 * Total Accepted:    67.6K
 * Total Submissions: 139.1K
 * Testcase Example:  '[[1,0],[0,1]]'
 *
 * 给你一个大小为 n x n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。
 * 
 * 返回执行此操作后，grid 中最大的岛屿面积是多少？
 * 
 * 岛屿 由一组上、下、左、右四个方向相连的 1 形成。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: grid = [[1, 0], [0, 1]]
 * 输出: 3
 * 解释: 将一格0变成1，最终连通两个小岛得到面积为 3 的岛屿。
 * 
 * 
 * 示例 2:
 * 
 * 输入: grid = [[1, 1], [1, 0]]
 * 输出: 4
 * 解释: 将一格0变成1，岛屿的面积扩大为 4。
 * 
 * 示例 3:
 * 
 * 输入: grid = [[1, 1], [1, 1]]
 * 输出: 4
 * 解释: 没有0可以让我们变成1，面积依然为 4。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == grid.length
 * n == grid[i].length
 * 1 <= n <= 500
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
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> area;
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            grid[i][j] = area.size() + 2; // 记录ij属于哪个岛
            int size = 1;
            for (auto& [dx, dy] : dirs) {
                int x = i + dx, y = j + dy;
                if (0 <= x && x < n && 0 <= y && y < n && grid[x][y] == 1) {
                    size += dfs(x, y);
                }
            }
            return size;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    area.push_back(dfs(i, j));
                }
            }
        }

        if (area.empty()) {
            return 1;
        }

        int res = 0;
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    s.clear();
                    int new_area = 1;
                    for (auto& [dx, dy] : dirs) {
                        int x = i + dx, y = j + dy;
                        if (0 <= x && x < n && 0 <= y && y < n && grid[x][y] != 0 && s.insert(grid[x][y]).second) {
                            new_area += area[grid[x][y] - 2];
                        }
                    }
                    res = max(res, new_area);
                }
            }
        }
        return res ? res : n * n;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1, 0], [0, 1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1, 1], [1, 0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1, 1], [1, 1]]\n
// @lcpr case=end

 */

