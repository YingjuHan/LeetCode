/*
 * @lc app=leetcode.cn id=368 lang=cpp
 * @lcpr version=
 *
 * [368] 最大整除子集
 *
 * https://leetcode.cn/problems/largest-divisible-subset/description/
 *
 * algorithms
 * Medium (47.32%)
 * Likes:    649
 * Dislikes: 0
 * Total Accepted:    80.9K
 * Total Submissions: 170.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个由 无重复 正整数组成的集合 nums ，请你找出并返回其中最大的整除子集 answer ，子集中每一元素对 (answer[i],
 * answer[j]) 都应当满足：
 * 
 * answer[i] % answer[j] == 0 ，或
 * answer[j] % answer[i] == 0
 * 
 * 
 * 如果存在多个有效解子集，返回其中任何一个均可。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,2,3]
 * 输出：[1,2]
 * 解释：[1,3] 也会被视为正确答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,2,4,8]
 * 输出：[1,2,4,8]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 2 * 10^9
 * nums 中的所有整数 互不相同
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
    vector<int> largestDivisibleSubset1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> memo(n), from(n, -1);

        auto dfs = [&](this auto&& dfs, int i) -> int {
            int &res = memo[i];
            if (res) {
                return res;
            }

            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j]) {
                    continue;
                }
                int f = dfs(j);
                if (f > res) {
                    res = f;
                    from[i] = j;
                }
            }
            res++;
            return res;
        };

        int max_f = 0, max_i = 0;
        for (int i = 0; i < n; i++) {
            int f = dfs(i);
            if (f > max_f) {
                max_f = f;
                max_i = i;
            }
        }
        
        vector<int> path;
        for (int i = max_i; i >= 0; i = from[i]) {
            path.emplace_back(nums[i]);
        }
        return path;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n + 1, 0), from(n, -1);

        int max_f = 0, max_i = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] > dp[i]) {
                    dp[i] = dp[j];
                    from[i] = j; 
                }
            }
            dp[i]++;
            if (dp[i] > dp[max_i]) {
                max_i = i;
            }
        }
        vector<int> path;
        for (int i = max_i; i >= 0; i = from[i]) {
            path.push_back(nums[i]);
        }
        return path; // 不需要 reverse，任意顺序返回均可
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,4,8]\n
// @lcpr case=end

 */

