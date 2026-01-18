/*
 * @lc app=leetcode.cn id=784 lang=cpp
 * @lcpr version=30204
 *
 * [784] 字母大小写全排列
 *
 * https://leetcode.cn/problems/letter-case-permutation/description/
 *
 * algorithms
 * Medium (73.06%)
 * Likes:    611
 * Dislikes: 0
 * Total Accepted:    130K
 * Total Submissions: 177.9K
 * Testcase Example:  '"a1b2"'
 *
 * 给定一个字符串 s ，通过将字符串 s 中的每个字母转变大小写，我们可以获得一个新的字符串。
 * 
 * 返回 所有可能得到的字符串集合 。以 任意顺序 返回输出。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "a1b2"
 * 输出：["a1b2", "a1B2", "A1b2", "A1B2"]
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "3z4"
 * 输出: ["3z4","3Z4"]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length <= 12
 * s 由小写英文字母、大写英文字母和数字组成
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
    vector<string> letterCasePermutation(string s) {
        int n = s.length();
        vector<string> res;
        string cur = s;
        
        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (i == n) {
                res.push_back(cur);
                return;
            }

            dfs(i + 1);

            if (isalpha(cur[i])) {
                cur[i] ^= ' ';
                dfs(i + 1);
                cur[i] ^= ' ';
            }
        };
        dfs(0);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "a1b2"\n
// @lcpr case=end

// @lcpr case=start
// "3z4"\n
// @lcpr case=end

 */

