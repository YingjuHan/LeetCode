/*
 * @lc app=leetcode.cn id=363 lang=cpp
 * @lcpr version=
 *
 * [363] 矩形区域不超过 K 的最大数值和
 *
 * https://leetcode.cn/problems/max-sum-of-rectangle-no-larger-than-k/description/
 *
 * algorithms
 * Hard (48.80%)
 * Likes:    522
 * Dislikes: 0
 * Total Accepted:    47.9K
 * Total Submissions: 97.8K
 * Testcase Example:  '[[1,0,1],[0,-2,3]]\n2'
 *
 * 给你一个 m x n 的矩阵 matrix 和一个整数 k ，找出并返回矩阵内部矩形区域的不超过 k 的最大数值和。
 * 
 * 题目数据保证总会存在一个数值和不超过 k 的矩形区域。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：matrix = [[1,0,1],[0,-2,3]], k = 2
 * 输出：2
 * 解释：蓝色边框圈出来的矩形区域 [[0, 1], [-2, 3]] 的数值和是 2，且 2 是不超过 k 的最大数字（k = 2）。
 * 
 * 
 * 示例 2：
 * 
 * 输入：matrix = [[2,2,-1]], k = 3
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -100 <= matrix[i][j] <= 100
 * -10^5 <= k <= 10^5
 * 
 * 
 * 
 * 
 * 进阶：如果行数远大于列数，该如何设计解决方案？
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
#include <set>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> matrixPreSum(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                matrixPreSum[i][j] = matrixPreSum[i][j - 1] + matrix[i - 1][j - 1];
            }
        }

        int res = INT_MIN;
        for (int l = 1; l <= n; l++) {
            for (int r = l; r <= n; r++) {
                multiset<int> st;
                st.insert(0);
                int curSum = 0;
                for (int i = 1; i <= m; i++) {
                    int curSumRow = matrixPreSum[i][r] - matrixPreSum[i][l - 1];
                    curSum += curSumRow;

                    // 对于当前的前缀和，找数中大于等于curSum-k的最小元素
                    // 设找到的数为p，则p大于等于curSum-k，再有curSum - p <= k
                    // 所有最小的p，使得curSum-p的值最大，且该值小于等于k
                    auto it = st.lower_bound(curSum - k);
                    if (it != st.end()) {
                        res = max(res, curSum - *it);
                    }
                    st.insert(curSum);
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,0,1],[0,-2,3]]\n2\n
// @lcpr case=end

// @lcpr case=start
// [[2,2,-1]]\n3\n
// @lcpr case=end

 */

