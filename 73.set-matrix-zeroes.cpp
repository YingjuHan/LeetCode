/*
 * @lc app=leetcode.cn id=73 lang=cpp
 * @lcpr version=30204
 *
 * [73] 矩阵置零
 *
 * https://leetcode.cn/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (71.42%)
 * Likes:    1329
 * Dislikes: 0
 * Total Accepted:    717.3K
 * Total Submissions: 1M
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * 输出：[[1,0,1],[0,0,0],[1,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * 输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[0].length
 * 1 <= m, n <= 200
 * -2^31 <= matrix[i][j] <= 2^31 - 1
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
 * 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
 * 你能想出一个仅使用常量空间的解决方案吗？
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
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool first_row_has_zero = ranges::contains(matrix[0], 0); // 记录第一行是否包含 0
        bool first_col_has_zero = ranges::any_of(matrix, [](auto& row) { return row[0] == 0; }); // 记录第一列是否包含 0

        // 用第一列 matrix[i][0] 保存 row_has_zero[i]
        // 用第一行 matrix[0][j] 保存 col_has_zero[j]
        for (int i = 1; i < m; i++) { // 无需遍历第一行，如果 matrix[0][j] 本身是 0，那么相当于 col_has_zero[j] 已经是 true
            for (int j = 1; j < n; j++) { // 无需遍历第一列，如果 matrix[i][0] 本身是 0，那么相当于 row_has_zero[i] 已经是 true
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // 相当于 row_has_zero[i] = true
                    matrix[0][j] = 0; // 相当于 col_has_zero[j] = true
                }
            }
        }

        for (int i = 1; i < m; i++) { // 跳过第一行，留到最后修改
            for (int j = 1; j < n; j++) { // 跳过第一列，留到最后修改
                if (matrix[i][0] == 0 || matrix[0][j] == 0) { // i 行或 j 列有 0
                    matrix[i][j] = 0;
                }
            }
        }

        // 如果第一列一开始就包含 0，那么把第一列全变成 0
        if (first_col_has_zero) {
            for (auto& row : matrix) {
                row[0] = 0;
            }
        }

        // 如果第一行一开始就包含 0，那么把第一行全变成 0
        if (first_row_has_zero) {
            ranges::fill(matrix[0], 0);
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,1],[1,0,1],[1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,2,0],[3,4,5,2],[1,3,1,5]]\n
// @lcpr case=end

 */

