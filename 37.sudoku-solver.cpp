/*
 * @lc app=leetcode.cn id=37 lang=cpp
 * @lcpr version=
 *
 * [37] 解数独
 *
 * https://leetcode.cn/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (67.53%)
 * Likes:    2002
 * Dislikes: 0
 * Total Accepted:    319.7K
 * Total Submissions: 474K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * 编写一个程序，通过填充空格来解决数独问题。
 * 
 * 数独的解法需 遵循如下规则：
 * 
 * 
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
 * 
 * 
 * 数独部分空格内已填入了数字，空白格用 '.' 表示。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：board =
 * [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * 
 * 输出：[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * 解释：输入的数独如上图所示，唯一有效的解决方案如下所示：
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board.length == 9
 * board[i].length == 9
 * board[i][j] 是一位数字或者 '.'
 * 题目数据 保证 输入数独仅有一个解
 * 
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
    void solveSudoku(vector<vector<char>>& board) {
        bool row_has[9][9]{};
        bool col_has[9][9]{};
        bool sub_box_has[3][3][9]{};
        vector<pair<int, int>> empty_pos;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char b = board[i][j];
                if (b == '.') {
                    empty_pos.emplace_back(i, j);
                } else {
                    int x = b - '1';
                    row_has[i][x] = col_has[j][x] = sub_box_has[i / 3][j / 3][x] = true;
                }
            }
        }

        auto get_candidates = [&](int i, int j) -> int {
            int candidates = 9;
            for (int x = 0; x < 9; x++) {
                if (row_has[i][x] || col_has[j][x] || sub_box_has[i][j][x]) {
                    candidates--;
                }
            }
            return candidates;
        };

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> empty_pos_pq; // {candidates, i, j}
        for (auto& [i, j] : empty_pos) {
            empty_pos_pq.emplace(get_candidates(i, j), i, j);
        }

        // 每次递归，选一个空格子，枚举填入的数字
        auto dfs = [&](this auto&& dfs) -> bool {
            if (empty_pos_pq.empty()) {
                return true;
            }

            auto [_, i, j] = empty_pos_pq.top();
            empty_pos_pq.pop();

            int candidates = 0;
            for (int x = 0; x < 9; x++) {
                if (row_has[i][x] || col_has[j][x] || sub_box_has[i / 3][j / 3][x]) {
                    continue;
                }

                board[i][j] = '1' + x;
                row_has[i][x] = col_has[j][x] = sub_box_has[i / 3][j / 3][x] = true;

                if (dfs()) {
                    return true;
                }

                row_has[i][x] = col_has[j][x] = sub_box_has[i / 3][j / 3][x] = false;
                board[i][j] = '.'; // 可以恢复也可以不恢复，因为下一次会被覆盖

                candidates++; // 统计待选数字个数
            }
            empty_pos_pq.emplace(candidates, i, j);
            
            return false;
        };
        dfs();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

 */

