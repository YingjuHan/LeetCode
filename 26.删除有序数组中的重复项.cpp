/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[slowIndex] != nums[fastIndex]) {
                slowIndex++;
                nums[slowIndex] = nums[fastIndex];

            }
        }
        return slowIndex + 1;
    }
};
// @lc code=end

