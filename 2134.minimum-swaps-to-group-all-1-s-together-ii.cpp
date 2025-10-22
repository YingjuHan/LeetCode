// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2134 lang=cpp
 * @lcpr version=30204
 *
 * [2134] 最少交换次数来组合所有的 1 II
 *
 * https://leetcode.cn/problems/minimum-swaps-to-group-all-1s-together-ii/description/
 *
 * algorithms
 * Medium (57.94%)
 * Likes:    122
 * Dislikes: 0
 * Total Accepted:    26.1K
 * Total Submissions: 44.9K
 * Testcase Example:  '[0,1,0,1,1,0,0]'
 *
 * 交换 定义为选中一个数组中的两个 互不相同 的位置并交换二者的值。
 * 
 * 环形 数组是一个数组，可以认为 第一个 元素和 最后一个 元素 相邻 。
 * 
 * 给你一个 二进制环形 数组 nums ，返回在 任意位置 将数组中的所有 1 聚集在一起需要的最少交换次数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [0,1,0,1,1,0,0]
 * 输出：1
 * 解释：这里列出一些能够将所有 1 聚集在一起的方案：
 * [0,0,1,1,1,0,0] 交换 1 次。
 * [0,1,1,1,0,0,0] 交换 1 次。
 * [1,1,0,0,0,0,1] 交换 2 次（利用数组的环形特性）。
 * 无法在交换 0 次的情况下将数组中的所有 1 聚集在一起。
 * 因此，需要的最少交换次数为 1 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [0,1,1,1,0,0,1,1,0]
 * 输出：2
 * 解释：这里列出一些能够将所有 1 聚集在一起的方案：
 * [1,1,1,0,0,0,0,1,1] 交换 2 次（利用数组的环形特性）。
 * [1,1,1,1,1,0,0,0,0] 交换 2 次。
 * 无法在交换 0 次或 1 次的情况下将数组中的所有 1 聚集在一起。
 * 因此，需要的最少交换次数为 2 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [1,1,0,0,1]
 * 输出：0
 * 解释：得益于数组的环形特性，所有的 1 已经聚集在一起。
 * 因此，需要的最少交换次数为 0 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * nums[i] 为 0 或者 1
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k = reduce(nums.begin(), nums.end(), 0); // 数组中1的数量
        if (k == 0) {
            return 0;
        }

        int n = nums.size();
        int res = INT_MAX;
        int num_0 = 0;

        for (int i = 0; i < n + k - 1; i++) {
            if (nums[i % n] == 0) {
                num_0++;
            }

            if (i < k - 1) {
                continue;
            }

            res = min(res, num_0);
            if (nums[(i - k + 1) % n] == 0) {
                num_0--;
            }
        }
        return res;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=minSwaps
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [0,1,0,1,1,0,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1,1,0,0,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,0,0,1]\n
// @lcpr case=end

 */

