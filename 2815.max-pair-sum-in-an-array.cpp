/*
 * @lc app=leetcode.cn id=2815 lang=cpp
 * @lcpr version=30204
 *
 * [2815] 数组中的最大数对和
 *
 * https://leetcode.cn/problems/max-pair-sum-in-an-array/description/
 *
 * algorithms
 * Easy (70.56%)
 * Likes:    33
 * Dislikes: 0
 * Total Accepted:    19K
 * Total Submissions: 25.4K
 * Testcase Example:  '[112,131,411]'
 *
 * 给你一个下标从 0 开始的整数数组 nums 。请你从 nums 中找出和 最大 的一对数，且这两个数数位上最大的数字相等。
 * 
 * 返回最大和，如果不存在满足题意的数字对，返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [51,71,17,24,42]
 * 输出：88
 * 解释：
 * i = 1 和 j = 2 ，nums[i] 和 nums[j] 数位上最大的数字相等，且这一对的总和 71 + 17 = 88 。 
 * i = 3 和 j = 4 ，nums[i] 和 nums[j] 数位上最大的数字相等，且这一对的总和 24 + 42 = 66 。
 * 可以证明不存在其他数对满足数位上最大的数字相等，所以答案是 88 。
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：-1
 * 解释：不存在数对满足数位上最大的数字相等。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= nums.length <= 100
 * 1 <= nums[i] <= 10^4
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
    int maxSum(vector<int>& nums) {
        int res = -1;
        vector<int> max_val(10, INT_MIN);
        for (int num : nums) {
            int max_d = 0;
            for (int x = num; x > 0 ; x /= 10) {
                max_d = max(max_d, x % 10);
            }

            res = max(res, num + max_val[max_d]);
            max_val[max_d] = max(max_val[max_d], num);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [51,71,17,24,42]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

 */

