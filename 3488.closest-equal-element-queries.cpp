/*
 * @lc app=leetcode.cn id=3488 lang=cpp
 * @lcpr version=30204
 *
 * [3488] 距离最小相等元素查询
 *
 * https://leetcode.cn/problems/closest-equal-element-queries/description/
 *
 * algorithms
 * Medium (39.89%)
 * Likes:    17
 * Dislikes: 0
 * Total Accepted:    6.9K
 * Total Submissions: 17.3K
 * Testcase Example:  '[1,3,1,4,1,3,2]\n[0,3,5]'
 *
 * 给你一个 环形 数组 nums 和一个数组 queries 。
 * 
 * 对于每个查询 i ，你需要找到以下内容：
 * 
 * 
 * 数组 nums 中下标 queries[i] 处的元素与 任意 其他下标 j（满足 nums[j] == nums[queries[i]]）之间的 最小
 * 距离。如果不存在这样的下标 j，则该查询的结果为 -1 。
 * 
 * 
 * 返回一个数组 answer，其大小与 queries 相同，其中 answer[i] 表示查询i的结果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： nums = [1,3,1,4,1,3,2], queries = [0,3,5]
 * 
 * 输出： [2,-1,3]
 * 
 * 解释：
 * 
 * 
 * 查询 0：下标 queries[0] = 0 处的元素为 nums[0] = 1 。最近的相同值下标为 2，距离为 2。
 * 查询 1：下标 queries[1] = 3 处的元素为 nums[3] = 4 。不存在其他包含值 4 的下标，因此结果为 -1。
 * 查询 2：下标 queries[2] = 5 处的元素为 nums[5] = 3 。最近的相同值下标为 1，距离为 3（沿着循环路径：5 -> 6 ->
 * 0 -> 1）。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： nums = [1,2,3,4], queries = [0,1,2,3]
 * 
 * 输出： [-1,-1,-1,-1]
 * 
 * 解释：
 * 
 * 数组 nums 中的每个值都是唯一的，因此没有下标与查询的元素值相同。所有查询的结果均为 -1。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= queries.length <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^6
 * 0 <= queries[i] < nums.length
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
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].emplace_back(i);
        }

        int n = nums.size();
        for (auto& [_, p] : mp) {
            // 前后各加一个哨兵
            int i0 = p[0];
            p.insert(p.begin(), p.back() - n);
            p.emplace_back(i0 + n);
        }

        // 我们在 p 中二分查找下标 query，设二分返回值为 j，那么
        // p[j−1] 就是在 query 左边的最近位置。
        // p[j+1] 就是在 query 右边的最近位置
        vector<int> res;
        for (int& query : queries) {
            auto& p = mp[nums[query]];
            if (p.size() == 3) { // 在 nums 中只出现了一次(前后右两个哨兵，1+2 = 3)
                res.emplace_back(-1);
            } else {
                int j = lower_bound(p.begin(), p.end(), query) - p.begin();
                res.emplace_back(min(query - p[j - 1], p[j + 1] - query));
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,1,4,1,3,2]\n[0,3,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n[0,1,2,3]\n
// @lcpr case=end

 */

