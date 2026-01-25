/*
 * @lc app=leetcode.cn id=1559 lang=cpp
 * @lcpr version=30204
 *
 * [1559] 二维网格图中探测环
 *
 * https://leetcode.cn/problems/detect-cycles-in-2d-grid/description/
 *
 * algorithms
 * Medium (45.96%)
 * Likes:    93
 * Dislikes: 0
 * Total Accepted:    12.5K
 * Total Submissions: 27.2K
 * Testcase Example:  '[["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]'
 *
 * 给你一个二维字符网格数组 grid ，大小为 m x n ，你需要检查 grid 中是否存在 相同值 形成的环。
 * 
 * 一个环是一条开始和结束于同一个格子的长度 大于等于 4
 * 的路径。对于一个给定的格子，你可以移动到它上、下、左、右四个方向相邻的格子之一，可以移动的前提是这两个格子有 相同的值 。
 * 
 * 同时，你也不能回到上一次移动时所在的格子。比方说，环  (1, 1) -> (1, 2) -> (1, 1) 是不合法的，因为从 (1, 2) 移动到
 * (1, 1) 回到了上一次移动时的格子。
 * 
 * 如果 grid 中有相同值形成的环，请你返回 true ，否则返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：grid =
 * [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
 * 输出：true
 * 解释：如下图所示，有 2 个用不同颜色标出来的环：
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：grid =
 * [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
 * 输出：true
 * 解释：如下图所示，只有高亮所示的一个合法环：
 * 
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m <= 500
 * 1 <= n <= 500
 * grid 只包含小写英文字母。
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
    
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<uint8_t>> vis(m, vector<uint8_t>(n, 0));

        auto dfs = [&](this auto&& dfs, int i, int j, int fai, int faj) -> bool {
            if (vis[i][j]) {
                return true;
            }
            vis[i][j] = 1;
            for (auto& [dx, dy] : dirs) {
                int x = i + dx, y = j + dy;
                if (x == fai && y == faj) {
                    continue;
                }
                if (0 <= x && x < m && 0 <= y && y < n && grid[x][y] == grid[i][j]) {
                    if (dfs(x, y, i, j)) {
                        return true;
                    }
                }
            }
            return false;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0 && dfs(i, j, -1, -1)) {
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
// [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]\n
// @lcpr case=end

// @lcpr case=start
// [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]\n
// @lcpr case=end

// @lcpr case=start
// [["a","b","b"],["b","z","b"],["b","b","a"]]\n
// @lcpr case=end

 */

