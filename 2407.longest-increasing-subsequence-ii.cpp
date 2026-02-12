/*
 * @lc app=leetcode.cn id=2407 lang=cpp
 * @lcpr version=30204
 *
 * [2407] 最长递增子序列 II
 *
 * https://leetcode.cn/problems/longest-increasing-subsequence-ii/description/
 *
 * algorithms
 * Hard (33.23%)
 * Likes:    102
 * Dislikes: 0
 * Total Accepted:    9.5K
 * Total Submissions: 28.6K
 * Testcase Example:  '[4,2,1,4,3,4,5,8,15]\n3'
 *
 * 给你一个整数数组 nums 和一个整数 k 。
 * 
 * 找到 nums 中满足以下要求的最长子序列：
 * 
 * 
 * 子序列 严格递增
 * 子序列中相邻元素的差值 不超过 k 。
 * 
 * 
 * 请你返回满足上述要求的 最长子序列 的长度。
 * 
 * 子序列 是从一个数组中删除部分元素后，剩余元素不改变顺序得到的数组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [4,2,1,4,3,4,5,8,15], k = 3
 * 输出：5
 * 解释：
 * 满足要求的最长子序列是 [1,3,4,5,8] 。
 * 子序列长度为 5 ，所以我们返回 5 。
 * 注意子序列 [1,3,4,5,8,15] 不满足要求，因为 15 - 8 = 7 大于 3 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [7,4,5,1,8,12,4,7], k = 5
 * 输出：4
 * 解释：
 * 满足要求的最长子序列是 [4,5,8,12] 。
 * 子序列长度为 4 ，所以我们返回 4 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [1,5], k = 1
 * 输出：1
 * 解释：
 * 满足要求的最长子序列是 [1] 。
 * 子序列长度为 1 ，所以我们返回 1 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i], k <= 10^5
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
    int lengthOfLIS(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        int u = 0;
        for (int x : nums) u = max(u, x);
        
        // 线段树数组大小通常设为 4*u
        vector<int> mx(u * 4 + 1, 0);

        // 修改 a[i] = val
        auto modify = [&](this auto&& self, int o, int l, int r, int i, int val) -> void {
            if (l == r) {
                mx[o] = val; // 修正：使用当前节点索引 o
                return;
            }
            int m = l + (r - l) / 2;
            if (i <= m) {
                self(o * 2, l, m, i, val);
            } else {
                self(o * 2 + 1, m + 1, r, i, val);
            }
            mx[o] = max(mx[o * 2], mx[o * 2 + 1]);
        };

        // 查询 max(a[L...R])
        auto query = [&](this auto&& self, int o, int l, int r, int L, int R) -> int {
            if (L > R) return 0; // 边界保护
            if (L <= l && r <= R) {
                return mx[o];
            }
            int res = 0;
            int m = l + (r - l) / 2;
            if (L <= m) {
                res = self(o * 2, l, m, L, R);
            }
            if (R > m) {
                res = max(res, self(o * 2 + 1, m + 1, r, L, R));
            }
            return res;
        };

        for (int x : nums) {
            // 查询 [max(1, x-k), x-1] 范围内的最大 LIS 长度
            int current_max = query(1, 1, u, max(1, x - k), x - 1);
            modify(1, 1, u, x, current_max + 1);
        }
        
        return mx[1];
    }
};]
// @lc code=end



/*
// @lcpr case=start
// [4,2,1,4,3,4,5,8,15]\n3\n
// @lcpr case=end

// @lcpr case=start
// [7,4,5,1,8,12,4,7]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,5]\n1\n
// @lcpr case=end

 */

