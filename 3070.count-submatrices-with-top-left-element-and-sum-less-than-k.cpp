/*
 * @lc app=leetcode.cn id=3070 lang=cpp
 * @lcpr version=
 *
 * [3070] 元素和小于等于 k 的子矩阵的数目
 *
 * https://leetcode.cn/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/description/
 *
 * algorithms
 * Medium (64.07%)
 * Likes:    9
 * Dislikes: 0
 * Total Accepted:    9K
 * Total Submissions: 14K
 * Testcase Example:  '[[7,6,3],[6,6,1]]\n18'
 *
 * 给你一个下标从 0 开始的整数矩阵 grid 和一个整数 k。
 * 
 * 返回包含 grid 左上角元素、元素和小于或等于 k 的 子矩阵的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：grid = [[7,6,3],[6,6,1]], k = 18
 * 输出：4
 * 解释：如上图所示，只有 4 个子矩阵满足：包含 grid 的左上角元素，并且元素和小于或等于 18 。
 * 
 * 示例 2：
 * 
 * 输入：grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
 * 输出：6
 * 解释：如上图所示，只有 6 个子矩阵满足：包含 grid 的左上角元素，并且元素和小于或等于 20 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length 
 * n == grid[i].length
 * 1 <= n, m <= 1000 
 * 0 <= grid[i][j] <= 1000
 * 1 <= k <= 10^9
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
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
                ans += sum[i + 1][j + 1] <= k;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[7,6,3],[6,6,1]]\n18\n
// @lcpr case=end

// @lcpr case=start
// [[7,2,9],[1,5,0],[2,6,6]]\n20\n
// @lcpr case=end

 */

