/*
 * @lc app=leetcode.cn id=473 lang=cpp
 * @lcpr version=30204
 *
 * [473] 火柴拼正方形
 *
 * https://leetcode.cn/problems/matchsticks-to-square/description/
 *
 * algorithms
 * Medium (47.05%)
 * Likes:    574
 * Dislikes: 0
 * Total Accepted:    88K
 * Total Submissions: 187K
 * Testcase Example:  '[1,1,2,2,2]'
 *
 * 你将得到一个整数数组 matchsticks ，其中 matchsticks[i] 是第 i 个火柴棒的长度。你要用 所有的火柴棍 拼成一个正方形。你
 * 不能折断 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须 使用一次 。
 * 
 * 如果你能使这个正方形，则返回 true ，否则返回 false 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 输入: matchsticks = [1,1,2,2,2]
 * 输出: true
 * 解释: 能拼成一个边长为2的正方形，每边两根火柴。
 * 
 * 
 * 示例 2:
 * 
 * 输入: matchsticks = [3,3,3,3,4]
 * 输出: false
 * 解释: 不能用所有火柴拼成一个正方形。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= matchsticks.length <= 15
 * 1 <= matchsticks[i] <= 10^8
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
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if (n < 4) return false;

        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4) return false;

        sort(matchsticks.begin(), matchsticks.end(), greater<int>());

        vector<int> batch(4);

        int target = sum / 4;

        auto dfs = [&](this auto&& dfs, int x) -> bool {
            if (x >= n) {
                return batch[0] == target && batch[1] == target && batch[2] == target && batch[3] == target;
            }

            for (int i = 0; i < 4; i++) {
                if (batch[i] + matchsticks[x] > target) continue;
                batch[i] += matchsticks[x];
                if (dfs(x + 1)) return true;
                batch[i] -= matchsticks[x];
            }
            return false;
        };

        return dfs(0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,3,3,4]\n
// @lcpr case=end

 */

