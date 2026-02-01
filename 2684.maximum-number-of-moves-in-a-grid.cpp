/*
 * @lc app=leetcode.cn id=2684 lang=cpp
 * @lcpr version=30204
 *
 * [2684] 矩阵中移动的最大次数
 *
 * https://leetcode.cn/problems/maximum-number-of-moves-in-a-grid/description/
 *
 * algorithms
 * Medium (50.23%)
 * Likes:    90
 * Dislikes: 0
 * Total Accepted:    39.6K
 * Total Submissions: 78.8K
 * Testcase Example:  '[[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]'
 *
 * 给你一个下标从 0 开始、大小为 m x n 的矩阵 grid ，矩阵由若干 正 整数组成。
 * 
 * 你可以从矩阵第一列中的 任一 单元格出发，按以下方式遍历 grid ：
 * 
 * 
 * 从单元格 (row, col) 可以移动到 (row - 1, col + 1)、(row, col + 1) 和 (row + 1, col + 1)
 * 三个单元格中任一满足值 严格 大于当前单元格的单元格。
 * 
 * 
 * 返回你在矩阵中能够 移动 的 最大 次数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
 * 输出：3
 * 解释：可以从单元格 (0, 0) 开始并且按下面的路径移动：
 * - (0, 0) -> (0, 1).
 * - (0, 1) -> (1, 2).
 * - (1, 2) -> (2, 3).
 * 可以证明这是能够移动的最大次数。
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [[3,2,4],[2,1,9],[1,1,7]]
 * 输出：0
 * 解释：从第一列的任一单元格开始都无法移动。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 2 <= m, n <= 1000
 * 4 <= m * n <= 10^5
 * 1 <= grid[i][j] <= 10^6
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
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        function<void(int, int)> dfs = [&](int i, int j) {
            ans = max(ans, j);
            if (ans == n - 1) {
                return;
            }

            for (int k = max(i - 1, 0); k < min(i + 2, m); k++) {
                if (grid[k][j + 1] > grid[i][j]) {
                    dfs(k, j + 1);
                }
            }
            grid[i][j] = 0;
        };
        for (int i = 0; i < m; i++) {
            dfs(i, 0);
        }
        return ans;
    }
};

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int j = n - 2; j >= 0; j--) {
            for (int i = 0; i < m; i++) {
                if (i > 0 && grid[i - 1][j + 1] > grid[i][j]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + 1);
                }
                if (grid[i][j] < grid[i][j + 1]) {
                    dp[i][j] = max(dp[i][j], dp[i][j + 1] + 1);
                }
                if (i < m - 1 && grid[i][j] < grid[i + 1][j + 1]) {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + 1);
                }
                if (j == 0) {
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,2,4],[2,1,9],[1,1,7]]\n
// @lcpr case=end

 */

