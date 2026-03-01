/*
 * @lc app=leetcode.cn id=624 lang=cpp
 * @lcpr version=30204
 *
 * [624] 数组列表中的最大距离
 *
 * https://leetcode.cn/problems/maximum-distance-in-arrays/description/
 *
 * algorithms
 * Medium (45.24%)
 * Likes:    187
 * Dislikes: 0
 * Total Accepted:    45.9K
 * Total Submissions: 101.3K
 * Testcase Example:  '[[1,2,3],[4,5],[1,2,3]]'
 *
 * 给定 m 个数组，每个数组都已经按照升序排好序了。
 * 
 * 现在你需要从两个不同的数组中选择两个整数（每个数组选一个）并且计算它们的距离。两个整数 a 和 b 之间的距离定义为它们差的绝对值 |a-b| 。
 * 
 * 返回最大距离。
 * 
 * 示例 1：
 * 
 * 输入：[[1,2,3],[4,5],[1,2,3]]
 * 输出：4
 * 解释：
 * 一种得到答案 4 的方法是从第一个数组或者第三个数组中选择 1，同时从第二个数组中选择 5 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：arrays = [[1],[1]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == arrays.length
 * 2 <= m <= 10^5
 * 1 <= arrays[i].length <= 500
 * -10^4 <= arrays[i][j] <= 10^4
 * arrays[i] 以 升序 排序。
 * 所有数组中最多有 10^5 个整数。
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
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        int mn = INT_MAX / 2, mx = INT_MIN / 2;
        for (auto& a : arrays) {
            ans = max({ans, a.back() - mn, mx - a[0]});
            mn = min(mn, a[0]);
            mx = max(mx, a.back());
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5],[1,2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1],[1]]\n
// @lcpr case=end

 */

