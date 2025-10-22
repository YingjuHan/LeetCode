/*
 * @lc app=leetcode.cn id=1016 lang=cpp
 * @lcpr version=30204
 *
 * [1016] 子串能表示从 1 到 N 数字的二进制串
 *
 * https://leetcode.cn/problems/binary-string-with-substrings-representing-1-to-n/description/
 *
 * algorithms
 * Medium (63.53%)
 * Likes:    140
 * Dislikes: 0
 * Total Accepted:    30.3K
 * Total Submissions: 47.6K
 * Testcase Example:  '"0110"\n3'
 *
 * 给定一个二进制字符串 s 和一个正整数 n，如果对于 [1, n] 范围内的每个整数，其二进制表示都是 s 的 子字符串 ，就返回 true，否则返回
 * false 。
 * 
 * 子字符串 是字符串中连续的字符序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "0110", n = 3
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "0110", n = 4
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s[i] 不是 '0' 就是 '1'
 * 1 <= n <= 10^9
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
    bool queryString(string s, int n) {
        // 1. 暴力计算
        for (int i = 1; i <= n; i++) {
            auto bin = bitset<32>(i).to_string();
            bin = bin.substr(bin.find('1'));
            if (s.find(bin) == string::npos) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "0110"\n3\n
// @lcpr case=end

// @lcpr case=start
// "0110"\n4\n
// @lcpr case=end

 */

