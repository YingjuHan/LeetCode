/*
 * @lc app=leetcode.cn id=3639 lang=cpp
 * @lcpr version=30204
 *
 * [3639] 变为活跃状态的最小时间
 *
 * https://leetcode.cn/problems/minimum-time-to-activate-string/description/
 *
 * algorithms
 * Medium (42.23%)
 * Likes:    6
 * Dislikes: 0
 * Total Accepted:    3K
 * Total Submissions: 7.2K
 * Testcase Example:  '"abc"\n[1,0,2]\n2'
 *
 * 给你一个长度为 n 的字符串 s 和一个整数数组 order，其中 order 是范围 [0, n - 1] 内数字的一个 排列。
 * 
 * 从时间 t = 0 开始，在每个时间点，将字符串 s 中下标为 order[t] 的字符替换为 '*'。
 * 
 * 如果 子字符串 包含 至少 一个 '*' ，则认为该子字符串有效。
 * 
 * 如果字符串中 有效子字符串 的总数大于或等于 k，则称该字符串为 活跃 字符串。
 * 
 * 返回字符串 s 变为 活跃 状态的最小时间 t。如果无法变为活跃状态，返回 -1。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abc", order = [1,0,2], k = 2
 * 
 * 输出: 0
 * 
 * 解释:
 * 
 * 
 * 
 * 
 * t
 * order[t]
 * 修改后的 s
 * 有效子字符串
 * 计数
 * 激活状态
 * (计数 >= k)
 * 
 * 
 * 
 * 
 * 0
 * 1
 * "a*c"
 * "*", "a*", "*c", "a*c"
 * 4
 * 是
 * 
 * 
 * 
 * 
 * 字符串 s 在 t = 0 时变为激活状态。因此，答案是 0。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "cat", order = [0,2,1], k = 6
 * 
 * 输出: 2
 * 
 * 解释:
 * 
 * 
 * 
 * 
 * t
 * order[t]
 * 修改后的 s
 * 有效子字符串
 * 计数
 * 激活状态
 * (计数 >= k)
 * 
 * 
 * 
 * 
 * 0
 * 0
 * "*at"
 * "*", "*a", "*at"
 * 3
 * 否
 * 
 * 
 * 1
 * 2
 * "*a*"
 * "*", "*a", "*a*", "a*", "*"
 * 5
 * 否
 * 
 * 
 * 2
 * 1
 * "***"
 * 所有子字符串(包含 '*')
 * 6
 * 是
 * 
 * 
 * 
 * 
 * 字符串 s 在 t = 2 时变为激活状态。因此，答案是 2。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "xy", order = [0,1], k = 4
 * 
 * 输出: -1
 * 
 * 解释:
 * 
 * 即使完成所有替换，也无法得到 k = 4 个有效子字符串。因此，答案是 -1。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= n == s.length <= 10^5
 * order.length == n
 * 0 <= order[i] <= n - 1
 * s 由小写英文字母组成。
 * order 是从 0 到 n - 1 的整数排列。
 * 1 <= k <= 10^9
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
    int minTime(string s, vector<int>& order, int k) {
        int n = s.size();

        // 全部都是*，都无法满足，共有n(n + 1)/2个有效子串
        if (1LL * n * (n + 1) / 2 < k) {
            return -1;
        }

        vector<int> star(n); // star数组标记哪些位置改成了星号

        auto check = [&](int m) -> bool {
            m++;
            for (int j = 0; j < m; j++) {
                star[order[j]] = m;
            }
            int cnt = 0;
            int last = -1;   // 记录最后一个星号的位置，初始化为-1（表示尚未遇到星号）
            for (int i = 0; i < n; i++) {
                if (star[i] == m) { // i位置是*
                    last = i;
                }
                cnt += last + 1; // 累加计数：last+1表示当前位置i之前（含i）可贡献的数量
                if (cnt >= k) {
                    return true;
                }
            }
            return false;
        };


        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abc"\n[1,0,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// "cat"\n[0,2,1]\n6\n
// @lcpr case=end

// @lcpr case=start
// "xy"\n[0,1]\n4\n
// @lcpr case=end

 */

