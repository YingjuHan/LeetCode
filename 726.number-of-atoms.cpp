/*
 * @lc app=leetcode.cn id=726 lang=cpp
 * @lcpr version=30204
 *
 * [726] 原子的数量
 *
 * https://leetcode.cn/problems/number-of-atoms/description/
 *
 * algorithms
 * Hard (55.49%)
 * Likes:    323
 * Dislikes: 0
 * Total Accepted:    32.1K
 * Total Submissions: 57.6K
 * Testcase Example:  '"H2O"'
 *
 * 给你一个字符串化学式 formula ，返回 每种原子的数量 。
 * 
 * 原子总是以一个大写字母开始，接着跟随 0 个或任意个小写字母，表示原子的名字。
 * 
 * 如果数量大于 1，原子后会跟着数字表示原子的数量。如果数量等于 1 则不会跟数字。
 * 
 * 
 * 例如，"H2O" 和 "H2O2" 是可行的，但 "H1O2" 这个表达是不可行的。
 * 
 * 
 * 两个化学式连在一起可以构成新的化学式。
 * 
 * 
 * 例如 "H2O2He3Mg4" 也是化学式。
 * 
 * 
 * 由括号括起的化学式并佐以数字（可选择性添加）也是化学式。
 * 
 * 
 * 例如 "(H2O2)" 和 "(H2O2)3" 是化学式。
 * 
 * 
 * 返回所有原子的数量，格式为：第一个（按字典序）原子的名字，跟着它的数量（如果数量大于
 * 1），然后是第二个原子的名字（按字典序），跟着它的数量（如果数量大于 1），以此类推。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：formula = "H2O"
 * 输出："H2O"
 * 解释：原子的数量是 {'H': 2, 'O': 1}。
 * 
 * 
 * 示例 2：
 * 
 * 输入：formula = "Mg(OH)2"
 * 输出："H2MgO2"
 * 解释：原子的数量是 {'H': 2, 'Mg': 1, 'O': 2}。
 * 
 * 
 * 示例 3：
 * 
 * 输入：formula = "K4(ON(SO3)2)2"
 * 输出："K4N2O14S4"
 * 解释：原子的数量是 {'K': 4, 'N': 2, 'O': 14, 'S': 4}。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= formula.length <= 1000
 * formula 由英文字母、数字、'(' 和 ')' 组成
 * formula 总是有效的化学式
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
    string countOfAtoms(string formula) {
        int i = 0, n = formula.length();

        auto parseAtom = [&]() -> string {
            string atom;
            atom += formula[i++]; // 扫描首字母
            while (i < n && islower(formula[i])) {
                atom += formula[i++]; // 扫描首字母后的小写字母
            }
            return atom;
        };

        auto parseNum = [&]() -> int {
            if (i == n || !isdigit(formula[i])) {
                return 1; // 不是数字，视作 1
            }
            int num = 0;
            while (i < n && isdigit(formula[i])) {
                num = num * 10 + int(formula[i++] - '0'); // 扫描数字
            }
            return num;
        };

        stack<unordered_map<string, int>> stk;
        stk.push({});
        while (i < n) {
            char ch = formula[i];
            if (ch == '(') {
                i++;
                stk.push({}); // 将一个空的哈希表压入栈中，准备统计括号内的原子数量
            } else if (ch == ')') {
                i++;
                int num = parseNum(); // 括号右侧数字
                auto atomNum = stk.top();
                stk.pop(); // 弹出括号内的原子数量
                for (auto &[atom, v] : atomNum) {
                    stk.top()[atom] += v * num; // 将括号内的原子数量乘上 num，加到上一层的原子数量中
                }
            } else {
                string atom = parseAtom();
                int num = parseNum();
                stk.top()[atom] += num; // 统计原子数量
            }
        }

        auto &atomNum = stk.top();
        vector<pair<string, int>> pairs;
        for (auto &[atom, v] : atomNum) {
            pairs.emplace_back(atom, v);
        }
        sort(pairs.begin(), pairs.end());

        string ans;
        for (auto &p : pairs) {
            ans += p.first;
            if (p.second > 1) {
                ans += to_string(p.second);
            }
        }
        return ans;
    }
};

// @lc code=end



/*
// @lcpr case=start
// "H2O"\n
// @lcpr case=end

// @lcpr case=start
// "Mg(OH)2"\n
// @lcpr case=end

// @lcpr case=start
// "K4(ON(SO3)2)2"\n
// @lcpr case=end

 */

