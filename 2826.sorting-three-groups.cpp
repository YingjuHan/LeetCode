/*
 * @lc app=leetcode.cn id=2826 lang=cpp
 * @lcpr version=30204
 *
 * [2826] 将三个组排序
 *
 * https://leetcode.cn/problems/sorting-three-groups/description/
 *
 * algorithms
 * Medium (66.34%)
 * Likes:    45
 * Dislikes: 0
 * Total Accepted:    15.6K
 * Total Submissions: 23.4K
 * Testcase Example:  '[2,1,3,2,1]'
 *
 * 给你一个整数数组 nums 。nums 的每个元素是 1，2 或 3。在每次操作中，你可以删除 nums 中的一个元素。返回使 nums 成为 非递减
 * 顺序所需操作数的 最小值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [2,1,3,2,1]
 * 输出：3
 * 解释：
 * 其中一个最优方案是删除 nums[0]，nums[2] 和 nums[3]。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,3,2,1,3,3]
 * 输出：2
 * 解释：
 * 其中一个最优方案是删除 nums[1] 和 nums[2]。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [2,2,2,2,3,3]
 * 输出：0
 * 解释：
 * nums 已是非递减顺序的。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 100
 * 1 <= nums[i] <= 3
 * 
 * 
 * 进阶：你可以使用 O(n) 时间复杂度以内的算法解决吗？
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
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> g;
        for (int x : nums) {
            auto it = ranges::upper_bound(g, x);
            if (it == g.end()) {
                g.push_back(x);
            } else {
                *it = x;
            }
        }
        return n - g.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,1,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,3,3]\n
// @lcpr case=end

 */

