/*
 * @lc app=leetcode.cn id=3212 lang=cpp
 * @lcpr version=
 *
 * [3212] 统计 X 和 Y 频数相等的子矩阵数量
 *
 * https://leetcode.cn/problems/count-submatrices-with-equal-frequency-of-x-and-y/description/
 *
 * algorithms
 * Medium (52.55%)
 * Likes:    7
 * Dislikes: 0
 * Total Accepted:    7.1K
 * Total Submissions: 13.5K
 * Testcase Example:  '[["X","Y","."],["Y",".","."]]'
 *
 * 给你一个二维字符矩阵 grid，其中 grid[i][j] 可能是 'X'、'Y' 或 '.'，返回满足以下条件的子矩阵数量：
 * 
 * 
 * 包含 grid[0][0]
 * 'X' 和 'Y' 的频数相等。
 * 至少包含一个 'X'。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： grid = [["X","Y","."],["Y",".","."]]
 * 
 * 输出： 3
 * 
 * 解释：
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： grid = [["X","X"],["X","Y"]]
 * 
 * 输出： 0
 * 
 * 解释：
 * 
 * 不存在满足 'X' 和 'Y' 频数相等的子矩阵。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入： grid = [[".","."],[".","."]]
 * 
 * 输出： 0
 * 
 * 解释：
 * 
 * 不存在满足至少包含一个 'X' 的子矩阵。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= grid.length, grid[i].length <= 1000
 * grid[i][j] 可能是 'X'、'Y' 或 '.'.
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
    int numberOfSubmatrices(vector<vector<char>>& grid) {\
        int res = 0, m = grid.size(), n = grid[0].size();
        vector<vector<array<int, 2>>> sum(m + 1, vector<array<int, 2>>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i + 1][j + 1][0] = sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0];
                sum[i + 1][j + 1][1] = sum[i + 1][j][1] + sum[i][j + 1][1] - sum[i][j][1];
                if (grid[i][j] == 'X') {
                    sum[i + 1][j + 1][1]++;
                } else if (grid[i][j] == 'Y') {
                    sum[i + 1][j + 1][0]++;
                }
                if (sum[i + 1][j + 1][0] > 0 && sum[i + 1][j + 1][1] == sum[i + 1][j + 1][0]) {
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
// [["X","Y","."],["Y",".","."]]\n
// @lcpr case=end

// @lcpr case=start
// [["X","X"],["X","Y"]]\n
// @lcpr case=end

// @lcpr case=start
// [[".","."],[".","."]]\n
// @lcpr case=end

 */

