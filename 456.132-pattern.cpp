/*
 * @lc app=leetcode.cn id=456 lang=cpp
 * @lcpr version=30204
 *
 * [456] 132 模式
 *
 * https://leetcode.cn/problems/132-pattern/description/
 *
 * algorithms
 * Medium (36.84%)
 * Likes:    913
 * Dislikes: 0
 * Total Accepted:    91.7K
 * Total Submissions: 249K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个整数数组 nums ，数组中共有 n 个整数。132 模式的子序列 由三个整数 nums[i]、nums[j] 和 nums[k]
 * 组成，并同时满足：i < j < k 和 nums[i] < nums[k] < nums[j] 。
 * 
 * 如果 nums 中存在 132 模式的子序列 ，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：false
 * 解释：序列中不存在 132 模式的子序列。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [3,1,4,2]
 * 输出：true
 * 解释：序列中有 1 个 132 模式的子序列： [1, 4, 2] 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [-1,3,2,0]
 * 输出：true
 * 解释：序列中有 3 个 132 模式的的子序列：[-1, 3, 2]、[-1, 3, 0] 和 [-1, 2, 0] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 <= n <= 2 * 10^5
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
#include <set>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }

        // 左侧最小值
        int left_min = nums[0];
        // 右侧所有元素,
        // 由于 2 是模式中的次小值，因此我们可以使用一个有序集合（例如平衡树）维护
        // 数组 a 中右侧元素 a[j+1..n−1] 中的所有值。当我们确定了 a[i] 和 a[j] 之后，
        // 只需要在有序集合中查询严格比 a[i] 大的那个最小的元素，即为 a[k]。
        // 需要注意的是，只有 a[k]<a[j] 时，a[k] 才能作为 3 对应的元素

        multiset<int> right_all;

        for (int k = 2; k < n; ++k) {
            right_all.insert(nums[k]);
        }

        for (int j = 1; j < n - 1; ++j) {
            if (left_min < nums[j]) {
                auto it = right_all.upper_bound(left_min);
                if (it != right_all.end() && *it < nums[j]) {
                    return true;
                }
            }
            left_min = min(left_min, nums[j]);
            right_all.erase(right_all.find(nums[j + 1]));
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [-1,3,2,0]\n
// @lcpr case=end

 */

