/*
 * @lc app=leetcode.cn id=2563 lang=cpp
 * @lcpr version=30204
 *
 * [2563] 统计公平数对的数目
 *
 * https://leetcode.cn/problems/count-the-number-of-fair-pairs/description/
 *
 * algorithms
 * Medium (48.89%)
 * Likes:    161
 * Dislikes: 0
 * Total Accepted:    44.9K
 * Total Submissions: 91.8K
 * Testcase Example:  '[0,1,7,4,4,5]\n3\n6'
 *
 * 给你一个下标从 0 开始、长度为 n 的整数数组 nums ，和两个整数 lower 和 upper ，返回 公平数对的数目 。
 * 
 * 如果 (i, j) 数对满足以下情况，则认为它是一个 公平数对 ：
 * 
 * 
 * 0 <= i < j < n，且
 * lower <= nums[i] + nums[j] <= upper
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [0,1,7,4,4,5], lower = 3, upper = 6
 * 输出：6
 * 解释：共计 6 个公平数对：(0,3)、(0,4)、(0,5)、(1,3)、(1,4) 和 (1,5) 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,7,9,2,5], lower = 11, upper = 11
 * 输出：1
 * 解释：只有单个公平数对：(2,3) 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * nums.length == n
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= lower <= upper <= 10^9
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
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        for (int j = 0; j < nums.size(); j++) {
            // 注意要在 [0, j-1] 中二分，因为题目要求两个下标 i < j
            auto r = upper_bound(nums.begin(), nums.begin() + j, upper - nums[j]);
            auto l = lower_bound(nums.begin(), nums.begin() + j, lower - nums[j]);
            res += r - l;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,7,4,4,5]\n3\n6\n
// @lcpr case=end

// @lcpr case=start
// [1,7,9,2,5]\n11\n11\n
// @lcpr case=end

 */

