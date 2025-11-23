/*
 * @lc app=leetcode.cn id=1262 lang=cpp
 * @lcpr version=30204
 *
 * [1262] 可被三整除的最大和
 *
 * https://leetcode.cn/problems/greatest-sum-divisible-by-three/description/
 *
 * algorithms
 * Medium (56.71%)
 * Likes:    392
 * Dislikes: 0
 * Total Accepted:    55.9K
 * Total Submissions: 96.5K
 * Testcase Example:  '[3,6,5,1,8]'
 *
 * 给你一个整数数组 nums，请你找出并返回能被三整除的元素 最大和。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [3,6,5,1,8]
 * 输出：18
 * 解释：选出数字 3, 6, 1 和 8，它们的和是 18（可被 3 整除的最大和）。
 * 
 * 示例 2：
 * 
 * 输入：nums = [4]
 * 输出：0
 * 解释：4 不能被 3 整除，所以无法选出数字，返回 0。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [1,2,3,4,4]
 * 输出：12
 * 解释：选出数字 1, 3, 4 以及 4，它们的和是 12（可被 3 整除的最大和）。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 4 * 10^4
 * 1 <= nums[i] <= 10^4
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % 3 == 0) {
            return s;
        } 

        vector<int> a[3];
        for (int x : nums) {
            a[x % 3].push_back(x);
        }
        sort(a[1].begin(), a[1].end());
        sort(a[2].begin(), a[2].end());
        int res;
        if (s % 3 == 1) {
            int res1 = a[1].size() > 0 ? s - a[1][0] : 0;
            int res2 = a[2].size() > 1 ? s - a[2][0] - a[2][1] : 0;
            res = max(res1, res2);
        }
        if (s % 3 == 2) {
            int res1 = a[2].size() > 0 ? s - a[2][0] : 0;
            int res2 = a[1].size() > 1 ? s - a[1][0] - a[1][1] : 0;
            res = max(res1, res2);
        }
        
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,6,5,1,8]\n
// @lcpr case=end

// @lcpr case=start
// [4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,4]\n
// @lcpr case=end

 */

