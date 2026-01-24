/*
 * @lc app=leetcode.cn id=1755 lang=cpp
 * @lcpr version=30204
 *
 * [1755] 最接近目标值的子序列和
 *
 * https://leetcode.cn/problems/closest-subsequence-sum/description/
 *
 * algorithms
 * Hard (48.55%)
 * Likes:    112
 * Dislikes: 0
 * Total Accepted:    10.1K
 * Total Submissions: 20.7K
 * Testcase Example:  '[5,-7,3,5]\n6'
 *
 * 给你一个整数数组 nums 和一个目标值 goal 。
 * 
 * 你需要从 nums 中选出一个子序列，使子序列元素总和最接近 goal 。也就是说，如果子序列元素和为 sum ，你需要 最小化绝对差 abs(sum
 * - goal) 。
 * 
 * 返回 abs(sum - goal) 可能的 最小值 。
 * 
 * 注意，数组的子序列是通过移除原始数组中的某些元素（可能全部或无）而形成的数组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [5,-7,3,5], goal = 6
 * 输出：0
 * 解释：选择整个数组作为选出的子序列，元素和为 6 。
 * 子序列和与目标值相等，所以绝对差为 0 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [7,-9,15,-2], goal = -5
 * 输出：1
 * 解释：选出子序列 [7,-9,-2] ，元素和为 -4 。
 * 绝对差为 abs(-4 - (-5)) = abs(1) = 1 ，是可能的最小值。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [1,2,3], goal = -7
 * 输出：7
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 40
 * -10^7 <= nums[i] <= 10^7
 * -10^9 <= goal <= 10^9
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
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size(), m = n / 2;
        int ls = m, rs = n - m;

        vector<int> lsum(1 << ls, 0);
        for (int i = 1; i < (1 << ls); i++) {
            for (int j = 0; j < ls ; j++) {
                if (i & (1 << j)) {
                    lsum[i] = lsum[i - (1 << j)] + nums[j];
                    break;
                }
            }
        }

        vector<int> rsum(1 << rs, 0);
        for (int i = 1; i < (1 << rs); i++) {
            for (int j = 0; j < rs; j++) {
                if (i & (1 << j)) {
                    rsum[i] = rsum[i - (1 << j)] + nums[ls + j];
                }
            }
        }

        sort(lsum.begin(), lsum.end());
        sort(rsum.begin(), rsum.end());

        int res = INT_MAX;
        for (int x : lsum) {
            res = min(res, abs(goal - x));
        }
        for (int x : rsum) {
            res = min(res, abs(goal - x));
        }

        int i = 0, j = rsum.size() - 1;
        while (i < lsum.size() && j >= 0) {
            int s = lsum[i] + rsum[j];
            res = min(res, abs(goal - s));

            if (s > goal) {
                j--;
            } else {
                i++;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,-7,3,5]\n6\n
// @lcpr case=end

// @lcpr case=start
// [7,-9,15,-2]\n-5\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n-7\n
// @lcpr case=end

 */

