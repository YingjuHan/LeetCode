/*
 * @lc app=leetcode.cn id=2875 lang=cpp
 * @lcpr version=30204
 *
 * [2875] 无限数组的最短子数组
 *
 * https://leetcode.cn/problems/minimum-size-subarray-in-infinite-array/description/
 *
 * algorithms
 * Medium (37.24%)
 * Likes:    61
 * Dislikes: 0
 * Total Accepted:    13.6K
 * Total Submissions: 36.3K
 * Testcase Example:  '[1,2,3]\n5'
 *
 * 给你一个下标从 0 开始的数组 nums 和一个整数 target 。
 * 
 * 下标从 0 开始的数组 infinite_nums 是通过无限地将 nums 的元素追加到自己之后生成的。
 * 
 * 请你从 infinite_nums 中找出满足 元素和 等于 target 的 最短 子数组，并返回该子数组的长度。如果不存在满足条件的子数组，返回
 * -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,2,3], target = 5
 * 输出：2
 * 解释：在这个例子中 infinite_nums = [1,2,3,1,2,3,1,2,...] 。
 * 区间 [1,2] 内的子数组的元素和等于 target = 5 ，且长度 length = 2 。
 * 可以证明，当元素和等于目标值 target = 5 时，2 是子数组的最短长度。
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,1,1,2,3], target = 4
 * 输出：2
 * 解释：在这个例子中 infinite_nums = [1,1,1,2,3,1,1,1,2,3,1,1,...].
 * 区间 [4,5] 内的子数组的元素和等于 target = 4 ，且长度 length = 2 。
 * 可以证明，当元素和等于目标值 target = 4 时，2 是子数组的最短长度。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [2,4,6,8], target = 3
 * 输出：-1
 * 解释：在这个例子中 infinite_nums = [2,4,6,8,2,4,6,8,...] 。
 * 可以证明，不存在元素和等于目标值 target = 3 的子数组。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * 1 <= target <= 10^9
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long total = 0LL;
        for (int num : nums) {
            total += num;
        }

        int k = target / total;
        int rem = target % total;

        int res = INT_MAX;
        int right = 0, left = 0;
        int n = nums.size();
        long long cur_sum = 0LL;
        while (right < n * 2) {
            int in_win = nums[right % n];
            cur_sum += in_win;
            right++;

            while (cur_sum > target % total) {
                int out_win = nums[left % n];
                cur_sum -= out_win;
                left++;
            }

            if (cur_sum == target % total) {
                res = min(res, right - left);
            }
        }
        return res == INT_MAX ? -1 : res + k * n;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,2,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [2,4,6,8]\n3\n
// @lcpr case=end

 */

