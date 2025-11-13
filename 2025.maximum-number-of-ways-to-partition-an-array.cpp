/*
 * @lc app=leetcode.cn id=2025 lang=cpp
 * @lcpr version=
 *
 * [2025] 分割数组的最多方案数
 *
 * https://leetcode.cn/problems/maximum-number-of-ways-to-partition-an-array/description/
 *
 * algorithms
 * Hard (33.91%)
 * Likes:    44
 * Dislikes: 0
 * Total Accepted:    3.9K
 * Total Submissions: 11.4K
 * Testcase Example:  '[2,-1,2]\n3'
 *
 * 给你一个下标从 0 开始且长度为 n 的整数数组 nums 。分割 数组 nums 的方案数定义为符合以下两个条件的 pivot 数目：
 * 
 * 
 * 1 <= pivot < n
 * nums[0] + nums[1] + ... + nums[pivot - 1] == nums[pivot] + nums[pivot + 1] +
 * ... + nums[n - 1]
 * 
 * 
 * 同时给你一个整数 k 。你可以将 nums 中 一个 元素变为 k 或 不改变 数组。
 * 
 * 请你返回在 至多 改变一个元素的前提下，最多 有多少种方法 分割 nums 使得上述两个条件都满足。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [2,-1,2], k = 3
 * 输出：1
 * 解释：一个最优的方案是将 nums[0] 改为 k 。数组变为 [3,-1,2] 。
 * 有一种方法分割数组：
 * - pivot = 2 ，我们有分割 [3,-1 | 2]：3 + -1 == 2 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [0,0,0], k = 1
 * 输出：2
 * 解释：一个最优的方案是不改动数组。
 * 有两种方法分割数组：
 * - pivot = 1 ，我们有分割 [0 | 0,0]：0 == 0 + 0 。
 * - pivot = 2 ，我们有分割 [0,0 | 0]: 0 + 0 == 0 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [22,4,-25,-20,-15,15,-16,7,19,-10,0,-13,-14], k = -33
 * 输出：4
 * 解释：一个最优的方案是将 nums[2] 改为 k 。数组变为 [22,4,-33,-20,-15,15,-16,7,19,-10,0,-13,-14]
 * 。
 * 有四种方法分割数组。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 2 <= n <= 10^5
 * -10^5 <= k, nums[i] <= 10^5
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
using ll = long long;
class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        vector<ll> sum(n);
        sum[0] = nums[0];
        unordered_map<ll, int> cl, cr;
        for (int i = 1; i < n; ++i) {
            sum[i] = sum[i - 1] + nums[i];
            cr[sum[i - 1]]++;
        }
        ll tot = sum[n - 1];
        if (tot % 2 == 0) ans = cr[tot / 2];
        //cl表示当修改nums[i]为k时，分隔位pivot小于i存放的前缀和，同理cr表示大于或者等于。
        for (int i = 0; i < n; ++i) {
            int dif = k - nums[i];
            if ((tot + dif) % 2 == 0) {
                //cr + dif == (tot + dif) / 2,因为cr的前缀和都包含了修改前的nums[i]
                ans = max(ans, cl[(tot + dif) / 2] + cr[(tot - dif) / 2]);
            }
            cl[sum[i]]++;
            cr[sum[i]]--;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,-1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n1\n
// @lcpr case=end

// @lcpr case=start
// [22,4,-25,-20,-15,15,-16,7,19,-10,0,-13,-14]\n-33\n
// @lcpr case=end

 */

