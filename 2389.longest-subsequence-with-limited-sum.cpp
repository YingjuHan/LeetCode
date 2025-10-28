/*
 * @lc app=leetcode.cn id=2389 lang=cpp
 * @lcpr version=30204
 *
 * [2389] 和有限的最长子序列
 *
 * https://leetcode.cn/problems/longest-subsequence-with-limited-sum/description/
 *
 * algorithms
 * Easy (73.38%)
 * Likes:    191
 * Dislikes: 0
 * Total Accepted:    56.2K
 * Total Submissions: 76.6K
 * Testcase Example:  '[4,5,2,1]\n[3,10,21]'
 *
 * 给你一个长度为 n 的整数数组 nums ，和一个长度为 m 的整数数组 queries 。
 * 
 * 返回一个长度为 m 的数组 answer ，其中 answer[i] 是 nums 中 元素之和小于等于 queries[i] 的 子序列 的 最大
 * 长度  。
 * 
 * 子序列 是由一个数组删除某些元素（也可以不删除）但不改变剩余元素顺序得到的一个数组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [4,5,2,1], queries = [3,10,21]
 * 输出：[2,3,4]
 * 解释：queries 对应的 answer 如下：
 * - 子序列 [2,1] 的和小于或等于 3 。可以证明满足题目要求的子序列的最大长度是 2 ，所以 answer[0] = 2 。
 * - 子序列 [4,5,1] 的和小于或等于 10 。可以证明满足题目要求的子序列的最大长度是 3 ，所以 answer[1] = 3 。
 * - 子序列 [4,5,2,1] 的和小于或等于 21 。可以证明满足题目要求的子序列的最大长度是 4 ，所以 answer[2] = 4 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [2,3,4,5], queries = [1]
 * 输出：[0]
 * 解释：空子序列是唯一一个满足元素和小于或等于 1 的子序列，所以 answer[0] = 0 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * m == queries.length
 * 1 <= n, m <= 1000
 * 1 <= nums[i], queries[i] <= 10^6
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
    // lower_bound(nums, target + 1) <=> upper_bound(nums, target)
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = right - (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        // 贪心：由于元素和有上限，为了子序列更长，子序列中的元素值越小越好
        // 对于本题来说，元素在数组中的位置是无关紧要的。因为我们从小到大算数组中的元素和，
        // 无论数组是 [1,2,3] 还是 [3,2,1] 还是别的顺序，不影响答案。所以可以排序

        // 把 nums 从小到大排序后，再从小到大选择尽量多的元素（相当于选择一个前缀），使这些元素的和不超过询问值

        // 由于 nums[i] 都是正整数，前缀和是严格单调递增的，这样就能在前缀和上使用二分查找：找到大于 queries[i]
        // 的第一个数的下标，由于下标是从 0 开始的，这个数的下标正好就是前缀和小于等于 queries[i] 的最长前缀的长度

        sort(nums.begin(), nums.end());
        vector<int> prefixSum(nums);
        for (int i = 1; i < nums.size(); i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        vector<int> res;
        for (int query : queries) {
            res.emplace_back(lower_bound(prefixSum, query + 1));
        }
        return res;        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,5,2,1]\n[3,10,21]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4,5]\n[1]\n
// @lcpr case=end

 */

