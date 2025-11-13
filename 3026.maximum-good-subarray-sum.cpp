/*
 * @lc app=leetcode.cn id=3026 lang=cpp
 * @lcpr version=
 *
 * [3026] 最大好子数组和
 *
 * https://leetcode.cn/problems/maximum-good-subarray-sum/description/
 *
 * algorithms
 * Medium (28.58%)
 * Likes:    28
 * Dislikes: 0
 * Total Accepted:    6.9K
 * Total Submissions: 24.1K
 * Testcase Example:  '[1,2,3,4,5,6]\n1'
 *
 * 给你一个长度为 n 的数组 nums 和一个 正 整数 k 。
 * 
 * 如果 nums 的一个子数组中，第一个元素和最后一个元素 差的绝对值恰好 为 k ，我们称这个子数组为 好 的。换句话说，如果子数组
 * nums[i..j] 满足 |nums[i] - nums[j]| == k ，那么它是一个好子数组。
 * 
 * 请你返回 nums 中 好 子数组的 最大 和，如果没有好子数组，返回 0 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,2,3,4,5,6], k = 1
 * 输出：11
 * 解释：好子数组中第一个元素和最后一个元素的差的绝对值必须为 1 。好子数组有 [1,2] ，[2,3] ，[3,4] ，[4,5] 和 [5,6]
 * 。最大子数组和为 11 ，对应的子数组为 [5,6] 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [-1,3,2,4,5], k = 3
 * 输出：11
 * 解释：好子数组中第一个元素和最后一个元素的差的绝对值必须为 3 。好子数组有 [-1,3,2] 和 [2,4,5] 。最大子数组和为 11
 * ，对应的子数组为 [2,4,5] 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [-1,-2,-3,-4], k = 2
 * 输出：-6
 * 解释：好子数组中第一个元素和最后一个元素的差的绝对值必须为 2 。好子数组有 [-1,-2,-3] 和 [-2,-3,-4] 。最大子数组和为 -6
 * ，对应的子数组为 [-1,-2,-3] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
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
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, long long> min_s;
        long long ans = LLONG_MIN, sum = 0;
        for (int num : nums) {
            auto it = min_s.find(num + k);
            if (it != min_s.end()) {
                ans = max(ans, sum + num - it->second);
            }

            it = min_s.find(num - k);
            if (it != min_s.end()) {
                ans = max(ans, sum + num - it->second);
            }

            it = min_s.find(num);
            if (it == min_s.end() || sum < it->second) {
                min_s[num] = sum;
            }

            sum += num;
        }
        return ans == LLONG_MIN ? 0 : ans;


    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6]\n1\n
// @lcpr case=end

// @lcpr case=start
// [-1,3,2,4,5]\n3\n
// @lcpr case=end

// @lcpr case=start
// [-1,-2,-3,-4]\n2\n
// @lcpr case=end

 */

