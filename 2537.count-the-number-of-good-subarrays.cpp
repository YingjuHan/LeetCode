/*
 * @lc app=leetcode.cn id=2537 lang=cpp
 * @lcpr version=30204
 *
 * [2537] 统计好子数组的数目
 *
 * https://leetcode.cn/problems/count-the-number-of-good-subarrays/description/
 *
 * algorithms
 * Medium (64.01%)
 * Likes:    124
 * Dislikes: 0
 * Total Accepted:    30.1K
 * Total Submissions: 47K
 * Testcase Example:  '[1,1,1,1,1]\n10'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回 nums 中 好 子数组的数目。
 * 
 * 一个子数组 arr 如果有 至少 k 对下标 (i, j) 满足 i < j 且 arr[i] == arr[j] ，那么称它是一个 好 子数组。
 * 
 * 子数组 是原数组中一段连续 非空 的元素序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,1,1,1,1], k = 10
 * 输出：1
 * 解释：唯一的好子数组是这个数组本身。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [3,1,4,3,2,2,4], k = 2
 * 输出：4
 * 解释：总共有 4 个不同的好子数组：
 * - [3,1,4,3,2,2] 有 2 对。
 * - [3,1,4,3,2,2,4] 有 3 对。
 * - [1,4,3,2,2,4] 有 2 对。
 * - [4,3,2,2,4] 有 2 对。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i], k <= 10^9
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
    long long countGood(vector<int>& nums, int k) {
        // 如果窗口中有 c 个元素 x，再进来一个 x，会新增 c 个相等数对。
        // 如果窗口中有 c 个元素 x，再去掉一个 x，会减少 c−1 个相等数对。

        // 用一个哈希表 cnt 维护子数组（窗口）中的每个元素的出现次数，以及相同数对的个数 pairs

        long long res = 0;
        unordered_map<int, int> cnt;
        int pairs = 0, left = 0, right = 0;

        while (right < nums.size()) {
            // 外层循环：从小到大维护数组的右端点right，将nums[right]移入窗口，那么窗口中有cnt[nums[right]]个数与nums[right]相同
            // 所以pairs会增加cnt[nums[right]],然后把 cnt[nums[right]] 加一
            int in_win = nums[right];
            pairs += cnt[in_win];
            cnt[in_win]++;
            right++;

            // 如果发现 pairs≥k，说明子数组符合要求，右移左端点 left
            // 把 cnt[nums[left]] 减少一，然后把 pairs 减少 cnt[nums[left]]。
            while (pairs >= k) {
                int out_win = nums[left];
                cnt[out_win]--;
                pairs -= cnt[out_win];
                left++;
            }

            res += left;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,1,1]\n10\n
// @lcpr case=end

// @lcpr case=start
// [3,1,4,3,2,2,4]\n2\n
// @lcpr case=end

 */

