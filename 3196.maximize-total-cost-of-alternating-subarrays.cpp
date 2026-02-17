/*
 * @lc app=leetcode.cn id=3196 lang=cpp
 * @lcpr version=30204
 *
 * [3196] 最大化子数组的总成本
 *
 * https://leetcode.cn/problems/maximize-total-cost-of-alternating-subarrays/description/
 *
 * algorithms
 * Medium (38.78%)
 * Likes:    23
 * Dislikes: 0
 * Total Accepted:    8.5K
 * Total Submissions: 21.7K
 * Testcase Example:  '[1,-2,3,4]'
 *
 * 给你一个长度为 n 的整数数组 nums。
 * 
 * 子数组 nums[l..r]（其中 0 <= l <= r < n）的 成本 定义为：
 * 
 * cost(l, r) = nums[l] - nums[l + 1] + ... + nums[r] * (−1)^r − l
 * 
 * 你的任务是将 nums 分割成若干子数组，使得所有子数组的成本之和 最大化，并确保每个元素 正好 属于一个子数组。
 * 
 * 具体来说，如果 nums 被分割成 k 个子数组，且分割点为索引 i1, i2, ..., ik − 1（其中 0 <= i1 < i2 < ... <
 * ik - 1 < n - 1），则总成本为：
 * 
 * cost(0, i1) + cost(i1 + 1, i2) + ... + cost(ik − 1 + 1, n − 1)
 * 
 * 返回在最优分割方式下的子数组成本之和的最大值。
 * 
 * 注意：如果 nums 没有被分割，即 k = 1，则总成本即为 cost(0, n - 1)。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： nums = [1,-2,3,4]
 * 
 * 输出： 10
 * 
 * 解释：
 * 
 * 一种总成本最大化的方法是将 [1, -2, 3, 4] 分割成子数组 [1, -2, 3] 和 [4]。总成本为 (1 + 2 + 3) + 4 =
 * 10。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： nums = [1,-1,1,-1]
 * 
 * 输出： 4
 * 
 * 解释：
 * 
 * 一种总成本最大化的方法是将 [1, -1, 1, -1] 分割成子数组 [1, -1] 和 [1, -1]。总成本为 (1 + 1) + (1 + 1)
 * = 4。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入： nums = [0]
 * 
 * 输出： 0
 * 
 * 解释：
 * 
 * 无法进一步分割数组，因此答案为 0。
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入： nums = [1,-1]
 * 
 * 输出： 2
 * 
 * 解释：
 * 
 * 选择整个数组，总成本为 1 + 1 = 2，这是可能的最大成本。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
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
    long long maximumTotalCost1(vector<int>& nums) {
        int n = nums.size();
        vector<long long> memo(n, LLONG_MIN);
        auto dfs = [&](this auto&& dfs, int i) -> long long {
            if (i < 0) {
                return 0;
            }
            if (i == 0) {
                return nums[0];
            }
            long long &res = memo[i];
            if (res != LLONG_MIN) {
                return res;
            }
            res = max(dfs(i - 1) + nums[i], dfs(i - 2) + nums[i - 1] - nums[i]);
            return res;
        };
        return dfs(n - 1);
    }

    long long maximumTotalCost2(vector<int>& nums) {
        int n = nums.size();
        // Using n+1 to stay safe with indexing
        vector<long long> f(n + 1, 0);
        
        // Base case: The first element always starts a subarray (added)
        f[1] = nums[0];
        
        for (int i = 1; i < n; i++) {
            // Option 1: nums[i] starts a new subarray
            long long option1 = f[i] + nums[i];
            
            // Option 2: nums[i] is the second element in a subarray (subtracted)
            // This effectively pairs nums[i-1] and nums[i] as (nums[i-1] - nums[i])
            long long option2 = f[i - 1] + nums[i - 1] - nums[i];
            
            f[i + 1] = max(option1, option2);
        }
        
        return f[n];
    }

    long long maximumTotalCost(vector<int>& nums) {
        long long f0 = 0, f1 = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            long long temp = f1;
            f1 = max(f1 + nums[i], f0 + nums[i - 1] - nums[i]);
            f0 = temp;
        }
        return f1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,-2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,-1,1,-1]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

// @lcpr case=start
// [1,-1]\n
// @lcpr case=end

 */

