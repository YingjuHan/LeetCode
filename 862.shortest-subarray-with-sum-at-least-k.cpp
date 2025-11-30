/*
 * @lc app=leetcode.cn id=862 lang=cpp
 * @lcpr version=30204
 *
 * [862] 和至少为 K 的最短子数组
 *
 * https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/description/
 *
 * algorithms
 * Hard (28.55%)
 * Likes:    794
 * Dislikes: 0
 * Total Accepted:    62.5K
 * Total Submissions: 218.8K
 * Testcase Example:  '[1]\n1'
 *
 * 给你一个整数数组 nums 和一个整数 k ，找出 nums 中和至少为 k 的 最短非空子数组 ，并返回该子数组的长度。如果不存在这样的 子数组
 * ，返回 -1 。
 * 
 * 子数组 是数组中 连续 的一部分。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1], k = 1
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,2], k = 4
 * 输出：-1
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [2,-1,2], k = 3
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^5 <= nums[i] <= 10^5
 * 1 <= k <= 10^9
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
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), res = n + 1;
        long s[n + 1];
        s[0] = 0L;
        for (int i = 0; i < n; ++i)
            s[i + 1] = s[i] + nums[i]; // 计算前缀和
        
        deque<int> q;
        for (int i = 0; i <= n; i++) {
            long cur_s = s[i];
            while (!q.empty() && cur_s - s[q.front()] >= k) {
                res = min(res, i - q.front());
                q.pop_front();
            }
            while (!q.empty() && cur_s - s[q.back()] <= 0) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return res > n ? - 1 : res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n4\n
// @lcpr case=end

// @lcpr case=start
// [2,-1,2]\n3\n
// @lcpr case=end

 */

