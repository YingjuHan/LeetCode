/*
 * @lc app=leetcode.cn id=739 lang=cpp
 * @lcpr version=30204
 *
 * [739] 每日温度
 *
 * https://leetcode.cn/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (69.15%)
 * Likes:    2069
 * Dislikes: 0
 * Total Accepted:    866K
 * Total Submissions: 1.2M
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i
 * 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: temperatures = [73,74,75,71,69,72,76,73]
 * 输出: [1,1,4,2,1,1,0,0]
 * 
 * 
 * 示例 2:
 * 
 * 输入: temperatures = [30,40,50,60]
 * 输出: [1,1,1,0]
 * 
 * 
 * 示例 3:
 * 
 * 输入: temperatures = [30,60,90]
 * 输出: [1,1,0]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
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
     * 写法1: 从右到左
     * 栈中记录下一个更大元素的候选项的下标
     * 每次循环,可以在候选项中找到答案
     */
    vector<int> dailyTemperatures1(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            int t = temperatures[i];
            while (!st.empty() && t >= temperatures[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top() - i;
            }
            st.push(i);
        }
        return res;
    } 

    /**
     * 写法2: 从左到右
     * 栈中记录还没算出下一个更大元素的那些数的下标。
     * 相当于栈是一个 todolist，在循环的过程中，现在还不知道答案是多少，在后面的循环中会算出答案。
     */
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            int t = temperatures[i];
            while (!st.empty() && t > temperatures[st.top()]) {
                int j = st.top();
                st.pop();
                res[j] = i - j;
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [73,74,75,71,69,72,76,73]\n
// @lcpr case=end

// @lcpr case=start
// [30,40,50,60]\n
// @lcpr case=end

// @lcpr case=start
// [30,60,90]\n
// @lcpr case=end

 */

