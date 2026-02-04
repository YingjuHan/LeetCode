/*
 * @lc app=leetcode.cn id=474 lang=cpp
 * @lcpr version=
 *
 * [474] 一和零
 *
 * https://leetcode.cn/problems/ones-and-zeroes/description/
 *
 * algorithms
 * Medium (67.73%)
 * Likes:    1321
 * Dislikes: 0
 * Total Accepted:    299.4K
 * Total Submissions: 441.7K
 * Testcase Example:  '["10","0001","111001","1","0"]\n5\n3'
 *
 * 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
 * 
 * 
 * 请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
 * 
 * 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
 * 输出：4
 * 解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
 * 其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1
 * ，大于 n 的值 3 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：strs = ["10", "0", "1"], m = 1, n = 1
 * 输出：2
 * 解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= strs.length <= 600
 * 1 <= strs[i].length <= 100
 * strs[i] 仅由 '0' 和 '1' 组成
 * 1 <= m, n <= 100
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
    int findMaxForm1(vector<string>& strs, int m, int n) {
        int l = strs.size();
        vector<int> cnt0(strs.size());
        for (int i = 0; i < l; i++) {
            cnt0[i] = ranges::count(strs[i], '0');
        }
        vector<vector<vector<int>>> memo(l, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> int {
            if (i < 0) {
                return 0;
            }
            int& res = memo[i][j][k];
            if (res != -1) {
                return res;
            }
            
            res = dfs(i - 1, j, k);
            int cnt1 = strs[i].length() - cnt0[i];
            if (j >= cnt0[i] && k >= cnt1) {
                res = max(res, dfs(i - 1, j - cnt0[i], k - cnt1) + 1);
            }
            return res;
        };
        return dfs(l - 1, m, n);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        vector<vector<vector<int>>> f(l + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for (int i = 0; i < l; i++) {
            int cnt0 = ranges::count(strs[i], '0');
            int cnt1 = strs[i].size() - cnt0;
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    if (j < cnt0 || k < cnt1) {
                        f[i + 1][j][k] = f[i][j][k];
                    } else {
                        f[i + 1][j][k] = max(f[i][j][k], f[i][j - cnt0][k - cnt1] + 1);
                    }
                }
            }
        }
        return f.back()[m][n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["10", "0001", "111001", "1", "0"]\n5\n3\n
// @lcpr case=end

// @lcpr case=start
// ["10", "0", "1"]\n1\n1\n
// @lcpr case=end

 */

