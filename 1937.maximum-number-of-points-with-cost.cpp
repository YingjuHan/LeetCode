/*
 * @lc app=leetcode.cn id=1937 lang=cpp
 * @lcpr version=30204
 *
 * [1937] 扣分后的最大得分
 *
 * https://leetcode.cn/problems/maximum-number-of-points-with-cost/description/
 *
 * algorithms
 * Medium (34.20%)
 * Likes:    165
 * Dislikes: 0
 * Total Accepted:    9.5K
 * Total Submissions: 27.6K
 * Testcase Example:  '[[1,2,3],[1,5,1],[3,1,1]]'
 *
 * 给你一个 m x n 的整数矩阵 points （下标从 0 开始）。一开始你的得分为 0 ，你想最大化从矩阵中得到的分数。
 * 
 * 你的得分方式为：每一行 中选取一个格子，选中坐标为 (r, c) 的格子会给你的总得分 增加 points[r][c] 。
 * 
 * 然而，相邻行之间被选中的格子如果隔得太远，你会失去一些得分。对于相邻行 r 和 r + 1 （其中 0 <= r < m - 1），选中坐标为 (r,
 * c1) 和 (r + 1, c2) 的格子，你的总得分 减少 abs(c1 - c2) 。
 * 
 * 请你返回你能得到的 最大 得分。
 * 
 * abs(x) 定义为：
 * 
 * 
 * 如果 x >= 0 ，那么值为 x 。
 * 如果 x < 0 ，那么值为 -x 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：points = [[1,2,3],[1,5,1],[3,1,1]]
 * 输出：9
 * 解释：
 * 蓝色格子是最优方案选中的格子，坐标分别为 (0, 2)，(1, 1) 和 (2, 0) 。
 * 你的总得分增加 3 + 5 + 3 = 11 。
 * 但是你的总得分需要扣除 abs(2 - 1) + abs(1 - 0) = 2 。
 * 你的最终得分为 11 - 2 = 9 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：points = [[1,5],[2,3],[4,2]]
 * 输出：11
 * 解释：
 * 蓝色格子是最优方案选中的格子，坐标分别为 (0, 1)，(1, 1) 和 (2, 0) 。
 * 你的总得分增加 5 + 3 + 4 = 12 。
 * 但是你的总得分需要扣除 abs(1 - 1) + abs(1 - 0) = 1 。
 * 你的最终得分为 12 - 1 = 11 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == points.length
 * n == points[r].length
 * 1 <= m, n <= 10^5
 * 1 <= m * n <= 10^5
 * 0 <= points[r][c] <= 10^5
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
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<vector<long long>> f(m, vector<long long>(n, 0LL));
        vector<long long> leftmax(n, 0), rightmax(n, 0);
        for (int j = 0; j < n; j++) {
            f[0][j] = points[0][j];
            leftmax[j] = j == 0 ? f[0][j] + j : max(leftmax[j - 1], f[0][j] + j);
        }
        for (int j = n - 1; j >= 0; j--) {
            rightmax[j] = j == n - 1 ? f[0][j] - j : max(rightmax[j + 1], f[0][j] - j);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                f[i][j] = points[i][j] + max(leftmax[j] - j, rightmax[j] + j);
                leftmax[j] = j == 0 ? f[i][j] + j : max(leftmax[j - 1], f[i][j] + j);
            }
            for (int j = n - 1; j >= 0; j--) {
                rightmax[j] = j == n - 1 ? f[i][j] - j : max(rightmax[j + 1], f[i][j] - j);
            }
        }
        return *max_element(f[m - 1].begin(), f[m - 1].end());
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[1,5,1],[3,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,5],[2,3],[4,2]]\n
// @lcpr case=end

 */

