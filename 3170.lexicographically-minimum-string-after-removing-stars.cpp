/*
 * @lc app=leetcode.cn id=3170 lang=cpp
 * @lcpr version=30204
 *
 * [3170] 删除星号以后字典序最小的字符串
 *
 * https://leetcode.cn/problems/lexicographically-minimum-string-after-removing-stars/description/
 *
 * algorithms
 * Medium (40.96%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    20.1K
 * Total Submissions: 39.7K
 * Testcase Example:  '"aaba*"'
 *
 * 给你一个字符串 s 。它可能包含任意数量的 '*' 字符。你的任务是删除所有的 '*' 字符。
 * 
 * 当字符串还存在至少一个 '*' 字符时，你可以执行以下操作：
 * 
 * 
 * 删除最左边的 '*' 字符，同时删除该星号字符左边一个字典序 最小 的字符。如果有多个字典序最小的字符，你可以删除它们中的任意一个。
 * 
 * 
 * 请你返回删除所有 '*' 字符以后，剩余字符连接而成的 字典序最小 的字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "aaba*"
 * 
 * 输出："aab"
 * 
 * 解释：
 * 
 * 删除 '*' 号和它左边的其中一个 'a' 字符。如果我们选择删除 s[3] ，s 字典序最小。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "abc"
 * 
 * 输出："abc"
 * 
 * 解释：
 * 
 * 字符串中没有 '*' 字符。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s 只含有小写英文字母和 '*' 字符。
 * 输入保证操作可以删除所有的 '*' 字符。
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
    /**
     * 剩余字符连接而成的 字典序最小 的字符串。
     * 
     * 去掉的字母靠左,会让更大的字母左移,字符串的字典序变大,
     * 因此每次操作应该去掉最小字母中靠后的字母
     */
    string clearStars(string s) {
        vector<stack<int>> cnt(26);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '*') {
                cnt[s[i] - 'a'].push(i);
            } else {
                for (int j = 0; j < 26; j++) {
                    if (!cnt[j].empty()) {
                        s[cnt[j].top()] = '*';
                        cnt[j].pop();
                        break;
                    }
                }
            }
        }
        string res;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '*') {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aaba*"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

 */

