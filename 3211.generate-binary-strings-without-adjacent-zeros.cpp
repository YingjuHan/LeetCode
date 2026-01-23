/*
 * @lc app=leetcode.cn id=3211 lang=cpp
 * @lcpr version=30204
 *
 * [3211] 生成不含相邻零的二进制字符串
 *
 * https://leetcode.cn/problems/generate-binary-strings-without-adjacent-zeros/description/
 *
 * algorithms
 * Medium (88.22%)
 * Likes:    46
 * Dislikes: 0
 * Total Accepted:    31.6K
 * Total Submissions: 35.8K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n。
 * 
 * 如果一个二进制字符串 x 的所有长度为 2 的子字符串中包含 至少 一个 "1"，则称 x 是一个 有效 字符串。
 * 
 * 返回所有长度为 n 的 有效 字符串，可以以任意顺序排列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： n = 3
 * 
 * 输出： ["010","011","101","110","111"]
 * 
 * 解释：
 * 
 * 长度为 3 的有效字符串有："010"、"011"、"101"、"110" 和 "111"。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： n = 1
 * 
 * 输出： ["0","1"]
 * 
 * 解释：
 * 
 * 长度为 1 的有效字符串有："0" 和 "1"。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 18
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
    vector<string> validStrings(int n) {
        vector<string> res;
        string path(n, 0);

        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (i == n) {
                res.push_back(path);
                return;
            }

            path[i] = '1';
            dfs(i + 1);

            if (i == 0 || path[i - 1] == '1') {
                path[i] = '0';
                dfs(i + 1);
            }
        };

        dfs(0);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

