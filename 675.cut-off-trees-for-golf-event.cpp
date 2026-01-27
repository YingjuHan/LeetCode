/*
 * @lc app=leetcode.cn id=675 lang=cpp
 * @lcpr version=
 *
 * [675] 为高尔夫比赛砍树
 *
 * https://leetcode.cn/problems/cut-off-trees-for-golf-event/description/
 *
 * algorithms
 * Hard (50.80%)
 * Likes:    250
 * Dislikes: 0
 * Total Accepted:    26.9K
 * Total Submissions: 53K
 * Testcase Example:  '[[1,2,3],[0,0,4],[7,6,5]]'
 *
 * 你被请来给一个要举办高尔夫比赛的树林砍树。树林由一个 m x n 的矩阵表示， 在这个矩阵中：
 * 
 * 
 * 0 表示障碍，无法触碰
 * 1 表示地面，可以行走
 * 比 1 大的数 表示有树的单元格，可以行走，数值表示树的高度
 * 
 * 
 * 每一步，你都可以向上、下、左、右四个方向之一移动一个单位，如果你站的地方有一棵树，那么你可以决定是否要砍倒它。
 * 
 * 你需要按照树的高度从低向高砍掉所有的树，每砍过一颗树，该单元格的值变为 1（即变为地面）。
 * 
 * 你将从 (0, 0) 点开始工作，返回你砍完所有树需要走的最小步数。 如果你无法砍完所有的树，返回 -1 。
 * 
 * 可以保证的是，没有两棵树的高度是相同的，并且你至少需要砍倒一棵树。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：forest = [[1,2,3],[0,0,4],[7,6,5]]
 * 输出：6
 * 解释：沿着上面的路径，你可以用 6 步，按从最矮到最高的顺序砍掉这些树。
 * 
 * 示例 2：
 * 
 * 输入：forest = [[1,2,3],[0,0,0],[7,6,5]]
 * 输出：-1
 * 解释：由于中间一行被障碍阻塞，无法访问最下面一行中的树。
 * 
 * 
 * 示例 3：
 * 
 * 输入：forest = [[2,3,4],[0,0,5],[8,7,6]]
 * 输出：6
 * 解释：可以按与示例 1 相同的路径来砍掉所有的树。
 * (0,0) 位置的树，可以直接砍去，不用算步数。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == forest.length
 * n == forest[i].length
 * 1 <= m, n <= 50
 * 0 <= forest[i][j] <= 10^9
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
    static constexpr int DIRS[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};

    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();
        vector<pair<int,int>> trees;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) {
                    trees.push_back({i, j});
                }
            }
        }

        sort(trees.begin(), trees.end(),
             [&](const pair<int,int>& a, const pair<int,int>& b) {
                 return forest[a.first][a.second] <
                        forest[b.first][b.second];
             });

        int cx = 0, cy = 0;
        int ans = 0;

        for (auto& [tx, ty] : trees) {
            int steps = bfs(forest, cx, cy, tx, ty);
            if (steps == -1) return -1;
            ans += steps;
            cx = tx;
            cy = ty;
        }
        return ans;
    }

    int bfs(vector<vector<int>>& forest, int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty) return 0;

        int m = forest.size(), n = forest[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        q.push({sx, sy});
        vis[sx][sy] = 1;
        int step = 0;

        while (!q.empty()) {
            int sz = q.size();
            step++;
            for (int i = 0; i < sz; i++) {
                auto [cx, cy] = q.front();
                q.pop();
                for (auto& d : DIRS) {
                    int nx = cx + d[0], ny = cy + d[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                        !vis[nx][ny] && forest[nx][ny] != 0) {

                        if (nx == tx && ny == ty) return step;

                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};

// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[0,0,4],[7,6,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[0,0,0],[7,6,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,3,4],[0,0,5],[8,7,6]]\n
// @lcpr case=end

 */

