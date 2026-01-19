/*
 * @lc app=leetcode.cn id=301 lang=cpp
 * @lcpr version=
 *
 * [301] 删除无效的括号
 *
 * https://leetcode.cn/problems/remove-invalid-parentheses/description/
 *
 * algorithms
 * Hard (56.04%)
 * Likes:    1001
 * Dislikes: 0
 * Total Accepted:    130.2K
 * Total Submissions: 232.3K
 * Testcase Example:  '"()())()"'
 *
 * 给你一个由若干括号和字母组成的字符串 s ，删除最小数量的无效括号，使得输入的字符串有效。
 * 
 * 返回所有可能的结果。答案可以按 任意顺序 返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "()())()"
 * 输出：["(())()","()()()"]
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "(a)())()"
 * 输出：["(a())()","(a)()()"]
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = ")("
 * 输出：[""]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 25
 * s 由小写英文字母以及括号 '(' 和 ')' 组成
 * s 中至多含 20 个括号
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
    vector<string> removeInvalidParentheses(string s) {
        int rmL = 0, rmR = 0; // rmL / rmR（删除额度）
        for (char c : s) {
            if (c == '(') rmL++;
            else if (c == ')') {
                if (rmL > 0) rmL--;
                else rmR++;
            }
        }

        unordered_set<string> seen;
        vector<string> res;
        string path;

        // bal = 当前 path 里，尚未被匹配的 '(' 的数量
        auto dfs = [&](auto&& self, int idx, int bal, int l, int r) -> void {
            if (idx == (int)s.size()) {
                if (bal == 0 && l == 0 && r == 0) {
                    if (seen.insert(path).second) res.push_back(path);
                }
                return;
            }

            char c = s[idx];

            if (c != '(' && c != ')') {
                path.push_back(c);
                self(self, idx + 1, bal, l, r);
                path.pop_back();
                return;
            }

            // option 1: delete this parenthesis if we still can
            if (c == '(' && l > 0) {
                self(self, idx + 1, bal, l - 1, r);
            }
            if (c == ')' && r > 0) {
                self(self, idx + 1, bal, l, r - 1);
            }

            // option 2: keep it
            if (c == '(') {
                path.push_back('(');
                self(self, idx + 1, bal + 1, l, r);
                path.pop_back();
            } else { // c == ')'
                if (bal > 0) { // must have a matching '('
                    path.push_back(')');
                    self(self, idx + 1, bal - 1, l, r);
                    path.pop_back();
                }
            }
        };

        dfs(dfs, 0, 0, rmL, rmR);
        return res;
    }
};

// @lc code=end



/*
// @lcpr case=start
// "()())()"\n
// @lcpr case=end

// @lcpr case=start
// "(a)())()"\n
// @lcpr case=end

// @lcpr case=start
// ")("\n
// @lcpr case=end

 */

