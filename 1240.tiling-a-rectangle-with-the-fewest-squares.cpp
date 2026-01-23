/*
 * @lc app=leetcode.cn id=1240 lang=cpp
 * @lcpr version=30204
 *
 * [1240] 铺瓷砖
 *
 * https://leetcode.cn/problems/tiling-a-rectangle-with-the-fewest-squares/description/
 *
 * algorithms
 * Hard (63.33%)
 * Likes:    232
 * Dislikes: 0
 * Total Accepted:    16.2K
 * Total Submissions: 25.6K
 * Testcase Example:  '2\n3'
 *
 * 给定一个大小为 n x m 的长方形，返回贴满矩形所需的整数边正方形的最小数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：n = 2, m = 3
 * 输出：3
 * 解释：需要 3 个正方形来覆盖长方形。
 * ⁠    2 个 1x1 的正方形
 * ⁠    1 个 2x2 的正方形
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：n = 5, m = 8
 * 输出：5
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：n = 11, m = 13
 * 输出：6
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n, m <= 13
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
    int ans;
    int tilingRectangle(int n, int m) {
        ans = max(n, m);
        vector<vector<bool>> rect(n, vector<bool>(m, false));
        dfs(0, 0, rect, 0);
        return ans;
    }

    void dfs(int x, int y, vector<vector<bool>>& rect, int cnt) {
        int n = rect.size(), m = rect[0].size();
        if (cnt >= ans) {
            return;
        }

        if (x >= n) {
            ans = cnt;
            return;
        }

        if (y >= m) {
            dfs(x + 1, 0, rect, cnt);
            return;
        }

        if (rect[x][y]) {
            dfs(x, y + 1, rect, cnt);
            return;
        }

        int len = min(n - x, m - y);
        while (len >= 1 && !isAvailable(rect, x, y, len)) {
            len--;
        }
        for (int k = len; k >= 1 ; k--) {
            /* 将长度为 k 的正方形区域标记覆盖 */
            fillUp(rect, x, y, k, true);
            /* 跳过 k 个位置开始检测 */
            dfs(x, y + k, rect, cnt + 1);
            fillUp(rect, x, y, k, false);
        }
    }

    // 判断在 rect 这个占用矩阵里，以 (x,y) 为左上角放一个 k×k 正方形，这块区域是否全是空的（都为 false）
    bool isAvailable(vector<vector<bool>> &rect, int x, int y, int k) {
    for (int i = 0; i < k; i++) {
        if (accumulate(rect[x + i].begin() + y,
                       rect[x + i].begin() + y + k,
                       false,
                       bit_or())) {
            return false;
        }
    }
    return true;
}


    void fillUp(vector<vector<bool>> &rect, int x, int y, int k, bool val) {
        for (int i = 0; i < k; i++){
            fill(rect[x + i].begin() + y, rect[x + i].begin() + y + k, val);
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n3\n
// @lcpr case=end

// @lcpr case=start
// 5\n8\n
// @lcpr case=end

// @lcpr case=start
// 11\n13\n
// @lcpr case=end

 */

