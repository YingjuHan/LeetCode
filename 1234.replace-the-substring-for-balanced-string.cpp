/*
 * @lc app=leetcode.cn id=1234 lang=cpp
 * @lcpr version=30204
 *
 * [1234] 替换子串得到平衡字符串
 *
 * https://leetcode.cn/problems/replace-the-substring-for-balanced-string/description/
 *
 * algorithms
 * Medium (48.70%)
 * Likes:    361
 * Dislikes: 0
 * Total Accepted:    49.5K
 * Total Submissions: 101.2K
 * Testcase Example:  '"QWER"'
 *
 * 有一个只含有 'Q', 'W', 'E', 'R' 四种字符，且长度为 n 的字符串。
 * 
 * 假如在该字符串中，这四个字符都恰好出现 n/4 次，那么它就是一个「平衡字符串」。
 * 
 * 
 * 
 * 给你一个这样的字符串 s，请通过「替换一个子串」的方式，使原字符串 s 变成一个「平衡字符串」。
 * 
 * 你可以用和「待替换子串」长度相同的 任何 其他字符串来完成替换。
 * 
 * 请返回待替换子串的最小可能长度。
 * 
 * 如果原字符串自身就是一个平衡字符串，则返回 0。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "QWER"
 * 输出：0
 * 解释：s 已经是平衡的了。
 * 
 * 示例 2：
 * 
 * 输入：s = "QQWE"
 * 输出：1
 * 解释：我们需要把一个 'Q' 替换成 'R'，这样得到的 "RQWE" (或 "QRWE") 是平衡的。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "QQQW"
 * 输出：2
 * 解释：我们可以把前面的 "QQ" 替换成 "ER"。 
 * 
 * 
 * 示例 4：
 * 
 * 输入：s = "QQQQ"
 * 输出：3
 * 解释：我们可以替换后 3 个 'Q'，使 s = "QWER"。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s.length 是 4 的倍数
 * s 中只含有 'Q', 'W', 'E', 'R' 四种字符
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
    int balancedString(string s) {
        // 如果在待替换子串之外的任意字符的出现次数超过 m= n / 4
        // 那么无论怎么替换，都无法使这个字符在整个字符串中的出现次数为 m
        // 也就是说：
        // 替换子串之外的任意字符的出现次数都不超过 m，
        // 那么可以通过替换，使 s 为平衡字符串，即每个字符的出现次数均为 m


        // 对于本题，设子串的左右端点为 left 和 right，枚举 right，如果子串外的任意字符的出现次数都不超过 m，
        // 则说明从 left 到 right 的这段子串可以是待替换子串，用其长度 right−left+1 更新答案的最小值，
        // 并向右移动 left，缩小子串长度
        unordered_map<char, int> cnt;
        for (char c : s) {
            cnt[c]++;
        }

        int n = s.length(), m = n / 4;
        if (cnt['Q'] == m && cnt['W'] == m && cnt['E'] == m && cnt['R'] == m) {
            return 0; // 已经符合要求
        }

        int res = n, left = 0;
        for (int right = 0; right < n; right++) {
            cnt[s[right]]--;
            while (cnt['Q'] <= m && cnt['W'] <= m && cnt['E'] <= m && cnt['R'] <= m) {
                res = min(res, right - left + 1);
                cnt[s[left]]++;
                left++;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "QWER"\n
// @lcpr case=end

// @lcpr case=start
// "QQWE"\n
// @lcpr case=end

// @lcpr case=start
// "QQQW"\n
// @lcpr case=end

// @lcpr case=start
// "QQQQ"\n
// @lcpr case=end

 */

