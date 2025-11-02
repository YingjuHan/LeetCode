/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 * @lcpr version=30204
 *
 * [1128] 等价多米诺骨牌对的数量
 *
 * https://leetcode.cn/problems/number-of-equivalent-domino-pairs/description/
 *
 * algorithms
 * Easy (54.49%)
 * Likes:    204
 * Dislikes: 0
 * Total Accepted:    66.6K
 * Total Submissions: 113K
 * Testcase Example:  '[[1,2],[2,1],[3,4],[5,6]]'
 *
 * 给你一组多米诺骨牌 dominoes 。
 * 
 * 形式上，dominoes[i] = [a, b] 与 dominoes[j] = [c, d] 等价 当且仅当 (a == c 且 b == d) 或者
 * (a == d 且 b == c) 。即一张骨牌可以通过旋转 0 度或 180 度得到另一张多米诺骨牌。
 * 
 * 在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i] 和 dominoes[j] 等价的骨牌对
 * (i, j) 的数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：dominoes = [[1,2],[2,1],[3,4],[5,6]]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 输入：dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= dominoes.length <= 4 * 10^4
 * dominoes[i].length == 2
 * 1 <= dominoes[i][j] <= 9
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
struct PairHash {
    template <typename T1, typename T2>
    size_t operator()(const pair<T1,T2>& p) const{
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int res = 0;
        unordered_map<pair<int, int>, int, PairHash> mp;
        for (auto& dominoe : dominoes) {
            res += mp[{dominoe[0], dominoe[1]}];

            if (dominoe[0] != dominoe[1]) {
                res += mp[{dominoe[1], dominoe[0]}];
            }
            mp[{dominoe[0], dominoe[1]}]++;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[2,1],[3,4],[5,6]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[1,2],[1,1],[1,2],[2,2]]\n
// @lcpr case=end

 */

