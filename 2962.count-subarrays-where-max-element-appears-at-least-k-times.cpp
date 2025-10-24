/*
 * @lc app=leetcode.cn id=2962 lang=cpp
 * @lcpr version=30204
 *
 * [2962] 统计最大元素出现至少 K 次的子数组
 *
 * https://leetcode.cn/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/
 *
 * algorithms
 * Medium (60.78%)
 * Likes:    108
 * Dislikes: 0
 * Total Accepted:    41.8K
 * Total Submissions: 68.8K
 * Testcase Example:  '[1,3,2,3,3]\n2'
 *
 * 给你一个整数数组 nums 和一个 正整数 k 。
 * 
 * 请你统计有多少满足 「 nums 中的 最大 元素」至少出现 k 次的子数组，并返回满足这一条件的子数组的数目。
 * 
 * 子数组是数组中的一个连续元素序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,3,2,3,3], k = 2
 * 输出：6
 * 解释：包含元素 3 至少 2 次的子数组为：[1,3,2,3]、[1,3,2,3,3]、[3,2,3]、[3,2,3,3]、[2,3,3] 和
 * [3,3] 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,4,2,1], k = 3
 * 输出：0
 * 解释：没有子数组包含元素 4 至少 3 次。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^6
 * 1 <= k <= 10^5
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
    long long countSubarrays(vector<int>& nums, int k) {
        int max_num = *max_element(nums.begin(), nums.end());
        long long res = 0;
        int left = 0, right = 0, cnt = 0;
        while (right < nums.size()) {
            int in_win = nums[right];
            if (in_win == max_num) {
                cnt++;
            }
            right++;

            while (cnt >= k) {
                int out_win = nums[left];
                if (out_win == max_num) {
                    cnt--;
                }
                left++;
            }

            res += left;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2,3,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,4,2,1]\n3\n
// @lcpr case=end

 */

