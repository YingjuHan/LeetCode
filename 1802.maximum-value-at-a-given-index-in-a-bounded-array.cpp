/*
 * @lc app=leetcode.cn id=1802 lang=cpp
 * @lcpr version=30204
 *
 * [1802] 有界数组中指定下标处的最大值
 *
 * https://leetcode.cn/problems/maximum-value-at-a-given-index-in-a-bounded-array/description/
 *
 * algorithms
 * Medium (37.67%)
 * Likes:    240
 * Dislikes: 0
 * Total Accepted:    30.3K
 * Total Submissions: 80.4K
 * Testcase Example:  '4\n2\n6'
 *
 * 给你三个正整数 n、index 和 maxSum 。你需要构造一个同时满足下述所有条件的数组 nums（下标 从 0 开始 计数）：
 * 
 * 
 * nums.length == n
 * nums[i] 是 正整数 ，其中 0 <= i < n
 * abs(nums[i] - nums[i+1]) <= 1 ，其中 0 <= i < n-1
 * nums 中所有元素之和不超过 maxSum
 * nums[index] 的值被 最大化
 * 
 * 
 * 返回你所构造的数组中的 nums[index] 。
 * 
 * 注意：abs(x) 等于 x 的前提是 x >= 0 ；否则，abs(x) 等于 -x 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 4, index = 2,  maxSum = 6
 * 输出：2
 * 解释：数组 [1,1,2,1] 和 [1,2,2,1] 满足所有条件。不存在其他在指定下标处具有更大值的有效数组。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 6, index = 1,  maxSum = 10
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= maxSum <= 10^9
 * 0 <= index < n
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
    int maxValue(int n, int index, int maxSum) {
        auto check = [&](int k) {
            long long sum = 0;
            sum += k;

            long l_len = index;
            long l_st = k - 1;
            if (l_len <= l_st) {
                sum += l_len * (l_st + (l_st - l_len + 1)) / 2;
            } else {
                sum += l_st * (l_st + 1) / 2 + (l_len - l_st);
            }

            long r_len = n - index - 1;
            long r_st = k - 1;
            if (r_len <= r_st) {
                sum += r_len * (r_st + (r_st - r_len + 1)) / 2;
            } else {
                sum += r_st * (r_st + 1) / 2 + (r_len - r_st);
            }

            return sum <= maxSum;
        };

        int left = 0, right = maxSum + 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n2\n6\n
// @lcpr case=end

// @lcpr case=start
// 6\n1\n10\n
// @lcpr case=end

 */

