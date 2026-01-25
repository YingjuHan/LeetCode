/*
 * @lc app=leetcode.cn id=130 lang=cpp
 * @lcpr version=30204
 *
 * [130] 被围绕的区域
 *
 * https://leetcode.cn/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (47.47%)
 * Likes:    1261
 * Dislikes: 0
 * Total Accepted:    356.6K
 * Total Submissions: 750.8K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' 组成，捕获 所有 被围绕的区域：
 * 
 * 
 * 连接：一个单元格与水平或垂直方向上相邻的单元格连接。
 * 区域：连接所有 'O' 的单元格来形成一个区域。
 * 围绕：如果您可以用 'X' 单元格 连接这个区域，并且区域中没有任何单元格位于 board 边缘，则该区域被 'X' 单元格围绕。
 * 
 * 
 * 通过 原地 将输入矩阵中的所有 'O' 替换为 'X' 来 捕获被围绕的区域。你不需要返回任何值。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board =
 * [['X','X','X','X'],['X','O','O','X'],['X','X','O','X'],['X','O','X','X']]
 * 
 * 
 * 输出：[['X','X','X','X'],['X','X','X','X'],['X','X','X','X'],['X','O','X','X']]
 * 
 * 解释：
 * 
 * 在上图中，底部的区域没有被捕获，因为它在 board 的边缘并且不能被围绕。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = [['X']]
 * 
 * 输出：[['X']]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 200
 * board[i][j] 为 'X' 或 'O'
 * 
 * 
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
    int m, n;
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if (m == 0) {
            return;
        }
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }

        for (int j = 1; j <= n - 2; j++) {
            dfs(board, 0, j);
            dfs(board, m - 1, j);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'A';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [['X','X','X','X'],['X','O','O','X'],['X','X','O','X'],['X','O','X','X']]\n
// @lcpr case=end

// @lcpr case=start
// [['X']]\n
// @lcpr case=end

 */

