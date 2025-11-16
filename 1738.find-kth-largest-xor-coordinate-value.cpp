/*
 * @lc app=leetcode.cn id=1738 lang=cpp
 * @lcpr version=
 *
 * [1738] 找出第 K 大的异或坐标值
 *
 * https://leetcode.cn/problems/find-kth-largest-xor-coordinate-value/description/
 *
 * algorithms
 * Medium (68.33%)
 * Likes:    136
 * Dislikes: 0
 * Total Accepted:    48.3K
 * Total Submissions: 70.6K
 * Testcase Example:  '[[5,2],[1,6]]\n1'
 *
 * 给你一个二维矩阵 matrix 和一个整数 k ，矩阵大小为 m x n 由非负整数组成。
 * 
 * 矩阵中坐标 (a, b) 的 目标值 可以通过对所有元素 matrix[i][j] 执行异或运算得到，其中 i 和 j 满足 0 <= i <= a <
 * m 且 0 <= j <= b < n（下标从 0 开始计数）。
 * 
 * 请你找出 matrix 的所有坐标中第 k 大的目标值（k 的值从 1 开始计数）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：matrix = [[5,2],[1,6]], k = 1
 * 输出：7
 * 解释：坐标 (0,1) 的目标值是 5 XOR 2 = 7 ，为最大的目标值。
 * 
 * 示例 2：
 * 
 * 输入：matrix = [[5,2],[1,6]], k = 2
 * 输出：5
 * 解释：坐标 (0,0) 的目标值是 5 = 5 ，为第 2 大的目标值。
 * 
 * 示例 3：
 * 
 * 输入：matrix = [[5,2],[1,6]], k = 3
 * 输出：4
 * 解释：坐标 (1,0) 的目标值是 5 XOR 1 = 4 ，为第 3 大的目标值。
 * 
 * 示例 4：
 * 
 * 输入：matrix = [[5,2],[1,6]], k = 4
 * 输出：0
 * 解释：坐标 (1,1) 的目标值是 5 XOR 2 XOR 1 XOR 6 = 0 ，为第 4 大的目标值。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 1000
 * 0 <= matrix[i][j] <= 10^6
 * 1 <= k <= m * n
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
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> s(m + 1, vector<int>(n + 1));
        vector<int> xors;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                s[i + 1][j + 1] = s[i + 1][j] ^ s[i][j + 1] ^ s[i][j] ^ matrix[i][j];
                xors.push_back(s[i + 1][j + 1]);
            }
        }
        sort(xors.begin(), xors.end(), greater<int>());
        return xors[k - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[5,2],[1,6]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[5,2],[1,6]]\n2\n
// @lcpr case=end

// @lcpr case=start
// [[5,2],[1,6]]\n3\n
// @lcpr case=end

// @lcpr case=start
// [[5,2],[1,6]]\n4\n
// @lcpr case=end

 */

