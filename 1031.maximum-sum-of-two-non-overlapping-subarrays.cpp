/*
 * @lc app=leetcode.cn id=1031 lang=cpp
 * @lcpr version=30204
 *
 * [1031] 两个无重叠子数组的最大和
 *
 * https://leetcode.cn/problems/maximum-sum-of-two-non-overlapping-subarrays/description/
 *
 * algorithms
 * Medium (66.89%)
 * Likes:    313
 * Dislikes: 0
 * Total Accepted:    33.3K
 * Total Submissions: 49.8K
 * Testcase Example:  '[0,6,5,2,2,5,1,9,4]\n1\n2'
 *
 * 给你一个整数数组 nums 和两个整数 firstLen 和 secondLen，请你找出并返回两个无重叠 子数组 中元素的最大和，长度分别为
 * firstLen 和 secondLen 。
 * 
 * 长度为 firstLen 的子数组可以出现在长为 secondLen 的子数组之前或之后，但二者必须是无重叠。
 * 
 * 子数组是数组的一个 连续 部分。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [0,6,5,2,2,5,1,9,4], firstLen = 1, secondLen = 2
 * 输出：20
 * 解释：子数组的一种选择中，[9] 长度为 1，[6,5] 长度为 2。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [3,8,1,3,2,1,8,9,0], firstLen = 3, secondLen = 2
 * 输出：29
 * 解释：子数组的一种选择中，[3,8,1] 长度为 3，[8,9] 长度为 2。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [2,1,5,6,0,9,5,0,3,8], firstLen = 4, secondLen = 3
 * 输出：31
 * 解释：子数组的一种选择中，[5,6,0,9] 长度为 4，[0,3,8] 长度为 3。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= firstLen, secondLen <= 1000
 * 2 <= firstLen + secondLen <= 1000
 * firstLen + secondLen <= nums.length <= 1000
 * 0 <= nums[i] <= 1000
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
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        // 数组下标范围为左闭右开区间 [i−Len,i)，其元素和为 s[i]−s[i−Len]。
        int res = 0, n = nums.size(), s[n + 1];
        s[0] = 0;
        partial_sum(nums.begin(), nums.end(), s + 1); // 前缀和
        
        auto f = [&](int firstLen, int secondLen) { // 枚举第二个数组，维护第一个数组的最大值
            int maxSumA = 0;
            for (int i = firstLen + secondLen; i <= n; i++) {
                maxSumA = max(maxSumA, s[i - secondLen] - s[i - secondLen - firstLen]);
                res = max(res, maxSumA + s[i] - s[i - secondLen]);
            }
        };

        f(firstLen, secondLen);
        f(secondLen, firstLen);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,6,5,2,2,5,1,9,4]\n1\n2\n
// @lcpr case=end

// @lcpr case=start
// [3,8,1,3,2,1,8,9,0]\n3\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,1,5,6,0,9,5,0,3,8]\n4\n3\n
// @lcpr case=end

 */

