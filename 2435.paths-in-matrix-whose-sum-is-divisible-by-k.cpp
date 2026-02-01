/*
 * @lc app=leetcode.cn id=2435 lang=cpp
 * @lcpr version=30204
 *
 * [2435] 矩阵中和能被 K 整除的路径
 *
 * https://leetcode.cn/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description/
 *
 * algorithms
 * Hard (60.29%)
 * Likes:    100
 * Dislikes: 0
 * Total Accepted:    24.1K
 * Total Submissions: 40K
 * Testcase Example:  '[[5,2,4],[3,0,5],[0,7,2]]\n3'
 *
 * 给你一个下标从 0 开始的 m x n 整数矩阵 grid 和一个整数 k 。你从起点 (0, 0) 出发，每一步只能往 下 或者往 右
 * ，你想要到达终点 (m - 1, n - 1) 。
 * 
 * 请你返回路径和能被 k 整除的路径数目，由于答案可能很大，返回答案对 10^9 + 7 取余 的结果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
 * 输出：2
 * 解释：有两条路径满足路径上元素的和能被 k 整除。
 * 第一条路径为上图中用红色标注的路径，和为 5 + 2 + 4 + 5 + 2 = 18 ，能被 3 整除。
 * 第二条路径为上图中用蓝色标注的路径，和为 5 + 3 + 0 + 5 + 2 = 15 ，能被 3 整除。
 * 
 * 
 * 示例 2：
 * 
 * 输入：grid = [[0,0]], k = 5
 * 输出：1
 * 解释：红色标注的路径和为 0 + 0 = 0 ，能被 5 整除。
 * 
 * 
 * 示例 3：
 * 
 * 输入：grid = [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1
 * 输出：10
 * 解释：每个数字都能被 1 整除，所以每一条路径的和都能被 k 整除。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 5 * 10^4
 * 1 <= m * n <= 5 * 10^4
 * 0 <= grid[i][j] <= 100
 * 1 <= k <= 50
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
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        constexpr int MOD = 1'000'000'007;
        int m = grid.size(), n = grid[0].size();

        vector f(m + 1, vector(n + 1, vector<int>(k, 0)));
        f[0][1][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int s = 0; s < k; s++) {
                    int new_s = (s + grid[i][j]) % k;
                    f[i + 1][j + 1][new_s] =
                        (f[i + 1][j + 1][new_s] + f[i][j + 1][s] + f[i + 1][j][s]) % MOD;
                }
            }
        }
        return f[m][n][0];
    }
};

// @lc code=end



/*
// @lcpr case=start
// [[5,2,4],[3,0,5],[0,7,2]]\n3\n
// @lcpr case=end

// @lcpr case=start
// [[0,0]]\n5\n
// @lcpr case=end

// @lcpr case=start
// [[7,3,4,9],[2,3,6,2],[2,3,7,0]]\n1\n
// @lcpr case=end

 */

