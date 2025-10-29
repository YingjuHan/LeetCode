/*
 * @lc app=leetcode.cn id=2226 lang=cpp
 * @lcpr version=30204
 *
 * [2226] 每个小孩最多能分到多少糖果
 *
 * https://leetcode.cn/problems/maximum-candies-allocated-to-k-children/description/
 *
 * algorithms
 * Medium (40.54%)
 * Likes:    98
 * Dislikes: 0
 * Total Accepted:    27.1K
 * Total Submissions: 66.9K
 * Testcase Example:  '[5,8,6]\n3'
 *
 * 给你一个 下标从 0 开始 的整数数组 candies 。数组中的每个元素表示大小为 candies[i] 的一堆糖果。你可以将每堆糖果分成任意数量的
 * 子堆 ，但 无法 再将两堆合并到一起。
 * 
 * 另给你一个整数 k 。你需要将这些糖果分配给 k 个小孩，使每个小孩分到 相同 数量的糖果。每个小孩可以拿走 至多一堆 糖果，有些糖果可能会不被分配。
 * 
 * 返回每个小孩可以拿走的 最大糖果数目 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：candies = [5,8,6], k = 3
 * 输出：5
 * 解释：可以将 candies[1] 分成大小分别为 5 和 3 的两堆，然后把 candies[2] 分成大小分别为 5 和 1
 * 的两堆。现在就有五堆大小分别为 5、5、3、5 和 1 的糖果。可以把 3 堆大小为 5 的糖果分给 3 个小孩。可以证明无法让每个小孩得到超过 5
 * 颗糖果。
 * 
 * 
 * 示例 2：
 * 
 * 输入：candies = [2,5], k = 11
 * 输出：0
 * 解释：总共有 11 个小孩，但只有 7 颗糖果，但如果要分配糖果的话，必须保证每个小孩至少能得到 1 颗糖果。因此，最后每个小孩都没有得到糖果，答案是
 * 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= candies.length <= 10^5
 * 1 <= candies[i] <= 10^7
 * 1 <= k <= 10^12
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
    /**
     * 让每个小孩至少有low颗糖
     * low越大越难，越小越简单
     */
    int maximumCandies(vector<int>& candies, long long k) {
        auto check = [&](int low) -> bool {
            long long sum = 0;
            for (int c : candies) {
                sum += c / low;
            }
            return sum >= k;
        };

        // 开区间左端点初始值：0。不分配糖果就能满足要求。
        // 开区间右端点初始值：max(candies)+1。糖果堆只能分割不能合并，一定无法满足要求。
        // avg+1 也是无法满足的，所以右端点也可以初始化为 min(max(candies),avg)+1。
        long long avg = reduce(candies.begin(), candies.end(), 0LL) / k;
        int left = 0, right = min((long long) ranges::max(candies), avg) + 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,8,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,5]\n11\n
// @lcpr case=end

 */

