/*
 * @lc app=leetcode.cn id=2461 lang=cpp
 * @lcpr version=30204
 *
 * [2461] 长度为 K 子数组中的最大和
 *
 * https://leetcode.cn/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/
 *
 * algorithms
 * Medium (45.61%)
 * Likes:    86
 * Dislikes: 0
 * Total Accepted:    35.3K
 * Total Submissions: 77.3K
 * Testcase Example:  '[1,5,4,2,9,9,9]\n3'
 *
 * 给你一个整数数组 nums 和一个整数 k 。请你从 nums 中满足下述条件的全部子数组中找出最大子数组和：
 * 
 * 
 * 子数组的长度是 k，且
 * 子数组中的所有元素 各不相同 。
 * 
 * 
 * 返回满足题面要求的最大子数组和。如果不存在子数组满足这些条件，返回 0 。
 * 
 * 子数组 是数组中一段连续非空的元素序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,5,4,2,9,9,9], k = 3
 * 输出：15
 * 解释：nums 中长度为 3 的子数组是：
 * - [1,5,4] 满足全部条件，和为 10 。
 * - [5,4,2] 满足全部条件，和为 11 。
 * - [4,2,9] 满足全部条件，和为 15 。
 * - [2,9,9] 不满足全部条件，因为元素 9 出现重复。
 * - [9,9,9] 不满足全部条件，因为元素 9 出现重复。
 * 因为 15 是满足全部条件的所有子数组中的最大子数组和，所以返回 15 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [4,4,4], k = 3
 * 输出：0
 * 解释：nums 中长度为 3 的子数组是：
 * - [4,4,4] 不满足全部条件，因为元素 4 出现重复。
 * 因为不存在满足全部条件的子数组，所以返回 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= k <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
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
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, s = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < nums.size(); i++) {
            // 1. 进入窗口
            s += nums[i];
            cnt[nums[i]]++;

            int left = i - k + 1;
            if (left < 0) { // 窗口大小不足 k
                continue;
            }

            // 2. 更新答案
            if (cnt.size() == k) {
                ans = max(ans, s);
            }

            // 3. 离开窗口
            int out = nums[left];
            s -= out;
            if (--cnt[out] == 0) {
                cnt.erase(out);
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,5,4,2,9,9,9]\n3\n
// @lcpr case=end

// @lcpr case=start
// [4,4,4]\n3\n
// @lcpr case=end

 */

