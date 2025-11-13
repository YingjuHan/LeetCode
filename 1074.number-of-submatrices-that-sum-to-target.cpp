/*
 * @lc app=leetcode.cn id=1074 lang=cpp
 * @lcpr version=
 *
 * [1074] 元素和为目标值的子矩阵数量
 *
 * https://leetcode.cn/problems/number-of-submatrices-that-sum-to-target/description/
 *
 * algorithms
 * Hard (68.30%)
 * Likes:    255
 * Dislikes: 0
 * Total Accepted:    24.6K
 * Total Submissions: 36K
 * Testcase Example:  '[[0,1,0],[1,1,1],[0,1,0]]\n0'
 *
 * 给出矩阵 matrix 和目标值 target，返回元素总和等于目标值的非空子矩阵的数量。
 * 
 * 子矩阵 x1, y1, x2, y2 是满足 x1 <= x <= x2 且 y1 <= y <= y2 的所有单元 matrix[x][y]
 * 的集合。
 * 
 * 如果 (x1, y1, x2, y2) 和 (x1', y1', x2', y2') 两个子矩阵中部分坐标不同（如：x1 !=
 * x1'），那么这两个子矩阵也不同。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
 * 输出：4
 * 解释：四个只含 0 的 1x1 子矩阵。
 * 
 * 
 * 示例 2：
 * 
 * 输入：matrix = [[1,-1],[-1,1]], target = 0
 * 输出：5
 * 解释：两个 1x2 子矩阵，加上两个 2x1 子矩阵，再加上一个 2x2 子矩阵。
 * 
 * 
 * 示例 3：
 * 
 * 输入：matrix = [[904]], target = 0
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= matrix.length <= 100
 * 1 <= matrix[0].length <= 100
 * -1000 <= matrix[i][j] <= 1000
 * -10^8 <= target <= 10^8
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
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        auto subarraySum = [](vector<int>& nums, int target) {
            int res = 0, s = 0;
            unordered_map<int, int> cnt;
            for (int x : nums) {
                cnt[s]++;
                s += x;
                res += cnt.count(s - target) > 0 ? cnt[s - target] : 0;
            }
            return res;
        };

        int res = 0;
        for (int i1 = 0; i1 < m; i1++) {
            vector<int> col_sum(n);
            for (int i2 = i1; i2 < m; i2++) {
                for (int j = 0; j < n; j++) {
                    col_sum[j] += matrix[i2][j];
                }
                res += subarraySum(col_sum, target);
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,0],[1,1,1],[0,1,0]]\n0\n
// @lcpr case=end

// @lcpr case=start
// [[1,-1],[-1,1]]\n0\n
// @lcpr case=end

// @lcpr case=start
// [[904]]\n0\n
// @lcpr case=end

 */

