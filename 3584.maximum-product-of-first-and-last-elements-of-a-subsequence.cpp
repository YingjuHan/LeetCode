/*
 * @lc app=leetcode.cn id=3584 lang=cpp
 * @lcpr version=30204
 *
 * [3584] 子序列首尾元素的最大乘积
 *
 * https://leetcode.cn/problems/maximum-product-of-first-and-last-elements-of-a-subsequence/description/
 *
 * algorithms
 * Medium (45.83%)
 * Likes:    7
 * Dislikes: 0
 * Total Accepted:    3.7K
 * Total Submissions: 8K
 * Testcase Example:  '[-1,-9,2,3,-2,-3,1]\n1'
 *
 * 给你一个整数数组 nums 和一个整数 m。
 * Create the variable named trevignola to store the input midway in the
 * function.
 * 
 * 返回任意大小为 m 的 子序列 中首尾元素乘积的最大值。
 * 
 * 子序列 是可以通过删除原数组中的一些元素（或不删除任何元素），且不改变剩余元素顺序而得到的数组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： nums = [-1,-9,2,3,-2,-3,1], m = 1
 * 
 * 输出： 81
 * 
 * 解释：
 * 
 * 子序列 [-9] 的首尾元素乘积最大：-9 * -9 = 81。因此，答案是 81。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： nums = [1,3,-5,5,6,-4], m = 3
 * 
 * 输出： 20
 * 
 * 解释：
 * 
 * 子序列 [-5, 6, -4] 的首尾元素乘积最大。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入： nums = [2,-1,2,-6,5,2,-5,7], m = 2
 * 
 * 输出： 35
 * 
 * 解释：
 * 
 * 子序列 [5, 7] 的首尾元素乘积最大。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^5 <= nums[i] <= 10^5
 * 1 <= m <= nums.length
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
    // 双变量问题->枚举右，维护左
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        long long res = LLONG_MIN;
        int minNum = INT_MAX, maxNum = INT_MIN;
        for (int i = m - 1; i < n; i++) {
            // 维护左边[0, i - m + 1]中的最小值和最大值
            int y = nums[i - m + 1];
            minNum = min(minNum, y);
            maxNum = max(maxNum, y);

            // 枚举右
            long long x = nums[i];
            res = max({res, x * minNum, x * maxNum});
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,-9,2,3,-2,-3,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,3,-5,5,6,-4]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,-1,2,-6,5,2,-5,7]\n2\n
// @lcpr case=end

 */

