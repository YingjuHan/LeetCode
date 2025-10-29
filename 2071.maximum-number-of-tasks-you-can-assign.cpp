/*
 * @lc app=leetcode.cn id=2071 lang=cpp
 * @lcpr version=30204
 *
 * [2071] 你可以安排的最多任务数目
 *
 * https://leetcode.cn/problems/maximum-number-of-tasks-you-can-assign/description/
 *
 * algorithms
 * Hard (43.09%)
 * Likes:    168
 * Dislikes: 0
 * Total Accepted:    17.6K
 * Total Submissions: 40.7K
 * Testcase Example:  '[3,2,1]\n[0,3,3]\n1\n1'
 *
 * 给你 n 个任务和 m 个工人。每个任务需要一定的力量值才能完成，需要的力量值保存在下标从 0 开始的整数数组 tasks 中，第 i 个任务需要
 * tasks[i] 的力量才能完成。每个工人的力量值保存在下标从 0 开始的整数数组 workers 中，第 j 个工人的力量值为 workers[j]
 * 。每个工人只能完成 一个 任务，且力量值需要 大于等于 该任务的力量要求值（即 workers[j] >= tasks[i] ）。
 * 
 * 除此以外，你还有 pills 个神奇药丸，可以给 一个工人的力量值 增加 strength 。你可以决定给哪些工人使用药丸，但每个工人 最多 只能使用
 * 一片 药丸。
 * 
 * 给你下标从 0 开始的整数数组tasks 和 workers 以及两个整数 pills 和 strength ，请你返回 最多
 * 有多少个任务可以被完成。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：tasks = [3,2,1], workers = [0,3,3], pills = 1, strength = 1
 * 输出：3
 * 解释：
 * 我们可以按照如下方案安排药丸：
 * - 给 0 号工人药丸。
 * - 0 号工人完成任务 2（0 + 1 >= 1）
 * - 1 号工人完成任务 1（3 >= 2）
 * - 2 号工人完成任务 0（3 >= 3）
 * 
 * 
 * 示例 2：
 * 
 * 输入：tasks = [5,4], workers = [0,0,0], pills = 1, strength = 5
 * 输出：1
 * 解释：
 * 我们可以按照如下方案安排药丸：
 * - 给 0 号工人药丸。
 * - 0 号工人完成任务 0（0 + 5 >= 5）
 * 
 * 
 * 示例 3：
 * 
 * 输入：tasks = [10,15,30], workers = [0,10,10,10,10], pills = 3, strength = 10
 * 输出：2
 * 解释：
 * 我们可以按照如下方案安排药丸：
 * - 给 0 号和 1 号工人药丸。
 * - 0 号工人完成任务 0（0 + 10 >= 10）
 * - 1 号工人完成任务 1（10 + 10 >= 15）
 * 
 * 
 * 示例 4：
 * 
 * 输入：tasks = [5,9,8,5,9], workers = [1,6,4,2,6], pills = 1, strength = 5
 * 输出：3
 * 解释：
 * 我们可以按照如下方案安排药丸：
 * - 给 2 号工人药丸。
 * - 1 号工人完成任务 0（6 >= 5）
 * - 2 号工人完成任务 2（4 + 5 >= 8）
 * - 4 号工人完成任务 3（6 >= 5）
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == tasks.length
 * m == workers.length
 * 1 <= n, m <= 5 * 10^4
 * 0 <= pills <= m
 * 0 <= tasks[i], workers[j], strength <= 10^9
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

    /**
     * 
     */
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int nw = workers.size();
        int nt = tasks.size();

        // 贪心：用最强的 k 名工人，完成最简单的 k 个任务

        /**
         * 枚举工人，计算他完成哪个任务
         * 
         * 遍历workers的后k个工人，w = workers[i]，分类讨论
         * 1. 如果w不吃药，能完成目前剩余任务中最简单的任务，那么就完成最简单的。无需考虑更难任务的情况，
         * 因为w能完成的任务，后面更强的工人也能完成
         * 2. 如果w必须吃药，贪心地，让w完成能完成的最难任务，充分利用效果
         * 3. 如果w不吃药也能完成任务，非要吃药？如果最简单的任务是t，更难的任务是t2，我让 w 吃药去完成
         * 更难的任务 t2不行吗？这种做法不是最优的，设后面更强的工人是w2，并且他不吃药也能完成 t2 ，那么
         * 让 w 完成 t，w2完成 t2，就可以省下一颗药了
         * 
         */
        auto check = [&](int k) -> bool {
            // 贪心：用最强的 k 名工人，完成最简单的 k 个任务
            int i = 0, p = pills;
            deque<int> valid_tasks;
            for (int j = nw - k; j < nw; j++) { // 枚举工人
                int w = workers[j];

                // 吃药的情况下，把能完成的任务记录到valid_tasks中
                while (i < k && tasks[i] <= w + strength) {
                    valid_tasks.push_back(tasks[i]);
                    i++;
                }

                // 即使吃也无法完成
                if (valid_tasks.empty()) {
                    return false;
                }

                if (w >= valid_tasks.front()) {
                    valid_tasks.pop_front();
                    continue;
                }

                if (p == 0) {
                    return false;
                }

                p--;

                // 完成（能完成的）最难的任务
                valid_tasks.pop_back();
            }
            return true;
        };

        int left = 0;
        int right = min(nw, nt) + 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            (check(mid) ? left : right) = mid;
        }
        return left;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,1]\n[0,3,3]\n1\n1\n
// @lcpr case=end

// @lcpr case=start
// [5,4]\n[0,0,0]\n1\n5\n
// @lcpr case=end

// @lcpr case=start
// [10,15,30]\n[0,10,10,10,10]\n3\n10\n
// @lcpr case=end

// @lcpr case=start
// [5,9,8,5,9]\n[1,6,4,2,6]\n1\n5\n
// @lcpr case=end

 */

