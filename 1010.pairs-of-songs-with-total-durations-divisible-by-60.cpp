/*
 * @lc app=leetcode.cn id=1010 lang=cpp
 * @lcpr version=30204
 *
 * [1010] 总持续时间可被 60 整除的歌曲
 *
 * https://leetcode.cn/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/
 *
 * algorithms
 * Medium (52.29%)
 * Likes:    331
 * Dislikes: 0
 * Total Accepted:    54.5K
 * Total Submissions: 104.1K
 * Testcase Example:  '[30,20,150,100,40]'
 *
 * 在歌曲列表中，第 i 首歌曲的持续时间为 time[i] 秒。
 * 
 * 返回其总持续时间（以秒为单位）可被 60 整除的歌曲对的数量。形式上，我们希望下标数字 i 和 j 满足  i < j 且有 (time[i] +
 * time[j]) % 60 == 0。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：time = [30,20,150,100,40]
 * 输出：3
 * 解释：这三对的总持续时间可被 60 整除：
 * (time[0] = 30, time[2] = 150): 总持续时间 180
 * (time[1] = 20, time[3] = 100): 总持续时间 120
 * (time[1] = 20, time[4] = 40): 总持续时间 60
 * 
 * 
 * 示例 2：
 * 
 * 输入：time = [60,60,60]
 * 输出：3
 * 解释：所有三对的总持续时间都是 120，可以被 60 整除。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= time.length <= 6 * 10^4
 * 1 <= time[i] <= 500
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
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0;
        unordered_map<int, int> mp;
        for (int t : time) {
            res += mp[(60 - t % 60) % 60];
            mp[t % 60]++;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [30,20,150,100,40]\n
// @lcpr case=end

// @lcpr case=start
// [60,60,60]\n
// @lcpr case=end

 */

