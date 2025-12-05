/*
 * @lc app=leetcode.cn id=621 lang=cpp
 * @lcpr version=30204
 *
 * [621] 任务调度器
 *
 * https://leetcode.cn/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (60.70%)
 * Likes:    1348
 * Dislikes: 0
 * Total Accepted:    171.1K
 * Total Submissions: 281.8K
 * Testcase Example:  '["A","A","A","B","B","B"]\n2'
 *
 * 给你一个用字符数组 tasks 表示的 CPU 需要执行的任务列表，用字母 A 到 Z 表示，以及一个冷却时间
 * n。每个周期或时间间隔允许完成一项任务。任务可以按任何顺序完成，但有一个限制：两个 相同种类 的任务之间必须有长度为 n 的冷却时间。
 * 
 * 返回完成所有任务所需要的 最短时间间隔 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：tasks = ["A","A","A","B","B","B"], n = 2
 * 
 * 输出：8
 * 
 * 解释：
 * 
 * 在完成任务 A 之后，你必须等待两个间隔。对任务 B 来说也是一样。在第 3 个间隔，A 和 B 都不能完成，所以你需要待命。在第 4
 * 个间隔，由于已经经过了 2 个间隔，你可以再次执行 A 任务。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：tasks = ["A","C","A","B","D","B"], n = 1
 * 
 * 输出：6
 * 
 * 解释：一种可能的序列是：A -> B -> C -> D -> A -> B。
 * 
 * 由于冷却间隔为 1，你可以在完成另一个任务后重复执行这个任务。
 * 
 * 
 * 示例 3：
 * 
 * 输入：tasks = ["A","A","A","B","B","B"], n = 3
 * 
 * 输出：10
 * 
 * 解释：一种可能的序列为：A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B。
 * 
 * 只有两种任务类型，A 和 B，需要被 3 个间隔分割。这导致重复执行这些任务的间隔当中有两次待命状态。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= tasks.length <= 10^4
 * tasks[i] 是大写英文字母
 * 0 <= n <= 100
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
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> count;
        for (char task : tasks) {
            count[task]++;
        }
        vector<pair<char, int>> a(count.begin(), count.end());
        sort(a.begin(), a.end(), [](const auto& p, const auto& q) {
            return p.second > q.second;
        });
        int res = 0;
        while (a[0].second > 0) {
            int i = 0;
            while (i <= n) {
                if (a[0].second == 0) break;
                if (i < a.size() && a[i].second > 0) a[i].second--;
                res++;
                i++;
            }
            sort(a.begin(), a.end(), [](const auto& p, const auto& q) {
                return p.second > q.second;
            });
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["A","A","A","B","B","B"]\n2\n
// @lcpr case=end

// @lcpr case=start
// ["A","C","A","B","D","B"]\n1\n
// @lcpr case=end

// @lcpr case=start
// ["A","A","A","B","B","B"]\n3\n
// @lcpr case=end

 */

