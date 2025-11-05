/*
 * @lc app=leetcode.cn id=2552 lang=cpp
 * @lcpr version=30204
 *
 * [2552] 统计上升四元组
 *
 * https://leetcode.cn/problems/count-increasing-quadruplets/description/
 *
 * algorithms
 * Hard (50.75%)
 * Likes:    88
 * Dislikes: 0
 * Total Accepted:    15.9K
 * Total Submissions: 31.3K
 * Testcase Example:  '[1,3,2,4,5]'
 *
 * 给你一个长度为 n 下标从 0 开始的整数数组 nums ，它包含 1 到 n 的所有数字，请你返回上升四元组的数目。
 * 
 * 如果一个四元组 (i, j, k, l) 满足以下条件，我们称它是上升的：
 * 
 * 
 * 0 <= i < j < k < l < n 且
 * nums[i] < nums[k] < nums[j] < nums[l] 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,3,2,4,5]
 * 输出：2
 * 解释：
 * - 当 i = 0 ，j = 1 ，k = 2 且 l = 3 时，有 nums[i] < nums[k] < nums[j] < nums[l] 。
 * - 当 i = 0 ，j = 1 ，k = 2 且 l = 4 时，有 nums[i] < nums[k] < nums[j] < nums[l] 。
 * 没有其他的四元组，所以我们返回 2 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：0
 * 解释：只存在一个四元组 i = 0 ，j = 1 ，k = 2 ，l = 3 ，但是 nums[j] < nums[k] ，所以我们返回 0
 * 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 4 <= nums.length <= 4000
 * 1 <= nums[i] <= nums.length
 * nums 中所有数字 互不相同 ，nums 是一个排列。
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
    /**
     * 枚举中间的j和k
     * 需要知道：k右边右多少个比nums[j]大的数，j左边右多少个比nums[k]小的数
     * 预处理
     * greate[k][x] 定义为在k右边的比x大的数的个数
     * less[j][x]   定义为在j左边的比x小的数的个数
     */
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> great(n, vector<int>(n + 1));
        for (int k = n - 2; k >= 2; k--) {
            great[k] = great[k + 1]; // 比x大的数量是累加的，所以
            for (int x = 1; x < nums[k + 1]; x++) {
                great[k][x]++;
            }
        }

        vector<int> less(n + 1);
        long long res = 0;
        for (int j = 1; j < n - 2; j++) {
            for (int x = nums[j - 1] + 1; x <= n; x++) {
                less[x]++;
            }
            for (int k = j + 1; k < n - 1; k++) {
                if (nums[j] > nums[k]) {
                    res += less[nums[k]] * great[k][nums[j]];
                }
            }
        }
        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

 */

