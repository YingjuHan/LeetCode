/*
 * @lc app=leetcode.cn id=3287 lang=cpp
 * @lcpr version=30204
 *
 * [3287] 求出数组中最大序列值
 *
 * https://leetcode.cn/problems/find-the-maximum-sequence-value-of-array/description/
 *
 * algorithms
 * Hard (67.68%)
 * Likes:    49
 * Dislikes: 0
 * Total Accepted:    8.8K
 * Total Submissions: 13.1K
 * Testcase Example:  '[2,6,7]\n1'
 *
 * 给你一个整数数组 nums 和一个 正 整数 k 。
 * 
 * 定义长度为 2 * x 的序列 seq 的 值 为：
 * 
 * 
 * (seq[0] OR seq[1] OR ... OR seq[x - 1]) XOR (seq[x] OR seq[x + 1] OR ... OR
 * seq[2 * x - 1]).
 * 
 * 
 * 请你求出 nums 中所有长度为 2 * k 的 子序列 的 最大值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,6,7], k = 1
 * 
 * 输出：5
 * 
 * 解释：
 * 
 * 子序列 [2, 7] 的值最大，为 2 XOR 7 = 5 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [4,2,5,6,7], k = 2
 * 
 * 输出：2
 * 
 * 解释：
 * 
 * 子序列 [4, 5, 6, 7] 的值最大，为 (4 OR 5) XOR (6 OR 7) = 2 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= nums.length <= 400
 * 1 <= nums[i] < 2^7
 * 1 <= k <= nums.length / 2
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
    int maxValue(vector<int>& nums, int k) {
        const int MX = 1 << 7;
        int n = nums.size();
        vector<array<int, MX>> suf(n - k + 1);
        vector<array<int, MX>> f(k + 1);
        f[0][0] = true;
        for (int i = n - 1; i >= k; i--) {
            int v = nums[i];
            // 注意当 i 比较大的时候，循环次数应和 i 有关，因为更大的 j，对应的 f[j] 全为 false
            for (int j = min(k - 1, n - 1 - i); j >= 0; j--) {
                for (int x = 0; x < MX; x++) {
                    if (f[j][x]) {
                        f[j + 1][x | v] = true;
                    }
                }
            }
            if (i <= n - k) {
                suf[i] = f[k];
            }
        }

        int ans = 0;
        f = vector<array<int, MX>>(k + 1);
        f[0][0] = true;
        for (int i = 0; i < n - k; i++) {
            int v = nums[i];
            for (int j = min(k - 1, i); j >= 0; j--) {
                for (int x = 0; x < MX; x++) {
                    if (f[j][x]) {
                        f[j + 1][x | v] = true;
                    }
                }
            }
            if (i < k - 1) {
                continue;
            }
            // 这里 f[k] 就是 pre[i]
            for (int x = 0; x < MX; x++) {
                if (f[k][x]) {
                    for (int y = 0; y < MX; y++) {
                        if (suf[i + 1][y]) {
                            ans = max(ans, x ^ y);
                        }
                    }
                }
            }
            if (ans == MX - 1) {
                return ans;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,6,7]\n1\n
// @lcpr case=end

// @lcpr case=start
// [4,2,5,6,7]\n2\n
// @lcpr case=end

 */

