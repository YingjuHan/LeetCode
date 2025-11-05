/*
 * @lc app=leetcode.cn id=2909 lang=cpp
 * @lcpr version=30204
 *
 * [2909] 元素和最小的山形三元组 II
 *
 * https://leetcode.cn/problems/minimum-sum-of-mountain-triplets-ii/description/
 *
 * algorithms
 * Medium (58.22%)
 * Likes:    40
 * Dislikes: 0
 * Total Accepted:    14.5K
 * Total Submissions: 24.8K
 * Testcase Example:  '[8,6,1,5,3]'
 *
 * 给你一个下标从 0 开始的整数数组 nums 。
 * 
 * 如果下标三元组 (i, j, k) 满足下述全部条件，则认为它是一个 山形三元组 ：
 * 
 * 
 * i < j < k
 * nums[i] < nums[j] 且 nums[k] < nums[j]
 * 
 * 
 * 请你找出 nums 中 元素和最小 的山形三元组，并返回其 元素和 。如果不存在满足条件的三元组，返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [8,6,1,5,3]
 * 输出：9
 * 解释：三元组 (2, 3, 4) 是一个元素和等于 9 的山形三元组，因为： 
 * - 2 < 3 < 4
 * - nums[2] < nums[3] 且 nums[4] < nums[3]
 * 这个三元组的元素和等于 nums[2] + nums[3] + nums[4] = 9 。可以证明不存在元素和小于 9 的山形三元组。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [5,4,8,7,10,2]
 * 输出：13
 * 解释：三元组 (1, 3, 5) 是一个元素和等于 13 的山形三元组，因为： 
 * - 1 < 3 < 5 
 * - nums[1] < nums[3] 且 nums[5] < nums[3]
 * 这个三元组的元素和等于 nums[1] + nums[3] + nums[5] = 13 。可以证明不存在元素和小于 13 的山形三元组。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [6,5,4,3,4,5]
 * 输出：-1
 * 解释：可以证明 nums 中不存在山形三元组。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^8
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
    int minimumSum(vector<int>& nums) {
        int pre = nums[0], res = INT_MAX, n = nums.size();
        vector<int> suf(n);
        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i > 1; i--) {
            suf[i] = min(suf[i + 1], nums[i]);
        }
        for (int j = 1; j < n - 1; j++) {
            if (pre < nums[j] && nums[j] > suf[j + 1]) {
                res = min(res, pre + nums[j] + suf[j + 1]);
            }
            pre = min(pre, nums[j]);
        }
        return res == INT_MAX ? -1 : res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [8,6,1,5,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,7,10,2]\n
// @lcpr case=end

// @lcpr case=start
// [6,5,4,3,4,5]\n
// @lcpr case=end

 */

