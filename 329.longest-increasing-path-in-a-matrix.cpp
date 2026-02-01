/*
 * @lc app=leetcode.cn id=329 lang=cpp
 * @lcpr version=
 *
 * [329] 矩阵中的最长递增路径
 *
 * https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (53.38%)
 * Likes:    929
 * Dislikes: 0
 * Total Accepted:    130.8K
 * Total Submissions: 244.4K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * 给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。
 * 
 * 对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
 * 输出：4 
 * 解释：最长递增路径为 [1, 2, 6, 9]。
 * 
 * 示例 2：
 * 
 * 输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
 * 输出：4 
 * 解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
 * 
 * 
 * 示例 3：
 * 
 * 输入：matrix = [[1]]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 200
 * 0 <= matrix[i][j] <= 2^31 - 1
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
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        int ans = 0;
        
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (memo[i][j] != 0) {
                return memo[i][j];
            }

            memo[i][j]++;
            for (auto& [dx, dy] : DIRS) {
                int x = i + dx, y = j + dy;
                if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                    memo[i][j] = max(memo[i][j], dfs(x, y) + 1);
                } 
            }
            return memo[i][j];
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> f(m, vector<int>(n, 1));
        vector<array<int, 3>> vp;
        vp.reserve(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vp.push_back({i, j, matrix[i][j]});
            }
        }
        sort(vp.begin(), vp.end(), [](const array<int, 3>& a, const array<int, 3>& b) {
            return a[2] < b[2];
        });

        int res = 1;
        for (const auto& p : vp) {
            int x = p[0], y = p[1], v = p[2];
            if (x < 0 || y < 0 || x >= m - 1 || y >= n - 1) {
                continue;
            }
            if (matrix[x - 1][y] < v && f[x - 1][y] + 1 > f[x][y]) {
                f[x][y] = f[x - 1][y] + 1;
            }
            if (matrix[x + 1][y] < v && f[x + 1][y] + 1 > f[x][y]) {
                f[x][y] = f[x + 1][y] + 1;
            }
            if (matrix[x][y - 1] < v && f[x][y - 1] + 1 > f[x][y]) {
                f[x][y] = f[x][y - 1] + 1;
            }
            if (matrix[x][y + 1] < v && f[x][y + 1] + 1 > f[x][y]) {
                f[x][y] = f[x][y + 1] + 1;
            }
            res = max(f[x][y], res);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[9,9,4],[6,6,8],[2,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,4,5],[3,2,6],[2,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1]]\n
// @lcpr case=end

 */

