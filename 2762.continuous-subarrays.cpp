/*
 * @lc app=leetcode.cn id=2762 lang=cpp
 * @lcpr version=30204
 *
 * [2762] 不间断子数组
 *
 * https://leetcode.cn/problems/continuous-subarrays/description/
 *
 * algorithms
 * Medium (57.00%)
 * Likes:    74
 * Dislikes: 0
 * Total Accepted:    15.6K
 * Total Submissions: 27.3K
 * Testcase Example:  '[5,4,2,4]'
 *
 * 给你一个下标从 0 开始的整数数组 nums 。nums 的一个子数组如果满足以下条件，那么它是 不间断 的：
 * 
 * 
 * i，i + 1 ，...，j  表示子数组中的下标。对于所有满足 i <= i1, i2 <= j 的下标对，都有 0 <= |nums[i1] -
 * nums[i2]| <= 2 。
 * 
 * 
 * 请你返回 不间断 子数组的总数目。
 * 
 * 子数组是一个数组中一段连续 非空 的元素序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [5,4,2,4]
 * 输出：8
 * 解释：
 * 大小为 1 的不间断子数组：[5], [4], [2], [4] 。
 * 大小为 2 的不间断子数组：[5,4], [4,2], [2,4] 。
 * 大小为 3 的不间断子数组：[4,2,4] 。
 * 没有大小为 4 的不间断子数组。
 * 不间断子数组的总数目为 4 + 3 + 1 = 8 。
 * 除了这些以外，没有别的不间断子数组。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,2,3]
 * 输出：6
 * 解释：
 * 大小为 1 的不间断子数组：[1], [2], [3] 。
 * 大小为 2 的不间断子数组：[1,2], [2,3] 。
 * 大小为 3 的不间断子数组：[1,2,3] 。
 * 不间断子数组的总数目为 3 + 2 + 1 = 6 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
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
#include <map>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long res = 0;
        map<int, int> cnt;
        int left = 0, right = 0;
        while (right < nums.size()) {
            int in_win = nums[right];
            cnt[in_win]++;
            right++;

            while (cnt.rbegin()->first - cnt.begin()->first > 2)
            {
                int out_win = nums[left];
                cnt[out_win]--;
                if (cnt[out_win] == 0) {
                    cnt.erase(out_win);
                }
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
// [5,4,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

