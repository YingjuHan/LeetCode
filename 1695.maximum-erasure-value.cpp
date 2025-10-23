// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1695 lang=cpp
 * @lcpr version=30204
 *
 * [1695] 删除子数组的最大得分
 *
 * https://leetcode.cn/problems/maximum-erasure-value/description/
 *
 * algorithms
 * Medium (63.76%)
 * Likes:    140
 * Dislikes: 0
 * Total Accepted:    54.6K
 * Total Submissions: 85K
 * Testcase Example:  '[4,2,4,5,6]'
 *
 * 给你一个正整数数组 nums ，请你从中删除一个含有 若干不同元素 的子数组。删除子数组的 得分 就是子数组各元素之 和 。
 * 
 * 返回 只删除一个 子数组可获得的 最大得分 。
 * 
 * 如果数组 b 是数组 a 的一个连续子序列，即如果它等于 a[l],a[l+1],...,a[r] ，那么它就是 a 的一个子数组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [4,2,4,5,6]
 * 输出：17
 * 解释：最优子数组是 [2,4,5,6]
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [5,2,1,2,5,2,1,2,5]
 * 输出：8
 * 解释：最优子数组是 [5,2,1] 或 [1,2,5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
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
    int maximumUniqueSubarray(vector<int>& nums) {
        int right = 0, left = 0, res = 0, cnt = 0;
        unordered_set<int> st;

        for (int x : nums) {
            while (st.count(x)) {
                st.erase(nums[left]);
                cnt -= nums[left];
                left++;
            }
            st.insert(x);
            cnt += x;
            res = max(res, cnt);
        }
        return res;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maximumUniqueSubarray
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [4,2,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [5,2,1,2,5,2,1,2,5]\n
// @lcpr case=end

 */

