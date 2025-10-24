/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=30204
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (45.93%)
 * Likes:    3128
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 3M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 * 
 * 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 * 
 * 示例 2：
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 * 
 * 示例 3：
 * 
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums 是一个非递减数组
 * -10^9 <= target <= 10^9
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
    int lower_bound1(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1; // 闭区间 [left, right]
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1; // [mid + 1, right]
            } else {
                right = mid - 1; // [left, mid - 1]
            }
        }
        return left;
    }

    int lower_bound2(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1; // 左闭右开区间 [left, right)
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) { 
                left = mid + 1; // [mid + 1, right]
            } else {
                right = mid;  // [left, mid)
            }
        }
        return left; //  left == right
    }

    int lower_bound3(vector<int>& nums, int target) {
        int left = -1, right = nums.size(); // 开区间 (left, right)
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) { 
                left = mid; // (mid, right)
            } else {
                right = mid;  // (left, mid)
            }
        }
        return right;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound1(nums, target);
        if (start == nums.size() || nums[start] != target) {
            return {-1, -1};
        }
        int end = lower_bound1(nums, target + 1) - 1;
        return {start, end};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */

