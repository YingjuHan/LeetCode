/*
 * @lc app=leetcode.cn id=967 lang=cpp
 * @lcpr version=30204
 *
 * [967] 连续差相同的数字
 *
 * https://leetcode.cn/problems/numbers-with-same-consecutive-differences/description/
 *
 * algorithms
 * Medium (55.28%)
 * Likes:    118
 * Dislikes: 0
 * Total Accepted:    19.5K
 * Total Submissions: 35.3K
 * Testcase Example:  '3\n7'
 *
 * 返回所有长度为 n 且满足其每两个连续位上的数字之间的差的绝对值为 k 的 非负整数 。
 * 
 * 请注意，除了 数字 0 本身之外，答案中的每个数字都 不能 有前导零。例如，01 有一个前导零，所以是无效的；但 0 是有效的。
 * 
 * 你可以按 任何顺序 返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 3, k = 7
 * 输出：[181,292,707,818,929]
 * 解释：注意，070 不是一个有效的数字，因为它有前导零。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 2, k = 1
 * 输出：[10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 * 
 * 示例 3：
 * 
 * 输入：n = 2, k = 0
 * 输出：[11,22,33,44,55,66,77,88,99]
 * 
 * 
 * 示例 4：
 * 
 * 输入：n = 2, k = 2
 * 输出：[13,20,24,31,35,42,46,53,57,64,68,75,79,86,97]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= n <= 9
 * 0 <= k <= 9
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
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;

        auto dfs = [&](this auto&& dfs, int i, int left) -> void {
            if (left == 0) {
                res.push_back(i);
                return;
            }

            int a = i % 10; // 末尾数字是 a
            if (a + k < 10) { // // 下一个数字可以填 a+k
                dfs(i * 10 + a + k, left - 1);
            }

            // // 下一个数字可以填 a-k
            if (k > 0 && a - k >= 0) {
                dfs(i * 10 + a - k, left - 1);
            }
        };

        for (int i = 1; i <= 9; i++) {
            dfs(i, n - 1);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 2\n1\n
// @lcpr case=end

// @lcpr case=start
// 2\n0\n
// @lcpr case=end

// @lcpr case=start
// 2\n2\n
// @lcpr case=end

 */

