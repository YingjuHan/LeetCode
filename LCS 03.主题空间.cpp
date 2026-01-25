/*
 * @lc app=leetcode.cn id=LCS 03 lang=cpp
 * @lcpr version=30204
 *
 * [LCS 03] 主题空间
 *
 * https://leetcode.cn/problems/YesdPw/description/
 *
 * algorithms
 * Medium (45.44%)
 * Likes:    35
 * Dislikes: 0
 * Total Accepted:    10.2K
 * Total Submissions: 22.4K
 * Testcase Example:  '["110","231","221"]'
 *
 * 「以扣会友」线下活动所在场地由若干主题空间与走廊组成，场地的地图记作由一维字符串型数组 `grid`，字符串中仅包含 `"0"～"5"` 这 6
 * 个字符。地图上每一个字符代表面积为 1 的区域，其中 `"0"`
 * 表示走廊，其他字符表示主题空间。相同且连续（连续指上、下、左、右四个方向连接）的字符组成同一个主题空间。
 * 
 * 假如整个 `grid` 区域的外侧均为走廊。请问，不与走廊直接相邻的主题空间的最大面积是多少？如果不存在这样的空间请返回 `0`。
 * 
 * **示例 1：**
 * >输入：`grid = ["110","231","221"]`
 * >
 * >输出：`1`
 * >
 * >解释：4 个主题空间中，只有 1 个不与走廊相邻，面积为 1。
 * >![image.png](https://pic.leetcode.cn/1613708145-rscctN-image.png)
 * 
 * 
 * **示例 2：**
 * >输入：`grid = ["11111100000","21243101111","21224101221","11111101111"]`
 * >
 * >输出：`3`
 * >
 * >解释：8 个主题空间中，有 5 个不与走廊相邻，面积分别为 3、1、1、1、2，最大面积为 3。
 * >![image.png](https://pic.leetcode.cn/1613707985-KJyiXJ-image.png)
 * 
 * 
 * **提示：**
 * - `1 <= grid.length <= 500`
 * - `1 <= grid[i].length <= 500`
 * - `grid[i][j]` 仅可能为 `"0"～"5"`
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
    int largestArea(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        // lambda 递归 DFS
        auto dfs = [&](auto&& self, int i, int j, char c, int& flag, int& count) -> void {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
                flag = 0;
                return;
            }
            if (grid[i][j] != c) return;

            ++count;
            grid[i][j] = '6';  // 标记访问

            self(self, i + 1, j, c, flag, count);
            self(self, i - 1, j, c, flag, count);
            self(self, i, j + 1, c, flag, count);
            self(self, i, j - 1, c, flag, count);
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0' || grid[i][j] == '6') continue;

                int flag = 1, count = 0;
                dfs(dfs, i, j, grid[i][j], flag, count);

                if (flag) ans = max(ans, count);
            }
        }
        return ans;
    }
};


// @lc code=end



/*
// @lcpr case=start
// ["110","231","221"]`>\n
// @lcpr case=end

// @lcpr case=start
// ["11111100000","21243101111","21224101221","11111101111"]`>\n
// @lcpr case=end

 */

