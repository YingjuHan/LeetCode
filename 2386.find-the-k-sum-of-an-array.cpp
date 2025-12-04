/*
 * @lc app=leetcode.cn id=2386 lang=cpp
 * @lcpr version=30204
 *
 * [2386] 找出数组的第 K 大和
 *
 * https://leetcode.cn/problems/find-the-k-sum-of-an-array/description/
 *
 * algorithms
 * Hard (55.27%)
 * Likes:    148
 * Dislikes: 0
 * Total Accepted:    16.1K
 * Total Submissions: 29.1K
 * Testcase Example:  '[2,4,-2]\n5'
 *
 * 给你一个整数数组 nums 和一个 正 整数 k 。你可以选择数组的任一 子序列 并且对其全部元素求和。
 * 
 * 数组的 第 k 大和 定义为：可以获得的第 k 个 最大 子序列和（子序列和允许出现重复）
 * 
 * 返回数组的 第 k 大和 。
 * 
 * 子序列是一个可以由其他数组删除某些或不删除元素派生而来的数组，且派生过程不改变剩余元素的顺序。
 * 
 * 注意：空子序列的和视作 0 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [2,4,-2], k = 5
 * 输出：2
 * 解释：所有可能获得的子序列和列出如下，按递减顺序排列：
 * 6、4、4、2、2、0、0、-2
 * 数组的第 5 大和是 2 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,-2,3,4,-10,12], k = 16
 * 输出：10
 * 解释：数组的第 16 大和是 10 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 <= n <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 1 <= k <= min(2000, 2^n)
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
    long long kSum(vector<int>& nums, int k) {
        long long sum = 0;
        for (int& x: nums) {
            if (x >= 0) {
                sum += x;
            } else {
                x = -x;
            }
        }
        sort(nums.begin(), nums.end());

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.emplace(0, 0);
        while (--k) {
            auto [s, i] = pq.top();
            pq.pop();
            if (i < nums.size()) {
                pq.emplace(s + nums[i], i + 1);
                if (i) {
                    pq.emplace(s + nums[i] - nums[i - 1], i + 1);
                }
            }
        }
        return sum - pq.top().first;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,4,-2]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,-2,3,4,-10,12]\n16\n
// @lcpr case=end

 */

