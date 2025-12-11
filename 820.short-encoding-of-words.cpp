/*
 * @lc app=leetcode.cn id=820 lang=cpp
 * @lcpr version=30204
 *
 * [820] 单词的压缩编码
 *
 * https://leetcode.cn/problems/short-encoding-of-words/description/
 *
 * algorithms
 * Medium (52.80%)
 * Likes:    341
 * Dislikes: 0
 * Total Accepted:    77.2K
 * Total Submissions: 146.1K
 * Testcase Example:  '["time","me","bell"]'
 *
 * 单词数组 words 的 有效编码 由任意助记字符串 s 和下标数组 indices 组成，且满足：
 * 
 * 
 * words.length == indices.length
 * 助记字符串 s 以 '#' 字符结尾
 * 对于每个下标 indices[i] ，s 的一个从 indices[i] 开始、到下一个 '#' 字符结束（但不包括 '#'）的 子字符串 恰好与
 * words[i] 相等
 * 
 * 
 * 给你一个单词数组 words ，返回成功对 words 进行编码的最小助记字符串 s 的长度 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：words = ["time", "me", "bell"]
 * 输出：10
 * 解释：一组有效编码为 s = "time#bell#" 和 indices = [0, 2, 5] 。
 * words[0] = "time" ，s 开始于 indices[0] = 0 到下一个 '#' 结束的子字符串，如加粗部分所示
 * "time#bell#"
 * words[1] = "me" ，s 开始于 indices[1] = 2 到下一个 '#' 结束的子字符串，如加粗部分所示 "time#bell#"
 * words[2] = "bell" ，s 开始于 indices[2] = 5 到下一个 '#' 结束的子字符串，如加粗部分所示
 * "time#bell#"
 * 
 * 
 * 示例 2：
 * 
 * 输入：words = ["t"]
 * 输出：2
 * 解释：一组有效编码为 s = "t#" 和 indices = [0] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= words.length <= 2000
 * 1 <= words[i].length <= 7
 * words[i] 仅由小写字母组成
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
class TrieNode {
    TrieNode* son[26]{};
public:
    int count = 0;
public:
    TrieNode* get(char c) {
        if (son[c - 'a'] == nullptr) {
            son[c - 'a'] = new TrieNode();
            count++;
        }
        return son[c - 'a'];
    }
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode* trie = new TrieNode();
        unordered_map<TrieNode*, int> nodes;

        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            TrieNode* cur = trie;
            for (int j = word.length() - 1; j >= 0; j--) {
                cur = cur->get(word[j]);
            }
            nodes[cur] = i;
        }

        int res = 0;
        for (auto& [node, idx] : nodes) {
            if (node->count == 0) {
                res += words[idx].length() + 1;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["time", "me", "bell"]\n
// @lcpr case=end

// @lcpr case=start
// ["t"]\n
// @lcpr case=end

 */

