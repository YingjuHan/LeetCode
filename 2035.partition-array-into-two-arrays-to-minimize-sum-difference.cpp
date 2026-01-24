/*
 * @lc app=leetcode.cn id=2035 lang=cpp
 * @lcpr version=30204
 *
 * [2035] 将数组分成两个数组并最小化数组和的差
 *
 * https://leetcode.cn/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/
 *
 * algorithms
 * Hard (39.42%)
 * Likes:    88
 * Dislikes: 0
 * Total Accepted:    6.5K
 * Total Submissions: 16.4K
 * Testcase Example:  '[3,9,7,3]'
 *
 * 给你一个长度为 2 * n 的整数数组。你需要将 nums 分成 两个 长度为 n 的数组，分别求出两个数组的和，并 最小化 两个数组和之 差的绝对值
 * 。nums 中每个元素都需要放入两个数组之一。
 * 
 * 请你返回 最小 的数组和之差。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：nums = [3,9,7,3]
 * 输出：2
 * 解释：最优分组方案是分成 [3,9] 和 [7,3] 。
 * 数组和之差的绝对值为 abs((3 + 9) - (7 + 3)) = 2 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [-36,36]
 * 输出：72
 * 解释：最优分组方案是分成 [-36] 和 [36] 。
 * 数组和之差的绝对值为 abs((-36) - (36)) = 72 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：nums = [2,-1,0,4,-2,-9]
 * 输出：0
 * 解释：最优分组方案是分成 [2,4,-9] 和 [-1,0,-2] 。
 * 数组和之差的绝对值为 abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 15
 * nums.length == 2 * n
 * -10^7 <= nums[i] <= 10^7
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
#include <bits/stdc++.h>

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = (int)nums.size() / 2;
        vector<int> L(nums.begin(), nums.begin() + n);
        vector<int> R(nums.begin() + n, nums.end());

        // left[cnt] 存左半：选 cnt 个 + 时的带符号和
        vector<vector<int>> left(n + 1);

        for (int mask = 0; mask < (1 << n); ++mask) {
            int sum = 0, cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (mask >> j & 1) {   // 1 => +L[j]
                    sum += L[j];
                    cnt++;
                } else {               // 0 => -L[j]
                    sum -= L[j];
                }
            }
            left[cnt].push_back(sum);
        }

        for (auto& v : left) sort(v.begin(), v.end());

        long long ans = LLONG_MAX;

        for (int mask = 0; mask < (1 << n); ++mask) {
            int sumR = 0, cntR = 0;
            for (int j = 0; j < n; ++j) {
                if (mask >> j & 1) {   // 1 => +R[j]
                    sumR += R[j];
                    cntR++;
                } else {               // 0 => -R[j]
                    sumR -= R[j];
                }
            }

            int need = n - cntR;          // 左半需要的 + 个数
            auto& v = left[need];

            int target = -sumR;           // 希望 sumL 接近 -sumR
            auto it = lower_bound(v.begin(), v.end(), target);

            if (it != v.end()) {
                ans = min(ans, llabs((long long)*it + sumR));
            }
            if (it != v.begin()) {
                --it;
                ans = min(ans, llabs((long long)*it + sumR));
            }
        }

        return (int)ans;
    }
};

// @lc code=end



/*
// @lcpr case=start
// [3,9,7,3]\n
// @lcpr case=end

// @lcpr case=start
// [-36,36]\n
// @lcpr case=end

// @lcpr case=start
// [2,-1,0,4,-2,-9]\n
// @lcpr case=end

 */

