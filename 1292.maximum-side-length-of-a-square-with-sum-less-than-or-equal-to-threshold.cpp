/*
 * @lc app=leetcode.cn id=1292 lang=cpp
 * @lcpr version=
 *
 * [1292] 元素和小于等于阈值的正方形的最大边长
 *
 * https://leetcode.cn/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/
 *
 * algorithms
 * Medium (53.14%)
 * Likes:    130
 * Dislikes: 0
 * Total Accepted:    15.3K
 * Total Submissions: 28.6K
 * Testcase Example:  '[[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]]\n4'
 *
 * 给你一个大小为 m x n 的矩阵 mat 和一个整数阈值 threshold。
 * 
 * 请你返回元素总和小于或等于阈值的正方形区域的最大边长；如果没有这样的正方形区域，则返回 0 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
 * 输出：2
 * 解释：总和小于或等于 4 的正方形的最大边长为 2，如图所示。
 * 
 * 
 * 示例 2：
 * 
 * 输入：mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]],
 * threshold = 1
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 300
 * 0 <= mat[i][j] <= 10^4
 * 0 <= threshold <= 10^5^ 
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
    int getRect(vector<vector<int>>& s, int x1, int y1, int x2, int y2) {
        return s[x2][y2] - s[x2][y1 -1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> s(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + mat[i][j];
            }
        }

        int res = 0;
        int l = 1, r = min(m, n);
        while (l <= r) {
            int mid = l + (r - l) / 2;
            bool find = false;
            for (int i = 1; i <= m - mid + 1; i++) {
                for (int j = 1; j <= n - mid + 1; j++) {
                    if (getRect(s, i, j, i + mid - 1, j + mid - 1) <= threshold) {
                        find = true;
                    }
                }
            }

            if (find) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]]\n1\n
// @lcpr case=end

 */

