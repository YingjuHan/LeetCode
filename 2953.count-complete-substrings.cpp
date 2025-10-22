/*
 * @lc app=leetcode.cn id=2953 lang=cpp
 * @lcpr version=30204
 *
 * [2953] 统计完全子字符串
 *
 * https://leetcode.cn/problems/count-complete-substrings/description/
 *
 * algorithms
 * Hard (37.86%)
 * Likes:    54
 * Dislikes: 0
 * Total Accepted:    7.7K
 * Total Submissions: 20.3K
 * Testcase Example:  '"igigee"\n2'
 *
 * 给你一个字符串 word 和一个整数 k 。
 *
 * 如果 word 的一个子字符串 s 满足以下条件，我们称它是 完全字符串：
 *
 *
 * s 中每个字符 恰好 出现 k 次。
 * 相邻字符在字母表中的顺序 至多 相差 2 。也就是说，s 中两个相邻字符 c1 和 c2 ，它们在字母表中的位置相差 至多 为 2 。
 *
 *
 * 请你返回 word 中 完全 子字符串的数目。
 *
 * 子字符串 指的是一个字符串中一段连续 非空 的字符序列。
 *
 *
 *
 * 示例 1：
 *
 * 输入：word = "igigee", k = 2
 * 输出：3
 * 解释：完全子字符串需要满足每个字符恰好出现 2 次，且相邻字符相差至多为 2 ：igigee, igigee, igigee 。
 *
 *
 * 示例 2：
 *
 * 输入：word = "aaabbbccc", k = 3
 * 输出：6
 * 解释：完全子字符串需要满足每个字符恰好出现 3 次，且相邻字符相差至多为 2 ：aaabbbccc, aaabbbccc, aaabbbccc,
 * aaabbbccc, aaabbbccc, aaabbbccc 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= word.length <= 10^5
 * word 只包含小写英文字母。
 * 1 <= k <= word.length
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
class Solution
{
public:
    int f(string s, int k)
    {
        int res = 0;
        for (int m = 1; m <= 26 && k * m <= s.length(); m++) {
            int cnt[26]{};
            auto check = [&]() {
                for (int i = 0; i < 26; i++) {
                    if (cnt[i] && cnt[i] != k) {
                        return;
                    }
                }
                res++;
            };
            for (int right = 0; right < s.length(); right++) {
                cnt[s[right] - 'a']++;
                int left = right + 1 - k * m;
                if (left >= 0) {
                    check();
                    cnt[s[left] - 'a']--;
                }
            }
        }
        return res;
    }
    int countCompleteSubstrings(string word, int k)
    {
        int n = word.length();
        int ans = 0;
        int i = 0;
        string s(word);
        while (i < n) {
            int st = i;
            // 内层循环用while实现，找到连续符合条件的子串终点
            i++;
            while (i < n && abs(int(word[i]) - int(word[i - 1])) <= 2) {
                i++;
            }
            // 计算当前连续子串的完整子串数量并累加
            ans += f(s.substr(st, i - st), k);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "igigee"\n2\n
// @lcpr case=end

// @lcpr case=start
// "aaabbbccc"\n3\n
// @lcpr case=end

 */
