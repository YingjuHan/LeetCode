/*
 * @lc app=leetcode.cn id=3439 lang=cpp
 * @lcpr version=30203
 *
 * [3439] 重新安排会议得到最多空余时间 I
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> free(n + 1, 0);
        free[0] = startTime[0];
        for (int i = 1; i < n; i++) {
            free[i] = startTime[i] - endTime[i - 1];
        }
        free[n] = eventTime - endTime[n - 1];

        int res = 0;
        int windowSum = 0;
        for (int i = 0; i <= n; i++) {
            windowSum += free[i];
            if (i < k) {
                continue;
            }

            res = max(res, windowSum);
            windowSum -= free[i - k];
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n1\n[1,3]\n[2,5]\n
// @lcpr case=end

// @lcpr case=start
// 10\n1\n[0,2,9]\n[1,4,10]\n
// @lcpr case=end

// @lcpr case=start
// 5\n2\n[0,1,2,3,4]\n[1,2,3,4,5]\n
// @lcpr case=end

 */

