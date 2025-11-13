/*
 * @lc app=leetcode.cn id=1446 lang=cpp
 * @lcpr version=
 *
 * [1446] 连续字符
 *
 * https://leetcode.cn/problems/consecutive-characters/description/
 *
 * algorithms
 * Easy (60.46%)
 * Likes:    146
 * Dislikes: 0
 * Total Accepted:    74.5K
 * Total Submissions: 123.1K
 * Testcase Example:  '"leetcode"'
 *
 * 给你一个字符串 s ，字符串的「能量」定义为：只包含一种字符的最长非空子字符串的长度。
 * 
 * 请你返回字符串 s 的 能量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "leetcode"
 * 输出：2
 * 解释：子字符串 "ee" 长度为 2 ，只包含字符 'e' 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "abbcccddddeeeeedcba"
 * 输出：5
 * 解释：子字符串 "eeeee" 长度为 5 ，只包含字符 'e' 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 500
 * s 只包含小写英文字母。
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
    int maxPower(string s) {
        int n = s.length();
        int res = 0;
        for (int i = 0; i < n;) {
            int start = i;
            for (i++; i < n && s[i] == s[i - 1]; i++);
            res = max(res, i - start);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "leetcode"\n
// @lcpr case=end

// @lcpr case=start
// "abbcccddddeeeeedcba"\n
// @lcpr case=end

 */

