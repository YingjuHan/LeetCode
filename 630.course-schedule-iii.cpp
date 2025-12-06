/*
 * @lc app=leetcode.cn id=630 lang=cpp
 * @lcpr version=30204
 *
 * [630] 课程表 III
 *
 * https://leetcode.cn/problems/course-schedule-iii/description/
 *
 * algorithms
 * Hard (48.76%)
 * Likes:    644
 * Dislikes: 0
 * Total Accepted:    51.3K
 * Total Submissions: 105.1K
 * Testcase Example:  '[[100,200],[200,1300],[1000,1250],[2000,3200]]'
 *
 * 这里有 n 门不同的在线课程，按从 1 到 n 编号。给你一个数组 courses ，其中 courses[i] = [durationi,
 * lastDayi] 表示第 i 门课将会 持续 上 durationi 天课，并且必须在不晚于 lastDayi 的时候完成。
 * 
 * 你的学期从第 1 天开始。且不能同时修读两门及两门以上的课程。
 * 
 * 返回你最多可以修读的课程数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：courses = [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
 * 输出：3
 * 解释：
 * 这里一共有 4 门课程，但是你最多可以修 3 门：
 * 首先，修第 1 门课，耗费 100 天，在第 100 天完成，在第 101 天开始下门课。
 * 第二，修第 3 门课，耗费 1000 天，在第 1100 天完成，在第 1101 天开始下门课程。
 * 第三，修第 2 门课，耗时 200 天，在第 1300 天完成。
 * 第 4 门课现在不能修，因为将会在第 3300 天完成它，这已经超出了关闭日期。
 * 
 * 示例 2：
 * 
 * 输入：courses = [[1,2]]
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 输入：courses = [[3,2],[4,3]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= courses.length <= 10^4
 * 1 <= durationi, lastDayi <= 10^4
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
    int scheduleCourse(vector<vector<int>>& courses) {
        // courses[i] = [durationi, lastDayi]
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int day = 0;
        priority_queue<int, vector<int>, less<int>> pq;
        for (int i = 0; i < courses.size(); i++) {
            int durationi = courses[i][0], lastDayi = courses[i][1];
            if (day + durationi <= lastDayi) {
                day += durationi;
                pq.push(durationi);
            } else if (!pq.empty() && pq.top() > durationi) {
                day += durationi;
                day -= pq.top(); pq.pop(); pq.push(durationi);
            }
        }
        return pq.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,2],[4,3]]\n
// @lcpr case=end

 */

