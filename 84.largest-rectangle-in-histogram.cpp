/*
 * @lc app=leetcode.cn id=84 lang=cpp
 * @lcpr version=30204
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode.cn/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (46.47%)
 * Likes:    3025
 * Dislikes: 0
 * Total Accepted:    602.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 输入：heights = [2,1,5,6,2,3]
 * 输出：10
 * 解释：最大的矩形为图中红色区域，面积为 10
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入： heights = [2,4]
 * 输出： 4
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= heights.length <=10^5
 * 0 <= heights[i] <= 10^4
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
    int largestRectangleArea1(vector<int>& heights) {
        heights.push_back(-1); // 最后大火收汁，用 -1 把栈清空
        stack<int> st;
        st.push(-1); // 在栈中只有一个数的时候，栈顶的「下面那个数」是 -1，对应 left[i] = -1 的情况
        int ans = 0;
        for (int right = 0; right < heights.size(); right++) {
            int h = heights[right];
            while (st.size() > 1 && heights[st.top()] >= h) {
                int i = st.top(); // 矩形的高（的下标）
                st.pop();
                int left = st.top(); // 栈顶下面那个数就是 left
                ans = max(ans, heights[i] * (right - left - 1));
            }
            st.push(right);
        }
        return ans;
    }

    /**
     * 1. 核心思路：找“左右边界”
     * 要把某个柱子 heights[i] 作为矩形的高度，这个矩形能向左右延伸多远？
     *   左边界： 左边第一个比它矮的柱子。
     *   右边界： 右边第一个比它矮的柱子。
     * 只要找到了这两个边界，矩形的宽度就是 right[i] - left[i] - 1，面积就是 heights[i] * 宽度
     * 
     * 2. 代码执行:
     * 第一步: 计算左边界(left数组)
     * 通过一次遍历, 维护一个高度递增的栈
     *   如果当前柱子比栈顶矮, 说明栈顶不是左边界, 直接弹出
     *   直到发现比当前矮的, 那个位置就是left[i]
     *   如果栈为空, 说明左边没有比它矮的, 记为-1
     * 
     * 第二步: 计算右边界(right数组)
     *  同理，从右往左遍历：
     *  寻找右侧第一个比当前柱子矮的位置。
     *  如果右边没有比它矮的，记为 n（数组长度）。
     * 
     * 第三步：计算最大面积
     * 遍历每一个柱子，计算以它为高度的面积，取最大值：height[i] * (right[i] - left[i] - 1)
     */
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            int h = heights[i];
            while (!st.empty() && heights[st.top()] >= h) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }

        vector<int> right(n, n);
        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            int h = heights[i];
            while (!st.empty() && heights[st.top()] >= h) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,5,6,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n
// @lcpr case=end

 */

