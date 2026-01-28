/*
 * @lc app=leetcode.cn id=864 lang=cpp
 * @lcpr version=30204
 *
 * [864] 获取所有钥匙的最短路径
 *
 * https://leetcode.cn/problems/shortest-path-to-get-all-keys/description/
 *
 * algorithms
 * Hard (58.80%)
 * Likes:    326
 * Dislikes: 0
 * Total Accepted:    26.1K
 * Total Submissions: 44.4K
 * Testcase Example:  '["@.a..","###.#","b.A.B"]'
 *
 * 给定一个二维网格 grid ，其中：
 * 
 * 
 * '.' 代表一个空房间
 * '#' 代表一堵墙
 * '@' 是起点
 * 小写字母代表钥匙
 * 大写字母代表锁
 * 
 * 
 * 
 * 我们从起点开始出发，一次移动是指向四个基本方向之一行走一个单位空间。我们不能在网格外面行走，也无法穿过一堵墙。如果途经一个钥匙，我们就把它捡起来。除非我们手里有对应的钥匙，否则无法通过锁。
 * 
 * 假设 k 为 钥匙/锁 的个数，且满足 1 <= k <= 6，字母表中的前 k
 * 个字母在网格中都有自己对应的一个小写和一个大写字母。换言之，每个锁有唯一对应的钥匙，每个钥匙也有唯一对应的锁。另外，代表钥匙和锁的字母互为大小写并按字母顺序排列。
 * 
 * 返回获取所有钥匙所需要的移动的最少次数。如果无法获取所有钥匙，返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：grid = ["@.a..","###.#","b.A.B"]
 * 输出：8
 * 解释：目标是获得所有钥匙，而不是打开所有锁。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：grid = ["@..aA","..B#.","....b"]
 * 输出：6
 * 
 * 
 * 示例 3:
 * 
 * 输入: grid = ["@Aa"]
 * 输出: -1
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 30
 * grid[i][j] 只含有 '.', '#', '@', 'a'-'f' 以及 'A'-'F'
 * 钥匙的数目范围是 [1, 6] 
 * 每个钥匙都对应一个 不同 的字母
 * 每个钥匙正好打开一个对应的锁
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
    static constexpr int DIRS[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int sx = 0, sy = 0;
        unordered_map<char, int> key_to_idx;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = grid[i][j];
                if (c == '@') {
                    sx = i; sy = j;
                } else if (islower((unsigned char)c)) {
                    if (!key_to_idx.count(c)) {
                        key_to_idx[c] = (int)key_to_idx.size();
                    }
                }
            }
        }
        int K = (int)key_to_idx.size();
        int FULL = (1 << K) - 1;
        queue<tuple<int, int, int>> q;
        vector<vector<vector<int>>> dist(
            m, vector<vector<int>>(n, vector<int>(1 << K, -1))
        );
        q.emplace(sx, sy, 0);
        dist[sx][sy][0] = 0;
        while (!q.empty()) {
            auto [x, y, mask] = q.front();
            q.pop();
            
            for (auto& [dx, dy] : DIRS) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != '#') {
                    char c = grid[nx][ny];
                    if (c == '.' || c == '@') {
                        if (dist[nx][ny][mask] == -1) {
                            dist[nx][ny][mask] = dist[x][y][mask] + 1;
                            q.emplace(nx, ny, mask);
                        }
                    } else if (islower(c)) {
                        auto it = key_to_idx.find(c);
                        if (it == key_to_idx.end()) continue;
                        int idx = it->second;

                        int nmask = mask | (1 << idx);
                        if (dist[nx][ny][nmask] == -1) {
                            dist[nx][ny][nmask] = dist[x][y][mask] + 1;
                            if (nmask == FULL) {
                                return dist[nx][ny][nmask];
                            }
                            q.emplace(nx, ny, nmask);
                        }
                    } else if (isupper(c)) {
                        char k = tolower((unsigned char)c);
                        auto it = key_to_idx.find(k);
                        if (it == key_to_idx.end()) continue; // 没对应钥匙
                        int idx = it->second;
                        if ((mask & (1 << idx)) && dist[nx][ny][mask] == -1) {
                            dist[nx][ny][mask] = dist[x][y][mask] + 1;
                            q.emplace(nx, ny, mask);
                        }
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
// ["@.a..","###.#","b.A.B"]\n
// @lcpr case=end

// @lcpr case=start
// ["@..aA","..B#.","....b"]\n
// @lcpr case=end

// @lcpr case=start
// ["@Aa"]\n
// @lcpr case=end

 */

