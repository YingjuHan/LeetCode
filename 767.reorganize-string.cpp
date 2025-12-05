/*
 * @lc app=leetcode.cn id=767 lang=cpp
 * @lcpr version=30204
 *
 * [767] 重构字符串
 *
 * https://leetcode.cn/problems/reorganize-string/description/
 *
 * algorithms
 * Medium (49.58%)
 * Likes:    571
 * Dislikes: 0
 * Total Accepted:    62.3K
 * Total Submissions: 125.7K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串 s ，检查是否能重新排布其中的字母，使得两相邻的字符不同。
 * 
 * 返回 s 的任意可能的重新排列。若不可行，返回空字符串 "" 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: s = "aab"
 * 输出: "aba"
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "aaab"
 * 输出: ""
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length <= 500
 * s 只包含小写字母
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
    string reorganizeString(string s) {
        int n = s.length();
        unordered_map<char, int> count;
        for (char ch : s) {
            count[ch]++;
        }
        vector<pair<char, int>> a(count.begin(), count.end());
        sort(a.begin(), a.end(), [](const auto& p, const auto& q) {
            return p.second > q.second;
        });
        int m = a[0].second;
        if (m > n - m + 1) return "";

        string res(n, 0);
        int i = 0;
        for (auto [ch, cnt] : a) {
            while (cnt--) {
                res[i] = ch;
                i+=2;
                if (i >= n) {
                    i = 1;
                }
            }
        }
        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "aaab"\n
// @lcpr case=end

 */

