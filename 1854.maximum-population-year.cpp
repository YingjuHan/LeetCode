/*
 * @lc app=leetcode.cn id=1854 lang=cpp
 * @lcpr version=
 *
 * [1854] 人口最多的年份
 *
 * https://leetcode.cn/problems/maximum-population-year/description/
 *
 * algorithms
 * Easy (71.49%)
 * Likes:    91
 * Dislikes: 0
 * Total Accepted:    25.7K
 * Total Submissions: 35.9K
 * Testcase Example:  '[[1993,1999],[2000,2010]]'
 *
 * 给你一个二维整数数组 logs ，其中每个 logs[i] = [birthi, deathi] 表示第 i 个人的出生和死亡年份。
 * 
 * 年份 x 的 人口 定义为这一年期间活着的人的数目。第 i 个人被计入年份 x 的人口需要满足：x 在闭区间 [birthi, deathi - 1]
 * 内。注意，人不应当计入他们死亡当年的人口中。
 * 
 * 返回 人口最多 且 最早 的年份。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：logs = [[1993,1999],[2000,2010]]
 * 输出：1993
 * 解释：人口最多为 1 ，而 1993 是人口为 1 的最早年份。
 * 
 * 
 * 示例 2：
 * 
 * 输入：logs = [[1950,1961],[1960,1971],[1970,1981]]
 * 输出：1960
 * 解释： 
 * 人口最多为 2 ，分别出现在 1960 和 1970 。
 * 其中最早年份是 1960 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= logs.length <= 100
 * 1950 <= birthi < deathi <= 2050
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
    static constexpr int offset = 1950;   // 起始年份与起始下标之差
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> diff(101, 0);
        for (auto& log : logs) {
            diff[log[0] - offset]++;
            diff[log[1] - offset]--; // 人不应当计入他们死亡当年的人口中，因此不是diff[log[1] - offset + 1]--
        }
        int mx = 0, curr = 0, res = 0;
        for (int i = 0; i <= 100; i++) {
            curr += diff[i];
            if (curr > mx) {
                mx = curr;
                res = i;
            }
        }
        return res + offset;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1993,1999],[2000,2010]]\n
// @lcpr case=end

// @lcpr case=start
// [[1950,1961],[1960,1971],[1970,1981]]\n
// @lcpr case=end

 */

