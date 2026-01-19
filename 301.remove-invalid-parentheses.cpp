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
        int l = 0, r = 0;
        for (char c : s) {
            if (c == '(')  {
                l++;
            } else if (c == ')') {
                r++;
            }
        }
        vector<string> res;
        string path;
        auto check = [](string s) -> bool {
            int l = 0, r = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '(') l++;
                else if (s[i] == ')') {
                    if (l == 0) {
                        r++;
                    } else {
                        l--;
                    }
                }
            }
            if (l == 0 && r == 0) {
                return true;
            }
            return false;
        };
        auto dfs = [&](this auto&& dfs, int i) {
            if (i == s.length()) {
                if (check(path)) {
                    res.emplace_back(path);
                    return;
                }
            }

            if (s[i] != '(' && s[i] != ')') {
                path += s[i];
                dfs(i + 1);
                path.erase(path.size() - 1);
            } else if (s[i] == '(') {
                int k = i;
                while (k < s.size() && s[k] == '(') {
                    k++;
                }
                l -= k - i;
                for (int i = 0; i <= k - i; i++) {
                    if (l >= 0) {
                        dfs(k);
                    }
                    path += '(';
                    l++;
                }
            } else if (s[i] == ')') {
                int k = i;
                while (k < s.size() && s[k] == ')') {
                    k++;
                }
                r -= k - i;
                for (int i = 0; i <= k - i; i++) {
                    if (r >= 0) {
                        dfs(k);
                    }
                    path += ')';
                    r++;
                }
            }
        };

        dfs(0);
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

