/*
 * @lc app=leetcode.cn id=2518 lang=cpp
 * @lcpr version=30204
 *
 * [2518] 好分区的数目
 *
 * https://leetcode.cn/problems/number-of-great-partitions/description/
 *
 * algorithms
 * Hard (42.17%)
 * Likes:    46
 * Dislikes: 0
 * Total Accepted:    5.4K
 * Total Submissions: 12.7K
 * Testcase Example:  '[1,2,3,4]\n4'
 *
 * 给你一个正整数数组 nums 和一个整数 k 。
 * 
 * 分区 的定义是：将数组划分成两个有序的 组 ，并满足每个元素 恰好 存在于 某一个 组中。如果分区中每个组的元素和都大于等于 k
 * ，则认为分区是一个好分区。
 * 
 * 返回 不同 的好分区的数目。由于答案可能很大，请返回对 10^9 + 7 取余 后的结果。
 * 
 * 如果在两个分区中，存在某个元素 nums[i] 被分在不同的组中，则认为这两个分区不同。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,2,3,4], k = 4
 * 输出：6
 * 解释：好分区的情况是 ([1,2,3], [4]), ([1,3], [2,4]), ([1,4], [2,3]), ([2,3], [1,4]),
 * ([2,4], [1,3]) 和 ([4], [1,2,3]) 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [3,3,3], k = 4
 * 输出：0
 * 解释：数组中不存在好分区。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [6,6], k = 2
 * 输出：2
 * 解释：可以将 nums[0] 放入第一个分区或第二个分区中。
 * 好分区的情况是 ([6], [6]) 和 ([6], [6]) 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length, k <= 1000
 * 1 <= nums[i] <= 10^9
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
    // 好分区数 = 总分区数 − 坏分区数
    // 总分区数 = 2 ^ n
    const int MOD = 1e9 + 7;
    int countPartitions(vector<int>& nums, int k) {
        if (accumulate(nums.begin(), nums.end(), 0L) < k * 2) {
            return 0;
        }

        int res = 1;
        vector<int> f(k, 0);
        for (int x : nums) {
            res = res * 2 % MOD;
            for (int j = k - 1; j >= x; j--) {
                f[j] = (f[j] + f[j - x]) % MOD;
            }
        }
        for (int x : f) {
            res = (res - x * 2 % MOD + MOD) % MOD;
        }
        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n4\n
// @lcpr case=end

// @lcpr case=start
// [3,3,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [6,6]\n2\n
// @lcpr case=end

 */

