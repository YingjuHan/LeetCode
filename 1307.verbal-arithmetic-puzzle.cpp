/*
 * @lc app=leetcode.cn id=1307 lang=cpp
 * @lcpr version=
 *
 * [1307] 口算难题
 *
 * https://leetcode.cn/problems/verbal-arithmetic-puzzle/description/
 *
 * algorithms
 * Hard (35.88%)
 * Likes:    81
 * Dislikes: 0
 * Total Accepted:    4.4K
 * Total Submissions: 12.5K
 * Testcase Example:  '["SEND","MORE"]\n"MONEY"'
 *
 * 给你一个方程，左边用 words 表示，右边用 result 表示。
 * 
 * 你需要根据以下规则检查方程是否可解：
 * 
 * 
 * 每个字符都会被解码成一位数字（0 - 9）。
 * 每对不同的字符必须映射到不同的数字。
 * 每个 words[i] 和 result 都会被解码成一个没有前导零的数字。
 * 左侧数字之和（words）等于右侧数字（result）。 
 * 
 * 
 * 如果方程可解，返回 True，否则返回 False。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：words = ["SEND","MORE"], result = "MONEY"
 * 输出：true
 * 解释：映射 'S'-> 9, 'E'->5, 'N'->6, 'D'->7, 'M'->1, 'O'->0, 'R'->8, 'Y'->'2'
 * 所以 "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652
 * 
 * 示例 2：
 * 
 * 输入：words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
 * 输出：true
 * 解释：映射 'S'-> 6, 'I'->5, 'X'->0, 'E'->8, 'V'->7, 'N'->2, 'T'->1, 'W'->'3',
 * 'Y'->4
 * 所以 "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214
 * 
 * 示例 3：
 * 
 * 输入：words = ["THIS","IS","TOO"], result = "FUNNY"
 * 输出：true
 * 
 * 
 * 示例 4：
 * 
 * 输入：words = ["LEET","CODE"], result = "POINT"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= words.length <= 5
 * 1 <= words[i].length, results.length <= 7
 * words[i], result 只含有大写英文字母
 * 表达式中使用的不同字符数最大为 10
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
    vector<int> used;    // used记录哪些数字被使用了
    vector<int> weights; // weights计算每个字母的权重
    vector<int> notZero; // notZero记录哪些字母不能对应到0
    vector<int> chars;   // chars记录所有用到的字母
    int N;
    Solution() {
        used = vector<int>(10, 0);
        weights = vector<int>(26, 0);
        notZero = vector<int>(26, 0);
        N = 0;
    }
    bool dfs(int i, int sum) {
        if (i == N) return sum == 0;
        for (int j = 0; j < 10; ++j) {
            if (notZero[i] && j == 0) continue;
            if (used[j]) continue;
            used[j] = true;
            if (dfs(i + 1, sum + j * weights[chars[i]])) return true;
            used[j] = false;
        }
        return false;
    }
    bool isSolvable(vector<string>& words, string result) {
        for (auto& w : words) {
            int p = 1;
            for (int i = w.size() - 1; i >= 0; --i) {
                chars.push_back(w[i] - 'A');
                weights[w[i] - 'A'] += p;
                p *= 10;
            }
            if (w.size() > 1) notZero[w[0] - 'A'] = 1;
        }
        int p = 1;
        for (int i = result.size() - 1; i >= 0; --i) {
            chars.push_back(result[i] - 'A');
            weights[result[i] - 'A'] -= p;
            p *= 10;
        }
        if (result.size() > 0) notZero[result[0] - 'A'] = 1;
        sort(chars.begin(), chars.end());
        chars.erase(unique(chars.begin(), chars.end()), chars.end());
        N = chars.size();
        int sum = 0;
        return dfs(0, sum);
    }
};

// @lc code=end



/*
// @lcpr case=start
// ["SEND","MORE"]\n"MONEY"\n
// @lcpr case=end

// @lcpr case=start
// ["SIX","SEVEN","SEVEN"]\n"TWENTY"\n
// @lcpr case=end

// @lcpr case=start
// ["THIS","IS","TOO"]\n"FUNNY"\n
// @lcpr case=end

// @lcpr case=start
// ["LEET","CODE"]\n"POINT"\n
// @lcpr case=end

 */

