/*
 * @lc app=leetcode.cn id=523 lang=cpp
 * @lcpr version=
 *
 * [523] 连续的子数组和
 *
 * https://leetcode.cn/problems/continuous-subarray-sum/description/
 *
 * algorithms
 * Medium (29.47%)
 * Likes:    640
 * Dislikes: 0
 * Total Accepted:    124.7K
 * Total Submissions: 422.9K
 * Testcase Example:  '[23,2,4,6,7]\n6'
 *
 * 给你一个整数数组 nums 和一个整数 k ，如果 nums 有一个 好的子数组 返回 true ，否则返回 false：
 * 
 * 一个 好的子数组 是：
 * 
 * 
 * 长度 至少为 2 ，且
 * 子数组元素总和为 k 的倍数。
 * 
 * 
 * 注意：
 * 
 * 
 * 子数组 是数组中 连续 的部分。
 * 如果存在一个整数 n ，令整数 x 符合 x = n * k ，则称 x 是 k 的一个倍数。0 始终 视为 k 的一个倍数。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [23,2,4,6,7], k = 6
 * 输出：true
 * 解释：[2,4] 是一个大小为 2 的子数组，并且和为 6 。
 * 
 * 示例 2：
 * 
 * 输入：nums = [23,2,6,4,7], k = 6
 * 输出：true
 * 解释：[23, 2, 6, 4, 7] 是大小为 5 的子数组，并且和为 42 。 
 * 42 是 6 的倍数，因为 42 = 7 * 6 且 7 是一个整数。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [23,2,6,4,7], k = 13
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^9
 * 0 <= sum(nums[i]) <= 2^31 - 1
 * 1 <= k <= 2^31 - 1
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
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }

        unordered_map<int, int> cnt;
        cnt[0] = -1;
        int remainder = 0;
        for (int i = 0; i < n; i++) {
            remainder = (remainder + nums[i]) % k;
            if (cnt.count(remainder)) {
                int prevIndex = cnt[remainder];
                if (i - prevIndex >= 2) {
                    return true;
                }
            } else {
                cnt[remainder] = i;
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [23,2,4,6,7]\n6\n
// @lcpr case=end

// @lcpr case=start
// [23,2,6,4,7]\n6\n
// @lcpr case=end

// @lcpr case=start
// [23,2,6,4,7]\n13\n
// @lcpr case=end

 */

