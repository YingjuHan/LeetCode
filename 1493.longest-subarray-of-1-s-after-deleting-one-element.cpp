/*
 * @lc app=leetcode.cn id=1493 lang=cpp
 * @lcpr version=30204
 *
 * [1493] 删掉一个元素以后全为 1 的最长子数组
 *
 * https://leetcode.cn/problems/longest-subarray-of-1s-after-deleting-one-element/description/
 *
 * algorithms
 * Medium (68.12%)
 * Likes:    214
 * Dislikes: 0
 * Total Accepted:    87.5K
 * Total Submissions: 128.3K
 * Testcase Example:  '[1,1,0,1]'
 *
 * 给你一个二进制数组 nums ，你需要从中删掉一个元素。
 * 
 * 请你在删掉元素的结果数组中，返回最长的且只包含 1 的非空子数组的长度。
 * 
 * 如果不存在这样的子数组，请返回 0 。
 * 
 * 
 * 
 * 提示 1：
 * 
 * 输入：nums = [1,1,0,1]
 * 输出：3
 * 解释：删掉位置 2 的数后，[1,1,1] 包含 3 个 1 。
 * 
 * 示例 2：
 * 
 * 输入：nums = [0,1,1,1,0,1,1,0,1]
 * 输出：5
 * 解释：删掉位置 4 的数字后，[0,1,1,1,1,1,0,1] 的最长全 1 子数组为 [1,1,1,1,1] 。
 * 
 * 示例 3：
 * 
 * 输入：nums = [1,1,1]
 * 输出：2
 * 解释：你必须要删除一个元素。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * nums[i] 要么是 0 要么是 1 。
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
    int longestSubarray(vector<int>& nums) {
        /**
         * 删掉一个元素以后全为 1 的最长子数组的长度，转化为找到子数组中最多一个0的子数组的长度
         */

        int left = 0, right = 0, res = 0;
        int cnt_0 = 0;

        while (right < nums.size()) {
            int in_win = nums[right];
            if (in_win == 0) {
                cnt_0++;
            }
            right++;

            while (cnt_0 > 1) {
                int out_win = nums[left];
                if (out_win == 0) {
                    cnt_0--;
                }
                left++;
            }
            res = max(res, right - 1 - left); // right已经更新到下一个位置，需要-1
        }
        return res - 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1,1,0,1,1,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n
// @lcpr case=end

 */

