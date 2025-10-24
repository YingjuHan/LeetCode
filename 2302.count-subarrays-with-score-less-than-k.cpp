/*
 * @lc app=leetcode.cn id=2302 lang=cpp
 * @lcpr version=30204
 *
 * [2302] 统计得分小于 K 的子数组数目
 *
 * https://leetcode.cn/problems/count-subarrays-with-score-less-than-k/description/
 *
 * algorithms
 * Hard (60.79%)
 * Likes:    105
 * Dislikes: 0
 * Total Accepted:    34.7K
 * Total Submissions: 57.1K
 * Testcase Example:  '[2,1,4,3,5]\n10'
 *
 * 一个数组的 分数 定义为数组之和 乘以 数组的长度。
 * 
 * 
 * 比方说，[1, 2, 3, 4, 5] 的分数为 (1 + 2 + 3 + 4 + 5) * 5 = 75 。
 * 
 * 
 * 给你一个正整数数组 nums 和一个整数 k ，请你返回 nums 中分数 严格小于 k 的 非空整数子数组数目。
 * 
 * 子数组 是数组中的一个连续元素序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [2,1,4,3,5], k = 10
 * 输出：6
 * 解释：
 * 有 6 个子数组的分数小于 10 ：
 * - [2] 分数为 2 * 1 = 2 。
 * - [1] 分数为 1 * 1 = 1 。
 * - [4] 分数为 4 * 1 = 4 。
 * - [3] 分数为 3 * 1 = 3 。 
 * - [5] 分数为 5 * 1 = 5 。
 * - [2,1] 分数为 (2 + 1) * 2 = 6 。
 * 注意，子数组 [1,4] 和 [4,3,5] 不符合要求，因为它们的分数分别为 10 和 36，但我们要求子数组的分数严格小于 10 。
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,1,1], k = 5
 * 输出：5
 * 解释：
 * 除了 [1,1,1] 以外每个子数组分数都小于 5 。
 * [1,1,1] 分数为 (1 + 1 + 1) * 3 = 9 ，大于 5 。
 * 所以总共有 5 个子数组得分小于 5 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * 1 <= k <= 10^15
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
    long long countSubarrays(vector<int>& nums, long long k) {
        long long res = 0, sum = 0;
        int left = 0, right = 0;
        long long prod = 1LL;
        while (right < nums.size()) {
            int in_win = nums[right];
            sum += in_win;
            right++;
            while (sum * (right - left) >= k) {
                sum -= nums[left];
                left++;
            }
            res += right - left;
        }
        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,4,3,5]\n10\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n5\n
// @lcpr case=end

 */

