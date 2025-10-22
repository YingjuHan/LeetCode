/*
 * @lc app=leetcode.cn id=3347 lang=cpp
 * @lcpr version=30204
 *
 * [3347] 执行操作后元素的最高频率 II
 *
 * https://leetcode.cn/problems/maximum-frequency-of-an-element-after-performing-operations-ii/description/
 *
 * algorithms
 * Hard (41.91%)
 * Likes:    12
 * Dislikes: 0
 * Total Accepted:    3K
 * Total Submissions: 6.6K
 * Testcase Example:  '[1,4,5]\n1\n2'
 *
 * 给你一个整数数组 nums 和两个整数 k 和 numOperations 。
 * 
 * 你必须对 nums 执行 操作  numOperations 次。每次操作中，你可以：
 * 
 * 
 * 选择一个下标 i ，它在之前的操作中 没有 被选择过。
 * 将 nums[i] 增加范围 [-k, k] 中的一个整数。
 * 
 * 
 * 在执行完所有操作以后，请你返回 nums 中出现 频率最高 元素的出现次数。
 * 
 * 一个元素 x 的 频率 指的是它在数组中出现的次数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,4,5], k = 1, numOperations = 2
 * 
 * 输出：2
 * 
 * 解释：
 * 
 * 通过以下操作得到最高频率 2 ：
 * 
 * 
 * 将 nums[1] 增加 0 ，nums 变为 [1, 4, 5] 。
 * 将 nums[2] 增加 -1 ，nums 变为 [1, 4, 4] 。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,11,20,20], k = 5, numOperations = 1
 * 
 * 输出：2
 * 
 * 解释：
 * 
 * 通过以下操作得到最高频率 2 ：
 * 
 * 
 * 将 nums[1] 增加 0 。
 * 
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
 * 0 <= numOperations <= nums.length
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
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int res = 0, cnt = 0, left = 0, right = 0;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            cnt++;

            // 循环直到连续相同段的末尾，统计x的出现次数
            if (i < n - 1 && x == nums[i + 1]) {
                continue;
            }

            while (nums[left] < x - k) {
                left++;
            }

            while (right < n && nums[right] <= x + k) {
                right++;
            }

            res = max(res, min(right - left, cnt + numOperations));
            cnt = 0;
        }

        if (res >= numOperations) {
            return res;
        }

        left = 0;
        for (int right = 0; right < n; right++) {
            int x = nums[right];
            while (nums[left] < x - k * 2) {
                left++;
            }
            res = max(res, right - left + 1);
        }
        return min(res, numOperations);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,4,5]\n1\n2\n
// @lcpr case=end

// @lcpr case=start
// [5,11,20,20]\n5\n1\n
// @lcpr case=end

 */

