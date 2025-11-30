/*
 * @lc app=leetcode.cn id=1499 lang=cpp
 * @lcpr version=30204
 *
 * [1499] 满足不等式的最大值
 *
 * https://leetcode.cn/problems/max-value-of-equation/description/
 *
 * algorithms
 * Hard (48.78%)
 * Likes:    186
 * Dislikes: 0
 * Total Accepted:    20.9K
 * Total Submissions: 42.9K
 * Testcase Example:  '[[1,3],[2,0],[5,10],[6,-10]]\n1'
 *
 * 给你一个数组 points 和一个整数 k 。数组中每个元素都表示二维平面上的点的坐标，并按照横坐标 x 的值从小到大排序。也就是说 points[i]
 * = [xi, yi] ，并且在 1 <= i < j <= points.length 的前提下， xi < xj 总成立。
 * 
 * 请你找出 yi + yj + |xi - xj| 的 最大值，其中 |xi - xj| <= k 且 1 <= i < j <=
 * points.length。
 * 
 * 题目测试数据保证至少存在一对能够满足 |xi - xj| <= k 的点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
 * 输出：4
 * 解释：前两个点满足 |xi - xj| <= 1 ，代入方程计算，则得到值 3 + 0 + |1 - 2| = 4 。第三个和第四个点也满足条件，得到值
 * 10 + -10 + |5 - 6| = 1 。
 * 没有其他满足条件的点，所以返回 4 和 1 中最大的那个。
 * 
 * 示例 2：
 * 
 * 输入：points = [[0,0],[3,0],[9,2]], k = 3
 * 输出：3
 * 解释：只有前两个点满足 |xi - xj| <= 3 ，代入方程后得到值 0 + 0 + |0 - 3| = 3 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= points.length <= 10^5
 * points[i].length == 2
 * -10^8 <= xi, yi <= 10^8
 * 0 <= k <= 2 * 10^8
 * 对于所有的 1 <= i < j <= points.length，均有 xi < xj。
 * xi 构成一个严格递增序列。
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
    int findMaxValueOfEquation(vector<vector<int>> &points, int k) {
        int ans = INT_MIN;
        deque<pair<int, int>> q;
        for (auto &p: points) {
            int x = p[0], y = p[1];
            while (!q.empty() && q.front().first < x - k) // 队首超出范围
                q.pop_front(); // 弹它！
            if (!q.empty())
                ans = max(ans, x + y + q.front().second); // 加上最大的 yi-xi
            while (!q.empty() && q.back().second <= y - x) // 队尾不如新来的强
                q.pop_back(); // 弹它！
            q.emplace_back(x, y - x);
        }
        return ans;
    }
};

// @lc code=end



/*
// @lcpr case=start
// [[1,3],[2,0],[5,10],[6,-10]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[3,0],[9,2]]\n3\n
// @lcpr case=end

 */

