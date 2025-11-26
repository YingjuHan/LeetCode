/*
 * @lc app=leetcode.cn id=221 lang=cpp
 * @lcpr version=30204
 *
 * [221] 最大正方形
 *
 * https://leetcode.cn/problems/maximal-square/description/
 *
 * algorithms
 * Medium (51.76%)
 * Likes:    1849
 * Dislikes: 0
 * Total Accepted:    426.7K
 * Total Submissions: 824.4K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 输入：matrix = [["0","1"],["1","0"]]
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 输入：matrix = [["0"]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 300
 * matrix[i][j] 为 '0' 或 '1'
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
    int largestSize(vector<int> heights) {
        stack<int> st;
        heights.push_back(-1);
        st.push(-1);
        int res = 0;
        for (int right = 0; right < heights.size(); right++) {
            int h = heights[right];
            while (st.size() > 1 && heights[st.top()] >= h) {
                int i = st.top();
                st.pop();
                int left = st.top();
                res = max(res, min(heights[i], right - left - 1));
            }
            st.push(right);
        }
        return res;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        int res = 0;
        vector<int> heights(n);
        for (auto& row : matrix) {
            for (int j = 0; j < n; j++) {
                if (row[j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            res = max(res, largestSize(heights));
        }
        return res * res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["0","1"],["1","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["0"]]\n
// @lcpr case=end

 */

