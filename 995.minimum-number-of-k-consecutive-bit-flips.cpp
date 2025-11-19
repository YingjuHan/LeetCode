/*
 * @lc app=leetcode.cn id=995 lang=cpp
 * @lcpr version=30204
 *
 * [995] K 连续位的最小翻转次数
 *
 * https://leetcode.cn/problems/minimum-number-of-k-consecutive-bit-flips/description/
 *
 * algorithms
 * Hard (54.49%)
 * Likes:    311
 * Dislikes: 0
 * Total Accepted:    31K
 * Total Submissions: 56.2K
 * Testcase Example:  '[0,1,0]\n1'
 *
 * 给定一个二进制数组 nums 和一个整数 k 。
 * 
 * k位翻转 就是从 nums 中选择一个长度为 k 的 子数组 ，同时把子数组中的每一个 0 都改成 1 ，把子数组中的每一个 1 都改成 0 。
 * 
 * 返回数组中不存在 0 所需的最小 k位翻转 次数。如果不可能，则返回 -1 。
 * 
 * 子数组 是数组的 连续 部分。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [0,1,0], K = 1
 * 输出：2
 * 解释：先翻转 A[0]，然后翻转 A[2]。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,1,0], K = 2
 * 输出：-1
 * 解释：无论我们怎样翻转大小为 2 的子数组，我们都不能使数组变为 [1,1,1]。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [0,0,0,1,0,1,1,0], K = 3
 * 输出：3
 * 解释：
 * 翻转 A[0],A[1],A[2]: A变成 [1,1,1,1,0,1,1,0]
 * 翻转 A[4],A[5],A[6]: A变成 [1,1,1,1,1,0,0,0]
 * 翻转 A[5],A[6],A[7]: A变成 [1,1,1,1,1,1,1,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= k <= nums.length
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
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> diff(n + 1);
        diff[0] = nums[0];
        for (int i = 1; i < n; i++) {
            diff[i] = nums[i] - nums[i - 1];
        }

        // 如何记录操作数？
        // 遇到0就反转，答案就加一，修改当前的值这样前半部分就没啥影响

        int res = 0, s = 0;
        for (int i = 0; i < n; i++) {
            s += diff[i];
            if (s % 2 == 0) {
                if (i + k > n) {
                    return -1;
                } else {
                    s+=1;
                    diff[i] += 1;
                    diff[i + k] -= 1;
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,1,0]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0,1,0,1,1,0]\n3\n
// @lcpr case=end

 */

