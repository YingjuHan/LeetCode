/*
 * @lc app=leetcode.cn id=1504 lang=cpp
 * @lcpr version=30204
 *
 * [1504] 统计全 1 子矩形
 *
 * https://leetcode.cn/problems/count-submatrices-with-all-ones/description/
 *
 * algorithms
 * Medium (69.81%)
 * Likes:    268
 * Dislikes: 0
 * Total Accepted:    29K
 * Total Submissions: 41.6K
 * Testcase Example:  '[[1,0,1],[1,1,0],[1,1,0]]'
 *
 * 给你一个 m x n 的二进制矩阵 mat ，请你返回有多少个 子矩形 的元素全部都是 1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：mat = [[1,0,1],[1,1,0],[1,1,0]]
 * 输出：13
 * 解释：
 * 有 6 个 1x1 的矩形。
 * 有 2 个 1x2 的矩形。
 * 有 3 个 2x1 的矩形。
 * 有 1 个 2x2 的矩形。
 * 有 1 个 3x1 的矩形。
 * 矩形数目总共 = 6 + 2 + 3 + 1 + 1 = 13 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
 * 输出：24
 * 解释：
 * 有 8 个 1x1 的子矩形。
 * 有 5 个 1x2 的子矩形。
 * 有 2 个 1x3 的子矩形。
 * 有 4 个 2x1 的子矩形。
 * 有 2 个 2x2 的子矩形。
 * 有 2 个 3x1 的子矩形。
 * 有 1 个 3x2 的子矩形。
 * 矩形数目总共 = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24 。
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= m, n <= 150
 * mat[i][j] 仅包含 0 或 1
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
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int res = 0;
        for (int top = 0; top < m; top++) {
            vector<int> a(n);
            for (int bottom = top; bottom < m; bottom++) {
                int h = bottom - top + 1;
                int last = -1;
                for (int j = 0; j < n; j++) {
                    // 统计 a 的全 h 子数组的数目
                    a[j] += mat[bottom][j]; // 把bottom一行加入a中
                    if (a[j] != h) {
                        last = j;
                    } else {
                        res += j - last;
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
// [[1,0,1],[1,1,0],[1,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,1,0],[0,1,1,1],[1,1,1,0]]\n
// @lcpr case=end

 */

