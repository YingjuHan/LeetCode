/*
 * @lc app=leetcode.cn id=498 lang=cpp
 * @lcpr version=30204
 *
 * [498] 对角线遍历
 *
 * https://leetcode.cn/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (57.66%)
 * Likes:    548
 * Dislikes: 0
 * Total Accepted:    159.8K
 * Total Submissions: 277.1K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,4,7,5,3,6,8,9]
 * 
 * 
 * 示例 2：
 * 
 * 输入：mat = [[1,2],[3,4]]
 * 输出：[1,2,3,4]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 10^4
 * 1 <= m * n <= 10^4
 * -10^5 <= mat[i][j] <= 10^5
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
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;

        // 令 k = i + j
        for (int k = 0; k <= m + n - 2; k++) {
            int min_j = max(k - m + 1, 0);
            int max_j = min(k, n - 1);
            if (k % 2 == 0) {
                for (int j = min_j; j <= max_j; j++) {
                    res.push_back(mat[k - j][j]);
                }
            } else {
                for (int j = max_j; j >= min_j; j--) {
                    res.push_back(mat[k - j][j]);
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,4]]\n
// @lcpr case=end

 */

