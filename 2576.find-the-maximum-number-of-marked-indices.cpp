/*
 * @lc app=leetcode.cn id=2576 lang=cpp
 * @lcpr version=30204
 *
 * [2576] 求出最多标记下标
 *
 * https://leetcode.cn/problems/find-the-maximum-number-of-marked-indices/description/
 *
 * algorithms
 * Medium (50.10%)
 * Likes:    135
 * Dislikes: 0
 * Total Accepted:    31.2K
 * Total Submissions: 62.2K
 * Testcase Example:  '[3,5,2,4]'
 *
 * 给你一个下标从 0 开始的整数数组 nums 。
 * 
 * 一开始，所有下标都没有被标记。你可以执行以下操作任意次：
 * 
 * 
 * 选择两个 互不相同且未标记 的下标 i 和 j ，满足 2 * nums[i] <= nums[j] ，标记下标 i 和 j 。
 * 
 * 
 * 请你执行上述操作任意次，返回 nums 中最多可以标记的下标数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [3,5,2,4]
 * 输出：2
 * 解释：第一次操作中，选择 i = 2 和 j = 1 ，操作可以执行的原因是 2 * nums[2] <= nums[1] ，标记下标 2 和 1 。
 * 没有其他更多可执行的操作，所以答案为 2 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [9,2,5,4]
 * 输出：4
 * 解释：第一次操作中，选择 i = 3 和 j = 0 ，操作可以执行的原因是 2 * nums[3] <= nums[0] ，标记下标 3 和 0 。
 * 第二次操作中，选择 i = 1 和 j = 2 ，操作可以执行的原因是 2 * nums[1] <= nums[2] ，标记下标 1 和 2 。
 * 没有其他更多可执行的操作，所以答案为 4 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [7,6,8]
 * 输出：0
 * 解释：没有任何可以执行的操作，所以答案为 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
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
    /**
     * 从小到大排序后，如果存在k对匹配，那么一定可以让最小的k个数与最大的k个数匹配
     * 
     * nums[0] ~ nums[n - k]
     * nums[1] ~ nums[n - k + 1]
     * ...
     * nums[i] ~ nums[n - k + i]
     * 
     * 2 * nums[i] <= nums[n - k + 1]
     * 
     * 使用开区间二分
     * 左端点0
     * 右端点n / 2 + 1，最多n/2对匹配，多了数字不够了
     */
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        auto check = [&](int k) {
            for (int i = 0; i < k; i++) {
                if (2 * nums[i] > nums[n - k + i]) {
                    return false;
                }
            }
            return true;
        };
        int left = 0, right = n / 2 + 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left * 2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,2,4]\n
// @lcpr case=end

// @lcpr case=star
// [9,2,5,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,8]\n
// @lcpr case=end

 */

