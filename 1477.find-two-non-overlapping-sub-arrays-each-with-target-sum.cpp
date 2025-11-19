/*
 * @lc app=leetcode.cn id=1477 lang=cpp
 * @lcpr version=
 *
 * [1477] 找两个和为目标值且不重叠的子数组
 *
 * https://leetcode.cn/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/description/
 *
 * algorithms
 * Medium (34.73%)
 * Likes:    174
 * Dislikes: 0
 * Total Accepted:    13.5K
 * Total Submissions: 38.8K
 * Testcase Example:  '[3,2,2,4,3]\n3'
 *
 * 给你一个整数数组 arr 和一个整数值 target 。
 * 
 * 请你在 arr 中找 两个互不重叠的子数组 且它们的和都等于 target 。可能会有多种方案，请你返回满足要求的两个子数组长度和的 最小值 。
 * 
 * 请返回满足要求的最小长度和，如果无法找到这样的两个子数组，请返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [3,2,2,4,3], target = 3
 * 输出：2
 * 解释：只有两个子数组和为 3 （[3] 和 [3]）。它们的长度和为 2 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [7,3,4,7], target = 7
 * 输出：2
 * 解释：尽管我们有 3 个互不重叠的子数组和为 7 （[7], [3,4] 和 [7]），但我们会选择第一个和第三个子数组，因为它们的长度和 2
 * 是最小值。
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = [4,3,2,6,2,3,4], target = 6
 * 输出：-1
 * 解释：我们只有一个和为 6 的子数组。
 * 
 * 
 * 示例 4：
 * 
 * 输入：arr = [5,5,4,4,5], target = 3
 * 输出：-1
 * 解释：我们无法找到和为 3 的子数组。
 * 
 * 
 * 示例 5：
 * 
 * 输入：arr = [3,1,1,1,5,1,2,1], target = 3
 * 输出：3
 * 解释：注意子数组 [1,2] 和 [2,1] 不能成为一个方案因为它们重叠了。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 10^5
 * 1 <= arr[i] <= 1000
 * 1 <= target <= 10^8
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
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int res = INT_MAX / 2;
        vector<int> pre(n + 1, INT_MAX / 2);
        vector<int> s(n + 1);
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + arr[i];
        }

        int l = 0;
        for (int r = 0; r < n; r++) {
            while (s[r + 1] - s[l] > target) {
                l++;
            }

            if (s[r + 1] - s[l] == target) {
                res = min(res, pre[l] + r - l + 1);
                pre[r + 1] = min(pre[r], r - l + 1);
            } else {
                pre[r + 1] = pre[r];
            }
        }
        return res == INT_MAX / 2 ? -1 : res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,2,4,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [7,3,4,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [4,3,2,6,2,3,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [5,5,4,4,5]\n3\n
// @lcpr case=end

// @lcpr case=start
// [3,1,1,1,5,1,2,1]\n3\n
// @lcpr case=end

 */

