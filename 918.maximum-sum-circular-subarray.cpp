/*
 * @lc app=leetcode.cn id=918 lang=cpp
 * @lcpr version=
 *
 * [918] 环形子数组的最大和
 *
 * https://leetcode.cn/problems/maximum-sum-circular-subarray/description/
 *
 * algorithms
 * Medium (45.94%)
 * Likes:    853
 * Dislikes: 0
 * Total Accepted:    132.7K
 * Total Submissions: 287.3K
 * Testcase Example:  '[1,-2,3,-2]'
 *
 * 给定一个长度为 n 的环形整数数组 nums ，返回 nums 的非空 子数组 的最大可能和 。
 * 
 * 环形数组 意味着数组的末端将会与开头相连呈环状。形式上， nums[i] 的下一个元素是 nums[(i + 1) % n] ， nums[i]
 * 的前一个元素是 nums[(i - 1 + n) % n] 。
 * 
 * 子数组 最多只能包含固定缓冲区 nums 中的每个元素一次。形式上，对于子数组 nums[i], nums[i + 1], ..., nums[j]
 * ，不存在 i <= k1, k2 <= j 其中 k1 % n == k2 % n 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,-2,3,-2]
 * 输出：3
 * 解释：从子数组 [3] 得到最大和 3
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [5,-3,5]
 * 输出：10
 * 解释：从子数组 [5,5] 得到最大和 5 + 5 = 10
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [3,-2,2,-3]
 * 输出：3
 * 解释：从子数组 [3] 和 [3,-2,2] 都可以得到最大和 3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 <= n <= 3 * 10^4
 * -3 * 10^4 <= nums[i] <= 3 * 10^4​​​​​​​
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
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_f = 0; // 计算最大子数组和的 DP 数组（空间优化成一个变量）
        int max_s = INT_MIN; // 最大子数组和，不能为空
        int min_f = 0; // 计算最小子数组和的 DP 数组（空间优化成一个变量）
        int min_s = 0; // 最小子数组和，可以为空（元素和为 0）
        int sum = 0; // nums 的元素和

        for (int x : nums) {
            max_f = max(max_f, 0) + x;
            max_s = max(max_s, max_f);
            min_f = min(min_f, 0) + x;
            min_s = min(min_s, min_f);
            sum += x;
        }
        return max_s < 0 ? max_s : max(max_s, sum - min_s);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,-2,3,-2]\n
// @lcpr case=end

// @lcpr case=start
// [5,-3,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,-2,2,-3]\n
// @lcpr case=end

 */

