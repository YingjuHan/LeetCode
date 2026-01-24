/*
 * @lc app=leetcode.cn id=880 lang=cpp
 * @lcpr version=30204
 *
 * [880] 索引处的解码字符串
 *
 * https://leetcode.cn/problems/decoded-string-at-index/description/
 *
 * algorithms
 * Medium (28.50%)
 * Likes:    212
 * Dislikes: 0
 * Total Accepted:    10.6K
 * Total Submissions: 37.3K
 * Testcase Example:  '"leet2code3"\n10'
 *
 * 给定一个编码字符串 s 。请你找出 解码字符串 并将其写入磁带。解码时，从编码字符串中 每次读取一个字符 ，并采取以下步骤：
 * 
 * 
 * 如果所读的字符是字母，则将该字母写在磁带上。
 * 如果所读的字符是数字（例如 d），则整个当前磁带总共会被重复写 d-1 次。
 * 
 * 
 * 现在，对于给定的编码字符串 s 和索引 k，查找并返回解码字符串中的第 k 个字母。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "leet2code3", k = 10
 * 输出："o"
 * 解释：
 * 解码后的字符串为 "leetleetcodeleetleetcodeleetleetcode"。
 * 字符串中的第 10 个字母是 "o"。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "ha22", k = 5
 * 输出："h"
 * 解释：
 * 解码后的字符串为 "hahahaha"。第 5 个字母是 "h"。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "a2345678999999999999999", k = 1
 * 输出："a"
 * 解释：
 * 解码后的字符串为 "a" 重复 8301530446056247680 次。第 1 个字母是 "a"。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= s.length <= 100
 * s 只包含小写字母与数字 2 到 9 。
 * s 以字母开头。
 * 1 <= k <= 10^9
 * 题目保证 k 小于或等于解码字符串的长度。
 * 解码后的字符串保证少于 2^63 个字母。
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
    string decodeAtIndex(string s, int k) {
        long long len = 0;
        for (int i = 0; i < s.size(); i++) {
            long long add = isalpha(s[i]) ? 1 : (s[i] - '1') * len;
            if (len + add < k) {
                len += add;
            } else {
                if (len + add == k || k % len == 0) {
                    while (!isalpha(s[i])) {
                        i--;
                    }
                    return string("") + s[i];
                }
                return decodeAtIndex(s.substr(0, i), k % len);
            }
        }
        return "";
    }
};
// @lc code=end



/*
// @lcpr case=start
// "leet2code3"\n10\n
// @lcpr case=end

// @lcpr case=start
// "ha22"\n5\n
// @lcpr case=end

// @lcpr case=start
// "a2345678999999999999999"\n1\n
// @lcpr case=end

 */

