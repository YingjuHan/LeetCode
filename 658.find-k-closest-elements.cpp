// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem658.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=658 lang=cpp
 * @lcpr version=30204
 *
 * [658] 找到 K 个最接近的元素
 *
 * https://leetcode.cn/problems/find-k-closest-elements/description/
 *
 * algorithms
 * Medium (48.65%)
 * Likes:    643
 * Dislikes: 0
 * Total Accepted:    128.1K
 * Total Submissions: 263.2K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 * 给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。
 * 
 * 整数 a 比整数 b 更接近 x 需要满足：
 * 
 * 
 * |a - x| < |b - x| 或者
 * |a - x| == |b - x| 且 a < b
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [1,2,3,4,5], k = 4, x = 3
 * 输出：[1,2,3,4]
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [1,1,2,3,4,5], k = 4, x = -1
 * 输出：[1,1,2,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= k <= arr.length
 * 1 <= arr.length <= 10^4
 * arr 按 升序 排列
 * -10^4 <= arr[i], x <= 10^4
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
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        while (right - left >= k) {
            if (abs(arr[right] - x) >= abs(arr[left] - x)) {
                right--;
            } else {
                left++;
            }
        }

        vector<int> res;
        for (int i = left; i <=right; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n4\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3,4,5]\n4\n-1\n
// @lcpr case=end

 */

