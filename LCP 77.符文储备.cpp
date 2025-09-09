/*
 * @lc app=leetcode.cn id=LCP 77 lang=cpp
 * @lcpr version=30204
 *
 * [LCP 77] 符文储备
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
    int runeReserve(vector<int>& runes) {
        sort(runes.begin(), runes.end());
        int res = 1;
        int count = 1;
        for (int i = 1; i < runes.size(); ++i)
        {
            if (runes[i] - runes[i - 1] > 1) {
                count = 1;
            } else {
                ++count;
                res = max(res, count);
            } 
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,5,4,1,7]`>\n
// @lcpr case=end

// @lcpr case=start
// [1,1,3,3,2,4]`>\n
// @lcpr case=end

 */

