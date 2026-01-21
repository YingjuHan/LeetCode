/*
 * @lc app=leetcode.cn id=1079 lang=cpp
 * @lcpr version=
 *
 * [1079] 活字印刷
 *
 * https://leetcode.cn/problems/letter-tile-possibilities/description/
 *
 * algorithms
 * Medium (79.13%)
 * Likes:    295
 * Dislikes: 0
 * Total Accepted:    38.7K
 * Total Submissions: 48.9K
 * Testcase Example:  '"AAB"'
 *
 * 你有一套活字字模 tiles，其中每个字模上都刻有一个字母 tiles[i]。返回你可以印出的非空字母序列的数目。
 * 
 * 注意：本题中，每个活字字模只能使用一次。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："AAB"
 * 输出：8
 * 解释：可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"。
 * 
 * 
 * 示例 2：
 * 
 * 输入："AAABBC"
 * 输出：188
 * 
 * 
 * 示例 3：
 * 
 * 输入："V"
 * 输出：1
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= tiles.length <= 7
 * tiles 由大写英文字母组成
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
#include <set>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> cnt;
        set<char> tile;
        int n = tiles.length();
        for (char c : tiles) {
            cnt[c]++;
            tile.insert(c);
        }

        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i == 0) {
                return 1;
            }
            int res = 1;
            for (char t : tile) {
                if (cnt[t] > 0) {
                    cnt[t]--;
                    res += dfs(i - 1);
                    cnt[t]++;
                }
            }
        };
        return dfs(n) - 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "AAB"\n
// @lcpr case=end

// @lcpr case=start
// "AAABBC"\n
// @lcpr case=end

// @lcpr case=start
// "V"\n
// @lcpr case=end

 */

