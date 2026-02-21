/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=30204
 *
 * [42] 接雨水
 *
 * https://leetcode.cn/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (64.39%)
 * Likes:    5987
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 2.4M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
 * 
 * 示例 2：
 * 
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
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
    int trap1(vector<int>& height) {
        int n = height.size();
        vector<int> pre_max(n);
        pre_max[0] = height[0];
        for (int i = 1; i < n; i++) {
            pre_max[i] = max(pre_max[i - 1], height[i]);
        }

        vector<int> suf_max(n);
        suf_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf_max[i] = max(suf_max[i + 1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(pre_max[i], suf_max[i]) - height[i];
        }
        return ans;
    }
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0, left = 0, right = n - 1, pre_max = 0, suf_max = 0;
        while (left <= right) {
            pre_max = max(pre_max, height[left]);
            suf_max = max(suf_max, height[right]);
            if (pre_max < suf_max) {
                ans += pre_max - height[left];
                left++;
            } else {
                ans += suf_max - height[right];
                right--;
            }
        }
        return ans;
    }
    int trap2(vector<int>& height) {
        int res = 0;
        stack<int> st;
        for (int i = 0; i < height.size(); i++) {
            int h = height[i];
            while (!st.empty() && h >= height[st.top()]) {
                int bottom_h = height[st.top()];
                st.pop();
                if (!st.empty()) {
                    int left = st.top();
                    int dh = min(height[left], h) - bottom_h;
                    res += dh * (i - left - 1);
                }
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

 */

