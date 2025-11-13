/*
 * @lc app=leetcode.cn id=560 lang=cpp
 * @lcpr version=30204
 *
 * [560] 和为 K 的子数组
 *
 * https://leetcode.cn/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (44.39%)
 * Likes:    2938
 * Dislikes: 0
 * Total Accepted:    893.2K
 * Total Submissions: 2M
 * Testcase Example:  '[1,1,1]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
 * 
 * 子数组是数组中元素的连续非空序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,1,1], k = 2
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,2,3], k = 3
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
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
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre_sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre_sum[i + 1] = pre_sum[i] + nums[i];
        }

        unordered_map<int, int> cnt;
        int res = 0;
        for (int s : pre_sum) {
            res += cnt.count(s - k) > 0 ? cnt[s - k] : 0;
            cnt[s]++;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n3\n
// @lcpr case=end

 */

