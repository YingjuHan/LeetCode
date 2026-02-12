/*
 * @lc app=leetcode.cn id=673 lang=cpp
 * @lcpr version=30204
 *
 * [673] 最长递增子序列的个数
 *
 * https://leetcode.cn/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (45.85%)
 * Likes:    975
 * Dislikes: 0
 * Total Accepted:    133.8K
 * Total Submissions: 291.3K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。
 * 
 * 注意 这个数列必须是 严格 递增的。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [1,3,5,4,7]
 * 输出: 2
 * 解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [2,2,2,2,2]
 * 输出: 5
 * 解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
 * 
 * 
 * 
 * 
 * 提示: 
 * 
 * 
 * 
 * 
 * 1 <= nums.length <= 2000
 * -10^6 <= nums[i] <= 10^6
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
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> f(nums.size(), 1); // 记录以nums[i]结尾的最大递增子序列长度
        vector<int> count(nums.size(), 1); // 记录是以nums[i]结尾的最大递增子序列个数
        int maxcnt = 1;
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] > nums[i]) {
                    if (f[j] == f[i] + 1) {// 此时dp[j]状态不由dp[i]转移, 即找到了另一最长序列
                        count[j] += count[i];
                    } else if (f[j] < f[i] + 1) { // 最长序列长度加一
                        f[j] = f[i] + 1;
                        count[j] = count[i];
                    }
                }
                maxcnt = max(f[j], maxcnt);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (f[i] == maxcnt)
                res += count[i];
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,5,4,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n
// @lcpr case=end

 */

