/*
 * @lc app=leetcode.cn id=1818 lang=cpp
 * @lcpr version=30204
 *
 * [1818] 绝对差值和
 *
 * https://leetcode.cn/problems/minimum-absolute-sum-difference/description/
 *
 * algorithms
 * Medium (38.30%)
 * Likes:    188
 * Dislikes: 0
 * Total Accepted:    38.3K
 * Total Submissions: 100.1K
 * Testcase Example:  '[1,7,5]\n[2,3,5]'
 *
 * 给你两个正整数数组 nums1 和 nums2 ，数组的长度都是 n 。
 * 
 * 数组 nums1 和 nums2 的 绝对差值和 定义为所有 |nums1[i] - nums2[i]|（0 <= i < n）的 总和（下标从 0
 * 开始）。
 * 
 * 你可以选用 nums1 中的 任意一个 元素来替换 nums1 中的 至多 一个元素，以 最小化 绝对差值和。
 * 
 * 在替换数组 nums1 中最多一个元素 之后 ，返回最小绝对差值和。因为答案可能很大，所以需要对 10^9 + 7 取余 后返回。
 * 
 * |x| 定义为：
 * 
 * 
 * 如果 x >= 0 ，值为 x ，或者
 * 如果 x <= 0 ，值为 -x
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums1 = [1,7,5], nums2 = [2,3,5]
 * 输出：3
 * 解释：有两种可能的最优方案：
 * - 将第二个元素替换为第一个元素：[1,7,5] => [1,1,5] ，或者
 * - 将第二个元素替换为第三个元素：[1,7,5] => [1,5,5]
 * 两种方案的绝对差值和都是 |1-2| + (|1-3| 或者 |5-3|) + |5-5| = 3
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums1 = [2,4,6,8,10], nums2 = [2,4,6,8,10]
 * 输出：0
 * 解释：nums1 和 nums2 相等，所以不用替换元素。绝对差值和为 0
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums1 = [1,10,4,4,2,7], nums2 = [9,3,5,1,7,4]
 * 输出：20
 * 解释：将第一个元素替换为第二个元素：[1,10,4,4,2,7] => [10,10,4,4,2,7]
 * 绝对差值和为 |10-9| + |10-3| + |4-5| + |4-1| + |2-7| + |7-4| = 20
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums1.length
 * n == nums2.length
 * 1 <= n <= 10^5
 * 1 <= nums1[i], nums2[i] <= 10^5
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
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        /**
         * 获取nums1的排序（小->大）数组sorted
         * 在遍历nums1和nums2计算总的差值sum时，通过对sorted数组进行二分查找，找到最合适的nums1[i]作为替换值
         * 
         * 当处理到第i位时，假设该位的原差值位x=abs(nums1[i] - nums2[i])
         * 从sorted中找到最接近nums2[i]的值，计算一个新的差值nd
         * 如果满足nd < x，说明存在一个替换数可以使差值变小，用变量记录max下这个替换方案的变化，不断更新max
         * 当整个数组处理完后，max中为最优，sum-max为答案
         */

        vector<int> sortedNums1(nums1);
        sort(sortedNums1.begin(), sortedNums1.end());
        int sum = 0;
        int maxn = 0;
        int n = sortedNums1.size();
        for (int i = 0; i < n; i++)
        {
            int diff = abs(nums1[i] - nums2[i]);
            sum = (sum + diff) % mod;
            int j = lower_bound(sortedNums1.begin(), sortedNums1.end(), nums2[i]) - sortedNums1.begin();
            if (j < n) {
                maxn = max(maxn, diff - (sortedNums1[j] - nums2[i]));
            }

            if (j > 0) {
                maxn = max(maxn, diff - (nums2[i] - sortedNums1[j - 1]));
            }
        }
        return (sum - maxn + mod) % mod;
    }
    static constexpr int mod = 1'000'000'007;
};
// @lc code=end



/*
// @lcpr case=start
// [1,7,5]\n[2,3,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,6,8,10]\n[2,4,6,8,10]\n
// @lcpr case=end

// @lcpr case=start
// [1,10,4,4,2,7]\n[9,3,5,1,7,4]\n
// @lcpr case=end

 */

