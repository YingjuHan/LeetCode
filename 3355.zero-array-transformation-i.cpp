/*
 * @lc app=leetcode.cn id=3355 lang=cpp
 * @lcpr version=
 *
 * [3355] 零数组变换 I
 *
 * https://leetcode.cn/problems/zero-array-transformation-i/description/
 *
 * algorithms
 * Medium (55.67%)
 * Likes:    62
 * Dislikes: 0
 * Total Accepted:    21.6K
 * Total Submissions: 38.6K
 * Testcase Example:  '[1,0,1]\n[[0,2]]'
 *
 * 给定一个长度为 n 的整数数组 nums 和一个二维数组 queries，其中 queries[i] = [li, ri]。
 * 
 * 对于每个查询 queries[i]：
 * 
 * 
 * 在 nums 的下标范围 [li, ri] 内选择一个下标 子集。
 * 将选中的每个下标对应的元素值减 1。
 * 
 * 
 * 零数组 是指所有元素都等于 0 的数组。
 * 
 * 如果在按顺序处理所有查询后，可以将 nums 转换为 零数组 ，则返回 true，否则返回 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： nums = [1,0,1], queries = [[0,2]]
 * 
 * 输出： true
 * 
 * 解释：
 * 
 * 
 * 对于 i = 0：
 * 
 * 
 * 选择下标子集 [0, 2] 并将这些下标处的值减 1。
 * 数组将变为 [0, 0, 0]，这是一个零数组。
 * 
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： nums = [4,3,2,1], queries = [[1,3],[0,2]]
 * 
 * 输出： false
 * 
 * 解释：
 * 
 * 
 * 对于 i = 0： 
 * 
 * 
 * 选择下标子集 [1, 2, 3] 并将这些下标处的值减 1。
 * 数组将变为 [4, 2, 1, 0]。
 * 
 * 
 * 对于 i = 1：
 * 
 * 选择下标子集 [0, 1, 2] 并将这些下标处的值减 1。
 * 数组将变为 [3, 1, 0, 0]，这不是一个零数组。
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^5
 * 1 <= queries.length <= 10^5
 * queries[i].length == 2
 * 0 <= li <= ri < nums.length
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
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1);
        for (vector<int>& query : queries) {
            diff[query[0]]++;
            diff[query[1] + 1]--;
        }

        int s = 0;
        for (int i = 0; i < n; i++) {
            s += diff[i];
            if (nums[i] - s > 0) { // nums[i]无法通过累加s次的减1到0
                return false;
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,1]\n[[0,2]]\n
// @lcpr case=end

// @lcpr case=start
// [4,3,2,1]\n[[1,3],[0,2]]\n
// @lcpr case=end

 */

