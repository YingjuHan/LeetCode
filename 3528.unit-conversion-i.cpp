/*
 * @lc app=leetcode.cn id=3528 lang=cpp
 * @lcpr version=30204
 *
 * [3528] 单位转换 I
 *
 * https://leetcode.cn/problems/unit-conversion-i/description/
 *
 * algorithms
 * Medium (47.00%)
 * Likes:    7
 * Dislikes: 0
 * Total Accepted:    2K
 * Total Submissions: 4.2K
 * Testcase Example:  '[[0,1,2],[1,2,3]]'
 *
 * 有 n 种单位，编号从 0 到 n - 1。给你一个二维整数数组 conversions，长度为 n - 1，其中 conversions[i] =
 * [sourceUniti, targetUniti, conversionFactori] ，表示一个 sourceUniti 类型的单位等于
 * conversionFactori 个 targetUniti 类型的单位。
 * 
 * 请你返回一个长度为 n 的数组 baseUnitConversion，其中 baseUnitConversion[i] 表示 一个 0
 * 类型单位等于多少个 i 类型单位。由于结果可能很大，请返回每个 baseUnitConversion[i] 对 10^9 + 7 取模后的值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： conversions = [[0,1,2],[1,2,3]]
 * 
 * 输出： [1,2,6]
 * 
 * 解释：
 * 
 * 
 * 使用 conversions[0]：将一个 0 类型单位转换为 2 个 1 类型单位。
 * 使用 conversions[0] 和 conversions[1] 将一个 0 类型单位转换为 6 个 2 类型单位。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： conversions = [[0,1,2],[0,2,3],[1,3,4],[1,4,5],[2,5,2],[4,6,3],[5,7,4]]
 * 
 * 输出： [1,2,3,8,10,6,30,24]
 * 
 * 解释：
 * 
 * 
 * 使用 conversions[0] 将一个 0 类型单位转换为 2 个 1 类型单位。
 * 使用 conversions[1] 将一个 0 类型单位转换为 3 个 2 类型单位。
 * 使用 conversions[0] 和 conversions[2] 将一个 0 类型单位转换为 8 个 3 类型单位。
 * 使用 conversions[0] 和 conversions[3] 将一个 0 类型单位转换为 10 个 4 类型单位。
 * 使用 conversions[1] 和 conversions[4] 将一个 0 类型单位转换为 6 个 5 类型单位。
 * 使用 conversions[0]、conversions[3] 和 conversions[5] 将一个 0 类型单位转换为 30 个 6
 * 类型单位。
 * 使用 conversions[1]、conversions[4] 和 conversions[6] 将一个 0 类型单位转换为 24 个 7
 * 类型单位。
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= n <= 10^5
 * conversions.length == n - 1
 * 0 <= sourceUniti, targetUniti < n
 * 1 <= conversionFactori <= 10^9
 * 保证单位 0 可以通过 唯一 的转换路径（不需要反向转换）转换为任何其他单位。
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
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        const int MOD = 1'000'000'007;
        int n = conversions.size() + 1;
        vector<vector<pair<int, int>>> g(n);
        for (auto& edge : conversions) {
            g[edge[0]].emplace_back(edge[1], edge[2]);
        }
        vector<int> res(n);
        auto dfs = [&](this auto&& dfs, int x, long long mul) ->void {
            res[x] = mul;
            for (auto& [y, weight] : g[x]) {
                dfs(y, mul * weight % MOD);
            }
        };
        dfs(0, 1);
        return res;  
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,2],[1,2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,2],[0,2,3],[1,3,4],[1,4,5],[2,5,2],[4,6,3],[5,7,4]]\n
// @lcpr case=end

 */

