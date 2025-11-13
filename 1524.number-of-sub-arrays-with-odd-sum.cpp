/*
 * @lc app=leetcode.cn id=1524 lang=cpp
 * @lcpr version=30204
 *
 * [1524] 和为奇数的子数组数目
 *
 * https://leetcode.cn/problems/number-of-sub-arrays-with-odd-sum/description/
 *
 * algorithms
 * Medium (49.03%)
 * Likes:    111
 * Dislikes: 0
 * Total Accepted:    18.9K
 * Total Submissions: 36.5K
 * Testcase Example:  '[1,3,5]'
 *
 * 给你一个整数数组 arr 。请你返回和为 奇数 的子数组数目。
 * 
 * 由于答案可能会很大，请你将结果对 10^9 + 7 取余后返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [1,3,5]
 * 输出：4
 * 解释：所有的子数组为 [[1],[1,3],[1,3,5],[3],[3,5],[5]] 。
 * 所有子数组的和为 [1,4,9,3,8,5].
 * 奇数和包括 [1,9,3,5] ，所以答案为 4 。
 * 
 * 
 * 示例 2 ：
 * 
 * 输入：arr = [2,4,6]
 * 输出：0
 * 解释：所有子数组为 [[2],[2,4],[2,4,6],[4],[4,6],[6]] 。
 * 所有子数组和为 [2,6,12,4,10,6] 。
 * 所有子数组和都是偶数，所以答案为 0 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = [1,2,3,4,5,6,7]
 * 输出：16
 * 
 * 
 * 示例 4：
 * 
 * 输入：arr = [100,100,99,99]
 * 输出：4
 * 
 * 
 * 示例 5：
 * 
 * 输入：arr = [7]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 10^5
 * 1 <= arr[i] <= 100
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
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1'000'000'007;
        int n = arr.size();
        vector<int> cnt(2, 0);
        cnt[0] = 1;
        int res = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            res += (sum % 2 == 0 ? cnt[1] : cnt[0]);
            res %= MOD;
            cnt[sum % 2]++;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7]\n
// @lcpr case=end

// @lcpr case=start
// [100,100,99,99]\n
// @lcpr case=end

// @lcpr case=start
// [7]\n
// @lcpr case=end

 */

