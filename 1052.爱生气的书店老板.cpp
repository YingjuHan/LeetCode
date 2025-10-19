/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 * @lcpr version=30203
 *
 * [1052] 爱生气的书店老板
 */

// @lc code=start
#include <vector>

using namespace std;
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int s[2]{}, max_s1 = 0;
        for (int i = 0; i < customers.size(); i++) {
            s[grumpy[i]] += customers[i];
            int left = i - minutes + 1; // 窗口左端点
            if (left < 0) { // 窗口长度不足 minutes
                continue;
            }
            max_s1 = max(max_s1, s[1]);
            // 窗口最左边元素离开窗口
            s[1] -= grumpy[left] ? customers[left] : 0;
        }
        return s[0] + max_s1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,1,2,1,1,7,5]\n[0,1,0,1,0,1,0,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n[0]\n1\n
// @lcpr case=end

 */

