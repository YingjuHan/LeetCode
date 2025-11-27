/*
 * @lc app=leetcode.cn id=907 lang=cpp
 * @lcpr version=30204
 *
 * [907] 子数组的最小值之和
 *
 * https://leetcode.cn/problems/sum-of-subarray-minimums/description/
 *
 * algorithms
 * Medium (40.55%)
 * Likes:    887
 * Dislikes: 0
 * Total Accepted:    76.9K
 * Total Submissions: 189.7K
 * Testcase Example:  '[3,1,2,4]'
 *
 * 给定一个整数数组 arr，找到 min(b) 的总和，其中 b 的范围为 arr 的每个（连续）子数组。
 * 
 * 由于答案可能很大，因此 返回答案模 10^9 + 7 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [3,1,2,4]
 * 输出：17
 * 解释：
 * 子数组为 [3]，[1]，[2]，[4]，[3,1]，[1,2]，[2,4]，[3,1,2]，[1,2,4]，[3,1,2,4]。 
 * 最小值为 3，1，2，4，1，1，2，1，1，1，和为 17。
 * 
 * 示例 2：
 * 
 * 输入：arr = [11,81,94,43,3]
 * 输出：444
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 3 * 10^4
 * 1 <= arr[i] <= 3 * 10^4
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
    const int MOD = 1e9 + 7;
public:
    /**
     * 单调栈-三次遍历
     */
    int sumSubarrayMins3(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            // 左边界 left[i] 为左侧严格小于 arr[i] 的最近元素位置（不存在时为 -1）
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }

        vector<int> right(n, n);
        st = stack<int>();
        // 右边界 right[i] 为右侧小于等于 arr[i] 的最近元素位置（不存在时为 n）
        for (int i = n - 1; i>= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }

        long res = 0L;
        for (int i = 0; i < n; i++) {
            res += ((long)arr[i] * (i - left[i]) * (right[i] - i)) % MOD;
        }
        return res % MOD;
    }

    /**
     * 单调栈-二次遍历
     * 对于栈顶元素t,如果t右侧有多个小于或等于t的元素,那么t只会因为右侧第一个小于或等于t的元素而出栈,这符合右边界的定义
     */
    int sumSubarrayMins2(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                right[st.top()]  = i; // i是栈顶的右边界
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }

        long res = 0L;
        for (int i = 0; i < n; i++) {
            res += ((long)arr[i] * (i - left[i]) * (right[i] - i)) % MOD;
        }
        return res % MOD;
    }

    
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [11,81,94,43,3]\n
// @lcpr case=end

 */

