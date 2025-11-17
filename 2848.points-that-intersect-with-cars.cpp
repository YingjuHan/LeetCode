/*
 * @lc app=leetcode.cn id=2848 lang=cpp
 * @lcpr version=
 *
 * [2848] 与车相交的点
 *
 * https://leetcode.cn/problems/points-that-intersect-with-cars/description/
 *
 * algorithms
 * Easy (77.05%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    31.7K
 * Total Submissions: 41.2K
 * Testcase Example:  '[[3,6],[1,5],[4,7]]'
 *
 * 给你一个下标从 0 开始的二维整数数组 nums 表示汽车停放在数轴上的坐标。对于任意下标 i，nums[i] = [starti, endi] ，其中
 * starti 是第 i 辆车的起点，endi 是第 i 辆车的终点。
 * 
 * 返回数轴上被车 任意部分 覆盖的整数点的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [[3,6],[1,5],[4,7]]
 * 输出：7
 * 解释：从 1 到 7 的所有点都至少与一辆车相交，因此答案为 7 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [[1,3],[5,8]]
 * 输出：7
 * 解释：1、2、3、5、6、7、8 共计 7 个点满足至少与一辆车相交，因此答案为 7 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 100
 * nums[i].length == 2
 * 1 <= starti <= endi <= 100
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
    int numberOfPoints(vector<vector<int>>& nums) {
        auto it = max_element(nums.begin(), nums.end(),
            [](const auto&a, const auto& b) {
                return a[1] < b[1];
            });
        int max_end = (*it)[1];

        vector<int> diff(max_end + 2);
        for (auto& interval : nums) {
            diff[interval[0]]++;
            diff[interval[1] + 1]--;
        }
        int res = 0, s = 0;
        for (int d : diff) {
            s += d;
            res += s > 0;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[3,6],[1,5],[4,7]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[5,8]]\n
// @lcpr case=end

 */

