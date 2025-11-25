/*
 * @lc app=leetcode.cn id=3113 lang=cpp
 * @lcpr version=30204
 *
 * [3113] 边界元素是最大值的子数组数目
 *
 * https://leetcode.cn/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/description/
 *
 * algorithms
 * Hard (42.40%)
 * Likes:    20
 * Dislikes: 0
 * Total Accepted:    5.5K
 * Total Submissions: 11.5K
 * Testcase Example:  '[1,4,3,3,2]'
 *
 * 给你一个 正 整数数组 nums 。
 * 
 * 请你求出 nums 中有多少个子数组，满足子数组中 第一个 和 最后一个 元素都是这个子数组中的 最大 值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,4,3,3,2]
 * 
 * 输出：6
 * 
 * 解释：
 * 
 * 总共有 6 个子数组满足第一个元素和最后一个元素都是子数组中的最大值：
 * 
 * 
 * 子数组 [1,4,3,3,2] ，最大元素为 1 ，第一个和最后一个元素都是 1 。
 * 子数组 [1,4,3,3,2] ，最大元素为 4 ，第一个和最后一个元素都是 4 。
 * 子数组 [1,4,3,3,2] ，最大元素为 3 ，第一个和最后一个元素都是 3 。
 * 子数组 [1,4,3,3,2] ，最大元素为 3 ，第一个和最后一个元素都是 3 。
 * 子数组 [1,4,3,3,2] ，最大元素为 2 ，第一个和最后一个元素都是 2 。
 * 子数组 [1,4,3,3,2] ，最大元素为 3 ，第一个和最后一个元素都是 3 。
 * 
 * 
 * 所以我们返回 6 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,3,3]
 * 
 * 输出：6
 * 
 * 解释：
 * 
 * 总共有 6 个子数组满足第一个元素和最后一个元素都是子数组中的最大值：
 * 
 * 
 * 子数组 [3,3,3] ，最大元素为 3 ，第一个和最后一个元素都是 3 。
 * 子数组 [3,3,3] ，最大元素为 3 ，第一个和最后一个元素都是 3 。
 * 子数组 [3,3,3] ，最大元素为 3 ，第一个和最后一个元素都是 3 。
 * 子数组 [3,3,3] ，最大元素为 3 ，第一个和最后一个元素都是 3 。
 * 子数组 [3,3,3] ，最大元素为 3 ，第一个和最后一个元素都是 3 。
 * 子数组 [3,3,3] ，最大元素为 3 ，第一个和最后一个元素都是 3 。
 * 
 * 
 * 所以我们返回 6 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1]
 * 
 * 输出：1
 * 
 * 解释：
 * 
 * nums 中只有一个子数组 [1] ，最大元素为 1 ，第一个和最后一个元素都是 1 。
 * 
 * 所以我们返回 1 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
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
    long long numberOfSubarrays(vector<int>& nums) {
        long long res = nums.size();
        stack<pair<int, int>> st;
        st.push({INT_MAX, 0}); // 占位
        for (int x : nums) {
            while (x > st.top().first) {
                st.pop();
            }
            if (x == st.top().first) {
                res += st.top().second++;
            } else { // x < st.top().first
                st.push({x, 1});
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,4,3,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

