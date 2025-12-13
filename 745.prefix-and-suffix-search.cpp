// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=745 lang=cpp
 * @lcpr version=30204
 *
 * [745] 前缀和后缀搜索
 *
 * https://leetcode.cn/problems/prefix-and-suffix-search/description/
 *
 * algorithms
 * Hard (43.76%)
 * Likes:    218
 * Dislikes: 0
 * Total Accepted:    27.5K
 * Total Submissions: 62.8K
 * Testcase Example:  '["WordFilter","f"]\n[[["apple"]],["a","e"]]'
 *
 * 设计一个包含一些单词的特殊词典，并能够通过前缀和后缀来检索单词。
 * 
 * 实现 WordFilter 类：
 * 
 * 
 * WordFilter(string[] words) 使用词典中的单词 words 初始化对象。
 * f(string pref, string suff) 返回词典中具有前缀 pref 和后缀 suff
 * 的单词的下标。如果存在不止一个满足要求的下标，返回其中 最大的下标 。如果不存在这样的单词，返回 -1 。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入
 * ["WordFilter", "f"]
 * [[["apple"]], ["a", "e"]]
 * 输出
 * [null, 0]
 * 解释
 * WordFilter wordFilter = new WordFilter(["apple"]);
 * wordFilter.f("a", "e"); // 返回 0 ，因为下标为 0 的单词：前缀 prefix = "a" 且 后缀 suffix =
 * "e" 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= words.length <= 10^4
 * 1 <= words[i].length <= 7
 * 1 <= pref.length, suff.length <= 7
 * words[i]、pref 和 suff 仅由小写英文字母组成
 * 最多对函数 f 执行 10^4 次调用
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
struct TrieNode {
    TrieNode* son[27]{};
    int index = -1;
    bool isEnd = false;
};
class WordFilter {
    
public:
    TrieNode* root = new TrieNode();
    WordFilter(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; i++) {
            string fullword = words[i] + '#' + words[i];
            int nWord = words[i].size();
            for (int j = 0; j < nWord + 1; j++) {
                TrieNode* cur = root;
                for (int k = j; k < fullword.size(); k++){
                    int idx = fullword[k] == '#' ? 26 : fullword[k] - 'a';
                    if (cur->son[idx] == nullptr) {
                        cur->son[idx] = new TrieNode();
                    }
                    cur = cur->son[idx];
                    cur->isEnd = true;
                    cur->index = i;
                }
            }
        }
    }
    
    int f(string pref, string suff) {
        string fullword = suff+ "#" + pref;
        TrieNode* cur = root;
        for (char c : fullword) {
            int idx = c == '#' ? 26 : c - 'a';
            if (cur->son[idx] == nullptr) {
                return -1;
            }
            cur = cur->son[idx];
        }
        return cur->index;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
// @lc code=end



