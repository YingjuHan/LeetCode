/*
 * @lc app=leetcode.cn id=1187 lang=cpp
 * @lcpr version=30204
 *
 * [1187] 使数组严格递增
 *
 * https://leetcode.cn/problems/make-array-strictly-increasing/description/
 *
 * algorithms
 * Hard (60.26%)
 * Likes:    251
 * Dislikes: 0
 * Total Accepted:    18.5K
 * Total Submissions: 30.8K
 * Testcase Example:  '[1,5,3,6,7]\n[1,3,2,4]'
 *
 * 给你两个整数数组 arr1 和 arr2，返回使 arr1 严格递增所需要的最小「操作」数（可能为 0）。
 * 
 * 每一步「操作」中，你可以分别从 arr1 和 arr2 中各选出一个索引，分别为 i 和 j，0 <= i < arr1.length 和 0 <= j
 * < arr2.length，然后进行赋值运算 arr1[i] = arr2[j]。
 * 
 * 如果无法让 arr1 严格递增，请返回 -1。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
 * 输出：1
 * 解释：用 2 来替换 5，之后 arr1 = [1, 2, 3, 6, 7]。
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr1 = [1,5,3,6,7], arr2 = [4,3,1]
 * 输出：2
 * 解释：用 3 来替换 5，然后用 4 来替换 3，得到 arr1 = [1, 3, 4, 6, 7]。
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
 * 输出：-1
 * 解释：无法使 arr1 严格递增。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr1.length, arr2.length <= 2000
 * 0 <= arr1[i], arr2[i] <= 10^9
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
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        ranges::sort(arr2); // 为能二分查找，对 arr2 排序
        int n = arr1.size();
        unordered_map<int, int> memo[n];

        auto dfs = [&](this auto&& dfs, int i, int pre) -> int {
            if (i < 0) {
                return 0;
            }
            auto it = memo[i].find(pre);
            if (it != memo[i].end()) {
                return it->second;
            }

            // 不替换
            int res = arr1[i] < pre ? dfs(i - 1, arr1[i]) : INT_MAX / 2;

            // 二分查找arr2中小于pre的最大数的下标
            auto k = ranges::lower_bound(arr2, pre);
            if (k != arr2.begin()) {
                res = min(res, dfs(i - 1, *--k) + 1);
            }
            return memo[i][pre] = res;
        };
        int ans = dfs(n - 1, INT_MAX);
        return ans < INT_MAX / 2 ? ans : -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,5,3,6,7]\n[1,3,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,5,3,6,7]\n[4,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,5,3,6,7]\n[1,6,3,3]\n
// @lcpr case=end

 */

