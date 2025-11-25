/*
 * @lc app=leetcode.cn id=768 lang=cpp
 * @lcpr version=30204
 *
 * [768] 最多能完成排序的块 II
 *
 * https://leetcode.cn/problems/max-chunks-to-make-sorted-ii/description/
 *
 * algorithms
 * Hard (58.54%)
 * Likes:    326
 * Dislikes: 0
 * Total Accepted:    38K
 * Total Submissions: 65.3K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 给你一个整数数组 arr 。
 * 
 * 将 arr 分割成若干 块 ，并将这些块分别进行排序。之后再连接起来，使得连接的结果和按升序排序后的原数组相同。
 * 
 * 返回能将数组分成的最多块数？
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [5,4,3,2,1]
 * 输出：1
 * 解释：
 * 将数组分成2块或者更多块，都无法得到所需的结果。 
 * 例如，分成 [5, 4], [3, 2, 1] 的结果是 [4, 5, 1, 2, 3]，这不是有序的数组。 
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [2,1,3,4,4]
 * 输出：4
 * 解释：
 * 可以把它分成两块，例如 [2, 1], [3, 4, 4]。 
 * 然而，分成 [2, 1], [3], [4], [4] 可以得到最多的块数。 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 2000
 * 0 <= arr[i] <= 10^8
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
     * 从左到右，每个分块都有一个最大值，并且这些分块的最大值呈单调递增（非严格递增）。
     * 可以用一个栈来存储这些分块的最大值。最后得到的栈的大小，也就是题目所求的最多能完成排序的块。
     */
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;
        for (int v : arr) {
            if (st.empty() || st.top() <= v) {
                st.push(v);
            } else {
                int mx = st.top();
                st.pop();
                while (!st.empty() && st.top() > v) {
                    st.pop();
                }
                st.push(mx);
            }
        }
        return st.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3,4,4]\n
// @lcpr case=end

 */

