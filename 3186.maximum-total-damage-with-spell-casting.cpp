/*
 * @lc app=leetcode.cn id=3186 lang=cpp
 * @lcpr version=30204
 *
 * [3186] 施咒的最大总伤害
 *
 * https://leetcode.cn/problems/maximum-total-damage-with-spell-casting/description/
 *
 * algorithms
 * Medium (42.74%)
 * Likes:    100
 * Dislikes: 0
 * Total Accepted:    31K
 * Total Submissions: 72.5K
 * Testcase Example:  '[1,1,3,4]'
 *
 * 一个魔法师有许多不同的咒语。
 * 
 * 给你一个数组 power ，其中每个元素表示一个咒语的伤害值，可能会有多个咒语有相同的伤害值。
 * 
 * 已知魔法师使用伤害值为 power[i] 的咒语时，他们就 不能 使用伤害为 power[i] - 2 ，power[i] - 1 ，power[i]
 * + 1 或者 power[i] + 2 的咒语。
 * 
 * 每个咒语最多只能被使用 一次 。
 * 
 * 请你返回这个魔法师可以达到的伤害值之和的 最大值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：power = [1,1,3,4]
 * 
 * 输出：6
 * 
 * 解释：
 * 
 * 可以使用咒语 0，1，3，伤害值分别为 1，1，4，总伤害值为 6 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：power = [7,1,6,6]
 * 
 * 输出：13
 * 
 * 解释：
 * 
 * 可以使用咒语 1，2，3，伤害值分别为 1，6，6，总伤害值为 13 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= power.length <= 10^5
 * 1 <= power[i] <= 10^9
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
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> cnt;
        for (int x : power) {
            cnt[x]++;
        }

        vector<pair<int, int>> a(cnt.begin(), cnt.end());
        ranges::sort(a);

        int n = a.size();
        vector<long long> f(n + 1);
        for (int i = 0, j = 0; i < n; i++) {
            auto& [x, c] = a[i];
            while (a[j].first < x - 2) {
                j++;
            }
            f[i + 1] = max(f[i], f[j] + (long long)x * c);
        }
        return f[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,1,6,6]\n
// @lcpr case=end

 */

