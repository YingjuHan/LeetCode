/*
 * @lc app=leetcode.cn id=1981 lang=cpp
 * @lcpr version=30204
 *
 * [1981] 最小化目标值与所选元素的差
 *
 * https://leetcode.cn/problems/minimize-the-difference-between-target-and-chosen-elements/description/
 *
 * algorithms
 * Medium (38.15%)
 * Likes:    93
 * Dislikes: 0
 * Total Accepted:    13.2K
 * Total Submissions: 34K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]\n13'
 *
 * 给你一个大小为 m x n 的整数矩阵 mat 和一个整数 target 。
 * 
 * 从矩阵的 每一行 中选择一个整数，你的目标是 最小化 所有选中元素之 和 与目标值 target 的 绝对差 。
 * 
 * 返回 最小的绝对差 。
 * 
 * a 和 b 两数字的 绝对差 是 a - b 的绝对值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：mat = [[1,2,3],[4,5,6],[7,8,9]], target = 13
 * 输出：0
 * 解释：一种可能的最优选择方案是：
 * - 第一行选出 1
 * - 第二行选出 5
 * - 第三行选出 7
 * 所选元素的和是 13 ，等于目标值，所以绝对差是 0 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：mat = [[1],[2],[3]], target = 100
 * 输出：94
 * 解释：唯一一种选择方案是：
 * - 第一行选出 1
 * - 第二行选出 2
 * - 第三行选出 3
 * 所选元素的和是 6 ，绝对差是 94 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：mat = [[1,2,9,8,7]], target = 6
 * 输出：1
 * 解释：最优的选择方案是选出第一行的 7 。
 * 绝对差是 1 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 70
 * 1 <= mat[i][j] <= 70
 * 1 <= target <= 800
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
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();
        int ans = INT_MAX;
        int maxSum = 0;
        for (auto &row : mat) {
            maxSum += *max_element(row.begin(), row.end());
        }
        vector<uint8_t> f(maxSum + 1, 0), nf(maxSum + 1, 0);
        f[0] = 1;

        for (auto& row : mat) {
            fill(nf.begin(), nf.end(), 0);
            for (int s = 0; s <= maxSum; s++) {
                if (f[s]) {
                    for (int v : row) {
                        nf[s + v] = 1;
                    }
                }
            }
            f.swap(nf);
        }

        for (int s = 0; s <= maxSum; s++) {
            if (f[s]) {
                ans = min(ans, abs(s - target));
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n13\n
// @lcpr case=end

// @lcpr case=start
// [[1],[2],[3]]\n100\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,9,8,7]]\n6\n
// @lcpr case=end

 */

