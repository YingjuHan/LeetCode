/*
 * @lc app=leetcode.cn id=2915 lang=cpp
 * @lcpr version=30204
 *
 * [2915] 和为目标值的最长子序列的长度
 *
 * https://leetcode.cn/problems/length-of-the-longest-subsequence-that-sums-to-target/description/
 *
 * algorithms
 * Medium (53.24%)
 * Likes:    79
 * Dislikes: 0
 * Total Accepted:    29.2K
 * Total Submissions: 54.8K
 * Testcase Example:  '[1,2,3,4,5]\n9'
 *
 * 给你一个下标从 0 开始的整数数组 nums 和一个整数 target 。
 * 
 * 返回和为 target 的 nums 子序列中，子序列 长度的最大值 。如果不存在和为 target 的子序列，返回 -1 。
 * 
 * 子序列 指的是从原数组中删除一些或者不删除任何元素后，剩余元素保持原来的顺序构成的数组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,2,3,4,5], target = 9
 * 输出：3
 * 解释：总共有 3 个子序列的和为 9 ：[4,5] ，[1,3,5] 和 [2,3,4] 。最长的子序列是 [1,3,5] 和 [2,3,4]
 * 。所以答案为 3 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [4,1,3,2,1,5], target = 7
 * 输出：4
 * 解释：总共有 5 个子序列的和为 7 ：[4,3] ，[4,1,2] ，[4,2,1] ，[1,1,5] 和 [1,3,2,1] 。最长子序列为
 * [1,3,2,1] 。所以答案为 4 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [1,1,5,4,5], target = 3
 * 输出：-1
 * 解释：无法得到和为 3 的子序列。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 1000
 * 1 <= target <= 1000
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
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        // f[i + 1][j] 表示在 nums[0] 到 nums[i] 中的，元素和为 j 的子序列的最长长度
        vector<vector<int>> f(n + 1, vector<int>(target + 1, INT_MIN));
        f[0][0] = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int j = 0; j <= target; j++) {
                if (j < x) {
                    f[i + 1][j] = f[i][j];
                } else {
                    f[i + 1][j] = max(f[i][j], f[i][j - x] + 1);
                }
            }
        }
        return f[n][target] > 0 ? f[n][target] : -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n9\n
// @lcpr case=end

// @lcpr case=start
// [4,1,3,2,1,5]\n7\n
// @lcpr case=end

// @lcpr case=start
// [1,1,5,4,5]\n3\n
// @lcpr case=end

 */

