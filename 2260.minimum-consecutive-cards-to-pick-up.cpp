/*
 * @lc app=leetcode.cn id=2260 lang=cpp
 * @lcpr version=30204
 *
 * [2260] 必须拿起的最小连续卡牌数
 *
 * https://leetcode.cn/problems/minimum-consecutive-cards-to-pick-up/description/
 *
 * algorithms
 * Medium (52.10%)
 * Likes:    37
 * Dislikes: 0
 * Total Accepted:    20.5K
 * Total Submissions: 36.9K
 * Testcase Example:  '[3,4,2,3,4,7]'
 *
 * 给你一个整数数组 cards ，其中 cards[i] 表示第 i 张卡牌的 值 。如果两张卡牌的值相同，则认为这一对卡牌 匹配 。
 * 
 * 返回你必须拿起的最小连续卡牌数，以使在拿起的卡牌中有一对匹配的卡牌。如果无法得到一对匹配的卡牌，返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：cards = [3,4,2,3,4,7]
 * 输出：4
 * 解释：拿起卡牌 [3,4,2,3] 将会包含一对值为 3 的匹配卡牌。注意，拿起 [4,2,3,4] 也是最优方案。
 * 
 * 示例 2：
 * 
 * 输入：cards = [1,0,5,3]
 * 输出：-1
 * 解释：无法找出含一对匹配卡牌的一组连续卡牌。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= cards.length <= 10^5
 * 0 <= cards[i] <= 10^6
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
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> mp;
        int res = INT_MAX;

        for (int i = 0; i < cards.size(); i++) {
            if (mp.count(cards[i])) {
                res = min(res, i - mp[cards[i]] + 1);
            }
            mp[cards[i]] = i;
        }
        return res == INT_MAX ? -1 : res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,4,2,3,4,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,5,3]\n
// @lcpr case=end

 */

