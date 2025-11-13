/*
 * @lc app=leetcode.cn id=2949 lang=cpp
 * @lcpr version=
 *
 * [2949] 统计美丽子字符串 II
 *
 * https://leetcode.cn/problems/count-beautiful-substrings-ii/description/
 *
 * algorithms
 * Hard (35.39%)
 * Likes:    23
 * Dislikes: 0
 * Total Accepted:    3.1K
 * Total Submissions: 8.8K
 * Testcase Example:  '"baeyh"\n2'
 *
 * 给你一个字符串 s 和一个正整数 k 。
 * 
 * 用 vowels 和 consonants 分别表示字符串中元音字母和辅音字母的数量。
 * 
 * 如果某个字符串满足以下条件，则称其为 美丽字符串 ：
 * 
 * 
 * vowels == consonants，即元音字母和辅音字母的数量相等。
 * (vowels * consonants) % k == 0，即元音字母和辅音字母的数量的乘积能被 k 整除。
 * 
 * 
 * 返回字符串 s 中 非空美丽子字符串 的数量。
 * 
 * 子字符串是字符串中的一个连续字符序列。
 * 
 * 英语中的 元音字母 为 'a'、'e'、'i'、'o' 和 'u' 。
 * 
 * 英语中的 辅音字母 为除了元音字母之外的所有字母。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "baeyh", k = 2
 * 输出：2
 * 解释：字符串 s 中有 2 个美丽子字符串。
 * - 子字符串 "baeyh"，vowels = 2（["a","e"]），consonants = 2（["y","h"]）。
 * 可以看出字符串 "aeyh" 是美丽字符串，因为 vowels == consonants 且 vowels * consonants % k == 0
 * 。
 * - 子字符串 "baeyh"，vowels = 2（["a","e"]），consonants = 2（["b","y"]）。
 * 可以看出字符串 "baey" 是美丽字符串，因为 vowels == consonants 且 vowels * consonants % k == 0
 * 。
 * 可以证明字符串 s 中只有 2 个美丽子字符串。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "abba", k = 1
 * 输出：3
 * 解释：字符串 s 中有 3 个美丽子字符串。
 * - 子字符串 "abba"，vowels = 1（["a"]），consonants = 1（["b"]）。
 * - 子字符串 "abba"，vowels = 1（["a"]），consonants = 1（["b"]）。
 * - 子字符串 "abba"，vowels = 2（["a","a"]），consonants = 2（["b","b"]）。
 * 可以证明字符串 s 中只有 3 个美丽子字符串。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "bcdf", k = 1
 * 输出：0
 * 解释：字符串 s 中没有美丽子字符串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 5 * 10^4
 * 1 <= k <= 1000
 * s 仅由小写英文字母组成。
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
#include <map>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int p_sqrt(int n) {
        int res = 1;
        for (int i = 2; i * i <= n; i++) {
            int i2 = i * i;
            while (n % i2 == 0) {
                res *= i;
                n /= i2;
            }
            if (n % i == 0) {
                res *= i;
                n /= i;
            }
        }
        if (n > 1) {
            res *= n;
        }
        return res;
    }

    const int AEIOU_MASK = 1065233;

    long long beautifulSubstrings(string s, int k) {
        k = p_sqrt(k * 4);
        map<pair<int, int>, int> cnt;
        cnt[{k - 1, 0}]++; // 添加(k - 1, sum)
        long long res = 0;
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            int bit = (AEIOU_MASK >> (s[i] - 'a')) & 1;
            sum += bit * 2 - 1;
            res += cnt[{i % k, sum}]++;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "baeyh"\n2\n
// @lcpr case=end

// @lcpr case=start
// "abba"\n1\n
// @lcpr case=end

// @lcpr case=start
// "bcdf"\n1\n
// @lcpr case=end

 */

