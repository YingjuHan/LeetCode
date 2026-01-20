/*
 * @lc app=leetcode.cn id=2850 lang=cpp
 * @lcpr version=30204
 *
 * [2850] 将石头分散到网格图的最少移动次数
 *
 * https://leetcode.cn/problems/minimum-moves-to-spread-stones-over-grid/description/
 *
 * algorithms
 * Medium (59.41%)
 * Likes:    81
 * Dislikes: 0
 * Total Accepted:    19K
 * Total Submissions: 31.9K
 * Testcase Example:  '[[1,1,0],[1,1,1],[1,2,1]]'
 *
 * 给你一个大小为 3 * 3 ，下标从 0 开始的二维整数矩阵 grid ，分别表示每一个格子里石头的数目。网格图中总共恰好有 9
 * 个石头，一个格子里可能会有 多个 石头。
 * 
 * 每一次操作中，你可以将一个石头从它当前所在格子移动到一个至少有一条公共边的相邻格子。
 * 
 * 请你返回每个格子恰好有一个石头的 最少移动次数 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：grid = [[1,1,0],[1,1,1],[1,2,1]]
 * 输出：3
 * 解释：让每个格子都有一个石头的一个操作序列为：
 * 1 - 将一个石头从格子 (2,1) 移动到 (2,2) 。
 * 2 - 将一个石头从格子 (2,2) 移动到 (1,2) 。
 * 3 - 将一个石头从格子 (1,2) 移动到 (0,2) 。
 * 总共需要 3 次操作让每个格子都有一个石头。
 * 让每个格子都有一个石头的最少操作次数为 3 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：grid = [[1,3,0],[1,0,0],[1,0,3]]
 * 输出：4
 * 解释：让每个格子都有一个石头的一个操作序列为：
 * 1 - 将一个石头从格子 (0,1) 移动到 (0,2) 。
 * 2 - 将一个石头从格子 (0,1) 移动到 (1,1) 。
 * 3 - 将一个石头从格子 (2,2) 移动到 (1,2) 。
 * 4 - 将一个石头从格子 (2,2) 移动到 (2,1) 。
 * 总共需要 4 次操作让每个格子都有一个石头。
 * 让每个格子都有一个石头的最少操作次数为 4 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * grid.length == grid[i].length == 3
 * 0 <= grid[i][j] <= 9
 * grid 中元素之和为 9 。
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
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> from, to;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    for (int k = 1; k < grid[i][j]; k++) {
                        from.emplace_back(i, j);
                    }
                } else {
                    to.emplace_back(i, j);
                }
            }
        }
        int res = INT_MAX;

        do {
            int total = 0;
            for (int i = 0; i < from.size(); i++) {
                total += abs(from[i].first - to[i].first) + abs(from[i].second - to[i].second);
            }
            res = min(res, total);
        } while (next_permutation(from.begin(), from.end()));

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,0],[1,1,1],[1,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,0],[1,0,0],[1,0,3]]\n
// @lcpr case=end

 */

