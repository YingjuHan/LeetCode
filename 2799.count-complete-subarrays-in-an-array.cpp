/*
 * @lc app=leetcode.cn id=2799 lang=cpp
 * @lcpr version=30204
 *
 * [2799] 统计完全子数组的数目
 *
 * https://leetcode.cn/problems/count-complete-subarrays-in-an-array/description/
 *
 * algorithms
 * Medium (73.49%)
 * Likes:    98
 * Dislikes: 0
 * Total Accepted:    35.7K
 * Total Submissions: 48.6K
 * Testcase Example:  '[1,3,1,2,2]'
 *
 * 给你一个由 正 整数组成的数组 nums 。
 * 
 * 如果数组中的某个子数组满足下述条件，则称之为 完全子数组 ：
 * 
 * 
 * 子数组中 不同 元素的数目等于整个数组不同元素的数目。
 * 
 * 
 * 返回数组中 完全子数组 的数目。
 * 
 * 子数组 是数组中的一个连续非空序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,3,1,2,2]
 * 输出：4
 * 解释：完全子数组有：[1,3,1,2]、[1,3,1,2,2]、[3,1,2] 和 [3,1,2,2] 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [5,5,5,5]
 * 输出：10
 * 解释：数组仅由整数 5 组成，所以任意子数组都满足完全子数组的条件。子数组的总数为 10 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 2000
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
    int countCompleteSubarrays(vector<int>& nums) {
        int left = 0, right = 0, res = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        unordered_map<int, int> cnt;

        while (right < nums.size()) {
            int in_win = nums[right];
            cnt[in_win]++;
            right++;

            while (cnt.size() == st.size()) {
                int out_win = nums[left];
                cnt[out_win]--;
                if (cnt[out_win] == 0) {
                    cnt.erase(out_win);
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
// [1,3,1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,5,5,5]\n
// @lcpr case=end

 */

