/*
 * @lc app=leetcode.cn id=1671 lang=cpp
 * @lcpr version=30204
 *
 * [1671] 得到山形数组的最少删除次数
 *
 * https://leetcode.cn/problems/minimum-number-of-removals-to-make-mountain-array/description/
 *
 * algorithms
 * Hard (50.21%)
 * Likes:    156
 * Dislikes: 0
 * Total Accepted:    23K
 * Total Submissions: 45.8K
 * Testcase Example:  '[1,3,1]'
 *
 * 我们定义 arr 是 山形数组 当且仅当它满足：
 * 
 * 
 * arr.length >= 3
 * 存在某个下标 i （从 0 开始） 满足 0 < i < arr.length - 1 且：
 * 
 * arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
 * arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
 * 
 * 
 * 
 * 
 * 给你整数数组 nums​ ，请你返回将 nums 变成 山形状数组 的​ 最少 删除次数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,3,1]
 * 输出：0
 * 解释：数组本身就是山形数组，所以我们不需要删除任何元素。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [2,1,1,5,6,2,3,1]
 * 输出：3
 * 解释：一种方法是将下标为 0，1 和 5 的元素删除，剩余元素为 [1,5,6,3,1] ，是山形数组。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 1000
 * 1 <= nums[i] <= 10^9
 * 题目保证 nums 删除一些元素后一定能得到山形数组。
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
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf(n), g;
        for (int i = n - 1; i >= 0; i--) {
            int x = nums[i];
            auto it = lower_bound(g.begin(), g.end(), x);
            suf[i] = it - g.begin() + 1; // 从 nums[i] 开始的最长严格递减子序列的长度
            if (it == g.end()) {
                g.push_back(x);
            } else {
                *it = x;
            }
        }

        int mx = 0;
        g.clear();
        for (int i = 0; i < n - 1; i++) {
            int x = nums[i];
            auto it = lower_bound(g.begin(), g.end(), x);
            int pre = it - g.begin() + 1; // 在 nums[i] 结束的最长严格递增子序列的长度
            if (it == g.end()) {
                g.push_back(x);
            } else {
                *it = x;
            }
            if (pre >= 2 && suf[i] >= 2) {
                mx = max(mx, pre + suf[i] - 1);
            }
        }
        return n - mx;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,1,5,6,2,3,1]\n
// @lcpr case=end

 */

