/*
 * @lc app=leetcode.cn id=805 lang=cpp
 * @lcpr version=30204
 *
 * [805] 数组的均值分割
 *
 * https://leetcode.cn/problems/split-array-with-same-average/description/
 *
 * algorithms
 * Hard (42.59%)
 * Likes:    319
 * Dislikes: 0
 * Total Accepted:    24.9K
 * Total Submissions: 58.6K
 * Testcase Example:  '[1,2,3,4,5,6,7,8]'
 *
 * 给定你一个整数数组 nums
 * 
 * 我们要将 nums 数组中的每个元素移动到 A 数组 或者 B 数组中，使得 A 数组和 B 数组不为空，并且 average(A) ==
 * average(B) 。
 * 
 * 如果可以完成则返回true ， 否则返回 false  。
 * 
 * 注意：对于数组 arr ,  average(arr) 是 arr 的所有元素的和除以 arr 长度。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,2,3,4,5,6,7,8]
 * 输出: true
 * 解释: 我们可以将数组分割为 [1,4,5,8] 和 [2,3,6,7], 他们的平均值都是4.5。
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [3,1]
 * 输出: false
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= nums.length <= 30
 * 0 <= nums[i] <= 10^4
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
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size(), m = n / 2;
        if (n == 1) {
            return false;
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int &x : nums) {
            x = x * n - sum;
        }

        // 枚举左半所有非空子集和，存进哈希表
        unordered_set<int> left;
        for (int i = 1; i < (1 << m); i++) {
            int total = 0;
            for (int j = 0; j < m; j++) {
                if (i & (1 << j)) { // 整数i的第j位是不是1 (当前方案中，要不要选第 j 个元素, j是1-选,j是0-不选)
                    total += nums[j];
                }
            }
            if (total == 0) {
                return true;
            }
            left.emplace(total);
        }

        int rsum = accumulate(nums.begin() + m, nums.end(), 0);
        for (int i = 1; i < (1 << (n - m)); i++) {
            int total = 0;
            for (int j = m; j < n; j++) {
                if (i & (1 << (j - m))) {
                    total += nums[j]; // 整数i的第j - m位是不是1 (当前方案中，要不要选第 j - m 个元素, 是1-选,是0-不选)
                }
            }
            if (total == 0 || (rsum != total && left.count(-total))) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,7,8]\n
// @lcpr case=end

// @lcpr case=start
// [3,1]\n
// @lcpr case=end

 */

