/*
 * @lc app=leetcode.cn id=1760 lang=cpp
 * @lcpr version=30204
 *
 * [1760] 袋子里最少数目的球
 *
 * https://leetcode.cn/problems/minimum-limit-of-balls-in-a-bag/description/
 *
 * algorithms
 * Medium (64.74%)
 * Likes:    311
 * Dislikes: 0
 * Total Accepted:    45.1K
 * Total Submissions: 69.7K
 * Testcase Example:  '[9]\n2'
 *
 * 给你一个整数数组 nums ，其中 nums[i] 表示第 i 个袋子里球的数目。同时给你一个整数 maxOperations 。
 * 
 * 你可以进行如下操作至多 maxOperations 次：
 * 
 * 
 * 选择任意一个袋子，并将袋子里的球分到 2 个新的袋子中，每个袋子里都有 正整数 个球。
 * 
 * 
 * 比方说，一个袋子里有 5 个球，你可以把它们分到两个新袋子里，分别有 1 个和 4 个球，或者分别有 2 个和 3 个球。
 * 
 * 
 * 
 * 
 * 你的开销是单个袋子里球数目的 最大值 ，你想要 最小化 开销。
 * 
 * 请你返回进行上述操作后的最小开销。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [9], maxOperations = 2
 * 输出：3
 * 解释：
 * - 将装有 9 个球的袋子分成装有 6 个和 3 个球的袋子。[9] -> [6,3] 。
 * - 将装有 6 个球的袋子分成装有 3 个和 3 个球的袋子。[6,3] -> [3,3,3] 。
 * 装有最多球的袋子里装有 3 个球，所以开销为 3 并返回 3 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [2,4,8,2], maxOperations = 4
 * 输出：2
 * 解释：
 * - 将装有 8 个球的袋子分成装有 4 个和 4 个球的袋子。[2,4,8,2] -> [2,4,4,4,2] 。
 * - 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,4,4,4,2] -> [2,2,2,4,4,2] 。
 * - 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,2,2,4,4,2] -> [2,2,2,2,2,4,2] 。
 * - 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2] 。
 * 装有最多球的袋子里装有 2 个球，所以开销为 2 并返回 2 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [7,17], maxOperations = 2
 * 输出：7
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= maxOperations, nums[i] <= 10^9
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
     * 操作越多，装的袋子越多，每个袋子装的越少，最小化开销就是操作少，袋子少，每个袋子尽量多，
     * 如果最后分成k个袋子，需要操作k-1次，因为每次操作都是选一个袋子变成两个袋子
     */
    int minimumSize(vector<int>& nums, int maxOperations) {
        auto check = [&](int k) -> bool { // k是袋子数量
            long long cnt = 0;
            for (int num : nums) {
                cnt += (num - 1) / k;
            }
            return cnt <= maxOperations;
        };
        int left = 0, right = *max_element(nums.begin(), nums.end());
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [9]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,4,8,2]\n4\n
// @lcpr case=end

// @lcpr case=start
// [7,17]\n2\n
// @lcpr case=end

 */

