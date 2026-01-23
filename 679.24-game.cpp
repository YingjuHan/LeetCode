/*
 * @lc app=leetcode.cn id=679 lang=cpp
 * @lcpr version=30204
 *
 * [679] 24 点游戏
 *
 * https://leetcode.cn/problems/24-game/description/
 *
 * algorithms
 * Hard (56.22%)
 * Likes:    520
 * Dislikes: 0
 * Total Accepted:    58.4K
 * Total Submissions: 103.9K
 * Testcase Example:  '[4,1,8,7]'
 *
 * 给定一个长度为4的整数数组 cards 。你有 4 张卡片，每张卡片上都包含一个范围在 [1,9] 的数字。您应该使用运算符 ['+', '-',
 * '*', '/'] 和括号 '(' 和 ')' 将这些卡片上的数字排列成数学表达式，以获得值24。
 * 
 * 你须遵守以下规则:
 * 
 * 
 * 除法运算符 '/' 表示实数除法，而不是整数除法。
 * 
 * 
 * 例如， 4 /(1 - 2 / 3)= 4 /(1 / 3)= 12 。
 * 
 * 
 * 每个运算都在两个数字之间。特别是，不能使用 “-” 作为一元运算符。
 * 
 * 例如，如果 cards =[1,1,1,1] ，则表达式 “-1 -1 -1 -1” 是 不允许 的。
 * 
 * 
 * 你不能把数字串在一起
 * 
 * 例如，如果 cards =[1,2,1,2] ，则表达式 “12 + 12” 无效。
 * 
 * 
 * 
 * 
 * 如果可以得到这样的表达式，其计算结果为 24 ，则返回 true ，否则返回 false 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: cards = [4, 1, 8, 7]
 * 输出: true
 * 解释: (8-4) * (7-1) = 24
 * 
 * 
 * 示例 2:
 * 
 * 输入: cards = [1, 2, 1, 2]
 * 输出: false
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * cards.length == 4
 * 1 <= cards[i] <= 9
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
    static constexpr double EPS = 1e-9; 
    bool judgePoint24(vector<int>& cards) {
        vector<double> cards_d(cards.begin(), cards.end());

        auto dfs = [&](this auto&& dfs, vector<double>& cards_d) -> bool {
            int n = cards_d.size();
            if (n == 1) {
                return abs(cards_d[0] - 24) < EPS;
            }

            for (int i = 0; i < n; i++) {
                double x = cards_d[i];
                for (int j = i + 1; j < n; j++) {
                    double y = cards_d[j];

                    vector<double> candidates = {x + y, x - y, y - x, x * y};
                    if (abs(y) > EPS) {
                        candidates.emplace_back(x / y);
                    }
                    if (abs(x) > EPS) {
                        candidates.emplace_back(y / x);
                    }

                    auto new_cards_d = cards_d;
                    new_cards_d.erase(new_cards_d.begin() + j);
                    for (double res : candidates) {
                        new_cards_d[i] = res;

                        if (dfs(new_cards_d)) {
                            return true;
                        }
                    }
                }
            }
            return false;
        };
        return dfs(cards_d);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4, 1, 8, 7]\n
// @lcpr case=end

// @lcpr case=start
// [1, 2, 1, 2]\n
// @lcpr case=end

 */

