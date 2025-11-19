/*
 * @lc app=leetcode.cn id=1703 lang=cpp
 * @lcpr version=30204
 *
 * [1703] 得到连续 K 个 1 的最少相邻交换次数
 *
 * https://leetcode.cn/problems/minimum-adjacent-swaps-for-k-consecutive-ones/description/
 *
 * algorithms
 * Hard (55.81%)
 * Likes:    172
 * Dislikes: 0
 * Total Accepted:    13K
 * Total Submissions: 23.3K
 * Testcase Example:  '[1,0,0,1,0,1]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k 。 nums 仅包含 0 和 1 。每一次移动，你可以选择 相邻 两个数字并将它们交换。
 * 
 * 请你返回使 nums 中包含 k 个 连续 1 的 最少 交换次数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,0,0,1,0,1], k = 2
 * 输出：1
 * 解释：在第一次操作时，nums 可以变成 [1,0,0,0,1,1] 得到连续两个 1 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,0,0,0,0,0,1,1], k = 3
 * 输出：5
 * 解释：通过 5 次操作，最左边的 1 可以移到右边直到 nums 变为 [0,0,0,0,0,1,1,1] 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [1,1,0,1], k = 2
 * 输出：0
 * 解释：nums 已经有连续 2 个 1 了。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * nums[i] 要么是 0 ，要么是 1 。
 * 1 <= k <= sum(nums)
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
    int minMoves(vector<int>& nums, int k) {
        vector<int> p;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i]) p.push_back(i - p.size());
        int m = p.size(), s[m + 1];
        s[0] = 0;
        partial_sum(p.begin(), p.end(), s + 1); // p 的前缀和
        int ans = INT_MAX;
        for (int i = 0; i <= m - k; ++i) // p[i] 到 p[i+k-1] 中所有数到 p[i+k/2] 的距离之和，取最小值
            ans = min(ans, s[i] + s[i + k] - s[i + k / 2] * 2 - p[i + k / 2] * (k % 2));
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,0,1,0,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,0,0,0,0,0,1,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,0,1]\n2\n
// @lcpr case=end

 */

