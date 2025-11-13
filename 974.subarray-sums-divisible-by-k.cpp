/*
 * @lc app=leetcode.cn id=974 lang=cpp
 * @lcpr version=30204
 *
 * [974] 和可被 K 整除的子数组
 *
 * https://leetcode.cn/problems/subarray-sums-divisible-by-k/description/
 *
 * algorithms
 * Medium (48.90%)
 * Likes:    563
 * Dislikes: 0
 * Total Accepted:    80.6K
 * Total Submissions: 161.4K
 * Testcase Example:  '[4,5,0,-2,-3,1]\n5'
 *
 * 给定一个整数数组 nums 和一个整数 k ，返回其中元素之和可被 k 整除的非空 子数组 的数目。
 * 
 * 子数组 是数组中 连续 的部分。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [4,5,0,-2,-3,1], k = 5
 * 输出：7
 * 解释：
 * 有 7 个子数组满足其元素之和可被 k = 5 整除：
 * [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2,
 * -3]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [5], k = 9
 * 输出: 0
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * -10^4 <= nums[i] <= 10^4
 * 2 <= k <= 10^4
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
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        int res = 0, preSum = 0;
        for (int i = 0; i < n; i++) {
            cnt[preSum]++;
            preSum = (preSum + nums[i] % k + k) % k; // 保证preSum >= 0
            res += cnt[preSum];
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,5,0,-2,-3,1]\n5\n
// @lcpr case=end

// @lcpr case=start
// [5]\n9\n
// @lcpr case=end

 */

