/*
 * @lc app=leetcode.cn id=1590 lang=cpp
 * @lcpr version=
 *
 * [1590] 使数组和能被 P 整除
 *
 * https://leetcode.cn/problems/make-sum-divisible-by-p/description/
 *
 * algorithms
 * Medium (37.59%)
 * Likes:    273
 * Dislikes: 0
 * Total Accepted:    32.1K
 * Total Submissions: 85.3K
 * Testcase Example:  '[3,1,4,2]\n6'
 *
 * 给你一个正整数数组 nums，请你移除 最短 子数组（可以为 空），使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。
 * 
 * 请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 -1 。
 * 
 * 子数组 定义为原数组中连续的一组元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [3,1,4,2], p = 6
 * 输出：1
 * 解释：nums 中元素和为 10，不能被 p 整除。我们可以移除子数组 [4] ，剩余元素的和为 6 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [6,3,5,2], p = 9
 * 输出：2
 * 解释：我们无法移除任何一个元素使得和被 9 整除，最优方案是移除子数组 [5,2] ，剩余元素为 [6,3]，和为 9 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [1,2,3], p = 3
 * 输出：0
 * 解释：和恰好为 6 ，已经能被 3 整除了。所以我们不需要移除任何元素。
 * 
 * 
 * 示例  4：
 * 
 * 输入：nums = [1,2,3], p = 7
 * 输出：-1
 * 解释：没有任何方案使得移除子数组后剩余元素的和被 7 整除。
 * 
 * 
 * 示例 5：
 * 
 * 输入：nums = [1000000000,1000000000,1000000000], p = 3
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 1 <= p <= 10^9
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
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        vector<int> s(n + 1, 0);
        for (int i = 0; i < n; i++) {
            s[i + 1] = (s[i] + nums[i]) % p;
        }
        int total = s[n];
        if (total == 0) {
            return 0;
        }

        int res = n;
        unordered_map<int, int> last;
        for (int i = 0; i <= n;i++) {
            last[s[i]] = i;
            auto it = last.find((s[i] - total + p) % p);
            if (it != last.end()) {
                res = min(res, i - it->second);
            }
        }
        return res == n ? -1 : res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,4,2]\n6\n
// @lcpr case=end

// @lcpr case=start
// [6,3,5,2]\n9\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n7\n
// @lcpr case=end

// @lcpr case=start
// [1000000000,1000000000,1000000000]\n3\n
// @lcpr case=end

 */

