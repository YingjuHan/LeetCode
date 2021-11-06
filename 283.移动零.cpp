/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 慢指针所指向的都是不等于0的元素，筛选出一个不等于0的元素就放到慢指针所指的位置，
        // 然后让慢指针前进一步将快指针走到末尾的时候，其实已经全部交换完毕了
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != 0) {
                int temp = nums[fastIndex];
                nums[fastIndex] = nums[slowIndex];
                nums[slowIndex] = temp;
                slowIndex++;
            }
        }
    }
};
// @lc code=end

