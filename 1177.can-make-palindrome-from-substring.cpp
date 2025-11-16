/*
 * @lc app=leetcode.cn id=1177 lang=cpp
 * @lcpr version=
 *
 * [1177] 构建回文串检测
 *
 * https://leetcode.cn/problems/can-make-palindrome-from-substring/description/
 *
 * algorithms
 * Medium (45.80%)
 * Likes:    211
 * Dislikes: 0
 * Total Accepted:    29.2K
 * Total Submissions: 63.6K
 * Testcase Example:  '"abcda"\n[[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]'
 *
 * 给你一个字符串 s，请你对 s 的子串进行检测。
 * 
 * 每次检测，待检子串都可以表示为 queries[i] = [left, right, k]。我们可以 重新排列 子串 s[left], ...,
 * s[right]，并从中选择 最多 k 项替换成任何小写英文字母。 
 * 
 * 如果在上述检测过程中，子串可以变成回文形式的字符串，那么检测结果为 true，否则结果为 false。
 * 
 * 返回答案数组 answer[]，其中 answer[i] 是第 i 个待检子串 queries[i] 的检测结果。
 * 
 * 注意：在替换时，子串中的每个字母都必须作为 独立的 项进行计数，也就是说，如果 s[left..right] = "aaa" 且 k =
 * 2，我们只能替换其中的两个字母。（另外，任何检测都不会修改原始字符串 s，可以认为每次检测都是独立的）
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：s = "abcda", queries = [[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
 * 输出：[true,false,false,true,true]
 * 解释：
 * queries[0] : 子串 = "d"，回文。
 * queries[1] : 子串 = "bc"，不是回文。
 * queries[2] : 子串 = "abcd"，只替换 1 个字符是变不成回文串的。
 * queries[3] : 子串 = "abcd"，可以变成回文的 "abba"。 也可以变成 "baab"，先重新排序变成 "bacd"，然后把
 * "cd" 替换为 "ab"。
 * queries[4] : 子串 = "abcda"，可以变成回文的 "abcba"。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length, queries.length <= 10^5
 * 0 <= queries[i][0] <= queries[i][1] < s.length
 * 0 <= queries[i][2] <= s.length
 * s 中只有小写英文字母
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
    // 优化前
    // vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    //     int n = s.length(), q = queries.size();
    //     vector<array<int, 26>> sum(n + 1);
    //     for (int i = 0; i < n; i++) {
    //         sum[i + 1] = sum[i];
    //         sum[i + 1][s[i] - 'a']++;
    //     }

    //     vector<bool> res(q);
    //     for (int i = 0; i < q; i++) {
    //         auto& query = queries[i];
    //         int left = query[0], right = query[1], k = query[2], cnt = 0;
    //         for (int j = 0; j < 26; j++) {
    //             cnt += (sum[right + 1][j] - sum[left][j]) % 2; // 奇数+1，偶数+0
    //         }
    //         res[i] = cnt / 2 <= k;
    //     }
    //     return res;
    // }

    /**
     * 优化1
     * 由于只关心每种字母出现次数的奇偶性，所以不需要咋前缀和中存储每种字母的出现次数，
     * 只需要保存每种字母的出现次数的奇偶性
     * 
     * 用0表示出现偶数次，用1表示出现奇数次
     * 
     * 注意只有奇数减偶数，或者偶数减奇数，才能得到奇数。
     * 所以如果相减的结果不为 0（或者说相减的两个数不相等），就表示出现了奇数次。
     */
    // vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    //     int n = s.length(), q = queries.size();
    //     vector<array<int, 26>> sum(n + 1);
    //     for (int i = 0; i < n; i++) {
    //         sum[i + 1] = sum[i];
    //         sum[i + 1][s[i] - 'a']++;
    //         sum[i + 1][s[i] - 'a'] %= 2; // 偶数是 0
    //     }

    //     vector<bool> res(q);
    //     for (int i = 0; i < q; i++) {
    //         auto& query = queries[i];
    //         int left = query[0], right = query[1], k = query[2], m = 0;
    //         for (int j = 0; j < 26; j++) {
    //             m += (sum[right + 1][j] != sum[left][j]);
    //         }
    //         res[i] = m / 2 <= k;
    //     }
    //     return res;
    // }

    /**
     * 由于异或运算满足 1 和 0 的结果是 1，而 0 和 0，以及 1 和 1 的结果都是 0，
     * 所以可以用异或替换上面的减法
     */
    // vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    //     int n = s.length(), q = queries.size();
    //     vector<array<int, 26>> sum(n + 1);
    //     for (int i = 0; i < n; i++) {
    //         sum[i + 1] = sum[i];
    //         sum[i + 1][s[i] - 'a'] ^= 1;
    //     }
    //     vector<bool> res(q);
    //     for (int i = 0; i < q; i++) {
    //         auto &query = queries[i];
    //         int left = query[0], right = query[1], k = query[2], m = 0;
    //         for (int j = 0; j < 26; j++) {
    //             m += sum[right + 1][j] ^ sum[left][j];
    //         }
    //         res[i] = m / 2 <= k;
    //     }
    //     return res;
    // }


    /**
     * 由于长为26的数组中只存储0和1，可以压缩到一个二进制数中
     * 二进制数从低到高第i个比特存储着0和1的信息
     * 
     * 例如二进制 10010 表示 b 和 e 出现奇数次，其余字母出现偶数次。
     * 
     * 在计算前缀和时（准确地说是异或前缀和）：
     *      修改 a 出现次数的奇偶性，可以异或二进制 1；
     *      修改 b 出现次数的奇偶性，可以异或二进制 10；
     *      修改 c 出现次数的奇偶性，可以异或二进制 100；
     *      ...
     */
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.length(), q = queries.size();
        int sum[n+1];
        sum[0] = 0;
        for (int i = 0; i < n; i++) {
            int bit = 1 << (s[i] - 'a');
            sum[i + 1] = sum[i] ^ bit;
        }

        vector<bool> res(q);
        for (int i = 0; i < q; i++) {
            auto &query = queries[i];
            int left = query[0], right = query[1], k = query[2];
            int m = __builtin_popcount(sum[right + 1] ^ sum[left]);
            res[i] = m / 2 <= k;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcda"\n[[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]\n
// @lcpr case=end

 */

