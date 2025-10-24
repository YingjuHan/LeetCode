/*
 * @lc app=leetcode.cn id=930 lang=cpp
 * @lcpr version=30204
 *
 * [930] 和相同的二元子数组
 *
 * https://leetcode.cn/problems/binary-subarrays-with-sum/description/
 *
 * algorithms
 * Medium (59.71%)
 * Likes:    371
 * Dislikes: 0
 * Total Accepted:    70.9K
 * Total Submissions: 118.8K
 * Testcase Example:  '[1,0,1,0,1]\n2'
 *
 * 给你一个二元数组 nums ，和一个整数 goal ，请你统计并返回有多少个和为 goal 的 非空 子数组。
 * 
 * 子数组 是数组的一段连续部分。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,0,1,0,1], goal = 2
 * 输出：4
 * 解释：
 * 有 4 个满足题目要求的子数组：[1,0,1]、[1,0,1,0]、[0,1,0,1]、[1,0,1]
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [0,0,0,0,0], goal = 0
 * 输出：15
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * nums[i] 不是 0 就是 1
 * 0 <= goal <= nums.length
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
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int res = 0, left_1 = 0, left_2 = 0, right = 0;
        int temp_sum_1 = 0, temp_sum_2 = 0;
        
        while (right < nums.size()) {
            int in_win = nums[right];
            temp_sum_1 += in_win;
            temp_sum_2 += in_win;
            right++;

            while (left_1 <= right - 1 && temp_sum_1 >= goal) {
                temp_sum_1 -= nums[left_1];
                left_1++;
            }

            while (left_2 <= right - 1 && temp_sum_2 >= goal + 1) {
                temp_sum_2 -= nums[left_2];
                left_2++;
            }

            res += left_1 - left_2;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,1,0,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0,0,0]\n0\n
// @lcpr case=end

 */

