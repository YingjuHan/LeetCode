/*
 * @lc app=leetcode.cn id=1329 lang=cpp
 * @lcpr version=30204
 *
 * [1329] 将矩阵按对角线排序
 *
 * https://leetcode.cn/problems/sort-the-matrix-diagonally/description/
 *
 * algorithms
 * Medium (81.26%)
 * Likes:    145
 * Dislikes: 0
 * Total Accepted:    32K
 * Total Submissions: 39.3K
 * Testcase Example:  '[[3,3,1,1],[2,2,1,2],[1,1,1,2]]'
 *
 * 矩阵对角线 是一条从矩阵最上面行或者最左侧列中的某个元素开始的对角线，沿右下方向一直到矩阵末尾的元素。例如，矩阵 mat 有 6 行 3 列，从
 * mat[2][0] 开始的 矩阵对角线 将会经过 mat[2][0]、mat[3][1] 和 mat[4][2] 。
 * 
 * 给你一个 m * n 的整数矩阵 mat ，请你将同一条 矩阵对角线 上的元素按升序排序后，返回排好序的矩阵。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
 * 输出：[[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 * 
 * 
 * 示例 2：
 * 
 * 输入：mat =
 * [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
 * 
 * 输出：[[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 100
 * 1 <= mat[i][j] <= 100
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
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        vector<int> temp(min(m, n));

        // 令k = i - j, min_k = 1 - n, max_k = m - 1
        for (int k = 1 - n; k <= m - 1; k++) {
            int min_i = max(k, 0);
            int max_i = min(k + n - 1, m - 1);

            for (int i = min_i; i <= max_i; i++) {
                temp[i - min_i] = mat[i][i - k];
            }
            sort(temp.begin(), temp.end(), greater<int>());
            for (int i = min_i; i <= max_i; i++) {
                res[i][i - k] = temp[i - min_i];
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[3,3,1,1],[2,2,1,2],[1,1,1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]\n
// @lcpr case=end

 */

