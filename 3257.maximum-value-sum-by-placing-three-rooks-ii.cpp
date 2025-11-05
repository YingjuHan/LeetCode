/*
 * @lc app=leetcode.cn id=3257 lang=cpp
 * @lcpr version=30204
 *
 * [3257] 放三个车的价值之和最大 II
 *
 * https://leetcode.cn/problems/maximum-value-sum-by-placing-three-rooks-ii/description/
 *
 * algorithms
 * Hard (33.88%)
 * Likes:    16
 * Dislikes: 0
 * Total Accepted:    2.4K
 * Total Submissions: 7.1K
 * Testcase Example:  '[[-3,1,1,1],[-3,1,-3,1],[-3,2,1,1]]'
 *
 * 给你一个 m x n 的二维整数数组 board ，它表示一个国际象棋棋盘，其中 board[i][j] 表示格子 (i, j) 的 价值 。
 * 
 * 处于 同一行 或者 同一列 车会互相 攻击 。你需要在棋盘上放三个车，确保它们两两之间都 无法互相攻击 。
 * 
 * 请你返回满足上述条件下，三个车所在格子 值 之和 最大 为多少。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board = [[-3,1,1,1],[-3,1,-3,1],[-3,2,1,1]]
 * 
 * 输出：4
 * 
 * 解释：
 * 
 * 
 * 
 * 我们可以将车分别放在格子 (0, 2) ，(1, 3) 和 (2, 1) 处，价值之和为 1 + 1 + 2 = 4 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = [[1,2,3],[4,5,6],[7,8,9]]
 * 
 * 输出：15
 * 
 * 解释：
 * 
 * 我们可以将车分别放在格子 (0, 0) ，(1, 1) 和 (2, 2) 处，价值之和为 1 + 5 + 9 = 15 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：board = [[1,1,1],[1,1,1],[1,1,1]]
 * 
 * 输出：3
 * 
 * 解释：
 * 
 * 我们可以将车分别放在格子 (0, 2) ，(1, 1) 和 (2, 0) 处，价值之和为 1 + 1 + 1 = 3 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= m == board.length <= 500
 * 3 <= n == board[i].length <= 500
 * -10^9 <= board[i][j] <= 10^9
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
    /**
     * 枚举中间的车在第i派，需要直到0~i-1和i+1~m-1排的车放在哪里
     * 枚举第二个车，就自动保证了第一个车和第三个车不会同行，我们只需关注三车不能同列。
     * 
     * 在满足 “三辆车不同列” 的约束下，最优解一定是从三行中分别选前 3 大的数组合，
     * 再多统计更小数毫无意义，反而会增加计算量
     * 
     * 第 0 到 i−1 排的车，放在三个不同的列上的最大、次大、第三大的格子值分别是多少，以及具体放在哪列。记作 pre[i−1]。
     * 第 i+1 到 m−1 排的车，放在三个不同的列上的最大、次大、第三大的格子值分别是多少，以及具体放在哪列。记作 suf[i+1]。
     * 
     * 枚举中间的车在第 i 排第 j 列，暴力枚举 pre[i−1] 和 suf[i+1] 的最大、次大、第三大的组合，
     * 只要三个车在不同的列上，就用格子值之和更新答案的最大值。
     * 
     * 代码实现时，可以只预处理 suf，对于 pre，可以在枚举中间的车的同时计算。
     */
    long long maximumValueSum(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        array<pair<int, int>, 3> p; // 单行的 “Top3 候选者”
        ranges::fill(p, pair(INT_MIN, -1));
        vector<array<pair<int, int>, 3>> suf(m); // 后缀行的 Top3 缓存

        auto update = [&](vector<int>& row) -> void {
            for (int j = 0; j < row.size(); j++) {
                int x = row[j];
                if (x > p[0].first) {
                    if (j != p[0].second) {
                        if (j != p[1].second) {
                            p[2] = p[1];
                        }
                        p[1] = p[0];
                    }
                    p[0] = {x, j};
                } else if (x > p[1].first && j != p[0].second) {
                    if (j != p[1].second) {
                        p[2] = p[1];
                    }
                    p[1] = {x, j};
                } else if (x > p[2].first && j != p[0].second && j != p[1].second) {
                    p[2] = {x, j};
                }
            }
        };

        for (int i = m - 1; i > 1; i--) { // i: 2 ~ m-1, 0 1是给前缀、当前枚举的行使用的
            update(board[i]);
            suf[i] = p;
        }

        long long ans = LLONG_MIN;
        ranges::fill(p, pair(INT_MIN, -1)); // 重置，计算 pre
        for (int i = 1; i < m - 1; i++) {
            update(board[i - 1]);
            for (int j2 = 0; j2 < n; j2++) { // 第2个车
                for (auto& [x, j1] : p) { // 第1个车
                    for (auto& [z, j3] : suf[i + 1]) { // 第3个车
                        if (j1 != j2 && j1 != j3 && j2 != j3) {
                            ans = max(ans, (long long) x + board[i][j2] + z);
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[-3,1,1,1],[-3,1,-3,1],[-3,2,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1],[1,1,1],[1,1,1]]\n
// @lcpr case=end

 */

