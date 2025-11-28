/*
 * @lc app=leetcode.cn id=1673 lang=cpp
 * @lcpr version=30204
 *
 * [1673] 找出最具竞争力的子序列
 *
 * https://leetcode.cn/problems/find-the-most-competitive-subsequence/description/
 *
 * algorithms
 * Medium (50.91%)
 * Likes:    195
 * Dislikes: 0
 * Total Accepted:    33.4K
 * Total Submissions: 65.6K
 * Testcase Example:  '[3,5,2,6]\n2'
 *
 * 给你一个整数数组 nums 和一个正整数 k ，返回长度为 k 且最具 竞争力 的 nums 子序列。
 * 
 * 数组的子序列是从数组中删除一些元素（可能不删除元素）得到的序列。
 * 
 * 在子序列 a 和子序列 b 第一个不相同的位置上，如果 a 中的数字小于 b 中对应的数字，那么我们称子序列 a 比子序列 b（相同长度下）更具 竞争力
 * 。 例如，[1,3,4] 比 [1,3,5] 更具竞争力，在第一个不相同的位置，也就是最后一个位置上， 4 小于 5 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [3,5,2,6], k = 2
 * 输出：[2,6]
 * 解释：在所有可能的子序列集合 {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]} 中，[2,6] 最具竞争力。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [2,4,3,3,5,4,9,6], k = 4
 * 输出：[2,3,3,4]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^9
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
    // 返回 nums 的长度恰好为 k 的字典序最小子序列
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            while (!res.empty() && x < res.back() && nums.size() - i + res.size() > k) {
                res.pop_back();
            }
            res.push_back(x);
        }
        res.resize(k);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,2,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3,3,5,4,9,6]\n4\n
// @lcpr case=end

 */

