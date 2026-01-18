/*
 * @lc app=leetcode.cn id=3566 lang=cpp
 * @lcpr version=30204
 *
 * [3566] 等积子集的划分方案
 *
 * https://leetcode.cn/problems/partition-array-into-two-equal-product-subsets/description/
 *
 * algorithms
 * Medium (43.68%)
 * Likes:    8
 * Dislikes: 0
 * Total Accepted:    4.3K
 * Total Submissions: 9.8K
 * Testcase Example:  '[3,1,6,8,4]\n24'
 *
 * 给你一个整数数组 nums，其中包含的正整数 互不相同 ，另给你一个整数 target。
 * 
 * 请判断是否可以将 nums 分成两个 非空、互不相交 的 子集 ，并且每个元素必须  恰好 属于 一个 子集，使得这两个子集中元素的乘积都等于
 * target。
 * 
 * 如果存在这样的划分，返回 true；否则，返回 false。
 * 
 * 子集 是数组中元素的一个选择集合。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： nums = [3,1,6,8,4], target = 24
 * 
 * 输出： true
 * 
 * 解释：子集 [3, 8] 和 [1, 6, 4] 的乘积均为 24。因此，输出为 true 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： nums = [2,5,3,7], target = 15
 * 
 * 输出： false
 * 
 * 解释：无法将 nums 划分为两个非空的互不相交子集，使得它们的乘积均为 15。因此，输出为 false。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 12
 * 1 <= target <= 10^15
 * 1 <= nums[i] <= 100
 * nums 中的所有元素互不相同。
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
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        auto dfs = [&](this auto&& dfs, int i, long long mul1, long long mul2) -> bool {
            if (mul1 > target || mul2 > target) {
                return false;
            }
            if (i == nums.size()) {
                return mul1 == target && mul2 == target;
            }

            return dfs(i + 1, mul1 * nums[i], mul2) || dfs(i + 1, mul1, mul2 * nums[i]);
        };
        return dfs(0, 1, 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,6,8,4]\n24\n
// @lcpr case=end

// @lcpr case=start
// [2,5,3,7]\n15\n
// @lcpr case=end

 */

