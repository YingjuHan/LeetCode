/*
 * @lc app=leetcode.cn id=2233 lang=cpp
 * @lcpr version=30204
 *
 * [2233] K 次增加后的最大乘积
 *
 * https://leetcode.cn/problems/maximum-product-after-k-increments/description/
 *
 * algorithms
 * Medium (39.31%)
 * Likes:    40
 * Dislikes: 0
 * Total Accepted:    12.9K
 * Total Submissions: 32.8K
 * Testcase Example:  '[0,4]\n5'
 *
 * 给你一个非负整数数组 nums 和一个整数 k 。每次操作，你可以选择 nums 中 任一 元素并将它 增加 1 。
 * 
 * 请你返回 至多 k 次操作后，能得到的 nums的 最大乘积 。由于答案可能很大，请你将答案对 10^9 + 7 取余后返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [0,4], k = 5
 * 输出：20
 * 解释：将第一个数增加 5 次。
 * 得到 nums = [5, 4] ，乘积为 5 * 4 = 20 。
 * 可以证明 20 是能得到的最大乘积，所以我们返回 20 。
 * 存在其他增加 nums 的方法，也能得到最大乘积。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [6,3,3,2], k = 2
 * 输出：216
 * 解释：将第二个数增加 1 次，将第四个数增加 1 次。
 * 得到 nums = [6, 4, 3, 3] ，乘积为 6 * 4 * 3 * 3 = 216 。
 * 可以证明 216 是能得到的最大乘积，所以我们返回 216 。
 * 存在其他增加 nums 的方法，也能得到最大乘积。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length, k <= 10^5
 * 0 <= nums[i] <= 10^6
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // 只加最小的
    int maximumProduct(vector<int>& nums, int k) {
        const int MOD = (int)1e9 + 7;
        vector<int> minHeap(nums);
        make_heap(minHeap.begin(), minHeap.end(), greater<>());
        for (int i = 0; i < k; i++) {
            pop_heap(minHeap.begin(), minHeap.end(), greater<>());
            minHeap.back()++;
            push_heap(minHeap.begin(), minHeap.end(), greater<>());
        }
        long long multiSum = 1;
        for (const int &num : minHeap) {
            multiSum = (multiSum * num) % MOD;
        }
        return multiSum % MOD;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,4]\n5\n
// @lcpr case=end

// @lcpr case=start
// [6,3,3,2]\n2\n
// @lcpr case=end

 */

