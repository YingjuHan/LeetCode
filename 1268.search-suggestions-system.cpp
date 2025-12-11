/*
 * @lc app=leetcode.cn id=1268 lang=cpp
 * @lcpr version=30204
 *
 * [1268] 搜索推荐系统
 *
 * https://leetcode.cn/problems/search-suggestions-system/description/
 *
 * algorithms
 * Medium (62.23%)
 * Likes:    217
 * Dislikes: 0
 * Total Accepted:    30.1K
 * Total Submissions: 48.4K
 * Testcase Example:  '["mobile","mouse","moneypot","monitor","mousepad"]\n"mouse"'
 *
 * 给你一个产品数组 products 和一个字符串 searchWord ，products  数组中每个产品都是一个字符串。
 * 
 * 请你设计一个推荐系统，在依次输入单词 searchWord 的每一个字母后，推荐 products 数组中前缀与 searchWord
 * 相同的最多三个产品。如果前缀相同的可推荐产品超过三个，请按字典序返回最小的三个。
 * 
 * 请你以二维列表的形式，返回在输入 searchWord 每个字母后相应的推荐产品的列表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord
 * = "mouse"
 * 输出：[
 * ["mobile","moneypot","monitor"],
 * ["mobile","moneypot","monitor"],
 * ["mouse","mousepad"],
 * ["mouse","mousepad"],
 * ["mouse","mousepad"]
 * ]
 * 解释：按字典序排序后的产品列表是 ["mobile","moneypot","monitor","mouse","mousepad"]
 * 输入 m 和 mo，由于所有产品的前缀都相同，所以系统返回字典序最小的三个产品 ["mobile","moneypot","monitor"]
 * 输入 mou， mous 和 mouse 后系统都返回 ["mouse","mousepad"]
 * 
 * 
 * 示例 2：
 * 
 * 输入：products = ["havana"], searchWord = "havana"
 * 输出：[["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
 * 
 * 
 * 示例 3：
 * 
 * 输入：products = ["bags","baggage","banner","box","cloths"], searchWord =
 * "bags"
 * 
 * 输出：[["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
 * 
 * 
 * 示例 4：
 * 
 * 输入：products = ["havana"], searchWord = "tatiana"
 * 输出：[[],[],[],[],[],[],[]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= products.length <= 1000
 * 1 <= Σ products[i].length <= 2 * 10^4
 * products[i] 中所有的字符都是小写英文字母。
 * 1 <= searchWord.length <= 1000
 * searchWord 中所有字符都是小写英文字母。
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
    Node* son[26]{};
    priority_queue<string> pq;
};

class Solution {
    Node* root;
    void insert(string& word) {
        Node* cur = root;
        for (char c : word) {
            c -= 'a';
            if (cur->son[c] == nullptr) {
                cur->son[c] = new Node();
            }
            cur = cur->son[c];

            cur->pq.emplace(word);
            if (cur->pq.size() > 3) {
                cur->pq.pop();
            }
        }
    }

    void search(string& searchWord, vector<vector<string>>& res) {
        Node* cur = root;
        int i = 0;
        for (char c : searchWord) {
            cur = cur->son[c - 'a'];
            if (cur == nullptr) {
                return;
            }
            while (!cur->pq.empty()) {
                res[i].emplace_back(cur->pq.top());
                cur->pq.pop();
            }
            reverse(res[i].begin(), res[i].end());
            i++;
        }
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new Node();
        for (string& s : products) {
            insert(s);
        }
        int m = searchWord.size();
        vector<vector<string>> res(m);
        search(searchWord, res);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["mobile","mouse","moneypot","monitor","mousepad"]\n"mouse"\n
// @lcpr case=end

// @lcpr case=start
// ["havana"]\n"havana"\n
// @lcpr case=end

// @lcpr case=start
// ["bags","baggage","banner","box","cloths"]\n"bags"\n
// @lcpr case=end

// @lcpr case=start
// ["havana"]\n"tatiana"\n
// @lcpr case=end

 */

