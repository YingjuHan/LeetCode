/*
 * @lc app=leetcode.cn id=3152 lang=cpp
 * @lcpr version=30204
 *
 * [3152] 特殊数组 II
 *
 * https://leetcode.cn/problems/special-array-ii/description/
 *
 * algorithms
 * Medium (43.00%)
 * Likes:    66
 * Dislikes: 0
 * Total Accepted:    32.1K
 * Total Submissions: 71.9K
 * Testcase Example:  '[3,4,1,2,6]\n[[0,4]]'
 *
 * 如果数组的每一对相邻元素都是两个奇偶性不同的数字，则该数组被认为是一个 特殊数组 。
 * 
 * 你有一个整数数组 nums 和一个二维整数矩阵 queries，对于 queries[i] = [fromi, toi]，请你帮助你检查 子数组
 * nums[fromi..toi] 是不是一个 特殊数组 。
 * 
 * 返回布尔数组 answer，如果 nums[fromi..toi] 是特殊数组，则 answer[i] 为 true ，否则，answer[i] 为
 * false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3,4,1,2,6], queries = [[0,4]]
 * 
 * 输出：[false]
 * 
 * 解释：
 * 
 * 子数组是 [3,4,1,2,6]。2 和 6 都是偶数。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [4,3,1,6], queries = [[0,2],[2,3]]
 * 
 * 输出：[false,true]
 * 
 * 解释：
 * 
 * 
 * 子数组是 [4,3,1]。3 和 1 都是奇数。因此这个查询的答案是 false。
 * 子数组是 [1,6]。只有一对：(1,6)，且包含了奇偶性不同的数字。因此这个查询的答案是 true。
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * 1 <= queries.length <= 10^5
 * queries[i].length == 2
 * 0 <= queries[i][0] <= queries[i][1] <= nums.length - 1
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
    /**
     * a[i] = 0: nums[i - 1] nums[i]奇偶性不同
     * a[i] = 1: nums[i - 1] nums[i]奇偶性相同
     * 
     * 如果 a 的下标从 from 到 to−1 的子数组和等于 0，
     * 就说明 nums 的下标从 from 到 to 的这个子数组，
     * 其所有相邻元素的奇偶性都不同，该子数组为特殊数组。
     * 
     * 计算 a 的前缀和 s，可以快速判断子数组和是否为 0
     * s[to] - s[from] = 0
     * 
     */
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> s(n, 0);
        for (int i = 1; i < n; i++) {
            s[i] = s[i - 1] + (nums[i - 1] % 2 == nums[i] % 2);
        }

        vector<bool> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            res[i] = s[queries[i][0]] == s[queries[i][1]];
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,4,1,2,6]\n[[0,4]]\n
// @lcpr case=end

// @lcpr case=start
// [4,3,1,6]\n[[0,2],[2,3]]\n
// @lcpr case=end

 */

