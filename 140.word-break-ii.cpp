/*
 * @lc app=leetcode.cn id=140 lang=cpp
 * @lcpr version=30204
 *
 * [140] 单词拆分 II
 *
 * https://leetcode.cn/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (61.03%)
 * Likes:    801
 * Dislikes: 0
 * Total Accepted:    115.6K
 * Total Submissions: 189.2K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * 给定一个字符串 s 和一个字符串字典 wordDict ，在字符串 s 中增加空格来构建一个句子，使得句子中所有的单词都在词典中。以任意顺序
 * 返回所有这些可能的句子。
 * 
 * 注意：词典中的同一个单词可能在分段中被重复使用多次。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入:s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
 * 输出:["cats and dog","cat sand dog"]
 * 
 * 
 * 示例 2：
 * 
 * 输入:s = "pineapplepenapple", wordDict =
 * ["apple","pen","applepen","pine","pineapple"]
 * 输出:["pine apple pen apple","pineapple pen apple","pine applepen apple"]
 * 解释: 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 输入:s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * 输出:[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 
 * 1 <= s.length <= 20
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 10
 * s 和 wordDict[i] 仅有小写英文字母组成
 * wordDict 中所有字符串都 不同
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
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // 将字典转换为哈希集合，提高查找效率
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        
        // 计算字典中单词的最大长度，限制搜索范围
        int max_len = 0;
        for (const string& word : wordDict) {
            max_len = max(max_len, (int)word.size());
        }

        // 动态规划预处理：dp[i]表示s[i..n-1]能否被拆分
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        for (int i = n - 1; i >= 0; i--) {
            int end = min(i + max_len, n);
            for (int j = i + 1; j <= end; j++) {
                if (dp[j] && dict.count(s.substr(i, j - i))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        vector<string> res;
        if (!dp[0]) {
            return res;
        }

        vector<string> path;
        
        auto dfs = [&](this auto&& dfs, int start) -> void {
            if (start == n) {
                string t;
                for (int i = 0; i < path.size(); i++) {
                    if (i > 0) {
                        t += " ";
                    }
                    t += path[i];
                }
                res.push_back(t);
                return;
            }

            int end_time = min(start + max_len, n);
            for (int end = start + 1; end <= end_time; end++) {
                string word = s.substr(start, end - start);
                if (dict.count(word) && dp[end]) {
                    path.push_back(word);
                    dfs(end);
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "catsanddog"\n["cat","cats","and","sand","dog"]\n
// @lcpr case=end

// @lcpr case=start
// "pineapplepenapple"\n["apple","pen","applepen","pine","pineapple"]\n
// @lcpr case=end

// @lcpr case=start
// "catsandog"\n["cats","dog","sand","and","cat"]\n
// @lcpr case=end

 */

