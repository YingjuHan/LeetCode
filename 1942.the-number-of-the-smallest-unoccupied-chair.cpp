/*
 * @lc app=leetcode.cn id=1942 lang=cpp
 * @lcpr version=30204
 *
 * [1942] 最小未被占据椅子的编号
 *
 * https://leetcode.cn/problems/the-number-of-the-smallest-unoccupied-chair/description/
 *
 * algorithms
 * Medium (46.32%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    8.6K
 * Total Submissions: 18.6K
 * Testcase Example:  '[[1,4],[2,3],[4,6]]\n1'
 *
 * 有 n 个朋友在举办一个派对，这些朋友从 0 到 n - 1 编号。派对里有 无数 张椅子，编号为 0 到 infinity
 * 。当一个朋友到达派对时，他会占据 编号最小 且未被占据的椅子。
 * 
 * 
 * 比方说，当一个朋友到达时，如果椅子 0 ，1 和 5 被占据了，那么他会占据 2 号椅子。
 * 
 * 
 * 当一个朋友离开派对时，他的椅子会立刻变成未占据状态。如果同一时刻有另一个朋友到达，可以立即占据这张椅子。
 * 
 * 给你一个下标从 0 开始的二维整数数组 times ，其中 times[i] = [arrivali, leavingi] 表示第 i
 * 个朋友到达和离开的时刻，同时给你一个整数 targetFriend 。所有到达时间 互不相同 。
 * 
 * 请你返回编号为 targetFriend 的朋友占据的 椅子编号 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：times = [[1,4],[2,3],[4,6]], targetFriend = 1
 * 输出：1
 * 解释：
 * - 朋友 0 时刻 1 到达，占据椅子 0 。
 * - 朋友 1 时刻 2 到达，占据椅子 1 。
 * - 朋友 1 时刻 3 离开，椅子 1 变成未占据。
 * - 朋友 0 时刻 4 离开，椅子 0 变成未占据。
 * - 朋友 2 时刻 4 到达，占据椅子 0 。
 * 朋友 1 占据椅子 1 ，所以返回 1 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：times = [[3,10],[1,5],[2,6]], targetFriend = 0
 * 输出：2
 * 解释：
 * - 朋友 1 时刻 1 到达，占据椅子 0 。
 * - 朋友 2 时刻 2 到达，占据椅子 1 。
 * - 朋友 0 时刻 3 到达，占据椅子 2 。
 * - 朋友 1 时刻 5 离开，椅子 0 变成未占据。
 * - 朋友 2 时刻 6 离开，椅子 1 变成未占据。
 * - 朋友 0 时刻 10 离开，椅子 2 变成未占据。
 * 朋友 0 占据椅子 2 ，所以返回 2 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == times.length
 * 2 <= n <= 10^4
 * times[i].length == 2
 * 1 <= arrivali < leavingi <= 10^5
 * 0 <= targetFriend <= n - 1
 * 每个 arrivali 时刻 互不相同 。
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
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        int maxT = 0;
        for (auto& time : times) {
            maxT = max(maxT, max(time[0], time[1]));
        }

        // events_leave[time] 离开人的列表
        // events_arrive[time] 到达人的列表
        vector<vector<int>> events_leave(maxT + 1, vector<int>());
        vector<vector<int>> events_arrive(maxT + 1, vector<int>());

        for (int i = 0; i < n; i++) {
            int a = times[i][0];
            int l = times[i][1];
            events_leave[l].push_back(i);
            events_arrive[a].push_back(i);
        }

        // 最小堆：存空闲的椅子编号
        priority_queue<int, vector<int>, greater<int>> unoccupied;
        for (int i = 0; i < n; i++) {
            unoccupied.push(i);
        }

        // belong[i] = i 号朋友坐的椅子
        vector<int> belong(n, -1);

        for (int t = 0; t <= maxT; t++) {
            // 人离开
            for (int id : events_leave[t]) {
                unoccupied.push(belong[id]);
            }

            // 人到达
            for (int id : events_arrive[t]) {
                belong[id] = unoccupied.top();
                unoccupied.pop();

                if (id == targetFriend) {
                    return belong[id];
                }
            } 
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4],[2,3],[4,6]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[3,10],[1,5],[2,6]]\n0\n
// @lcpr case=end

 */

