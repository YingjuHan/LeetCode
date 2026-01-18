/*
 * @lc app=leetcode.cn id=2597 lang=cpp
 * @lcpr version=30204
 *
 * [2597] 美丽子集的数目
 *
 * https://leetcode.cn/problems/the-number-of-beautiful-subsets/description/
 *
 * algorithms
 * Medium (50.37%)
 * Likes:    96
 * Dislikes: 0
 * Total Accepted:    23.8K
 * Total Submissions: 47.3K
 * Testcase Example:  '[2,4,6]\n2'
 *
 * 给你一个由正整数组成的数组 nums 和一个 正 整数 k 。
 * 
 * 如果 nums 的子集中，任意两个整数的绝对差均不等于 k ，则认为该子数组是一个 美丽 子集。
 * 
 * 返回数组 nums 中 非空 且 美丽 的子集数目。
 * 
 * nums 的子集定义为：可以经由 nums
 * 删除某些元素（也可能不删除）得到的一个数组。只有在删除元素时选择的索引不同的情况下，两个子集才会被视作是不同的子集。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [2,4,6], k = 2
 * 输出：4
 * 解释：数组 nums 中的美丽子集有：[2], [4], [6], [2, 6] 。
 * 可以证明数组 [2,4,6] 中只存在 4 个美丽子集。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1], k = 1
 * 输出：1
 * 解释：数组 nums 中的美丽数组有：[1] 。
 * 可以证明数组 [1] 中只存在 1 个美丽子集。 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 18
 * 1 <= nums[i], k <= 1000
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
    int beautifulSubsets(vector<int>& nums, int k) {
        int res = -1;
        unordered_map<int, int> cnt;

        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (i == nums.size()) {
                res++;
                return;
            }
            dfs(i + 1);

            int x = nums[i];
            // 在选择 x=nums[i] 的时候，如果之前选过 x−k 或 x+k，则不能选，否则可以选。
            if (cnt[x - k] == 0 && cnt[x + k] == 0) {
                cnt[x]++;
                dfs(i + 1);
                cnt[x]--;
            }
        };
        dfs(0);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,4,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

