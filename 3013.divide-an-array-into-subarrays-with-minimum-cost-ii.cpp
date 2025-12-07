/*
 * @lc app=leetcode.cn id=3013 lang=cpp
 * @lcpr version=30204
 *
 * [3013] 将数组分成最小总代价的子数组 II
 *
 * https://leetcode.cn/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/description/
 *
 * algorithms
 * Hard (38.72%)
 * Likes:    20
 * Dislikes: 0
 * Total Accepted:    2.9K
 * Total Submissions: 7.4K
 * Testcase Example:  '[1,3,2,6,4,2]\n3\n3'
 *
 * 给你一个下标从 0 开始长度为 n 的整数数组 nums 和两个 正 整数 k 和 dist 。
 * 
 * 一个数组的 代价 是数组中的 第一个 元素。比方说，[1,2,3] 的代价为 1 ，[3,4,1] 的代价为 3 。
 * 
 * 你需要将 nums 分割成 k 个 连续且互不相交 的子数组，满足 第二 个子数组与第 k 个子数组中第一个元素的下标距离 不超过 dist
 * 。换句话说，如果你将 nums 分割成子数组 nums[0..(i1 - 1)], nums[i1..(i2 - 1)], ...,
 * nums[ik-1..(n - 1)] ，那么它需要满足 ik-1 - i1 <= dist 。
 * 
 * 请你返回这些子数组的 最小 总代价。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,3,2,6,4,2], k = 3, dist = 3
 * 输出：5
 * 解释：将数组分割成 3 个子数组的最优方案是：[1,3] ，[2,6,4] 和 [2] 。这是一个合法分割，因为 ik-1 - i1 等于 5 - 2
 * = 3 ，等于 dist 。总代价为 nums[0] + nums[2] + nums[5] ，也就是 1 + 2 + 2 = 5 。
 * 5 是分割成 3 个子数组的最小总代价。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [10,1,2,2,2,1], k = 4, dist = 3
 * 输出：15
 * 解释：将数组分割成 4 个子数组的最优方案是：[10] ，[1] ，[2] 和 [2,2,1] 。这是一个合法分割，因为 ik-1 - i1 等于 3
 * - 1 = 2 ，小于 dist 。总代价为 nums[0] + nums[1] + nums[2] + nums[3] ，也就是 10 + 1 + 2
 * + 2 = 15 。
 * 分割 [10] ，[1] ，[2,2,2] 和 [1] 不是一个合法分割，因为 ik-1 和 i1 的差为 5 - 1 = 4 ，大于 dist 。
 * 15 是分割成 4 个子数组的最小总代价。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [10,8,18,9], k = 3, dist = 1
 * 输出：36
 * 解释：将数组分割成 4 个子数组的最优方案是：[10] ，[8] 和 [18,9] 。这是一个合法分割，因为 ik-1 - i1 等于 2 - 1 =
 * 1 ，等于 dist 。总代价为 nums[0] + nums[1] + nums[2] ，也就是 10 + 8 + 18 = 36 。
 * 分割 [10] ，[8,18] 和 [9] 不是一个合法分割，因为 ik-1 和 i1 的差为 3 - 1 = 2 ，大于 dist 。
 * 36 是分割成 3 个子数组的最小总代价。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= n <= 10^5
 * 1 <= nums[i] <= 10^9
 * 3 <= k <= n
 * k - 2 <= dist <= n - 2
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
#include <set>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        k = k - 1;
        long long sum = accumulate(nums.begin(), nums.begin() + dist + 2, 0LL);
        multiset<int> L(nums.begin() + 1, nums.begin() + dist + 2), R;
        auto L2R = [&]() {
            int x = *L.rbegin();
            sum -= x;
            L.erase(L.find(x));
            R.insert(x);
        };
        auto R2L = [&]() {
            int x = *R.begin();
            sum += x;
            R.erase(R.find(x));
            L.insert(x);
        };
        while (L.size() > k) {
            L2R();
        }
        long long ans = sum;
        for (int i = dist + 2; i < nums.size(); i++) {

            // 移除out
            int out = nums[i - dist - 1];
            auto it = L.find(out);
            if (it != L.end()) {
                sum -= out;
                L.erase(it);
            } else {
                R.erase(R.find(out));
            }

            // 添加in
            int in = nums[i];
            if (in < *L.rbegin()) {
                sum += in;
                L.insert(in);
            } else {
                R.insert(in);
            }

            // 维护大小
            if (L.size() == k - 1) {
                R2L();
            } else if (L.size() == k + 1) {
                L2R();
            }

            ans = min(ans, sum);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2,6,4,2]\n3\n3\n
// @lcpr case=end

// @lcpr case=start
// [10,1,2,2,2,1]\n4\n3\n
// @lcpr case=end

// @lcpr case=start
// [10,8,18,9]\n3\n1\n
// @lcpr case=end

 */

