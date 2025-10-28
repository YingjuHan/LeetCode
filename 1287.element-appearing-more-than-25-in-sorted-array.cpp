/*
 * @lc app=leetcode.cn id=1287 lang=cpp
 * @lcpr version=30204
 *
 * [1287] 有序数组中出现次数超过25%的元素
 *
 * https://leetcode.cn/problems/element-appearing-more-than-25-in-sorted-array/description/
 *
 * algorithms
 * Easy (58.78%)
 * Likes:    128
 * Dislikes: 0
 * Total Accepted:    54.9K
 * Total Submissions: 93.3K
 * Testcase Example:  '[1,2,2,6,6,6,6,7,10]'
 *
 * 给你一个非递减的 有序 整数数组，已知这个数组中恰好有一个整数，它的出现次数超过数组元素总数的 25%。
 * 
 * 请你找到并返回这个整数
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：arr = [1,2,2,6,6,6,6,7,10]
 * 输出：6
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 10^4
 * 0 <= arr[i] <= 10^5
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
    int findSpecialInteger(vector<int>& arr) {
        int m = arr.size() / 4;
        for (int i : {m, m * 2 + 1}) {
            int x = arr[i];
            if (ranges::upper_bound(arr, x) - ranges::lower_bound(arr, x) > m) {
                return x;
            }
        }
        return arr[m * 3 + 2];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,6,6,6,6,7,10]\n
// @lcpr case=end

 */

