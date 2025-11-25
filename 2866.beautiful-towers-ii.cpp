/*
 * @lc app=leetcode.cn id=2866 lang=cpp
 * @lcpr version=30204
 *
 * [2866] 美丽塔 II
 *
 * https://leetcode.cn/problems/beautiful-towers-ii/description/
 *
 * algorithms
 * Medium (46.38%)
 * Likes:    152
 * Dislikes: 0
 * Total Accepted:    19.6K
 * Total Submissions: 41.8K
 * Testcase Example:  '[5,3,4,1,1]'
 *
 * 给你一个长度为 n 下标从 0 开始的整数数组 maxHeights 。
 * 
 * 你的任务是在坐标轴上建 n 座塔。第 i 座塔的下标为 i ，高度为 heights[i] 。
 * 
 * 如果以下条件满足，我们称这些塔是 美丽 的：
 * 
 * 
 * 1 <= heights[i] <= maxHeights[i]
 * heights 是一个 山脉 数组。
 * 
 * 
 * 如果存在下标 i 满足以下条件，那么我们称数组 heights 是一个 山脉 数组：
 * 
 * 
 * 对于所有 0 < j <= i ，都有 heights[j - 1] <= heights[j]
 * 对于所有 i <= k < n - 1 ，都有 heights[k + 1] <= heights[k]
 * 
 * 
 * 请你返回满足 美丽塔 要求的方案中，高度和的最大值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：maxHeights = [5,3,4,1,1]
 * 输出：13
 * 解释：和最大的美丽塔方案为 heights = [5,3,3,1,1] ，这是一个美丽塔方案，因为：
 * - 1 <= heights[i] <= maxHeights[i]  
 * - heights 是个山脉数组，峰值在 i = 0 处。
 * 13 是所有美丽塔方案中的最大高度和。
 * 
 * 示例 2：
 * 
 * 输入：maxHeights = [6,5,3,9,2,7]
 * 输出：22
 * 解释： 和最大的美丽塔方案为 heights = [3,3,3,9,2,2] ，这是一个美丽塔方案，因为：
 * - 1 <= heights[i] <= maxHeights[i]
 * - heights 是个山脉数组，峰值在 i = 3 处。
 * 22 是所有美丽塔方案中的最大高度和。
 * 
 * 示例 3：
 * 
 * 输入：maxHeights = [3,2,5,5,2,3]
 * 输出：18
 * 解释：和最大的美丽塔方案为 heights = [2,2,5,5,2,2] ，这是一个美丽塔方案，因为：
 * - 1 <= heights[i] <= maxHeights[i]
 * - heights 是个山脉数组，最大值在 i = 2 处。
 * 注意，在这个方案中，i = 3 也是一个峰值。
 * 18 是所有美丽塔方案中的最大高度和。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n == maxHeights <= 10^5
 * 1 <= maxHeights[i] <= 10^9
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
    /**
     * 
     * 1. 相同的数,只需要保留最靠左的那个(的下标)
     * 2. 用单调栈维护需要保留的数
     * 3. 维护元素和
     */
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        stack<int> st;
        st.push(n);
        long long s = 0;
        vector<long long> suf(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int x = maxHeights[i];
            while (st.size() > 1 && x <= maxHeights[st.top()]) {
                int j = st.top();
                st.pop();
                s -= (long long)maxHeights[j] * (st.top() - j);
            }
            s += (long long)x * (st.top() - i);
            suf[i] = s;
            st.push(i);
        }

        long long res = s;
        st = stack<int>();
        st.push(-1);
        long long pre = 0;
        for (int i = 0; i < n; i++) {
            int x = maxHeights[i];
            while (st.size() > 1 && x <= maxHeights[st.top()]) {
                int j = st.top();
                st.pop();
                pre -= (long long)maxHeights[j] * (j - st.top());
            }
            pre += (long long)x * (i - st.top());
            st.push(i);
            res = max(res, pre + suf[i + 1]);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,3,4,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [6,5,3,9,2,7]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,5,5,2,3]\n
// @lcpr case=end

 */

