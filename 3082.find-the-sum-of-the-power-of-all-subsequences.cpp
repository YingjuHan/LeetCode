/*
 * @lc app=leetcode.cn id=3082 lang=cpp
 * @lcpr version=30204
 *
 * [3082] 求出所有子序列的能量和
 *
 * https://leetcode.cn/problems/find-the-sum-of-the-power-of-all-subsequences/description/
 *
 * algorithms
 * Hard (48.49%)
 * Likes:    37
 * Dislikes: 0
 * Total Accepted:    5.3K
 * Total Submissions: 11K
 * Testcase Example:  '[1,2,3]\n3'
 *
 * 给你一个长度为 n 的整数数组 nums 和一个 正 整数 k 。
 * 
 * 一个整数数组的 能量 定义为和 等于 k 的子序列的数目。
 * 
 * 请你返回 nums 中所有子序列的 能量和 。
 * 
 * 由于答案可能很大，请你将它对 10^9 + 7 取余 后返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：  nums = [1,2,3], k = 3 
 * 
 * 输出：  6 
 * 
 * 解释：
 * 
 * 总共有 5 个能量不为 0 的子序列：
 * 
 * 
 * 子序列 [1,2,3] 有 2 个和为 3 的子序列：[1,2,3] 和 [1,2,3] 。
 * 子序列 [1,2,3] 有 1 个和为 3 的子序列：[1,2,3] 。
 * 子序列 [1,2,3] 有 1 个和为 3 的子序列：[1,2,3] 。
 * 子序列 [1,2,3] 有 1 个和为 3 的子序列：[1,2,3] 。
 * 子序列 [1,2,3] 有 1 个和为 3 的子序列：[1,2,3] 。
 * 
 * 
 * 所以答案为 2 + 1 + 1 + 1 + 1 = 6 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：  nums = [2,3,3], k = 5 
 * 
 * 输出：  4 
 * 
 * 解释：
 * 
 * 总共有 3 个能量不为 0 的子序列：
 * 
 * 
 * 子序列 [2,3,3] 有 2 个子序列和为 5 ：[2,3,3] 和 [2,3,3] 。
 * 子序列 [2,3,3] 有 1 个子序列和为 5 ：[2,3,3] 。
 * 子序列 [2,3,3] 有 1 个子序列和为 5 ：[2,3,3] 。
 * 
 * 
 * 所以答案为 2 + 1 + 1 = 4 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：  nums = [1,2,3], k = 7 
 * 
 * 输出：  0 
 * 
 * 解释：不存在和为 7 的子序列，所以 nums 的能量和为 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 100
 * 1 <= nums[i] <= 10^4
 * 1 <= k <= 100
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
    int sumOfPower(vector<int>& nums, int k) {
        const int MOD = 1'000'000'007;
        int n = nums.size();
        vector<vector<int>> f(k + 1, vector<int>(n + 1));
        f[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = k; j >= nums[i]; j--) {
                for (int c = i + 1; c > 0; c--) {
                    f[j][c] = (f[i][c] + f[j - nums[i]][c - 1]) % MOD;
                }
            }
        }
        int res = 0;
        int pow2 = 1;
        for (int i = n; i > 0; i--) {
            res = (res + (long long)f[k][i] * pow2) % MOD;
            pow2 = pow2 * 2 % MOD;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,3,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n7\n
// @lcpr case=end

 */

