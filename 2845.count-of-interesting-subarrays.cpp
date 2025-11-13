/*
 * @lc app=leetcode.cn id=2845 lang=cpp
 * @lcpr version=
 *
 * [2845] 统计趣味子数组的数目
 *
 * https://leetcode.cn/problems/count-of-interesting-subarrays/description/
 *
 * algorithms
 * Medium (50.48%)
 * Likes:    96
 * Dislikes: 0
 * Total Accepted:    17.4K
 * Total Submissions: 34.4K
 * Testcase Example:  '[3,2,4]\n2\n1'
 *
 * 给你一个下标从 0 开始的整数数组 nums ，以及整数 modulo 和整数 k 。
 * 
 * 请你找出并统计数组中 趣味子数组 的数目。
 * 
 * 如果 子数组 nums[l..r] 满足下述条件，则称其为 趣味子数组 ：
 * 
 * 
 * 在范围 [l, r] 内，设 cnt 为满足 nums[i] % modulo == k 的索引 i 的数量。并且 cnt % modulo == k
 * 。
 * 
 * 
 * 以整数形式表示并返回趣味子数组的数目。 
 * 
 * 注意：子数组是数组中的一个连续非空的元素序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [3,2,4], modulo = 2, k = 1
 * 输出：3
 * 解释：在这个示例中，趣味子数组分别是： 
 * 子数组 nums[0..0] ，也就是 [3] 。 
 * - 在范围 [0, 0] 内，只存在 1 个下标 i = 0 满足 nums[i] % modulo == k 。
 * - 因此 cnt = 1 ，且 cnt % modulo == k 。
 * 子数组 nums[0..1] ，也就是 [3,2] 。
 * - 在范围 [0, 1] 内，只存在 1 个下标 i = 0 满足 nums[i] % modulo == k 。
 * - 因此 cnt = 1 ，且 cnt % modulo == k 。
 * 子数组 nums[0..2] ，也就是 [3,2,4] 。
 * - 在范围 [0, 2] 内，只存在 1 个下标 i = 0 满足 nums[i] % modulo == k 。
 * - 因此 cnt = 1 ，且 cnt % modulo == k 。
 * 可以证明不存在其他趣味子数组。因此，答案为 3 。
 * 
 * 示例 2：
 * 
 * 输入：nums = [3,1,9,6], modulo = 3, k = 0
 * 输出：2
 * 解释：在这个示例中，趣味子数组分别是： 
 * 子数组 nums[0..3] ，也就是 [3,1,9,6] 。
 * - 在范围 [0, 3] 内，只存在 3 个下标 i = 0, 2, 3 满足 nums[i] % modulo == k 。
 * - 因此 cnt = 3 ，且 cnt % modulo == k 。
 * 子数组 nums[1..1] ，也就是 [1] 。
 * - 在范围 [1, 1] 内，不存在下标满足 nums[i] % modulo == k 。
 * - 因此 cnt = 0 ，且 cnt % modulo == k 。
 * 可以证明不存在其他趣味子数组，因此答案为 2 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5 
 * 1 <= nums[i] <= 10^9
 * 1 <= modulo <= 10^9
 * 0 <= k < modulo
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
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int> count(n + 1, 0);
        for (int i = 0; i < n; i++) {
            count[i + 1] = count[i] + (nums[i] % modulo == k ? 1 : 0);
        }

        unordered_map<int, int> cnt;
        long long res = 0;
        for (int i = 0; i <= n; i++) {

            // 当遍历到 s[r]<k 时，cnt 中必然没有 s[r]−k+modulo，所以此时无需更新res
            if (count[i] >= k) {
                res += cnt[(count[i] - k) % modulo];
            }
            cnt[count[i] % modulo]++;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,4]\n2\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,1,9,6]\n3\n0\n
// @lcpr case=end

 */

