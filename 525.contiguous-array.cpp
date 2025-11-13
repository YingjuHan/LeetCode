/*
 * @lc app=leetcode.cn id=525 lang=cpp
 * @lcpr version=
 *
 * [525] 连续数组
 *
 * https://leetcode.cn/problems/contiguous-array/description/
 *
 * algorithms
 * Medium (55.47%)
 * Likes:    810
 * Dislikes: 0
 * Total Accepted:    95.9K
 * Total Submissions: 172.6K
 * Testcase Example:  '[0,1]'
 *
 * 给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [0,1]
 * 输出：2
 * 说明：[0, 1] 是具有相同数量 0 和 1 的最长连续子数组。
 * 
 * 示例 2：
 * 
 * 输入：nums = [0,1,0]
 * 输出：2
 * 说明：[0, 1] (或 [1, 0]) 是具有相同数量 0 和 1 的最长连续子数组。
 * 
 * 示例 3：
 * 
 * 输入：nums = [0,1,1,1,1,1,0,0,0]
 * 输出：6
 * 解释：[1,1,1,0,0,0] 是具有相同数量 0 和 1 的最长连续子数组。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * nums[i] 不是 0 就是 1
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
    int findMaxLength(vector<int>& nums) {
        for (int& x : nums) {
            x = x == 1 ? 1 : -1;
        }
        int n = nums.size();
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }

        unordered_map<int, int> pos;
        int res = 0;
        for (int i = 0; i <= n; i++) {
            int s = sum[i];
            if (pos.contains(s)) {
                res = max(res, i - pos[s]);
            } else {
                pos[s] = i;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1,1,1,1,0,0,0]\n
// @lcpr case=end

 */

