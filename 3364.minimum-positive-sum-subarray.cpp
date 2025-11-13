/*
 * @lc app=leetcode.cn id=3364 lang=cpp
 * @lcpr version=
 *
 * [3364] 最小正和子数组
 *
 * https://leetcode.cn/problems/minimum-positive-sum-subarray/description/
 *
 * algorithms
 * Easy (50.75%)
 * Likes:    14
 * Dislikes: 0
 * Total Accepted:    6.7K
 * Total Submissions: 13.1K
 * Testcase Example:  '[3,-2,1,4]\n2\n3'
 *
 * 给你一个整数数组 nums 和 两个 整数 l 和 r。你的任务是找到一个长度在 l 和 r 之间（包含）且和大于 0 的 子数组 的 最小 和。
 * 
 * 返回满足条件的子数组的 最小 和。如果不存在这样的子数组，则返回 -1。
 * 
 * 子数组 是数组中的一个连续 非空 元素序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： nums = [3, -2, 1, 4], l = 2, r = 3
 * 
 * 输出： 1
 * 
 * 解释：
 * 
 * 长度在 l = 2 和 r = 3 之间且和大于 0 的子数组有：
 * 
 * 
 * [3, -2] 和为 1
 * [1, 4] 和为 5
 * [3, -2, 1] 和为 2
 * [-2, 1, 4] 和为 3
 * 
 * 
 * 其中，子数组 [3, -2] 的和为 1，是所有正和中最小的。因此，答案为 1。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： nums = [-2, 2, -3, 1], l = 2, r = 3
 * 
 * 输出： -1
 * 
 * 解释：
 * 
 * 不存在长度在 l 和 r 之间且和大于 0 的子数组。因此，答案为 -1。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入： nums = [1, 2, 3, 4], l = 2, r = 4
 * 
 * 输出： 3
 * 
 * 解释：
 * 
 * 子数组 [1, 2] 的长度为 2，和为 3，是所有正和中最小的。因此，答案为 3。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 100
 * 1 <= l <= r <= nums.length
 * -1000 <= nums[i] <= 1000
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
#include <set>
// @lcpr-template-end
// @lc code=start
class Solution {
public:

    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int res = INT_MAX, n = nums.size();
        vector<int> s(n + 1);
        s[0] = 0;
        multiset<int> st;
        for (int j = 1; j <= n; j++) {
            s[j] = s[j - 1] + nums[j - 1];
            if (j < l) {
                continue;
            }

            st.insert(s[j - l]);
            auto it = st.lower_bound(s[j]);
            if (it != st.begin()) {
                res = min(res, s[j] - *(--it));
            }
            if (j >= r) {
                st.erase(st.find(s[j -r]));
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3, -2, 1, 4]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// [-2, 2, -3, 1]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// [1, 2, 3, 4]\n2\n4\n
// @lcpr case=end

 */

