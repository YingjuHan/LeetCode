/*
 * @lc app=leetcode.cn id=282 lang=cpp
 * @lcpr version=30204
 *
 * [282] 给表达式添加运算符
 *
 * https://leetcode.cn/problems/expression-add-operators/description/
 *
 * algorithms
 * Hard (46.85%)
 * Likes:    509
 * Dislikes: 0
 * Total Accepted:    32.4K
 * Total Submissions: 69.1K
 * Testcase Example:  '"123"\n6'
 *
 * 给定一个仅包含数字 0-9 的字符串 num 和一个目标值整数 target ，在 num 的数字之间添加 二元 运算符（不是一元）+、- 或 *
 * ，返回 所有 能够得到 target 的表达式。
 * 
 * 注意，返回表达式中的操作数 不应该 包含前导零。
 * 
 * 注意，一个数字可以包含多个数位。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: num = "123", target = 6
 * 输出: ["1+2+3", "1*2*3"] 
 * 解释: “1*2*3” 和 “1+2+3” 的值都是6。
 * 
 * 
 * 示例 2:
 * 
 * 输入: num = "232", target = 8
 * 输出: ["2*3+2", "2+3*2"]
 * 解释: “2*3+2” 和 “2+3*2” 的值都是8。
 * 
 * 
 * 示例 3:
 * 
 * 输入: num = "3456237490", target = 9191
 * 输出: []
 * 解释: 表达式 “3456237490” 无法得到 9191 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num.length <= 10
 * num 仅含数字
 * -2^31 <= target <= 2^31 - 1
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
    vector<string> addOperators(string num, int target) {
        int n = num.size();
        vector<string> res;

        auto dfs = [&](this auto&& dfs, int d, long long pre, long long sum, string s) {
            if (d == n) {
                if (sum == target) {
                    res.emplace_back(s);
                }
                return;
            }

            long long val = 0;
            for (int i = d; i < n; i++) {
                
                // 禁止前导0
                if (i != d && num[d] == '0') {
                    break;
                }
                int x = num[i] - '0';
                val = val * 10 + x;
                
                if (d == 0) {
                    dfs(i + 1, val, val, to_string(val));
                } else {
                    dfs(i + 1, pre * val, sum - pre + pre * val, s + "*" + to_string(val));
                    dfs(i + 1, val, sum + val, s + "+" + to_string(val));
                    dfs(i + 1, -val, sum - val, s + "-" + to_string(val));
                }
            }
        };

        dfs(0, 0, 0, "");
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "123"\n6\n
// @lcpr case=end

// @lcpr case=start
// "232"\n8\n
// @lcpr case=end

// @lcpr case=start
// "3456237490"\n9191\n
// @lcpr case=end

 */

