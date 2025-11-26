/*
 * @lc app=leetcode.cn id=2348 lang=cpp
 * @lcpr version=30204
 *
 * [2348] 全 0 子数组的数目
 *
 * https://leetcode.cn/problems/number-of-zero-filled-subarrays/description/
 *
 * algorithms
 * Medium (66.40%)
 * Likes:    48
 * Dislikes: 0
 * Total Accepted:    29.2K
 * Total Submissions: 44K
 * Testcase Example:  '[1,3,0,0,2,0,0,4]'
 *
 * 给你一个整数数组 nums ，返回全部为 0 的 子数组 数目。
 * 
 * 子数组 是一个数组中一段连续非空元素组成的序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,3,0,0,2,0,0,4]
 * 输出：6
 * 解释：
 * 子数组 [0] 出现了 4 次。
 * 子数组 [0,0] 出现了 2 次。
 * 不存在长度大于 2 的全 0 子数组，所以我们返回 6 。
 * 
 * 示例 2：
 * 
 * 输入：nums = [0,0,0,2,0,0]
 * 输出：9
 * 解释：
 * 子数组 [0] 出现了 5 次。
 * 子数组 [0,0] 出现了 3 次。
 * 子数组 [0,0,0] 出现了 1 次。
 * 不存在长度大于 3 的全 0 子数组，所以我们返回 9 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [2,10,2019]
 * 输出：0
 * 解释：没有全 0 子数组，所以我们返回 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
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
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int last = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                last = i;
            } else {
                res += i - last;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,0,0,2,0,0,4]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0,2,0,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,10,2019]\n
// @lcpr case=end

 */

