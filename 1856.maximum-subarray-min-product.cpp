/*
 * @lc app=leetcode.cn id=1856 lang=cpp
 * @lcpr version=30204
 *
 * [1856] 子数组最小乘积的最大值
 *
 * https://leetcode.cn/problems/maximum-subarray-min-product/description/
 *
 * algorithms
 * Medium (39.68%)
 * Likes:    149
 * Dislikes: 0
 * Total Accepted:    14K
 * Total Submissions: 35.3K
 * Testcase Example:  '[1,2,3,2]'
 *
 * 一个数组的 最小乘积 定义为这个数组中 最小值 乘以 数组的 和 。
 * 
 * 
 * 比方说，数组 [3,2,5] （最小值是 2）的最小乘积为 2 * (3+2+5) = 2 * 10 = 20 。
 * 
 * 
 * 给你一个正整数数组 nums ，请你返回 nums 任意 非空子数组 的最小乘积 的 最大值 。由于答案可能很大，请你返回答案对  10^9 + 7
 * 取余 的结果。
 * 
 * 请注意，最小乘积的最大值考虑的是取余操作 之前 的结果。题目保证最小乘积的最大值在 不取余 的情况下可以用 64 位有符号整数 保存。
 * 
 * 子数组 定义为一个数组的 连续 部分。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,2,3,2]
 * 输出：14
 * 解释：最小乘积的最大值由子数组 [2,3,2] （最小值是 2）得到。
 * 2 * (2+3+2) = 2 * 7 = 14 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [2,3,3,1,2]
 * 输出：18
 * 解释：最小乘积的最大值由子数组 [3,3] （最小值是 3）得到。
 * 3 * (3+3) = 3 * 6 = 18 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [3,1,5,6,4,2]
 * 输出：60
 * 解释：最小乘积的最大值由子数组 [5,6,4] （最小值是 4）得到。
 * 4 * (5+6+4) = 4 * 15 = 60 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^7
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
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0), right(n, n - 1);
        stack<int> st;
        vector<long long> presum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            presum[i + 1] = presum[i] + nums[i];
        }

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] <= nums[st.top()]) {
                // 这里的 right 是非严格定义的，right[i] 是右侧最近的小于等于 nums[i] 的元素下标
                right[st.top()] = i - 1;
                st.pop();
            }
            if (!st.empty()) {
                // 这里的 left 是严格定义的，left[i] 是左侧最近的严格小于 nums[i] 的元素下标
                left[i] = st.top() + 1;
            }
            
            st.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, 1LL * nums[i] * (presum[right[i] + 1] - presum[left[i]]));
        }
        return res % 1000000007;
    }
};
// @lc code=end


/*
// @lcpr case=start
// [1,2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,3,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,5,6,4,2]\n
// @lcpr case=end

 */

