/*
 * @lc app=leetcode.cn id=3181 lang=cpp
 * @lcpr version=
 *
 * [3181] 执行操作可获得的最大总奖励 II
 *
 * https://leetcode.cn/problems/maximum-total-reward-using-operations-ii/description/
 *
 * algorithms
 * Hard (43.12%)
 * Likes:    41
 * Dislikes: 0
 * Total Accepted:    15.5K
 * Total Submissions: 36K
 * Testcase Example:  '[1,1,3,3]'
 *
 * 给你一个整数数组 rewardValues，长度为 n，代表奖励的值。
 * 
 * 最初，你的总奖励 x 为 0，所有下标都是 未标记 的。你可以执行以下操作 任意次 ：
 * 
 * 
 * 从区间 [0, n - 1] 中选择一个 未标记 的下标 i。
 * 如果 rewardValues[i] 大于 你当前的总奖励 x，则将 rewardValues[i] 加到 x 上（即 x = x +
 * rewardValues[i]），并 标记 下标 i。
 * 
 * 
 * 以整数形式返回执行最优操作能够获得的 最大 总奖励。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：rewardValues = [1,1,3,3]
 * 
 * 输出：4
 * 
 * 解释：
 * 
 * 依次标记下标 0 和 2，总奖励为 4，这是可获得的最大值。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：rewardValues = [1,6,4,3,2]
 * 
 * 输出：11
 * 
 * 解释：
 * 
 * 依次标记下标 0、2 和 1。总奖励为 11，这是可获得的最大值。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= rewardValues.length <= 5 * 10^4
 * 1 <= rewardValues[i] <= 5 * 10^4
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
    // 未优化 超时
    int maxTotalReward(vector<int>& rewardValues) {
        ranges::sort(rewardValues);
        rewardValues.erase(ranges::unique(rewardValues).begin(), rewardValues.end());

        int n = rewardValues.size();
        int m = *max_element(rewardValues.begin(), rewardValues.end());

        vector<vector<char>> f(n + 1, vector<char>(2 * m, 0));
        f[0][0] = 1;

        for (int i = 0; i < n; i++) {
            int x = rewardValues[i];

            // 先把上一层拷贝到下一层（不选 x）
            for (int s = 0; s < 2 * m; s++) f[i + 1][s] = f[i][s];

            // 选 x：要求旧和 t < x，所以新和 s=t+x 在 [x, 2x-1]
            for (int s = 2 * x - 1; s >= x; s--) {
                if (f[i][s - x]) f[i + 1][s] = 1;
            }
        }

        int ans = 2 * m - 1;
        while (ans >= 0 && !f[n][ans]) ans--;
        return ans;
    }

    // 优化
    int maxTotalReward(vector<int>& rewardValues) {
        ranges::sort(rewardValues);
        rewardValues.erase(ranges::unique(rewardValues).begin(), rewardValues.end());

        bitset<100000> f{1};
        for (int v : rewardValues) {
            int shift = f.size() - v;
            // 左移 shift 再右移 shift，把所有 >= v 的比特位置 0
            // f |= f << shift >> shift << v;
            f |= f << shift >> (shift - v); // 简化上式
        }
        for (int i = rewardValues.back() * 2 - 1; ; i--) {
            if (f[i]) {
                return i;
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,6,4,3,2]\n
// @lcpr case=end

 */

