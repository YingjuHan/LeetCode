// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3349 lang=cpp
 * @lcpr version=30204
 *
 * [3349] 检测相邻递增子数组 I
 *
 * https://leetcode.cn/problems/adjacent-increasing-subarrays-detection-i/description/
 *
 * algorithms
 * Easy (40.70%)
 * Likes:    19
 * Dislikes: 0
 * Total Accepted:    19.2K
 * Total Submissions: 41.7K
 * Testcase Example:  '[2,5,7,8,9,2,3,4,3,1]\n3'
 *
 * 给你一个由 n 个整数组成的数组 nums 和一个整数 k，请你确定是否存在 两个 相邻 且长度为 k 的 严格递增
 * 子数组。具体来说，需要检查是否存在从下标 a 和 b (a < b) 开始的 两个 子数组，并满足下述全部条件：
 * 
 * 
 * 这两个子数组 nums[a..a + k - 1] 和 nums[b..b + k - 1] 都是 严格递增 的。
 * 这两个子数组必须是 相邻的，即 b = a + k。
 * 
 * 
 * 如果可以找到这样的 两个 子数组，请返回 true；否则返回 false。
 * 
 * 子数组 是数组中的一个连续 非空 的元素序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,5,7,8,9,2,3,4,3,1], k = 3
 * 
 * 输出：true
 * 
 * 解释
 * 
 * 
 * 从下标 2 开始的子数组为 [7, 8, 9]，它是严格递增的。
 * 从下标 5 开始的子数组为 [2, 3, 4]，它也是严格递增的。
 * 两个子数组是相邻的，因此结果为 true。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,4,4,4,4,5,6,7], k = 5
 * 
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= nums.length <= 100
 * 1 <= 2 * k <= nums.length
 * -1000 <= nums[i] <= 1000
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
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int current = 1;
        int previous = 0;
        int res = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                current++;
            } else {
                previous = current;
                current = 1;
            }
            // 满足题目要求的两个相邻子数组有两种情况，结果取两种情况中较大的
            // 1. 两个子数组分别属于一对相邻的严格递增段: 前一个子数组属于previous，后一个子数组属于current，res为min(previous, current)
            // 2. 两个子数组属于同一个严格递增段: 两个数组都属于current，res为current/2 (向下取整)
            res = max(res, min(previous, current));
            res = max(res, current / 2);
        }
        return res >= k;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=hasIncreasingSubarrays
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [2,5,7,8,9,2,3,4,3,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,4,4,4,5,6,7]\n5\n
// @lcpr case=end

 */

