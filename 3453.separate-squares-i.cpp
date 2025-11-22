/*
 * @lc app=leetcode.cn id=3453 lang=cpp
 * @lcpr version=
 *
 * [3453] 分割正方形 I
 *
 * https://leetcode.cn/problems/separate-squares-i/description/
 *
 * algorithms
 * Medium (43.78%)
 * Likes:    12
 * Dislikes: 0
 * Total Accepted:    4.1K
 * Total Submissions: 9.2K
 * Testcase Example:  '[[0,0,1],[2,2,1]]'
 *
 * 给你一个二维整数数组 squares ，其中 squares[i] = [xi, yi, li] 表示一个与 x
 * 轴平行的正方形的左下角坐标和正方形的边长。
 * 
 * 找到一个最小的 y 坐标，它对应一条水平线，该线需要满足它以上正方形的总面积 等于 该线以下正方形的总面积。
 * 
 * 答案如果与实际答案的误差在 10^-5 以内，将视为正确答案。
 * 
 * 注意：正方形 可能会 重叠。重叠区域应该被 多次计数 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： squares = [[0,0,1],[2,2,1]]
 * 
 * 输出： 1.00000
 * 
 * 解释：
 * 
 * 
 * 
 * 任何在 y = 1 和 y = 2 之间的水平线都会有 1 平方单位的面积在其上方，1 平方单位的面积在其下方。最小的 y 坐标是 1。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： squares = [[0,0,2],[1,1,1]]
 * 
 * 输出： 1.16667
 * 
 * 解释：
 * 
 * 
 * 
 * 面积如下：
 * 
 * 
 * 线下的面积：7/6 * 2 (红色) + 1/6 (蓝色) = 15/6 = 2.5。
 * 线上的面积：5/6 * 2 (红色) + 5/6 (蓝色) = 15/6 = 2.5。
 * 
 * 
 * 由于线以上和线以下的面积相等，输出为 7/6 = 1.16667。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= squares.length <= 5 * 10^4
 * squares[i] = [xi, yi, li]
 * squares[i].length == 3
 * 0 <= xi, yi <= 10^9
 * 1 <= li <= 10^9
 * 所有正方形的总面积不超过 10^12。
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
#include <map>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long long total_area = 0;
        map<int, long long> diff;
        for (auto& square : squares) {
            int y = square[1], l = square[2];
            total_area += 1LL * l * l;
            diff[y] += l;
            diff[y + l] -= l;
        }

        long long area = 0, sum_l = 0;
        for (auto it = diff.begin();;) {
            auto [y, sl] = *it;
            int y2 = (++it)->first;
            sum_l += sl; // // 矩形底边长度之和
            area += sum_l * (y2 - y);
            if (area * 2 >= total_area) {
                return y2 - (area * 2 - total_area) / (sum_l * 2.0);
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0,1],[2,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,2],[1,1,1]]\n
// @lcpr case=end

 */

