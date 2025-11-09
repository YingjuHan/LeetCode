/*
 * @lc app=leetcode.cn id=2055 lang=cpp
 * @lcpr version=30204
 *
 * [2055] 蜡烛之间的盘子
 *
 * https://leetcode.cn/problems/plates-between-candles/description/
 *
 * algorithms
 * Medium (44.02%)
 * Likes:    203
 * Dislikes: 0
 * Total Accepted:    40.1K
 * Total Submissions: 89.5K
 * Testcase Example:  '"**|**|***|"\n[[2,5],[5,9]]'
 *
 * 给你一个长桌子，桌子上盘子和蜡烛排成一列。给你一个下标从 0 开始的字符串 s ，它只包含字符 '*' 和 '|' ，其中 '*' 表示一个 盘子
 * ，'|' 表示一支 蜡烛 。
 * 
 * 同时给你一个下标从 0 开始的二维整数数组 queries ，其中 queries[i] = [lefti, righti] 表示 子字符串
 * s[lefti...righti] （包含左右端点的字符）。对于每个查询，你需要找到 子字符串中 在 两支蜡烛之间 的盘子的 数目 。如果一个盘子在
 * 子字符串中 左边和右边 都 至少有一支蜡烛，那么这个盘子满足在 两支蜡烛之间 。
 * 
 * 
 * 比方说，s = "||**||**|*" ，查询 [3, 8] ，表示的是子字符串 "*||**|" 。子字符串中在两支蜡烛之间的盘子数目为 2
 * ，子字符串中右边两个盘子在它们左边和右边 都 至少有一支蜡烛。
 * 
 * 
 * 请你返回一个整数数组 answer ，其中 answer[i] 是第 i 个查询的答案。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 输入：s = "**|**|***|", queries = [[2,5],[5,9]]
 * 输出：[2,3]
 * 解释：
 * - queries[0] 有两个盘子在蜡烛之间。
 * - queries[1] 有三个盘子在蜡烛之间。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 
 * 输入：s = "***|**|*****|**||**|*", queries =
 * [[1,17],[4,5],[14,17],[5,11],[15,16]]
 * 输出：[9,0,0,0,0]
 * 解释：
 * - queries[0] 有 9 个盘子在蜡烛之间。
 * - 另一个查询没有盘子在蜡烛之间。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= s.length <= 10^5
 * s 只包含字符 '*' 和 '|' 。
 * 1 <= queries.length <= 10^5
 * queries[i].length == 2
 * 0 <= lefti <= righti < s.length
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
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> preSum(n + 1, 0);
        vector<int> left(n, 0), right(n, 0);
        int p = -1;
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i];
            if (s[i] == '|') {
                p = i;
            } else {
                preSum[i + 1]++;
            }
            left[i] = p;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '|') {
                p = i;
            }
            right[i] = p;
        }

        vector<int> res(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            vector<int> q = queries[i];
            int l = right[q[0]];
            int r = left[q[1]];
            if (r > l) {
                res[i] = preSum[r] - preSum[l];
            }
            
        }
        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// "**|**|***|"\n[[2,5],[5,9]]\n
// @lcpr case=end

// @lcpr case=start
// "***|**|*****|**||**|*"\n[[1,17],[4,5],[14,17],[5,11],[15,16]]\n
// @lcpr case=end

 */

