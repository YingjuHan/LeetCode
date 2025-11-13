/*
 * @lc app=leetcode.cn id=1124 lang=cpp
 * @lcpr version=
 *
 * [1124] 表现良好的最长时间段
 *
 * https://leetcode.cn/problems/longest-well-performing-interval/description/
 *
 * algorithms
 * Medium (41.69%)
 * Likes:    583
 * Dislikes: 0
 * Total Accepted:    57.4K
 * Total Submissions: 137.6K
 * Testcase Example:  '[9,9,6,0,6,6,9]'
 *
 * 给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数。
 * 
 * 我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是「劳累的一天」。
 * 
 * 所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格 大于「不劳累的天数」。
 * 
 * 请你返回「表现良好时间段」的最大长度。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：hours = [9,9,6,0,6,6,9]
 * 输出：3
 * 解释：最长的表现良好时间段是 [9,9,6]。
 * 
 * 示例 2：
 * 
 * 输入：hours = [6,6,6]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= hours.length <= 10^4
 * 0 <= hours[i] <= 16
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
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        unordered_map<int, int> ump;
        int s = 0, res = 0;
        for (int i = 0; i < n; i++) {
            s += hours[i] > 8 ? 1 : -1;
            if (s > 0) {
                res = max(res, i + 1);
            } else {
                if (ump.count(s - 1)) {
                    res = max(res, i - ump[s - 1]);
                }
            }
            if (!ump.count(s)) {
                ump[s] = i;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [9,9,6,0,6,6,9]\n
// @lcpr case=end

// @lcpr case=start
// [6,6,6]\n
// @lcpr case=end

 */

