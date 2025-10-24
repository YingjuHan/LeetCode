/*
 * @lc app=leetcode.cn id=632 lang=cpp
 * @lcpr version=30204
 *
 * [632] 最小区间
 *
 * https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists/description/
 *
 * algorithms
 * Hard (64.40%)
 * Likes:    536
 * Dislikes: 0
 * Total Accepted:    45.4K
 * Total Submissions: 70.4K
 * Testcase Example:  '[[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]'
 *
 * 你有 k 个 非递减排列 的整数列表。找到一个 最小 区间，使得 k 个列表中的每个列表至少有一个数包含在其中。
 *
 * 我们定义如果 b-a < d-c 或者在 b-a == d-c 时 a < c，则区间 [a,b] 比 [c,d] 小。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
 * 输出：[20,24]
 * 解释：
 * 列表 1：[4, 10, 15, 24, 26]，24 在区间 [20,24] 中。
 * 列表 2：[0, 9, 12, 20]，20 在区间 [20,24] 中。
 * 列表 3：[5, 18, 22, 30]，22 在区间 [20,24] 中。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [[1,2,3],[1,2,3],[1,2,3]]
 * 输出：[1,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * nums.length == k
 * 1 <= k <= 3500
 * 1 <= nums[i].length <= 50
 * -10^5 <= nums[i][j] <= 10^5
 * nums[i] 按非递减顺序排列
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
class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < nums.size(); i++) {
            for (int x : nums[i]) {
                pairs.emplace_back(x, i);
            }
        }
        // 看上去 std::sort 比 ranges::sort 更快
        sort(pairs.begin(), pairs.end());

        int pairs_len = pairs.size();
        int res_left = pairs[0].first, res_right = pairs.back().first;
        int left = 0;
        int empty = nums.size(); // 用empty表示cnt[index] == 0的列表个数，index进入窗口之前如果cnt[index]为0，那么empty-1（空白的id就减少了），离开窗口后如果cnt[index]为0， empty+1，empty == 0 => cnt[i]都大于0
        vector<int> cnt(empty); // 索引为id，cnt[index]为对应id下的包含的数字个数，对于所有的索引都大于0就是包含所有编号

        for (auto [r_num, r_id] : pairs) {
            if (cnt[r_id] == 0) {
                empty--;
            }
            
            cnt[r_id]++;

            while (empty == 0) {
                auto [l_num, l_id] = pairs[left];
                if (r_num - l_num < res_right - res_left) {
                    res_right = r_num;
                    res_left = l_num;
                }
                cnt[l_id]--;
                if (cnt[l_id] == 0) {
                    empty++;
                }
                left++;
            }
        }
        return {res_left, res_right};
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[1,2,3],[1,2,3]]\n
// @lcpr case=end

 */
