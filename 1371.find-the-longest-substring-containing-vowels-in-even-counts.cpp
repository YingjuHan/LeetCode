/*
 * @lc app=leetcode.cn id=1371 lang=cpp
 * @lcpr version=
 *
 * [1371] 每个元音包含偶数次的最长子字符串
 *
 * https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/
 *
 * algorithms
 * Medium (61.63%)
 * Likes:    514
 * Dislikes: 0
 * Total Accepted:    33.9K
 * Total Submissions: 54.9K
 * Testcase Example:  '"eleetminicoworoep"'
 *
 * 给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度：每个元音字母，即 'a'，'e'，'i'，'o'，'u'
 * ，在子字符串中都恰好出现了偶数次。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "eleetminicoworoep"
 * 输出：13
 * 解释：最长子字符串是 "leetminicowor" ，它包含 e，i，o 各 2 个，以及 0 个 a，u 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "leetcodeisgreat"
 * 输出：5
 * 解释：最长子字符串是 "leetc" ，其中包含 2 个 e 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "bcbcbc"
 * 输出：6
 * 解释：这个示例中，字符串 "bcbcbc" 本身就是最长的，因为所有的元音 a，e，i，o，u 都出现了 0 次。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 5 x 10^5
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
    int findTheLongestSubstring(string s) {
        // 将 5 个元音字母出现次数的奇偶视为一种状态，一共有 32 种状态
        // 第 0 位为 1 表示 a 出现奇数次，第一位为 1 表示 e 出现奇数次……以此类推。仅有状态 0 符合题意
        // 而如果子串 [0，i] 与字串 [0,j] 状态相同，那么字串 [i+1,j] 的状态一定是 0，
        // 因此可以记录每个状态第一次出现的位置，此后再出现该状态时相减即可。
        vector<int> pre(32, INT_MAX);
        pre[0] = -1;
        int n = s.length();
        int cur = 0, res = 0;
        for (int i = 0; i < n; i++) {
            switch (s[i])
            {
            case 'a':
                cur^=1;
                break;
            case 'e':
                cur^=2;
                break;
            case 'i':
                cur^=4;
                break;
            case 'o':
                cur^=8;
                break;
            case 'u':
                cur^=16;
                break;
            default:
                break;
            }

            if (pre[cur] == INT_MAX) {
                pre[cur] = i;
            } else {
                res = max(res, i - pre[cur]);
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "eleetminicoworoep"\n
// @lcpr case=end

// @lcpr case=start
// "leetcodeisgreat"\n
// @lcpr case=end

// @lcpr case=start
// "bcbcbc"\n
// @lcpr case=end

 */

