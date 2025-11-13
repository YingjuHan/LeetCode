/*
 * @lc app=leetcode.cn id=1546 lang=cpp
 * @lcpr version=
 *
 * [1546] 和为目标值且不重叠的非空子数组的最大数目
 *
 * https://leetcode.cn/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/description/
 *
 * algorithms
 * Medium (49.76%)
 * Likes:    113
 * Dislikes: 0
 * Total Accepted:    11.7K
 * Total Submissions: 23.4K
 * Testcase Example:  '[1,1,1,1,1]\n2'
 *
 * 给你一个数组 nums 和一个整数 target 。
 * 
 * 请你返回 非空不重叠 子数组的最大数目，且每个子数组中数字和都为 target 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,1,1,1,1], target = 2
 * 输出：2
 * 解释：总共有 2 个不重叠子数组（加粗数字表示） [1,1,1,1,1] ，它们的和为目标值 2 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [-1,3,5,1,4,2,-9], target = 6
 * 输出：2
 * 解释：总共有 3 个子数组和为 6 。
 * ([5,1], [4,2], [3,5,1,4,2,-9]) 但只有前 2 个是不重叠的。
 * 
 * 示例 3：
 * 
 * 输入：nums = [-2,6,6,3,5,4,1,2,8], target = 10
 * 输出：3
 * 
 * 
 * 示例 4：
 * 
 * 输入：nums = [0,0,0], target = 0
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 0 <= target <= 10^6
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
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<long long, int> cnt;
        cnt[0] = -1;
        long long sum = 0;
        int end = -1, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (cnt.count(sum - target) > 0) {
                if (cnt[sum - target] + 1 > end) {
                    res++;
                    end = i;
                }
            }
            cnt[sum] = i;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,1,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [-1,3,5,1,4,2,-9]\n6\n
// @lcpr case=end

// @lcpr case=start
// [-2,6,6,3,5,4,1,2,8]\n10\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n0\n
// @lcpr case=end

 */

