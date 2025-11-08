/*
 * @lc app=leetcode.cn id=面试题 17.23 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 17.23] 最大黑方阵
 *
 * https://leetcode.cn/problems/max-black-square-lcci/description/
 *
 * LCCI
 * Medium (38.52%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    10.3K
 * Total Submissions: 26.8K
 * Testcase Example:  '[[1,0,1],[0,0,1],[0,0,1]]'
 *
 * 给定一个方阵，其中每个单元(像素)非黑即白。设计一个算法，找出 4 条边皆为黑色像素的最大子方阵。
 * 
 * 返回一个数组 [r, c, size] ，其中 r, c 分别代表子方阵左上角的行号和列号，size 是子方阵的边长。若有多个满足条件的子方阵，返回 r
 * 最小的，若 r 相同，返回 c 最小的子方阵。若无满足条件的子方阵，返回空数组。
 * 
 * 示例 1：
 * 
 * 输入：
 * [
 * [1,0,1],
 * [0,0,1],
 * [0,0,1]
 * ]
 * 输出：[1,0,2]
 * 解释：输入中 0 代表黑色，1 代表白色，标粗的元素即为满足条件的最大子方阵
 * 
 * 
 * 示例 2：
 * 
 * 输入：
 * [
 * [0,1,1],
 * [1,0,1],
 * [1,1,0]
 * ]
 * 输出：[0,0,1]
 * 
 * 
 * 提示：
 * 
 * 
 * matrix.length == matrix[0].length <= 200
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
    // 找出4条边皆为黑色（0）的最大子方阵，返回 [r, c, size]
    vector<int> findSquare(const vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector left1(n, vector<int>(n));
        vector right1(n, vector<int>(n));
        vector up1(n, vector<int>(n));
        vector down1(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            int l = -1;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    l = j;
                }
                left1[i][j] = l;
            }

            int r = n;
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == 1) {
                    r = j;
                }
                right1[i][j] = r;
            }
        }

        for (int j = 0; j < n; j++) {
            int u = -1;
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == 1) {
                    u = i;
                }
                up1[i][j] = u;
            }

            int d = n;
            for (int i = n - 1; i >= 0; i--) {
                if (matrix[i][j]) {
                    d = i;
                }
                down1[i][j] = d;
            }
        }

        tuple<int, int, int> ans{}; // (size, -r, -c)

        for (int k = 0; k < n * 2 - 1; k++) {
            set<int> st;
            int min_j = max(k - n + 1, 0);
            int max_j = min(k, n - 1);
            vector<vector<int>> to_remove(n);

            for (int j = max_j; j >= min_j; j--) {
                int i = k - j;
                if (matrix[i][j] == 0) {
                    // (i,j) 作为正方形的右上角，可以服务于左下角横坐标在 [i,i+sz-1] 中的正方形
                    st.insert(i);
                    int sz = min(j - left1[i][j], down1[i][j] - i); // min(左,下)
                    to_remove[i + sz - 1].push_back(i); // 在未来移除

                    // (i,j) 作为正方形的左下角
                    // 找 sl 中的大于 i-size 的最小横坐标 i2
                    sz = min(right1[i][j] - j, i - up1[i][j]); // min(右,上)
                    int i2 = *st.upper_bound(i - sz);
                    // i-i2+1 就是 (i,j) 作为正方形左下角时，正方形的最大边长
                    ans = max(ans, {i - i2 + 1, -i2, -j});
                }

                // 移除那些超过服务范围的右上角横坐标
                for (int i2 : to_remove[i]) {
                    st.erase(i2);
                }
            }
        }

        if (get<0>(ans) == 0) {
            return {};
        }
        return {-get<1>(ans), -get<2>(ans), get<0>(ans)};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,0,1],[0,0,1],[0,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,1],[1,0,1],[1,1,0]]\n
// @lcpr case=end

 */

