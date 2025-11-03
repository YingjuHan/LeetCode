/*
 * @lc app=leetcode.cn id=1995 lang=cpp
 * @lcpr version=30204
 *
 * [1995] 统计特殊四元组
 *
 * https://leetcode.cn/problems/count-special-quadruplets/description/
 *
 * algorithms
 * Easy (67.40%)
 * Likes:    155
 * Dislikes: 0
 * Total Accepted:    45K
 * Total Submissions: 66.7K
 * Testcase Example:  '[1,2,3,6]'
 *
 * 给你一个 下标从 0 开始 的整数数组 nums ，返回满足下述条件的 不同 四元组 (a, b, c, d) 的 数目 ：
 * 
 * 
 * nums[a] + nums[b] + nums[c] == nums[d] ，且
 * a < b < c < d
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,2,3,6]
 * 输出：1
 * 解释：满足要求的唯一一个四元组是 (0, 1, 2, 3) 因为 1 + 2 + 3 == 6 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [3,3,6,4,5]
 * 输出：0
 * 解释：[3,3,6,4,5] 中不存在满足要求的四元组。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [1,1,1,3,5]
 * 输出：4
 * 解释：满足要求的 4 个四元组如下：
 * - (0, 1, 2, 3): 1 + 1 + 1 == 3
 * - (0, 1, 3, 4): 1 + 1 + 3 == 5
 * - (0, 2, 3, 4): 1 + 1 + 3 == 5
 * - (1, 2, 3, 4): 1 + 1 + 3 == 5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 4 <= nums.length <= 50
 * 1 <= nums[i] <= 100
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
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        unordered_map<int, int> mp;
        for (int c = 0; c < n; c++) {
            for (int d = c + 1; d < n; d++) {
                res += mp[nums[d] - nums[c]];
            }
            for (int a = 0; a < c; a++) {
                mp[nums[a] + nums[c]]++;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,6]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,6,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,3,5]\n
// @lcpr case=end

 */

