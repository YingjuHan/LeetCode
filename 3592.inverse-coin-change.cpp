/*
 * @lc app=leetcode.cn id=3592 lang=cpp
 * @lcpr version=30204
 *
 * [3592] 硬币面值还原
 *
 * https://leetcode.cn/problems/inverse-coin-change/description/
 *
 * algorithms
 * Medium (65.34%)
 * Likes:    18
 * Dislikes: 0
 * Total Accepted:    3.2K
 * Total Submissions: 4.8K
 * Testcase Example:  '[0,1,0,2,0,3,0,4,0,5]'
 *
 * 给你一个 从 1 开始计数 的整数数组 numWays，其中 numWays[i] 表示使用某些 固定 面值的硬币（每种面值可以使用无限次）凑出总金额
 * i 的方法数。每种面值都是一个 正整数 ，并且其值 最多 为 numWays.length。
 * 
 * 然而，具体的硬币面值已经 丢失 。你的任务是还原出可能生成这个 numWays 数组的面值集合。
 * 
 * 返回一个按从小到大顺序排列的数组，其中包含所有可能的 唯一 整数面值。
 * 
 * 如果不存在这样的集合，返回一个 空 数组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： numWays = [0,1,0,2,0,3,0,4,0,5]
 * 
 * 输出： [2,4,6]
 * 
 * 解释：
 * 
 * 
 * 
 * 
 * 金额
 * 方法数
 * 解释
 * 
 * 
 * 1
 * 0
 * 无法用硬币凑出总金额 1。
 * 
 * 
 * 2
 * 1
 * 唯一的方法是 [2]。
 * 
 * 
 * 3
 * 0
 * 无法用硬币凑出总金额 3。
 * 
 * 
 * 4
 * 2
 * 可以用 [2, 2] 或 [4]。
 * 
 * 
 * 5
 * 0
 * 无法用硬币凑出总金额 5。
 * 
 * 
 * 6
 * 3
 * 可以用 [2, 2, 2]、[2, 4] 或 [6]。
 * 
 * 
 * 7
 * 0
 * 无法用硬币凑出总金额 7。
 * 
 * 
 * 8
 * 4
 * 可以用 [2, 2, 2, 2]、[2, 2, 4]、[2, 6] 或 [4, 4]。
 * 
 * 
 * 9
 * 0
 * 无法用硬币凑出总金额 9。
 * 
 * 
 * 10
 * 5
 * 可以用 [2, 2, 2, 2, 2]、[2, 2, 2, 4]、[2, 4, 4]、[2, 2, 6] 或 [4,
 * 6]。
 * 
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： numWays = [1,2,2,3,4]
 * 
 * 输出： [1,2,5]
 * 
 * 解释：
 * 
 * 
 * 
 * 
 * 金额
 * 方法数
 * 解释
 * 
 * 
 * 1
 * 1
 * 唯一的方法是 [1]。
 * 
 * 
 * 2
 * 2
 * 可以用 [1, 1] 或 [2]。
 * 
 * 
 * 3
 * 2
 * 可以用 [1, 1, 1] 或 [1, 2]。
 * 
 * 
 * 4
 * 3
 * 可以用 [1, 1, 1, 1]、[1, 1, 2] 或 [2, 2]。
 * 
 * 
 * 5
 * 4
 * 可以用 [1, 1, 1, 1, 1]、[1, 1, 1, 2]、[1, 2, 2] 或 [5]。
 * 
 * 
 * 
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入： numWays = [1,2,3,4,15]
 * 
 * 输出： []
 * 
 * 解释：
 * 
 * 没有任何面值集合可以生成该数组。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= numWays.length <= 100
 * 0 <= numWays[i] <= 2 * 10^8
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
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        int mx = *max_element(numWays.begin(), numWays.end());
        vector<int> f(n + 1);
        f[0] = 1;
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            int ways = numWays[i - 1];
            if (ways == f[i]) {
                continue;
            }
            if (ways - 1 != f[i]) {
                return {};
            }
            ans.push_back(i);
            for (int j = i; j <= n; j++) {
                f[j] += f[j - i]; // 因为“新增一枚面额 i”的贡献来自“凑出 j-i 的所有方案
                if (f[j] > mx) {
                    return {};
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,2,0,3,0,4,0,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,15]\n
// @lcpr case=end

 */

