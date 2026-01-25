/*
 * @lc app=leetcode.cn id=面试题 16.19 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 16.19] 水域大小
 *
 * https://leetcode.cn/problems/pond-sizes-lcci/description/
 *
 * LCCI
 * Medium (67.63%)
 * Likes:    173
 * Dislikes: 0
 * Total Accepted:    52.7K
 * Total Submissions: 77.9K
 * Testcase Example:  '[[0,2,1,0],[0,1,0,1],[1,1,0,1],[0,1,0,1]]'
 *
 * 
 * 你有一个用于表示一片土地的整数矩阵land，该矩阵中每个点的值代表对应地点的海拔高度。若值为0则表示水域。由垂直、水平或对角连接的水域为池塘。池塘的大小是指相连接的水域的个数。编写一个方法来计算矩阵中所有池塘的大小，返回值需要从小到大排序。
 * 示例：
 * 输入：
 * [
 * ⁠ [0,2,1,0],
 * ⁠ [0,1,0,1],
 * ⁠ [1,1,0,1],
 * ⁠ [0,1,0,1]
 * ]
 * 输出： [1,2,4]
 * 
 * 提示：
 * 
 * 0 < len(land) <= 1000
 * 0 < len(land[i]) <= 1000
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
    vector<int> pondSizes(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<int> res;

        auto dfs = [&](this auto&& dfs, int x, int y) {
            if (x < 0 || x >= m || y < 0 || y >= n || land[x][y]) {
                return 0;
            }
            land[x][y] = 1;
            int cnt0 = 1;
            for (int i = x - 1; i <= x + 1; i++) {
                for (int j = y - 1; j <= y + 1; j++) {
                    cnt0 += dfs(i, j);
                }
            }
            return cnt0;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 0) {
                    res.push_back(dfs(i, j));
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,2,1,0],[0,1,0,1],[1,1,0,1],[0,1,0,1]]\n
// @lcpr case=end

 */

