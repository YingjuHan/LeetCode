/*
 * @lc app=leetcode.cn id=2901 lang=cpp
 * @lcpr version=30204
 *
 * [2901] 最长相邻不相等子序列 II
 *
 * https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-ii/description/
 *
 * algorithms
 * Medium (55.20%)
 * Likes:    52
 * Dislikes: 0
 * Total Accepted:    14.5K
 * Total Submissions: 26.3K
 * Testcase Example:  '["bab","dab","cab"]\n[1,2,2]'
 *
 * 给定一个字符串数组 words ，和一个数组 groups ，两个数组长度都是 n 。
 * 
 * 两个长度相等字符串的 汉明距离 定义为对应位置字符 不同 的数目。
 * 
 * 你需要从下标 [0, 1, ..., n - 1] 中选出一个 最长子序列 ，将这个子序列记作长度为 k 的 [i0, i1, ..., ik - 1]
 * ，它需要满足以下条件：
 * 
 * 
 * 相邻 下标对应的 groups 值 不同。即，对于所有满足 0 < j + 1 < k 的 j 都有 groups[ij] != groups[ij +
 * 1] 。
 * 对于所有 0 < j + 1 < k 的下标 j ，都满足 words[ij] 和 words[ij + 1] 的长度 相等 ，且两个字符串之间的
 * 汉明距离 为 1 。
 * 
 * 
 * 请你返回一个字符串数组，它是下标子序列 依次 对应 words 数组中的字符串连接形成的字符串数组。如果有多个答案，返回任意一个。
 * 
 * 子序列 指的是从原数组中删掉一些（也可能一个也不删掉）元素，剩余元素不改变相对位置得到的新的数组。
 * 
 * 注意：words 中的字符串长度可能 不相等 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：words = ["bab","dab","cab"], groups = [1,2,2]
 * 输出：["bab","cab"]
 * 解释：一个可行的子序列是 [0,2] 。
 * - groups[0] != groups[2]
 * - words[0].length == words[2].length 且它们之间的汉明距离为 1 。
 * 所以一个可行的答案是 [words[0],words[2]] = ["bab","cab"] 。
 * 另一个可行的子序列是 [0,1] 。
 * - groups[0] != groups[1]
 * - words[0].length = words[1].length 且它们之间的汉明距离为 1 。
 * 所以另一个可行的答案是 [words[0],words[1]] = ["bab","dab"] 。
 * 符合题意的最长子序列的长度为 2 。
 * 
 * 示例 2：
 * 
 * 输入：words = ["a","b","c","d"], groups = [1,2,3,4]
 * 输出：["a","b","c","d"]
 * 解释：我们选择子序列 [0,1,2,3] 。
 * 它同时满足两个条件。
 * 所以答案为 [words[0],words[1],words[2],words[3]] = ["a","b","c","d"] 。
 * 它是所有下标子序列里最长且满足所有条件的。
 * 所以它是唯一的答案。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n == words.length == groups.length <= 1000
 * 1 <= words[i].length <= 10
 * 1 <= groups[i] <= n
 * words 中的字符串 互不相同 。
 * words[i] 只包含小写英文字母。
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
    bool isHammingOne(string& s, string& t) {
        if (s.length() != t.length()) {
            return false;
        }
        bool diff = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) {
                if (diff) {
                    return false;
                }
                diff = true;
            }
        }
        return diff;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        // 1. 初始化 f 为 1（每个单词本身就是长度为 1 的序列）
        // 以第 i 个单词作为序列的“起点”时，能够形成的最长合法子序列的长度

        // 2. 初始化 from 为 -1（作为终点标记）
        vector<int> f(n, 1), from(n, -1);
        int max_len = 1, start_node = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                // 这里假设题目要求：groups 不同 且 汉明距离为 1
                if (groups[i] != groups[j] && isHammingOne(words[i], words[j])) {
                    if (f[j] + 1 > f[i]) {
                        f[i] = f[j] + 1;
                        from[i] = j;
                    }
                }
            }
            // 更新全局最长起点
            if (f[i] >= max_len) {
                max_len = f[i];
                start_node = i;
            }
        }

        vector<string> ans;
        for (int i = start_node; i != -1; i = from[i]) {
            ans.push_back(words[i]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["bab","dab","cab"]\n[1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// ["a","b","c","d"]\n[1,2,3,4]\n
// @lcpr case=end

 */

