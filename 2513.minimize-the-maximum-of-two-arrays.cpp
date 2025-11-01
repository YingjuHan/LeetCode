/*
 * @lc app=leetcode.cn id=2513 lang=cpp
 * @lcpr version=30204
 *
 * [2513] 最小化两个数组中的最大值
 *
 * https://leetcode.cn/problems/minimize-the-maximum-of-two-arrays/description/
 *
 * algorithms
 * Medium (37.71%)
 * Likes:    52
 * Dislikes: 0
 * Total Accepted:    4.9K
 * Total Submissions: 13K
 * Testcase Example:  '2\n7\n1\n3'
 *
 * 给你两个数组 arr1 和 arr2 ，它们一开始都是空的。你需要往它们中添加正整数，使它们满足以下条件：
 * 
 * 
 * arr1 包含 uniqueCnt1 个 互不相同 的正整数，每个整数都 不能 被 divisor1 整除 。
 * arr2 包含 uniqueCnt2 个 互不相同 的正整数，每个整数都 不能 被 divisor2 整除 。
 * arr1 和 arr2 中的元素 互不相同 。
 * 
 * 
 * 给你 divisor1 ，divisor2 ，uniqueCnt1 和 uniqueCnt2 ，请你返回两个数组中 最大元素 的 最小值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：divisor1 = 2, divisor2 = 7, uniqueCnt1 = 1, uniqueCnt2 = 3
 * 输出：4
 * 解释：
 * 我们可以把前 4 个自然数划分到 arr1 和 arr2 中。
 * arr1 = [1] 和 arr2 = [2,3,4] 。
 * 可以看出两个数组都满足条件。
 * 最大值是 4 ，所以返回 4 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：divisor1 = 3, divisor2 = 5, uniqueCnt1 = 2, uniqueCnt2 = 1
 * 输出：3
 * 解释：
 * arr1 = [1,2] 和 arr2 = [3] 满足所有条件。
 * 最大值是 3 ，所以返回 3 。
 * 
 * 示例 3：
 * 
 * 输入：divisor1 = 2, divisor2 = 4, uniqueCnt1 = 8, uniqueCnt2 = 2
 * 输出：15
 * 解释：
 * 最终数组为 arr1 = [1,3,5,7,9,11,13,15] 和 arr2 = [2,6] 。
 * 上述方案是满足所有条件的最优解。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= divisor1, divisor2 <= 10^5
 * 1 <= uniqueCnt1, uniqueCnt2 < 10^9
 * 2 <= uniqueCnt1 + uniqueCnt2 <= 10^9
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
    long long lcmf(long long a, long long b) {
        return a / gcd(a, b) * b;
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        
        long long lcm = lcmf(divisor1, divisor2);
        auto check = [&](int mx) -> bool {
            long long left1 = max(0LL, uniqueCnt1 - (mx / divisor2 - mx / lcm));
            long long left2 = max(0LL, uniqueCnt2 - (mx / divisor1 - mx / lcm));
            long long common = mx - mx / divisor1 - mx / divisor2 + mx / lcm;
            return common >= left1 + left2;
        };

        long long left = 1LL, right = (uniqueCnt1 + uniqueCnt2) * 2LL;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n7\n1\n3\n
// @lcpr case=end

// @lcpr case=start
// 3\n5\n2\n1\n
// @lcpr case=end

// @lcpr case=start
// 2\n4\n8\n2\n
// @lcpr case=end

 */

