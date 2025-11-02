/*
 * @lc app=leetcode.cn id=1679 lang=cpp
 * @lcpr version=30204
 *
 * [1679] K 和数对的最大数目
 *
 * https://leetcode.cn/problems/max-number-of-k-sum-pairs/description/
 *
 * algorithms
 * Medium (58.11%)
 * Likes:    114
 * Dislikes: 0
 * Total Accepted:    56.2K
 * Total Submissions: 93.3K
 * Testcase Example:  '[1,2,3,4]\n5'
 *
 * 给你一个整数数组 nums 和一个整数 k 。
 * 
 * 每一步操作中，你需要从数组中选出和为 k 的两个整数，并将它们移出数组。
 * 
 * 返回你可以对数组执行的最大操作数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,2,3,4], k = 5
 * 输出：2
 * 解释：开始时 nums = [1,2,3,4]：
 * - 移出 1 和 4 ，之后 nums = [2,3]
 * - 移出 2 和 3 ，之后 nums = []
 * 不再有和为 5 的数对，因此最多执行 2 次操作。
 * 
 * 示例 2：
 * 
 * 输入：nums = [3,1,3,4,3], k = 6
 * 输出：1
 * 解释：开始时 nums = [3,1,3,4,3]：
 * - 移出前两个 3 ，之后nums = [1,4,3]
 * 不再有和为 6 的数对，因此最多执行 1 次操作。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 1 <= k <= 10^9
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
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int res = 0;
        for (int num : nums) {
            if (mp.count(k - num)) {
                res++;
                mp[k - num]--;
                if (mp[k - num] == 0) {
                    mp.erase(k - num);
                }
            } else {
                mp[num]++;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n5\n
// @lcpr case=end

// @lcpr case=start
// [3,1,3,4,3]\n6\n
// @lcpr case=end

 */

