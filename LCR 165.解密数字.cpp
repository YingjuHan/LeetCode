/*
 * @lc app=leetcode.cn id=LCR 165 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 165] 解密数字
 *
 * https://leetcode.cn/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/description/
 *
 * algorithms
 * Medium (51.09%)
 * Likes:    627
 * Dislikes: 0
 * Total Accepted:    273.1K
 * Total Submissions: 534.7K
 * Testcase Example:  '216612'
 *
 * 现有一串神秘的密文 ciphertext，经调查，密文的特点和规则如下：
 * 
 * 
 * 密文由非负整数组成
 * 数字 0-25 分别对应字母 a-z
 * 
 * 
 * 请根据上述规则将密文 ciphertext 解密为字母，并返回共有多少种解密结果。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：ciphertext = 216612
 * 输出：6
 * 解释：216612 解密后有 6 种不同的形式，分别是 "cbggbc"，"vggbc"，"vggm"，"cbggm"，"cqgbc" 和
 * "cqgm" 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= ciphertext < 2^31
 * 
 * 
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
    int crackNumber(int ciphertext) {
        string s = to_string(ciphertext);
        int a = 1, b = 1, len = s.length();
        for (int i = 2; i <= len; i++) {
            string temp = s.substr(i - 2, 2);
            int c = temp.compare("10") >= 0 && temp.compare("25") <= 0 ? a + b : a;
            b = a;
            a = c;
        }
        return a;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 216612\n
// @lcpr case=end

 */

