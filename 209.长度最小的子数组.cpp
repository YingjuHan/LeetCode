/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n==0) {
            return 0;
        }
        int result = INT_MAX;
        int start = 0;
        int end = 0;
        int sum = 0;
        while (end < n) {
            sum += nums[end];
            while (sum >= target) {
                result = min(result, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return result == INT_MAX ? 0 : result;
    }
};
// @lc code=end

