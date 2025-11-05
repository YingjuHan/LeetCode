// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem447.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=447 lang=cpp
 * @lcpr version=30204
 *
 * [447] 回旋镖的数量
 *
 * https://leetcode.cn/problems/number-of-boomerangs/description/
 *
 * algorithms
 * Medium (68.56%)
 * Likes:    337
 * Dislikes: 0
 * Total Accepted:    82.6K
 * Total Submissions: 120.4K
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * 给定平面上 n 对 互不相同 的点 points ，其中 points[i] = [xi, yi] 。回旋镖 是由点 (i, j, k) 表示的元组
 * ，其中 i 和 j 之间的欧式距离和 i 和 k 之间的欧式距离相等（需要考虑元组的顺序）。
 * 
 * 返回平面上所有回旋镖的数量。
 * 
 * 
 * 示例 1：
 * 
 * 输入：points = [[0,0],[1,0],[2,0]]
 * 输出：2
 * 解释：两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
 * 
 * 
 * 示例 2：
 * 
 * 输入：points = [[1,1],[2,2],[3,3]]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 输入：points = [[1,1]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == points.length
 * 1 <= n <= 500
 * points[i].length == 2
 * -10^4 <= xi, yi <= 10^4
 * 所有点都 互不相同
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
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        unordered_map<int, int> cnt;
        for (auto& p1 : points) {
            cnt.clear();
            for (auto& p2 : points) {
                int d2 = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
                res += 2 * cnt[d2];
                cnt[d2]++;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0],[1,0],[2,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,2],[3,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1]]\n
// @lcpr case=end

 */

