/*
 * @lc app=leetcode.cn id=2200 lang=cpp
 * @lcpr version=30204
 *
 * [2200] 找出数组中的所有 K 近邻下标
 *
 * https://leetcode.cn/problems/find-all-k-distant-indices-in-an-array/description/
 *
 * algorithms
 * Easy (64.56%)
 * Likes:    49
 * Dislikes: 0
 * Total Accepted:    30K
 * Total Submissions: 46.5K
 * Testcase Example:  '[3,4,9,1,3,9,5]\n9\n1'
 *
 * 给你一个下标从 0 开始的整数数组 nums 和两个整数 key 和 k 。K 近邻下标 是 nums 中的一个下标 i ，并满足至少存在一个下标 j
 * 使得 |i - j| <= k 且 nums[j] == key 。
 * 
 * 以列表形式返回按 递增顺序 排序的所有 K 近邻下标。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [3,4,9,1,3,9,5], key = 9, k = 1
 * 输出：[1,2,3,4,5,6]
 * 解释：因此，nums[2] == key 且 nums[5] == key。
 * - 对下标 0 ，|0 - 2| > k 且 |0 - 5| > k，所以不存在 j 使得 |0 - j| <= k 且 nums[j] ==
 * key。所以 0 不是一个 K 近邻下标。
 * - 对下标 1 ，|1 - 2| <= k 且 nums[2] == key，所以 1 是一个 K 近邻下标。
 * - 对下标 2 ，|2 - 2| <= k 且 nums[2] == key，所以 2 是一个 K 近邻下标。
 * - 对下标 3 ，|3 - 2| <= k 且 nums[2] == key，所以 3 是一个 K 近邻下标。
 * - 对下标 4 ，|4 - 5| <= k 且 nums[5] == key，所以 4 是一个 K 近邻下标。
 * - 对下标 5 ，|5 - 5| <= k 且 nums[5] == key，所以 5 是一个 K 近邻下标。
 * - 对下标 6 ，|6 - 5| <= k 且 nums[5] == key，所以 6 是一个 K 近邻下标。
 * 因此，按递增顺序返回 [1,2,3,4,5,6] 。 
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [2,2,2,2,2], key = 2, k = 2
 * 输出：[0,1,2,3,4]
 * 解释：对 nums 的所有下标 i ，总存在某个下标 j 使得 |i - j| <= k 且 nums[j] == key，所以每个下标都是一个 K
 * 近邻下标。 
 * 因此，返回 [0,1,2,3,4] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 1000
 * key 是数组 nums 中的一个整数
 * 1 <= k <= nums.length
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
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        /**
         * 在nums数组中找到所有与key元素距离不超过k的索引，返回索引的有序列表
         */
        // last记录最近一次出现key的索引，初始化为-k - 1，目的是弱数组中没有key，确保初始状态下所有i都不满足体条件
        int last = -k - 1;

        // 预处理：从数组开始到索引k-1中，找到最后一次出现的key(如果存在)
        // 因为这些key可能影响前k个索引的结果
        for (int i = k - 1; i >= 0; i--) {
            if (nums[i] == key) {
                last = i;
                break;
            }
        }

        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            // 若当前索引i右侧k步内存在key（且不越界），更新最新的key位置
            if (i + k < nums.size() && nums[i + k] == key) {
                last = i + k;
            }

            // 若最近的key位置last与当前索引i的距离 <= k， 则i是符合条件的索引
            if (i - last <= k) {  // 等价于 |i - last| ≤k（因 last 是最近的 key，i 在递增）
                res.push_back(i);
            }
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,4,9,1,3,9,5]\n9\n1\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n2\n2\n
// @lcpr case=end

 */

