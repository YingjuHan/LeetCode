/*
 * @lc app=leetcode.cn id=720 lang=cpp
 * @lcpr version=30204
 *
 * [720] 词典中最长的单词
 *
 * https://leetcode.cn/problems/longest-word-in-dictionary/description/
 *
 * algorithms
 * Medium (52.56%)
 * Likes:    365
 * Dislikes: 0
 * Total Accepted:    74K
 * Total Submissions: 140.8K
 * Testcase Example:  '["w","wo","wor","worl","world"]'
 *
 * 给出一个字符串数组 words 组成的一本英语词典。返回能够通过 words 中其它单词逐步添加一个字母来构造得到的 words 中最长的单词。
 * 
 * 若其中有多个可行的答案，则返回答案中字典序最小的单词。若无答案，则返回空字符串。
 * 
 * 请注意，单词应该从左到右构建，每个额外的字符都添加到前一个单词的结尾。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：words = ["w","wo","wor","worl", "world"]
 * 输出："world"
 * 解释： 单词"world"可由"w", "wo", "wor", 和 "worl"逐步添加一个字母组成。
 * 
 * 
 * 示例 2：
 * 
 * 输入：words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
 * 输出："apple"
 * 解释："apply" 和 "apple" 都能由词典中的单词组成。但是 "apple" 的字典序小于 "apply" 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 30
 * 所有输入的字符串 words[i] 都只包含小写字母。
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
struct Node
{
    Node* son[26]{};
    bool isEnd = false;
};

class Trie {
private:
    Node* root = new Node();

    int find(const string& word) {
        Node* cur = root;
        for (char c : word) {
            c -= 'a';
            if (cur->son[c] == nullptr) {
                return 0;
            }
            cur = cur->son[c];
        }
        return cur->isEnd ? 2 : 1;
    }

    void destory(Node* node) {
        if (node == nullptr) {
            return;
        }
        for (Node* son : node->son) {
            destory(son);
        }
        delete node;
    }
public:
    Trie() {}
    virtual ~Trie() {
        destory(root);
    }

    void insert(string word) {
        Node* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (cur->son[idx] == nullptr) {
                cur->son[idx] = new Node();
            }
            cur = cur->son[idx];
        }
        cur->isEnd = true;
    }

    bool search(const string& word) {
        Node* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (cur->son[idx] == nullptr || cur->son[idx]->isEnd == false) {
                return false;
            }
            cur = cur->son[idx];
        }
        return cur != nullptr && cur->isEnd == true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for (const string& word : words) {
            trie.insert(word);
        }

        string res = "";
        for (const string& word : words) {
            if (trie.search(word)) {
                if (word.size() > res.size() || (word.size() == res.size() && word < res)) {
                    res = word;
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["w","wo","wor","worl", "world"]\n
// @lcpr case=end

// @lcpr case=start
// ["a", "banana", "app", "appl", "ap", "apply", "apple"]\n
// @lcpr case=end

 */

