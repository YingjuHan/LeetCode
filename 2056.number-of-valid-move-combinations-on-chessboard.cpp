/*
 * @lc app=leetcode.cn id=2056 lang=cpp
 * @lcpr version=30204
 *
 * [2056] 棋盘上有效移动组合的数目
 *
 * https://leetcode.cn/problems/number-of-valid-move-combinations-on-chessboard/description/
 *
 * algorithms
 * Hard (69.02%)
 * Likes:    41
 * Dislikes: 0
 * Total Accepted:    8.8K
 * Total Submissions: 12.7K
 * Testcase Example:  '["rook"]\n[[1,1]]'
 *
 * 有一个 8 x 8 的棋盘，它包含 n 个棋子（棋子包括车，后和象三种）。给你一个长度为 n 的字符串数组 pieces ，其中 pieces[i]
 * 表示第 i 个棋子的类型（车，后或象）。除此以外，还给你一个长度为 n 的二维整数数组 positions ，其中 positions[i] =
 * [ri, ci] 表示第 i 个棋子现在在棋盘上的位置为 (ri, ci) ，棋盘下标从 1 开始。
 * 
 * 每个棋子的移动中，首先选择移动的 方向 ，然后选择 移动的步数 ，同时你要确保移动过程中棋子不能移到棋盘以外的地方。棋子需按照以下规则移动：
 * 
 * 
 * 车可以 水平或者竖直 从 (r, c) 沿着方向 (r+1, c)，(r-1, c)，(r, c+1) 或者 (r, c-1) 移动。
 * 后可以 水平竖直或者斜对角 从 (r, c) 沿着方向 (r+1, c)，(r-1, c)，(r, c+1)，(r, c-1)，(r+1,
 * c+1)，(r+1, c-1)，(r-1, c+1)，(r-1, c-1) 移动。
 * 象可以 斜对角 从 (r, c) 沿着方向 (r+1, c+1)，(r+1, c-1)，(r-1, c+1)，(r-1, c-1) 移动。
 * 
 * 
 * 你必须同时 移动 棋盘上的每一个棋子。移动组合 包含所有棋子的 移动 。每一秒，每个棋子都沿着它们选择的方向往前移动 一步
 * ，直到它们到达目标位置。所有棋子从时刻 0 开始移动。如果在某个时刻，两个或者更多棋子占据了同一个格子，那么这个移动组合 不有效 。
 * 
 * 请你返回 有效 移动组合的数目。
 * 
 * 注意：
 * 
 * 
 * 初始时，不会有两个棋子 在 同一个位置 。
 * 有可能在一个移动组合中，有棋子不移动。
 * 如果两个棋子 直接相邻 且两个棋子下一秒要互相占据对方的位置，可以将它们在同一秒内 交换位置 。
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 输入：pieces = ["rook"], positions = [[1,1]]
 * 输出：15
 * 解释：上图展示了棋子所有可能的移动。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：pieces = ["queen"], positions = [[1,1]]
 * 输出：22
 * 解释：上图展示了棋子所有可能的移动。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 
 * 输入：pieces = ["bishop"], positions = [[4,3]]
 * 输出：12
 * 解释：上图展示了棋子所有可能的移动。
 * 
 * 
 * 示例 4:
 * 
 * 
 * 
 * 输入：pieces = ["rook","rook"], positions = [[1,1],[8,8]]
 * 输出：223
 * 解释：每个车有 15 种移动，所以总共有 15 * 15 = 225 种移动组合。
 * 但是，有两个是不有效的移动组合：
 * - 将两个车都移动到 (8, 1) ，会导致它们在同一个格子相遇。
 * - 将两个车都移动到 (1, 8) ，会导致它们在同一个格子相遇。
 * 所以，总共有 225 - 2 = 223 种有效移动组合。
 * 注意，有两种有效的移动组合，分别是一个车在 (1, 8) ，另一个车在 (8, 1) 。
 * 即使棋盘状态是相同的，这两个移动组合被视为不同的，因为每个棋子移动操作是不相同的。
 * 
 * 
 * 示例 5：
 * 
 * 
 * 
 * 输入：pieces = ["queen","bishop"], positions = [[5,7],[3,4]]
 * 输出：281
 * 解释：总共有 12 * 24 = 288 种移动组合。
 * 但是，有一些不有效的移动组合：
 * - 如果后停在 (6, 7) ，它会阻挡象到达 (6, 7) 或者 (7, 8) 。
 * - 如果后停在 (5, 6) ，它会阻挡象到达 (5, 6) ，(6, 7) 或者 (7, 8) 。
 * - 如果象停在 (5, 2) ，它会阻挡后到达 (5, 2) 或者 (5, 1) 。
 * 在 288 个移动组合当中，281 个是有效的。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == pieces.length 
 * n == positions.length
 * 1 <= n <= 4
 * pieces 只包含字符串 "rook" ，"queen" 和 "bishop" 。
 * 棋盘上最多只有一个后。
 * 1 <= ri, ci <= 8
 * 每一个 positions[i] 互不相同。
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
struct Move {
    int x0, y0;
    int dx, dy;
    int step;
};
class Solution {
    vector<pair<int, int>> DIRS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}}; // 上下左右 + 斜向
    unordered_map<char, vector<pair<int, int>>> PIECE_DIRS = {
        {'r', {DIRS.begin(), DIRS.begin() + 4}},
        {'b', {DIRS.begin() + 4, DIRS.end()}},
        {'q', DIRS}
    };

    vector<Move> generate_moves(int x0, int y0, vector<pair<int, int>>& dirs) {
        const int SIZE = 8;
        vector<Move> moves = {{x0, y0, 0, 0, 0}};
        for (auto [dx, dy] : dirs) {
            int x = x0 + dx, y = y0 + dy;
            for (int step = 1; 0 < x && x <= SIZE && 0 < y && y <= SIZE; step++) {
                moves.emplace_back(x0, y0, dx, dy, step);
                x += dx;
                y += dy;
            }
        }
        return moves;
    }

    bool is_valid(Move& m1, Move& m2) {
        int x1 = m1.x0, y1 = m1.y0;
        int x2 = m2.x0, y2 = m2.y0;
        for (int i = 0; i < max(m1.step, m2.step); i++) {
            if (i < m1.step) {
                x1 += m1.dx;
                y1 += m1.dy;
            }
            if (i < m2.step) {
                x2 += m2.dx;
                y2 += m2.dy;
            }
            if (x1 == x2 && y1 == y2) {
                return false;
            }
        }
        return true;
    }
public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        int n = pieces.size();
        vector<vector<Move>> all_moves(n);
        for (int i = 0; i < n; i++) {
            all_moves[i] = generate_moves(positions[i][0], positions[i][1], PIECE_DIRS[pieces[i][0]]);
        }

        vector<Move> path(n);
        int res = 0;

        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (i == n) {
                res++;
                return;
            }

            for (Move& move1 : all_moves[i]) {
                bool ok = true;
                for (int j = 0; j < i; j++) {
                    if (!is_valid(move1, path[j])) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    path[i] = move1;
                    dfs(i + 1);
                }
            }
        };
        dfs(0);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["rook"]\n[[1,1]]\n
// @lcpr case=end

// @lcpr case=start
// ["queen"]\n[[1,1]]\n
// @lcpr case=end

// @lcpr case=start
// ["bishop"]\n[[4,3]]\n
// @lcpr case=end

// @lcpr case=start
// ["rook","rook"]\n[[1,1],[8,8]]\n
// @lcpr case=end

// @lcpr case=start
// ["queen","bishop"]\n[[5,7],[3,4]]\n
// @lcpr case=end

 */

