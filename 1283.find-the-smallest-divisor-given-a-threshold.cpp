/*
 * @lc app=leetcode.cn id=1283 lang=cpp
 * @lcpr version=30204
 *
 * [1283] 使结果不超过阈值的最小除数
 *
 * https://leetcode.cn/problems/find-the-smallest-divisor-given-a-threshold/description/
 *
 * algorithms
 * Medium (56.68%)
 * Likes:    146
 * Dislikes: 0
 * Total Accepted:    33.5K
 * Total Submissions: 59.1K
 * Testcase Example:  '[1,2,5,9]\n6'
 *
 * 给你一个整数数组 nums 和一个正整数 threshold  ，你需要选择一个正整数作为除数，然后将数组里每个数都除以它，并对除法结果求和。
 * 
 * 请你找出能够使上述结果小于等于阈值 threshold 的除数中 最小 的那个。
 * 
 * 每个数除以除数后都向上取整，比方说 7/3 = 3 ， 10/2 = 5 。
 * 
 * 题目保证一定有解。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,2,5,9], threshold = 6
 * 输出：5
 * 解释：如果除数为 1 ，我们可以得到和为 17 （1+2+5+9）。
 * 如果除数为 4 ，我们可以得到和为 7 (1+1+2+3) 。如果除数为 5 ，和为 5 (1+1+1+2)。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [2,3,5,7,11], threshold = 11
 * 输出：3
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [19], threshold = 5
 * 输出：4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 5 * 10^4
 * 1 <= nums[i] <= 10^6
 * nums.length <= threshold <= 10^6
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

/**
 * 二分答案：求最小
 * 题目求什么，就二分什么
 * 
 * 设除数为m，每个数除以m向上取整，由于m越大，商之和越小，存在单调性，可以二分答案
 * 最小的满足商之和 <= threshold的m就是答案
 */
class Solution {
public:
    bool check(vector<int>& nums, int threshold, int m) {
        // 上取整：当a和b均为正整数时：a/b的上取整 = (a+b-1)/b的下取整
        int sum = 0;
        for (int x : nums) {
            sum += (x + m - 1) / m;
            if (sum > threshold) {
                return false;
            }
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        // 采用闭区间
        // left端点起始值1
        // right端点起始值max(nums) - 1
        int left = 1, right = *max_element(nums.begin(), nums.end()) - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(nums, threshold, mid)) {
                right = mid - 1; // 搜索更小的
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,5,9]\n6\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5,7,11]\n11\n
// @lcpr case=end

// @lcpr case=start
// [19]\n5\n
// @lcpr case=end

 */

