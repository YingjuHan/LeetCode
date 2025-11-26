// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1793 lang=cpp
 * @lcpr version=30204
 *
 * [1793] 好子数组的最大分数
 *
 * https://leetcode.cn/problems/maximum-score-of-a-good-subarray/description/
 *
 * algorithms
 * Hard (55.84%)
 * Likes:    181
 * Dislikes: 0
 * Total Accepted:    30.5K
 * Total Submissions: 53.7K
 * Testcase Example:  '[1,4,3,7,4,5]\n3'
 *
 * 给你一个整数数组 nums （下标从 0 开始）和一个整数 k 。
 * 
 * 一个子数组 (i, j) 的 分数 定义为 min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1)
 * 。一个 好 子数组的两个端点下标需要满足 i <= k <= j 。
 * 
 * 请你返回 好 子数组的最大可能 分数 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,4,3,7,4,5], k = 3
 * 输出：15
 * 解释：最优子数组的左右端点下标是 (1, 5) ，分数为 min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [5,5,4,5,4,1,1,1], k = 0
 * 输出：20
 * 解释：最优子数组的左右端点下标是 (0, 4) ，分数为 min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 2 * 10^4
 * 0 <= k < nums.length
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
    int maximumScore(vector<int>& nums, int k) {
        int res = 0;
        stack<int> st;
        nums.push_back(-1);
        st.push(-1);
        for (int right = 0; right < nums.size(); right++) {
            int x = nums[right];
            while (st.size() > 1 && nums[st.top()] >= x) {
                int lowh_idx = st.top();
                st.pop();
                int left = st.top();
                if (left < k && k < right) {
                    res = max(res, nums[lowh_idx] * (right - left - 1));
                }
            }
        }
        return res;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maximumScore
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,4,3,7,4,5]\n3\n
// @lcpr case=end

// @lcpr case=start
// [5,5,4,5,4,1,1,1]\n0\n
// @lcpr case=end

 */

