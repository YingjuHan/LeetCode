/*
 * @lc app=leetcode.cn id=3397 lang=cpp
 * @lcpr version=30204
 *
 * [3397] 执行操作后不同元素的最大数量
 *
 * https://leetcode.cn/problems/maximum-number-of-distinct-elements-after-operations/description/
 *
 * algorithms
 * Medium (39.45%)
 * Likes:    31
 * Dislikes: 0
 * Total Accepted:    13.3K
 * Total Submissions: 25.1K
 * Testcase Example:  '[1,2,2,3,3,4]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k。
 * 
 * 你可以对数组中的每个元素 最多 执行 一次 以下操作：
 * 
 * 
 * 将一个在范围 [-k, k] 内的整数加到该元素上。
 * 
 * 
 * 返回执行这些操作后，nums 中可能拥有的不同元素的 最大 数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： nums = [1,2,2,3,3,4], k = 2
 * 
 * 输出： 6
 * 
 * 解释：
 * 
 * 对前四个元素执行操作，nums 变为 [-1, 0, 1, 2, 3, 4]，可以获得 6 个不同的元素。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： nums = [4,4,4,4], k = 1
 * 
 * 输出： 3
 * 
 * 解释：
 * 
 * 对 nums[0] 加 -1，以及对 nums[1] 加 1，nums 变为 [3, 5, 4, 4]，可以获得 3 个不同的元素。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 0 <= k <= 10^9
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
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), less<int>());
        int res = 0;
        int pre = INT_MIN;
        for (int num : nums) {
            int current;
            if (pre + 1 < num - k) {
                current = num - k;
            } else if (pre + 1 > num + k) {
                current = num + k;
            } else {
                current = pre + 1;
            }

            if (current > pre) {
                res += 1;
                pre = num;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,3,3,4]\n2\n
// @lcpr case=end

// @lcpr case=start
// [4,4,4,4]\n1\n
// @lcpr case=end

 */

