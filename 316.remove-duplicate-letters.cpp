/*
 * @lc app=leetcode.cn id=316 lang=cpp
 * @lcpr version=30204
 *
 * [316] 去除重复字母
 *
 * https://leetcode.cn/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Medium (50.12%)
 * Likes:    1165
 * Dislikes: 0
 * Total Accepted:    166.2K
 * Total Submissions: 331.6K
 * Testcase Example:  '"bcabc"'
 *
 * 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "bcabc"
 * 输出："abc"
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "cbacdcbc"
 * 输出："acdb"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 由小写英文字母组成
 * 
 * 
 * 
 * 
 * 注意：该题与 1081
 * https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters
 * 相同
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
    string removeDuplicateLetters(string s) {
        int left[26]{};
        for (char c : s) {
            left[c - 'a']++; // 统计字符出现的次数
        }

        string res;
        bool in_res[26]{};
        for (char c : s) {
            left[c - 'a']--;
            if (in_res[c - 'a'] > 0) { //   要求无重复字符
                continue;
            }
            while (!res.empty() && res.back() > c && left[res.back() - 'a'] > 0) {
                // (设 x=ans.back()) 如果 c < x，且右边还有 x，那么可以把 x 去掉，
                // 因为后面可以重新把 x 加到 ans 中
                in_res[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(c);
            in_res[c - 'a'] = true;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "bcabc"\n
// @lcpr case=end

// @lcpr case=start
// "cbacdcbc"\n
// @lcpr case=end

 */

