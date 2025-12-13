/*
 * @lc app=leetcode.cn id=676 lang=cpp
 * @lcpr version=30204
 *
 * [676] 实现一个魔法字典
 *
 * https://leetcode.cn/problems/implement-magic-dictionary/description/
 *
 * algorithms
 * Medium (67.08%)
 * Likes:    268
 * Dislikes: 0
 * Total Accepted:    59.1K
 * Total Submissions: 88.2K
 * Testcase Example:  '["MagicDictionary", "buildDict", "search", "search", "search", "search"]\n' +
  '[[], [["hello","leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]'
 *
 * 设计一个使用单词列表进行初始化的数据结构，单词列表中的单词 互不相同 。
 * 如果给出一个单词，请判定能否只将这个单词中一个字母换成另一个字母，使得所形成的新单词存在于你构建的字典中。
 * 
 * 实现 MagicDictionary 类：
 * 
 * 
 * MagicDictionary() 初始化对象
 * void buildDict(String[] dictionary) 使用字符串数组 dictionary 设定该数据结构，dictionary
 * 中的字符串互不相同
 * bool search(String searchWord) 给定一个字符串 searchWord ，判定能否只将字符串中 一个
 * 字母换成另一个字母，使得所形成的新字符串能够与字典中的任一字符串匹配。如果可以，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入
 * ["MagicDictionary", "buildDict", "search", "search", "search", "search"]
 * [[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
 * 输出
 * [null, null, false, true, false, false]
 * 
 * 解释
 * MagicDictionary magicDictionary = new MagicDictionary();
 * magicDictionary.buildDict(["hello", "leetcode"]);
 * magicDictionary.search("hello"); // 返回 False
 * magicDictionary.search("hhllo"); // 将第二个 'h' 替换为 'e' 可以匹配 "hello" ，所以返回 True
 * magicDictionary.search("hell"); // 返回 False
 * magicDictionary.search("leetcoded"); // 返回 False
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= dictionary.length <= 100
 * 1 <= dictionary[i].length <= 100
 * dictionary[i] 仅由小写英文字母组成
 * dictionary 中的所有字符串 互不相同
 * 1 <= searchWord.length <= 100
 * searchWord 仅由小写英文字母组成
 * buildDict 仅在 search 之前调用一次
 * 最多调用 100 次 search
 * 
 * 
 * 
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
    TrieNode* son[26]{};
    bool isEnd = false;
};
class MagicDictionary {
    TrieNode* root;
public:
    MagicDictionary() {
        root = new TrieNode();
    }
    
    void buildDict(vector<string> dictionary) {
        for (auto& word : dictionary) {
            TrieNode* cur = root;
            for (char c : word) {
                if (cur->son[c - 'a'] == nullptr) {
                    cur->son[c - 'a'] = new TrieNode();
                }
                cur = cur->son[c - 'a'];
            }
            cur->isEnd = true;
        }
    }
    
    bool search(string searchWord) {
        function<bool(TrieNode*, int, bool)> dfs = [&](TrieNode* node, int pos, bool modified) {
            if (pos == searchWord.size()) {
                return modified && node->isEnd;
            }

            int idx = searchWord[pos] - 'a';
            if (node->son[idx]) {
                if (dfs(node->son[idx], pos + 1, modified)) {
                    return true;
                }
            }

            if (!modified) {
                for (int i = 0; i < 26; i++) {
                    if (i != idx && node->son[i]) {
                        if (dfs(node->son[i], pos + 1, true)) {
                            return true;
                        }
                    }
                }
            }
            return false;
        };
        return dfs(root, 0, false);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
// @lc code=end



