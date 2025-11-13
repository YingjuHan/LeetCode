/*
 * @lc app=leetcode.cn id=3542 lang=cpp
 * @lcpr version=
 *
 * [3542] 将所有元素变为 0 的最少操作次数
 *
 * https://leetcode.cn/problems/minimum-operations-to-convert-all-elements-to-zero/description/
 *
 * algorithms
 * Medium (40.65%)
 * Likes:    58
 * Dislikes: 0
 * Total Accepted:    9.9K
 * Total Submissions: 17.7K
 * Testcase Example:  '[0,2]'
 *
 * 给你一个大小为 n 的 非负 整数数组 nums 。你的任务是对该数组执行若干次（可能为 0 次）操作，使得 所有 元素都变为 0。
 * 
 * 在一次操作中，你可以选择一个子数组 [i, j]（其中 0 <= i <= j < n），将该子数组中所有 最小的非负整数 的设为 0。
 * 
 * 返回使整个数组变为 0 所需的最少操作次数。
 * 一个 子数组 是数组中的一段连续元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: nums = [0,2]
 * 
 * 输出: 1
 * 
 * 解释:
 * 
 * 
 * 选择子数组 [1,1]（即 [2]），其中最小的非负整数是 2。将所有 2 设为 0，结果为 [0,0]。
 * 因此，所需的最少操作次数为 1。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入: nums = [3,1,2,1]
 * 
 * 输出: 3
 * 
 * 解释:
 * 
 * 
 * 选择子数组 [1,3]（即 [1,2,1]），最小非负整数是 1。将所有 1 设为 0，结果为 [3,0,2,0]。
 * 选择子数组 [2,2]（即 [2]），将 2 设为 0，结果为 [3,0,0,0]。
 * 选择子数组 [0,0]（即 [3]），将 3 设为 0，结果为 [0,0,0,0]。
 * 因此，最少操作次数为 3。
 * 
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入: nums = [1,2,1,2,1,2]
 * 
 * 输出: 4
 * 
 * 解释:
 * 
 * 
 * 选择子数组 [0,5]（即 [1,2,1,2,1,2]），最小非负整数是 1。将所有 1 设为 0，结果为 [0,2,0,2,0,2]。
 * 选择子数组 [1,1]（即 [2]），将 2 设为 0，结果为 [0,0,0,2,0,2]。
 * 选择子数组 [3,3]（即 [2]），将 2 设为 0，结果为 [0,0,0,0,0,2]。
 * 选择子数组 [5,5]（即 [2]），将 2 设为 0，结果为 [0,0,0,0,0,0]。
 * 因此，最少操作次数为 4。
 * 
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= n == nums.length <= 10^5
 * 0 <= nums[i] <= 10^5
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
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int top = -1; // 栈顶下标（把 nums 当作栈）
        for (int x : nums) {
            while (top >= 0 && x < nums[top]) {
                top--; // 出栈
                ans++;
            }
            // 如果 x 与栈顶相同，那么 x 与栈顶可以在同一次操作中都变成 0，x 无需入栈
            if (top < 0 || x != nums[top]) {
                nums[++top] = x; // 入栈
            }
        }
        return ans + top + (nums[0] > 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,2,1,2]\n
// @lcpr case=end

 */

