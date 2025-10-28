/*
 * @lc app=leetcode.cn id=2187 lang=cpp
 * @lcpr version=30204
 *
 * [2187] 完成旅途的最少时间
 *
 * https://leetcode.cn/problems/minimum-time-to-complete-trips/description/
 *
 * algorithms
 * Medium (39.08%)
 * Likes:    147
 * Dislikes: 0
 * Total Accepted:    49.2K
 * Total Submissions: 125.8K
 * Testcase Example:  '[1,2,3]\n5'
 *
 * 给你一个数组 time ，其中 time[i] 表示第 i 辆公交车完成 一趟旅途 所需要花费的时间。
 * 
 * 每辆公交车可以 连续 完成多趟旅途，也就是说，一辆公交车当前旅途完成后，可以 立马开始 下一趟旅途。每辆公交车 独立
 * 运行，也就是说可以同时有多辆公交车在运行且互不影响。
 * 
 * 给你一个整数 totalTrips ，表示所有公交车 总共 需要完成的旅途数目。请你返回完成 至少 totalTrips 趟旅途需要花费的 最少
 * 时间。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：time = [1,2,3], totalTrips = 5
 * 输出：3
 * 解释：
 * - 时刻 t = 1 ，每辆公交车完成的旅途数分别为 [1,0,0] 。
 * ⁠ 已完成的总旅途数为 1 + 0 + 0 = 1 。
 * - 时刻 t = 2 ，每辆公交车完成的旅途数分别为 [2,1,0] 。
 * ⁠ 已完成的总旅途数为 2 + 1 + 0 = 3 。
 * - 时刻 t = 3 ，每辆公交车完成的旅途数分别为 [3,1,1] 。
 * ⁠ 已完成的总旅途数为 3 + 1 + 1 = 5 。
 * 所以总共完成至少 5 趟旅途的最少时间为 3 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：time = [2], totalTrips = 1
 * 输出：2
 * 解释：
 * 只有一辆公交车，它将在时刻 t = 2 完成第一趟旅途。
 * 所以完成 1 趟旅途的最少时间为 2 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= time.length <= 10^5
 * 1 <= time[i], totalTrips <= 10^7
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
    bool check(vector<int>& time, long long x, int totalTrips) {
        long long sum = 0;
        for (int t : time) {
            sum += x/t;
            if (sum >= totalTrips) {
                return true;
            }
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        // 时间越多，可以完成的旅途也就越多；时间越少，可以完成的旅途也就越少
        // 如果答案为x：问题可以转换为
        // 每辆车都用时x，总共能完成多少旅程，能否达到totalTrips
        // 完成的数量为 i = 0 ~ n (x/times[i])下取整的和
        // 将它与totalTrips比较，如果比totalTrips小，说明答案小了，更新left端点，否则，更新right端点

        long long left = *min_element(time.begin(), time.end());
        long long right = 1LL * left * totalTrips;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (check(time, mid, totalTrips)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

