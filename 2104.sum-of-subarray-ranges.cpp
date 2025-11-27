/*
 * @lc app=leetcode.cn id=2104 lang=cpp
 * @lcpr version=30204
 *
 * [2104] 子数组范围和
 *
 * https://leetcode.cn/problems/sum-of-subarray-ranges/description/
 *
 * algorithms
 * Medium (63.89%)
 * Likes:    336
 * Dislikes: 0
 * Total Accepted:    47.5K
 * Total Submissions: 74.3K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整数数组 nums 。nums 中，子数组的 范围 是子数组中最大元素和最小元素的差值。
 * 
 * 返回 nums 中 所有 子数组范围的 和 。
 * 
 * 子数组是数组中一个连续 非空 的元素序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,2,3]
 * 输出：4
 * 解释：nums 的 6 个子数组如下所示：
 * [1]，范围 = 最大 - 最小 = 1 - 1 = 0 
 * [2]，范围 = 2 - 2 = 0
 * [3]，范围 = 3 - 3 = 0
 * [1,2]，范围 = 2 - 1 = 1
 * [2,3]，范围 = 3 - 2 = 1
 * [1,2,3]，范围 = 3 - 1 = 2
 * 所有范围的和是 0 + 0 + 0 + 1 + 1 + 2 = 4
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,3,3]
 * 输出：4
 * 解释：nums 的 6 个子数组如下所示：
 * [1]，范围 = 最大 - 最小 = 1 - 1 = 0
 * [3]，范围 = 3 - 3 = 0
 * [3]，范围 = 3 - 3 = 0
 * [1,3]，范围 = 3 - 1 = 2
 * [3,3]，范围 = 3 - 3 = 0
 * [1,3,3]，范围 = 3 - 1 = 2
 * 所有范围的和是 0 + 0 + 0 + 2 + 0 + 2 = 4
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [4,-2,-3,4,1]
 * 输出：59
 * 解释：nums 中所有子数组范围的和是 59
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 1000
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 * 
 * 
 * 进阶：你可以设计一种时间复杂度为 O(n) 的解决方案吗？
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
    long long solve(vector<int> nums) {
        int n = nums.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                right[st.top()] = i;
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }

        long long res = 0;

        for (int i = 0; i < n; i++) {
            res += 1LL * nums[i] * (i - left[i]) * (right[i] - i);
        }
        return res;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long res = solve(nums);
        for (int& num : nums) {
            num = -num;
        } 
        return res + solve(nums);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,-2,-3,4,1]\n
// @lcpr case=end

 */

