/*
 * @lc app=leetcode.cn id=1277 lang=cpp
 * @lcpr version=30204
 *
 * [1277] 统计全为 1 的正方形子矩阵
 *
 * https://leetcode.cn/problems/count-square-submatrices-with-all-ones/description/
 *
 * algorithms
 * Medium (76.62%)
 * Likes:    388
 * Dislikes: 0
 * Total Accepted:    55.5K
 * Total Submissions: 72.4K
 * Testcase Example:  '[[0,1,1,1],[1,1,1,1],[0,1,1,1]]'
 *
 * 给你一个 m * n 的矩阵，矩阵中的元素不是 0 就是 1，请你统计并返回其中完全由 1 组成的 正方形 子矩阵的个数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：matrix =
 * [
 * [0,1,1,1],
 * [1,1,1,1],
 * [0,1,1,1]
 * ]
 * 输出：15
 * 解释： 
 * 边长为 1 的正方形有 10 个。
 * 边长为 2 的正方形有 4 个。
 * 边长为 3 的正方形有 1 个。
 * 正方形的总数 = 10 + 4 + 1 = 15.
 * 
 * 
 * 示例 2：
 * 
 * 输入：matrix = 
 * [
 * ⁠ [1,0,1],
 * ⁠ [1,1,0],
 * ⁠ [1,1,0]
 * ]
 * 输出：7
 * 解释：
 * 边长为 1 的正方形有 6 个。 
 * 边长为 2 的正方形有 1 个。
 * 正方形的总数 = 6 + 1 = 7.
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 300
 * 1 <= arr[0].length <= 300
 * 0 <= arr[i][j] <= 1
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
    // 统计 a 的长度为h的全 h 子数组的数目
    int countSquares(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int res = 0;
        for (int top = 0; top < m; top++) {
            vector<int> a(n);
            for (int bottom = top; bottom < m; bottom++) {
                int h = bottom - top + 1;
                int last = -1;
                for (int j = 0; j < n; j++) {
                    a[j] += mat[bottom][j];
                    if (a[j] != h) {
                        last = j; // 记录上一个非 h 元素的位置
                    } else {
                        if (j - last >= h) { // 右端点为j的长为h的字数组全是h
                            res++;
                        }
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,1,1],[1,1,1,1],[0,1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,1],[1,1,0],[1,1,0]]\n
// @lcpr case=end

 */

