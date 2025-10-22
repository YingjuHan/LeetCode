// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2653 lang=cpp
 * @lcpr version=30204
 *
 * [2653] 滑动子数组的美丽值
 *
 * https://leetcode.cn/problems/sliding-subarray-beauty/description/
 *
 * algorithms
 * Medium (46.52%)
 * Likes:    103
 * Dislikes: 0
 * Total Accepted:    19.9K
 * Total Submissions: 42.5K
 * Testcase Example:  '[1,-1,-3,-2,3]\n3\n2'
 *
 * 给你一个长度为 n 的整数数组 nums ，请你求出每个长度为 k 的子数组的 美丽值 。
 * 
 * 一个子数组的 美丽值 定义为：如果子数组中第 x 小整数 是 负数 ，那么美丽值为第 x 小的数，否则美丽值为 0 。
 * 
 * 请你返回一个包含 n - k + 1 个整数的数组，依次 表示数组中从第一个下标开始，每个长度为 k 的子数组的 美丽值 。
 * 
 * 
 * 
 * 子数组指的是数组中一段连续 非空 的元素序列。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,-1,-3,-2,3], k = 3, x = 2
 * 输出：[-1,-2,-2]
 * 解释：总共有 3 个 k = 3 的子数组。
 * 第一个子数组是 [1, -1, -3] ，第二小的数是负数 -1 。
 * 第二个子数组是 [-1, -3, -2] ，第二小的数是负数 -2 。
 * 第三个子数组是 [-3, -2, 3] ，第二小的数是负数 -2 。
 * 
 * 示例 2：
 * 
 * 输入：nums = [-1,-2,-3,-4,-5], k = 2, x = 2
 * 输出：[-1,-2,-3,-4]
 * 解释：总共有 4 个 k = 2 的子数组。
 * [-1, -2] 中第二小的数是负数 -1 。
 * [-2, -3] 中第二小的数是负数 -2 。
 * [-3, -4] 中第二小的数是负数 -3 。
 * [-4, -5] 中第二小的数是负数 -4 。
 * 
 * 示例 3：
 * 
 * 输入：nums = [-3,1,2,-3,0,-3], k = 2, x = 1
 * 输出：[-3,0,-3,-3,-3]
 * 解释：总共有 5 个 k = 2 的子数组。
 * [-3, 1] 中最小的数是负数 -3 。
 * [1, 2] 中最小的数不是负数，所以美丽值为 0 。
 * [2, -3] 中最小的数是负数 -3 。
 * [-3, 0] 中最小的数是负数 -3 。
 * [0, -3] 中最小的数是负数 -3 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length 
 * 1 <= n <= 10^5
 * 1 <= k <= n
 * 1 <= x <= k 
 * -50 <= nums[i] <= 50 
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
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        // 计数排序（桶排序）+滑动窗口
        // 第x小数num：<num的个数 <x <= num的个数 >=x

        // 先统计k-1个数
        const int BIAS = 50;
        int cnt[BIAS * 2 + 1] {};
        for (int i = 0; i < k - 1; i++) {
            cnt[nums[i] + BIAS]++;
        }

        vector<int> res(nums.size() - k + 1, 0);

        for (int i = k - 1; i < nums.size(); i++) {
            int in = nums[i];
            cnt[in + BIAS]++;

            int left = x;
            for (int j = -50; j < 0; j++) {
                left -= cnt[j + BIAS];
                if (left <= 0) {
                    res[i - k + 1] = j;
                    break;
                }
            }


            int out = nums[i - k + 1];
            cnt[out + BIAS]--;
        }

        return res;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=getSubarrayBeauty
// paramTypes= ["number[]","number","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,-1,-3,-2,3]\n3\n2\n
// @lcpr case=end

// @lcpr case=start
// [-1,-2,-3,-4,-5]\n2\n2\n
// @lcpr case=end

// @lcpr case=start
// [-3,1,2,-3,0,-3]\n2\n1\n
// @lcpr case=end

 */

