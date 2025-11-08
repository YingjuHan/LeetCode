/*
 * @lc app=leetcode.cn id=3446 lang=cpp
 * @lcpr version=30204
 *
 * [3446] 按对角线进行矩阵排序
 *
 * https://leetcode.cn/problems/sort-matrix-by-diagonals/description/
 *
 * algorithms
 * Medium (85.76%)
 * Likes:    27
 * Dislikes: 0
 * Total Accepted:    15.6K
 * Total Submissions: 18.2K
 * Testcase Example:  '[[1,7,3],[9,8,2],[4,5,6]]'
 *
 * 给你一个大小为 n x n 的整数方阵 grid。返回一个经过如下调整的矩阵：
 * 
 * 
 * 左下角三角形（包括中间对角线）的对角线按 非递增顺序 排序。
 * 右上角三角形 的对角线按 非递减顺序 排序。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： grid = [[1,7,3],[9,8,2],[4,5,6]]
 * 
 * 输出： [[8,2,3],[9,6,7],[4,5,1]]
 * 
 * 解释：
 * 
 * 
 * 
 * 标有黑色箭头的对角线（左下角三角形）应按非递增顺序排序：
 * 
 * 
 * [1, 8, 6] 变为 [8, 6, 1]。
 * [9, 5] 和 [4] 保持不变。
 * 
 * 
 * 标有蓝色箭头的对角线（右上角三角形）应按非递减顺序排序：
 * 
 * 
 * [7, 2] 变为 [2, 7]。
 * [3] 保持不变。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： grid = [[0,1],[1,2]]
 * 
 * 输出： [[2,1],[1,0]]
 * 
 * 解释：
 * 
 * 
 * 
 * 标有黑色箭头的对角线必须按非递增顺序排序，因此 [0, 2] 变为 [2, 0]。其他对角线已经符合要求。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入： grid = [[1]]
 * 
 * 输出： [[1]]
 * 
 * 解释：
 * 
 * 只有一个元素的对角线已经符合要求，因此无需修改。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * grid.length == grid[i].length == n
 * 1 <= n <= 10
 * -10^5 <= grid[i][j] <= 10^5
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
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // 第一排在右上，最后一排在左下
        // 每排从左上到右下
        // 令 k=i-j+n，那么右上角 k=1，左下角 k=m+n-1
        for (int k = 1; k < m + n; k++) {
            // 核心：计算 j 的最小值和最大值
            int min_j = max(n - k, 0); // i=0 的时候，j=n-k，但不能是负数
            int max_j = min(m + n - 1 - k, n - 1); // i=m-1 的时候，j=m+n-1-k，但不能超过 n-1
            vector<int> a;
            for (int j = min_j; j <= max_j; j++) {
                a.push_back(grid[k + j - n][j]); // 根据 k 的定义得 i=k+j-n
            }
            if (min_j > 0) { // 右上角三角形
                ranges::sort(a);
            } else { // 左下角三角形（包括中间对角线）
                ranges::sort(a, greater<int>());
            }
            for (int j = min_j; j <= max_j; j++) {
                grid[k + j - n][j] = a[j - min_j];
            }
        }
        return grid;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,7,3],[9,8,2],[4,5,6]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1]]\n
// @lcpr case=end

 */

