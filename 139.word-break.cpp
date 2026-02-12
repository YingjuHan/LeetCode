/*
 * @lc app=leetcode.cn id=139 lang=cpp
 * @lcpr version=30204
 *
 * [139] 单词拆分
 *
 * https://leetcode.cn/problems/word-break/description/
 *
 * algorithms
 * Medium (59.55%)
 * Likes:    2900
 * Dislikes: 0
 * Total Accepted:    963.9K
 * Total Submissions: 1.6M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
 * 
 * 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
 * 
 * 
 * 示例 2：
 * 
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
 * 注意，你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 300
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 20
 * s 和 wordDict[i] 仅由小写英文字母组成
 * wordDict 中的所有字符串 互不相同
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
    bool wordBreak1(string s, vector<string>& wordDict) {
        int max_len = ranges::max(wordDict, {}, &string::size).size();
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        int n = s.size();
        vector<int> memo(n + 1, -1); // -1 表示没有计算过

        auto dfs = [&](this auto&& dfs, int i) -> bool {
            if (i == 0) { // 成功拆分！
                return true;
            }
            int& res = memo[i]; // 注意这里是引用
            if (res != -1) { // 之前计算过
                return res;
            }
            for (int j = i - 1; j >= max(i - max_len, 0); j--) {
                if (words.contains(s.substr(j, i - j)) && dfs(j)) {
                    return res = true; // 记忆化
                }
            }
            return res = false; // 记忆化
        };

        return dfs(n);
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int max_len = ranges::max(wordDict, {}, &string::size).size();
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        
        int n = s.size();
        vector<int> f(n + 1);
        f[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= max(i - max_len, 0); j--) {
                if (words.count(s.substr(j, i - j)) && f[j]) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
};  
// @lc code=end



/*
// @lcpr case=start
// "leetcode"\n["leet", "code"]\n
// @lcpr case=end

// @lcpr case=start
// "applepenapple"\n["apple", "pen"]\n
// @lcpr case=end

// @lcpr case=start
// "catsandog"\n["cats", "dog", "sand", "and", "cat"]\n
// @lcpr case=end

 */

