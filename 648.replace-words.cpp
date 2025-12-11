/*
 * @lc app=leetcode.cn id=648 lang=cpp
 * @lcpr version=30204
 *
 * [648] 单词替换
 *
 * https://leetcode.cn/problems/replace-words/description/
 *
 * algorithms
 * Medium (63.86%)
 * Likes:    346
 * Dislikes: 0
 * Total Accepted:    87.2K
 * Total Submissions: 136.6K
 * Testcase Example:  '["cat","bat","rat"]\n"the cattle was rattled by the battery"'
 *
 * 在英语中，我们有一个叫做 词根(root) 的概念，可以词根 后面 添加其他一些词组成另一个较长的单词——我们称这个词为 衍生词
 * (derivative)。例如，词根 help，跟随着 继承词 "ful"，可以形成新的单词 "helpful"。
 * 
 * 现在，给定一个由许多 词根 组成的词典 dictionary 和一个用空格分隔单词形成的句子 sentence。你需要将句子中的所有 衍生词 用 词根
 * 替换掉。如果 衍生词 有许多可以形成它的 词根，则用 最短 的 词根 替换它。
 * 
 * 你需要输出替换之后的句子。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by
 * the battery"
 * 输出："the cat was rat by the bat"
 * 
 * 
 * 示例 2：
 * 
 * 输入：dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
 * 输出："a a b c"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= dictionary.length <= 1000
 * 1 <= dictionary[i].length <= 100
 * dictionary[i] 仅由小写字母组成。
 * 1 <= sentence.length <= 10^6
 * sentence 仅由小写字母和空格组成。
 * sentence 中单词的总量在范围 [1, 1000] 内。
 * sentence 中每个单词的长度在范围 [1, 1000] 内。
 * sentence 中单词之间由一个空格隔开。
 * sentence 没有前导或尾随空格。
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
struct Node {
    Node* son[26]{};  // 默认初始化为 nullptr
    bool isEnd = false;
};

class Solution {
private:
    Node* root;

    void insert(const string& word) {
        // 不要在这里重新分配 root！
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

    string findShortestRoot(const string& word) {
        Node* cur = root;
        string prefix;
        for (char c : word) {
            int idx = c - 'a';
            if (cur->son[idx] == nullptr) {
                // 找不到匹配前缀，返回原单词
                return word;
            }
            cur = cur->son[idx];
            prefix += c;
            if (cur->isEnd) {
                // 找到最短根
                return prefix;
            }
        }
        // 走完也没遇到单词结尾，返回原单词
        return word;
    }

public:
    Solution() : root(nullptr) {}

    string replaceWords(vector<string>& dictionary, string sentence) {
        // 每次调用时重新建一棵 Trie
        root = new Node();

        for (const string& word : dictionary) {
            insert(word);
        }

        stringstream ss(sentence);
        string word, result;
        while (ss >> word) {
            if (!result.empty()) {
                result += " ";
            }
            result += findShortestRoot(word);
        }
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["cat","bat","rat"]\n"the cattle was rattled by the battery"\n
// @lcpr case=end

// @lcpr case=start
// ["a","b","c"]\n"aadsfasf absbs bbab cadsfafs"\n
// @lcpr case=end

 */

