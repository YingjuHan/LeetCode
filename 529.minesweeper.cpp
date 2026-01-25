/*
 * @lc app=leetcode.cn id=529 lang=cpp
 * @lcpr version=30204
 *
 * [529] 扫雷游戏
 *
 * https://leetcode.cn/problems/minesweeper/description/
 *
 * algorithms
 * Medium (64.52%)
 * Likes:    423
 * Dislikes: 0
 * Total Accepted:    64.8K
 * Total Submissions: 100.4K
 * Testcase Example:  '[["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]]\n' +
  '[3,0]'
 *
 * 让我们一起来玩扫雷游戏！
 * 
 * 给你一个大小为 m x n 二维字符矩阵 board ，表示扫雷游戏的盘面，其中：
 * 
 * 
 * 'M' 代表一个 未挖出的 地雷，
 * 'E' 代表一个 未挖出的 空方块，
 * 'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的 已挖出的 空白方块，
 * 数字（'1' 到 '8'）表示有多少地雷与这块 已挖出的 方块相邻，
 * 'X' 则表示一个 已挖出的 地雷。
 * 
 * 
 * 给你一个整数数组 click ，其中 click = [clickr, clickc] 表示在所有 未挖出的 方块（'M' 或者
 * 'E'）中的下一个点击位置（clickr 是行下标，clickc 是列下标）。
 * 
 * 根据以下规则，返回相应位置被点击后对应的盘面：
 * 
 * 
 * 如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X' 。
 * 如果一个 没有相邻地雷 的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的 未挖出 方块都应该被递归地揭露。
 * 如果一个 至少与一个地雷相邻 的空方块（'E'）被挖出，修改它为数字（'1' 到 '8' ），表示相邻地雷的数量。
 * 如果在此次点击中，若无更多方块可被揭露，则返回盘面。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：board =
 * [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]],
 * click = [3,0]
 * 
 * 输出：[["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
 * 
 * 
 * 示例 2：
 * 
 * 输入：board =
 * [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]],
 * click = [1,2]
 * 
 * 输出：[["B","1","E","1","B"],["B","1","X","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 50
 * board[i][j] 为 'M'、'E'、'B' 或数字 '1' 到 '8' 中的一个
 * click.length == 2
 * 0 <= clickr < m
 * 0 <= clickc < n
 * board[clickr][clickc] 为 'M' 或 'E'
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
// 在递归开始时定义一个num_of_bomb来计算当前这个格子周围有多少雷，
// 如果周围有雷，那我们直接将这个格子设置为当前的周围的雷的数量，
// 由于题设表示要周围没雷的时候才能网周围递归，所以此时我们不用继续递归这届return

// 然后就是另一种情况，如果没有雷的话，我们只需要和模板一样在周围继续递归寻找，
// 直到有标数字或者到边界的时候return。

    const int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    const int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int i = click[0], j = click[1];
        if (board[i][j] == 'M') board[i][j] = 'X';
        else dfs(board, i, j);
        return board;
    }

    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'E') {
            return;
        }
        int nb_bomb = 0;
        for (int k = 0; k < 8; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
                continue;
            }
            if (board[x][y] == 'M') {
                nb_bomb++;
            }
        }
        if (nb_bomb > 0) {
            board[i][j] = '0' + nb_bomb;
            return;
        }
        board[i][j] = 'B';
        for (int k = 0; k < 8; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())continue;
            dfs(board, x, y);
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]]\n[3,0]\n
// @lcpr case=end

// @lcpr case=start
// [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]\n[1,2]\n
// @lcpr case=end

 */

