/*
 * @lc app=leetcode.cn id=2014 lang=cpp
 * @lcpr version=30204
 *
 * [2014] 重复 K 次的最长子序列
 *
 * https://leetcode.cn/problems/longest-subsequence-repeated-k-times/description/
 *
 * algorithms
 * Hard (68.88%)
 * Likes:    51
 * Dislikes: 0
 * Total Accepted:    9.4K
 * Total Submissions: 13.6K
 * Testcase Example:  '"letsleetcode"\n2'
 *
 * 给你一个长度为 n 的字符串 s ，和一个整数 k 。请你找出字符串 s 中 重复 k 次的 最长子序列 。
 * 
 * 子序列 是由其他字符串删除某些（或不删除）字符派生而来的一个字符串。
 * 
 * 如果 seq * k 是 s 的一个子序列，其中 seq * k 表示一个由 seq 串联 k 次构造的字符串，那么就称 seq 是字符串 s 中一个
 * 重复 k 次 的子序列。
 * 
 * 
 * 举个例子，"bba" 是字符串 "bababcba" 中的一个重复 2 次的子序列，因为字符串 "bbabba" 是由 "bba" 串联 2
 * 次构造的，而 "bbabba" 是字符串 "bababcba" 的一个子序列。
 * 
 * 
 * 返回字符串 s 中 重复 k 次的最长子序列  。如果存在多个满足的子序列，则返回 字典序最大 的那个。如果不存在这样的子序列，返回一个 空
 * 字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：s = "letsleetcode", k = 2
 * 输出："let"
 * 解释：存在两个最长子序列重复 2 次：let" 和 "ete" 。
 * "let" 是其中字典序最大的一个。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "bb", k = 2
 * 输出："b"
 * 解释：重复 2 次的最长子序列是 "b" 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "ab", k = 2
 * 输出：""
 * 解释：不存在重复 2 次的最长子序列。返回空字符串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == s.length
 * 2 <= k <= 2000
 * 2 <= n < min(2001, k * 8)
 * s 由小写英文字母组成
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
    // 枚举从 nums 中选任意个数的所有排列，用 f 处理枚举的排列
    void permuteFunc(const string& nums, auto&& f) {
        int n = nums.length();
        string path;
        vector<uint8_t> on_path(n);
        auto dfs = [&](this auto&& dfs) -> void {
            if (!path.empty() && !f(path)) {
                return;
            }

            if (path.size() == n) {
                return;
            }

            // 枚举nums[j]填入path[i]
            for (int j = 0; j < n; j++) {
                if (on_path[j] || j > 0 && nums[j - 1] == nums[j] && !on_path[j - 1]) {
                    continue;
                }

                path += nums[j];
                on_path[j] = true;
                dfs();
                on_path[j] = false;
                path.pop_back();
            }
        };
        dfs();
    }

    // 返回 seq*k 是否为 s 的子序列
    bool isSubSequence(const string& seq, int k, const string& s) {
        int n = seq.size();
        int i = 0;
        for (char c : s) {
            if (seq[i % n] == c) {
                i++;
                if (i == n * k) { // seq*k 的所有字符匹配完毕
                    return true; // seq*k 是 s 的子序列
                }
            }
        }
        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int cnt[26]{};
        for (char c : s) {
            cnt[c - 'a']++;
        }

        string a;
        for (int i = 25; i >= 0; i--) {
            a.insert(a.end(), cnt[i] / k, 'a' + i);
        }

        string res;
        permuteFunc(a, [&](const string& seq) -> bool {
            if (!isSubSequence(seq, k, s)) {
                return false;
            }
            if (seq.size() > res.size() || seq.size() == res.size() && seq > res) {
                res = seq;
            }
            return true;
        });
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "letsleetcode"\n2\n
// @lcpr case=end

// @lcpr case=start
// "bb"\n2\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n2\n
// @lcpr case=end

 */

