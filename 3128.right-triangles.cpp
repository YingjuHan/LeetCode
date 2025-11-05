/*
 * @lc app=leetcode.cn id=3128 lang=cpp
 * @lcpr version=30204
 *
 * [3128] 直角三角形
 *
 * https://leetcode.cn/problems/right-triangles/description/
 *
 * algorithms
 * Medium (67.40%)
 * Likes:    55
 * Dislikes: 0
 * Total Accepted:    25.8K
 * Total Submissions: 38.2K
 * Testcase Example:  '[[0,1,0],[0,1,1],[0,1,0]]'
 *
 * 给你一个二维 boolean 矩阵 grid 。
 * 
 * 如果 grid 的 3 个元素的集合中，一个元素与另一个元素在 同一行，并且与第三个元素在 同一列，则该集合是一个 直角三角形。3 个元素 不必
 * 彼此相邻。
 * 
 * 请你返回使用 grid 中的 3 个元素可以构建的 直角三角形 数目，且满足 3 个元素值 都 为 1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 
 * 0
 * 1
 * 0
 * 
 * 
 * 0
 * 1
 * 1
 * 
 * 
 * 0
 * 1
 * 0
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 0
 * 1
 * 0
 * 
 * 
 * 0
 * 1
 * 1
 * 
 * 
 * 0
 * 1
 * 0
 * 
 * 
 * 
 * 
 * 
 * 
 * 输入：grid = [[0,1,0],[0,1,1],[0,1,0]]
 * 
 * 输出：2
 * 
 * 解释：
 * 
 * 有 2 个值为 1 的直角三角形。注意蓝色的那个 没有 组成直角三角形，因为 3 个元素在同一列。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 
 * 1
 * 0
 * 0
 * 0
 * 
 * 
 * 0
 * 1
 * 0
 * 1
 * 
 * 
 * 1
 * 0
 * 0
 * 0
 * 
 * 
 * 
 * 
 * 
 * 
 * 输入：grid = [[1,0,0,0],[0,1,0,1],[1,0,0,0]]
 * 
 * 输出：0
 * 
 * 解释：
 * 
 * 没有值为 1 的直角三角形。注意蓝色的那个 没有 组成直角三角形。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 
 * 
 * 1
 * 0
 * 1
 * 
 * 
 * 1
 * 0
 * 0
 * 
 * 
 * 1
 * 0
 * 0
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 1
 * 0
 * 1
 * 
 * 
 * 1
 * 0
 * 0
 * 
 * 
 * 1
 * 0
 * 0
 * 
 * 
 * 
 * 
 * 
 * 
 * 输入：grid = [[1,0,1],[1,0,0],[1,0,0]]
 * 
 * 输出：2
 * 
 * 解释：
 * 
 * 有两个值为 1 的直角三角形。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= grid.length <= 1000
 * 1 <= grid[i].length <= 1000
 * 0 <= grid[i][j] <= 1
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    /**
     * 有三个顶点，枚举「中间」的直角顶点更容易计算。
     * 
     * 三角形个数 = (col_sum - 1) * (row_sum - 1) col_sum和row_sum为纵向1和横向1的个数
     */
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long res = 0;
        vector<int> col_sum(n, -1); // 提前减一
        for (auto& row : grid) {
            for (int i = 0; i < n; i++) {
                col_sum[i] += row[i];
            }
        }

        for (auto& row : grid) {
            int row_sum = accumulate(row.begin(), row.end(), -1); // 提前减一
            for (int j = 0; j < n; j++) {
                if (row[j] == 1) {
                    res += row_sum * col_sum[j];
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,0],[0,1,1],[0,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0,0],[0,1,0,1],[1,0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,1],[1,0,0],[1,0,0]]\n
// @lcpr case=end

 */

