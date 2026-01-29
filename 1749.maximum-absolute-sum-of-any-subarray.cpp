/*
 * @lc app=leetcode.cn id=1749 lang=cpp
 * @lcpr version=30204
 *
 * [1749] 任意子数组和的绝对值的最大值
 *
 * https://leetcode.cn/problems/maximum-absolute-sum-of-any-subarray/description/
 *
 * algorithms
 * Medium (61.83%)
 * Likes:    201
 * Dislikes: 0
 * Total Accepted:    50.4K
 * Total Submissions: 80K
 * Testcase Example:  '[1,-3,2,3,-4]'
 *
 * 给你一个整数数组 nums 。一个子数组 [numsl, numsl+1, ..., numsr-1, numsr] 的 和的绝对值 为
 * abs(numsl + numsl+1 + ... + numsr-1 + numsr) 。
 * 
 * 请你找出 nums 中 和的绝对值 最大的任意子数组（可能为空），并返回该 最大值 。
 * 
 * abs(x) 定义如下：
 * 
 * 
 * 如果 x 是负整数，那么 abs(x) = -x 。
 * 如果 x 是非负整数，那么 abs(x) = x 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,-3,2,3,-4]
 * 输出：5
 * 解释：子数组 [2,3] 和的绝对值最大，为 abs(2+3) = abs(5) = 5 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [2,-5,1,-4,3,-2]
 * 输出：8
 * 解释：子数组 [-5,1,-4] 和的绝对值最大，为 abs(-5+1-4) = abs(-8) = 8 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
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
// 前缀和
class Solution1 {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int s = 0, mx = 0, mn = 0;
        for (int num : nums) {
            s += num;
            mx = max(mx, s);
            mn = min(mn, s);
        }
        return mx - mn;
    }
};

// 动态规划
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = 0, f_mx = 0, f_mn = 0;
        for (int x : nums) {
            f_mx = max(f_mx, 0) + x;
            f_mn = min(f_mn, 0) + x;
            ans = max({ans, f_mx, -f_mn});
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,-3,2,3,-4]\n
// @lcpr case=end

// @lcpr case=start
// [2,-5,1,-4,3,-2]\n
// @lcpr case=end

 */

