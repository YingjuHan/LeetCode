/*
 * @lc app=leetcode.cn id=1301 lang=cpp
 * @lcpr version=30204
 *
 * [1301] 最大得分的路径数目
 *
 * https://leetcode.cn/problems/number-of-paths-with-max-score/description/
 *
 * algorithms
 * Hard (41.33%)
 * Likes:    103
 * Dislikes: 0
 * Total Accepted:    14.4K
 * Total Submissions: 34.8K
 * Testcase Example:  '["E23","2X2","12S"]\r'
 *
 * 给你一个正方形字符数组 board ，你从数组最右下方的字符 'S' 出发。
 * 
 * 你的目标是到达数组最左上角的字符 'E' ，数组剩余的部分为数字字符 1, 2, ..., 9 或者障碍
 * 'X'。在每一步移动中，你可以向上、向左或者左上方移动，可以移动的前提是到达的格子没有障碍。
 * 
 * 一条路径的 「得分」 定义为：路径上所有数字的和。
 * 
 * 请你返回一个列表，包含两个整数：第一个整数是 「得分」 的最大值，第二个整数是得到最大得分的方案数，请把结果对 10^9 + 7 取余。
 * 
 * 如果没有任何路径可以到达终点，请返回 [0, 0] 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：board = ["E23","2X2","12S"]
 * 输出：[7,1]
 * 
 * 
 * 示例 2：
 * 
 * 输入：board = ["E12","1X1","21S"]
 * 输出：[4,2]
 * 
 * 
 * 示例 3：
 * 
 * 输入：board = ["E11","XXX","11S"]
 * 输出：[0,0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= board.length == board[i].length <= 100
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
using PII = pair<int,int>;

class Solution {
public:
    static constexpr int mod = 1e9 + 7;

    // 用 (u,v) 作为来源，尝试更新 (x,y)（当前格）
    void update(vector<vector<PII>>& dp, int n, int x, int y, int u, int v) {
        if (u >= n || v >= n) return;
        if (dp[u][v].first == -1) return; // 来源不可达

        if (dp[x][y].first < dp[u][v].first) {
            dp[x][y] = dp[u][v];          // 更大分数：直接覆盖(分数+路径数)
        } else if (dp[x][y].first == dp[u][v].first) {
            dp[x][y].second += dp[u][v].second;   // 相等：累加路径数
            if (dp[x][y].second >= mod) dp[x][y].second -= mod;
        }
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<PII>> dp(n, vector<PII>(n, {-1, 0}));

        dp[n-1][n-1] = {0, 1}; // S 点

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == n - 1 && j == n - 1) continue;
                if (board[i][j] == 'X') continue;

                // 当前格从三个后继格转移（注意方向）
                update(dp, n, i, j, i + 1, j);
                update(dp, n, i, j, i, j + 1);
                update(dp, n, i, j, i + 1, j + 1);

                if (dp[i][j].first == -1) continue;

                // 加上当前格分数：只有数字才加，E/S 不加
                char c = board[i][j];
                if (c >= '0' && c <= '9') dp[i][j].first += (c - '0');
            }
        }

        if (dp[0][0].first == -1) return {0, 0};
        return {dp[0][0].first, dp[0][0].second};
    }
};

// @lc code=end



/*
// @lcpr case=start
// ["E23","2X2","12S"]\n
// @lcpr case=end

// @lcpr case=start
// ["E12","1X1","21S"]\n
// @lcpr case=end

// @lcpr case=start
// ["E11","XXX","11S"]\n
// @lcpr case=end

 */

