/*
 * @lc app=leetcode.cn id=2398 lang=cpp
 * @lcpr version=30204
 *
 * [2398] 预算内的最多机器人数目
 *
 * https://leetcode.cn/problems/maximum-number-of-robots-within-budget/description/
 *
 * algorithms
 * Hard (44.78%)
 * Likes:    85
 * Dislikes: 0
 * Total Accepted:    20.1K
 * Total Submissions: 44.8K
 * Testcase Example:  '[3,6,1,3,4]\n[2,1,3,4,5]\n25'
 *
 * 你有 n 个机器人，给你两个下标从 0 开始的整数数组 chargeTimes 和 runningCosts ，两者长度都为 n 。第 i
 * 个机器人充电时间为 chargeTimes[i] 单位时间，花费 runningCosts[i] 单位时间运行。再给你一个整数 budget 。
 * 
 * 运行 k 个机器人 总开销 是 max(chargeTimes) + k * sum(runningCosts) ，其中
 * max(chargeTimes) 是这 k 个机器人中最大充电时间，sum(runningCosts) 是这 k 个机器人的运行时间之和。
 * 
 * 请你返回在 不超过 budget 的前提下，你 最多 可以运行的 连续 的机器人数目为多少。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：chargeTimes = [3,6,1,3,4], runningCosts = [2,1,3,4,5], budget = 25
 * 输出：3
 * 解释：
 * 可以在 budget 以内运行所有单个机器人或者连续运行 2 个机器人。
 * 选择前 3 个机器人，可以得到答案最大值 3 。总开销是 max(3,6,1) + 3 * sum(2,1,3) = 6 + 3 * 6 = 24
 * ，小于 25 。
 * 可以看出无法在 budget 以内连续运行超过 3 个机器人，所以我们返回 3 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：chargeTimes = [11,12,19], runningCosts = [10,8,7], budget = 19
 * 输出：0
 * 解释：即使运行任何一个单个机器人，还是会超出 budget，所以我们返回 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * chargeTimes.length == runningCosts.length == n
 * 1 <= n <= 5 * 10^4
 * 1 <= chargeTimes[i], runningCosts[i] <= 10^5
 * 1 <= budget <= 10^15
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
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int res = 0, left = 0;
        long long sum = 0;
        deque<int> q;
        for (int i = 0; i < chargeTimes.size(); i++) {
            int x = chargeTimes[i], y = runningCosts[i];
            while (!q.empty() && x >= chargeTimes[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            sum += y;

            while (!q.empty() && chargeTimes[q.front()] + (i - left + 1) * sum > budget) {
                if (q.front() == left) {
                    q.pop_front();
                }
                sum -= runningCosts[left];
                left++;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,6,1,3,4]\n[2,1,3,4,5]\n25\n
// @lcpr case=end

// @lcpr case=start
// [11,12,19]\n[10,8,7]\n19\n
// @lcpr case=end

 */

