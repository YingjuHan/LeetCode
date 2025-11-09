/*
 * @lc app=leetcode.cn id=2559 lang=cpp
 * @lcpr version=30204
 *
 * [2559] 统计范围内的元音字符串数
 *
 * https://leetcode.cn/problems/count-vowel-strings-in-ranges/description/
 *
 * algorithms
 * Medium (64.67%)
 * Likes:    92
 * Dislikes: 0
 * Total Accepted:    34.6K
 * Total Submissions: 51.7K
 * Testcase Example:  '["aba","bcb","ece","aa","e"]\n[[0,2],[1,4],[1,1]]'
 *
 * 给你一个下标从 0 开始的字符串数组 words 以及一个二维整数数组 queries 。
 * 
 * 每个查询 queries[i] = [li, ri] 会要求我们统计在 words 中下标在 li 到 ri 范围内（包含
 * 这两个值）并且以元音开头和结尾的字符串的数目。
 * 
 * 返回一个整数数组，其中数组的第 i 个元素对应第 i 个查询的答案。
 * 
 * 注意：元音字母是 'a'、'e'、'i'、'o' 和 'u' 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
 * 输出：[2,3,0]
 * 解释：以元音开头和结尾的字符串是 "aba"、"ece"、"aa" 和 "e" 。
 * 查询 [0,2] 结果为 2（字符串 "aba" 和 "ece"）。
 * 查询 [1,4] 结果为 3（字符串 "ece"、"aa"、"e"）。
 * 查询 [1,1] 结果为 0 。
 * 返回结果 [2,3,0] 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
 * 输出：[3,2,1]
 * 解释：每个字符串都满足这一条件，所以返回 [3,2,1] 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= words.length <= 10^5
 * 1 <= words[i].length <= 40
 * words[i] 仅由小写英文字母组成
 * sum(words[i].length) <= 3 * 10^5
 * 1 <= queries.length <= 10^5
 * 0 <= queries[j][0] <= queries[j][1] < words.length
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
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        auto check = [](char c) -> bool {
            // if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            //     return true;
            // }
            // return false;

            return 1065233 >> (c - 'a') & 1;
        };
        // int n = words.size();
        // vector<int> nums(n, 0);
        // for (int i = 0; i < n; i++) {
        //     string word = words[i];
        //     if (check(word[0]) && check(word[word.size() - 1])) {
        //         nums[i] = 1;
        //     }
        // }
        // vector<int> preSum(n + 1, 0);
        // for (int i = 0; i < n; i++) {
        //     preSum[i + 1] = preSum[i] + nums[i];
        // }
        // vector<int> res(queries.size(), 0);
        // for (int k = 0; k < queries.size(); k++) {
        //     res[k] = preSum[queries[k][1] + 1] - preSum[queries[k][0]];
        // }
        // return res;

        int m = words.size();
        vector<int> pref(m + 1);
        for (int i = 0; i < m; i++) {
            string s = words[i];
            pref[i + 1] = (check(s.front()) & check(s.back())) + pref[i];
        }
        int n = queries.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int l = queries[i][0], r = queries[i][1];
            ans[i] = pref[r + 1] - pref[l];
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["aba","bcb","ece","aa","e"]\n[[0,2],[1,4],[1,1]]\n
// @lcpr case=end

// @lcpr case=start
// ["a","e","i"]\n[[0,2],[0,1],[2,2]]\n
// @lcpr case=end

 */

