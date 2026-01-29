/*
 * @lc app=leetcode.cn id=1191 lang=cpp
 * @lcpr version=
 *
 * [1191] K 次串联后最大子数组之和
 *
 * https://leetcode.cn/problems/k-concatenation-maximum-sum/description/
 *
 * algorithms
 * Medium (28.60%)
 * Likes:    171
 * Dislikes: 0
 * Total Accepted:    20.4K
 * Total Submissions: 71.1K
 * Testcase Example:  '[1,2]\n3'
 *
 * 给定一个整数数组 arr 和一个整数 k ，通过重复 k 次来修改数组。
 * 
 * 例如，如果 arr = [1, 2] ， k = 3 ，那么修改后的数组将是 [1, 2, 1, 2, 1, 2] 。
 * 
 * 返回修改后的数组中的最大的子数组之和。注意，子数组长度可以是 0，在这种情况下它的总和也是 0。
 * 
 * 由于 结果可能会很大，需要返回的 10^9 + 7 的 模 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [1,2], k = 3
 * 输出：9
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [1,-2,1], k = 5
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = [-1,-2], k = 7
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 1 <= arr.length <= 10^5
 * 1 <= k <= 10^5
 * -10^4 <= arr[i] <= 10^4
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
    int maxSubArray(vector<int>& nums, int repeat = 1) {
        int n = nums.size();
        int ans = 0, f = 0; // 本题允许子数组为空，ans 可以初始化成 0
        for (int i = 0; i < n * repeat; i++) {
            f = max(f, 0) + nums[i % n];
            ans = max(ans, f);
        }
        return ans;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        if (k == 1) {
            return maxSubArray(arr);
        }
        long long ans = maxSubArray(arr, 2);
        int s = reduce(arr.begin(), arr.end());
        ans += 1LL * max(s, 0) * (k - 2);
        return ans % 1'000'000'007;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,-2,1]\n5\n
// @lcpr case=end

// @lcpr case=start
// [-1,-2]\n7\n
// @lcpr case=end

 */

