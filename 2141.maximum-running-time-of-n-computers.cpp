/*
 * @lc app=leetcode.cn id=2141 lang=cpp
 * @lcpr version=30204
 *
 * [2141] 同时运行 N 台电脑的最长时间
 *
 * https://leetcode.cn/problems/maximum-running-time-of-n-computers/description/
 *
 * algorithms
 * Hard (45.34%)
 * Likes:    111
 * Dislikes: 0
 * Total Accepted:    11.6K
 * Total Submissions: 25.7K
 * Testcase Example:  '2\n[3,3,3]'
 *
 * 你有 n 台电脑。给你整数 n 和一个下标从 0 开始的整数数组 batteries ，其中第 i 个电池可以让一台电脑 运行 batteries[i]
 * 分钟。你想使用这些电池让 全部 n 台电脑 同时 运行。
 *
 * 一开始，你可以给每台电脑连接 至多一个电池 。然后在任意整数时刻，你都可以将一台电脑与它的电池断开连接，并连接另一个电池，你可以进行这个操作 任意次
 * 。新连接的电池可以是一个全新的电池，也可以是别的电脑用过的电池。断开连接和连接新的电池不会花费任何时间。
 *
 * 注意，你不能给电池充电。
 *
 * 请你返回你可以让 n 台电脑同时运行的 最长 分钟数。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：n = 2, batteries = [3,3,3]
 * 输出：4
 * 解释：
 * 一开始，将第一台电脑与电池 0 连接，第二台电脑与电池 1 连接。
 * 2 分钟后，将第二台电脑与电池 1 断开连接，并连接电池 2 。注意，电池 0 还可以供电 1 分钟。
 * 在第 3 分钟结尾，你需要将第一台电脑与电池 0 断开连接，然后连接电池 1 。
 * 在第 4 分钟结尾，电池 1 也被耗尽，第一台电脑无法继续运行。
 * 我们最多能同时让两台电脑同时运行 4 分钟，所以我们返回 4 。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：n = 2, batteries = [1,1,1,1]
 * 输出：2
 * 解释：
 * 一开始，将第一台电脑与电池 0 连接，第二台电脑与电池 2 连接。
 * 一分钟后，电池 0 和电池 2 同时耗尽，所以你需要将它们断开连接，并将电池 1 和第一台电脑连接，电池 3 和第二台电脑连接。
 * 1 分钟后，电池 1 和电池 3 也耗尽了，所以两台电脑都无法继续运行。
 * 我们最多能让两台电脑同时运行 2 分钟，所以我们返回 2 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= batteries.length <= 10^5
 * 1 <= batteries[i] <= 10^9
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    /**
     * 思路：二分答案
     * 
     * 提出判断条件：若要让n台电脑同时运行x分钟，需满足n·x ≤ sum(min(batteries[i], x))
     * （sum为所有电池按x分钟限制后的电量总和）。
     * 
     * 通过分类讨论 “电量不小于x的电池” 和 “电量小于x的电池” 的供电策略，说明当该条件满足时，
     * 必然能实现n台电脑同时运行x分钟。
     * 
     * 利用单调性：由于运行时间满足 “能运行x分钟则也能运行更短时间” 的单调性，
     * 因此可通过二分法来求解最大的x（即最长同时运行时间）。
     */
    long long maxRunTime(int n, vector<int> &batteries)
    {
        long long sum = accumulate(batteries.begin(), batteries.end(), 0LL);
        long long left = 0, right = sum / n + 1;

        while (left + 1 < right)
        {
            long long mid = left + (right - left) / 2;
            long long cur_sum = 0LL;
            for (long long batterie : batteries)
            {
                cur_sum += min(batterie, mid);
            }
            if (n * mid <= cur_sum)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n[3,3,3]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,1,1,1]\n
// @lcpr case=end

 */
