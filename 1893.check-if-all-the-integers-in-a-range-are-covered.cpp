/*
 * @lc app=leetcode.cn id=1893 lang=cpp
 * @lcpr version=
 *
 * [1893] 检查是否区域内所有整数都被覆盖
 *
 * https://leetcode.cn/problems/check-if-all-the-integers-in-a-range-are-covered/description/
 *
 * algorithms
 * Easy (59.51%)
 * Likes:    158
 * Dislikes: 0
 * Total Accepted:    47.2K
 * Total Submissions: 79.2K
 * Testcase Example:  '[[1,2],[3,4],[5,6]]\n2\n5'
 *
 * 给你一个二维整数数组 ranges 和两个整数 left 和 right 。每个 ranges[i] = [starti, endi] 表示一个从
 * starti 到 endi 的 闭区间 。
 * 
 * 如果闭区间 [left, right] 内每个整数都被 ranges 中 至少一个 区间覆盖，那么请你返回 true ，否则返回 false 。
 * 
 * 已知区间 ranges[i] = [starti, endi] ，如果整数 x 满足 starti <= x <= endi ，那么我们称整数x
 * 被覆盖了。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：ranges = [[1,2],[3,4],[5,6]], left = 2, right = 5
 * 输出：true
 * 解释：2 到 5 的每个整数都被覆盖了：
 * - 2 被第一个区间覆盖。
 * - 3 和 4 被第二个区间覆盖。
 * - 5 被第三个区间覆盖。
 * 
 * 
 * 示例 2：
 * 
 * 输入：ranges = [[1,10],[10,20]], left = 21, right = 21
 * 输出：false
 * 解释：21 没有被任何一个区间覆盖。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= ranges.length <= 50
 * 1 <= starti <= endi <= 50
 * 1 <= left <= right <= 50
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
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(52);
        for (vector<int>& range : ranges) {
            diff[range[0]]++;
            diff[range[1] + 1]--;
        }
        int curr = 0;
        for (int i = 1; i <= 50; i++) {
            curr+=diff[i];
            if (i >= left && i <= right && curr <= 0)  {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[3,4],[5,6]]\n2\n5\n
// @lcpr case=end

// @lcpr case=start
// [[1,10],[10,20]]\n21\n21\n
// @lcpr case=end

 */

