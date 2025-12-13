/*
 * @lc app=leetcode.cn id=3045 lang=cpp
 * @lcpr version=30204
 *
 * [3045] 统计前后缀下标对 II
 *
 * https://leetcode.cn/problems/count-prefix-and-suffix-pairs-ii/description/
 *
 * algorithms
 * Hard (33.91%)
 * Likes:    25
 * Dislikes: 0
 * Total Accepted:    4.6K
 * Total Submissions: 13.6K
 * Testcase Example:  '["a","aba","ababa","aa"]'
 *
 * 给你一个下标从 0 开始的字符串数组 words 。
 * 
 * 定义一个 布尔 函数 isPrefixAndSuffix ，它接受两个字符串参数 str1 和 str2 ：
 * 
 * 
 * 当 str1 同时是 str2 的前缀（prefix）和后缀（suffix）时，isPrefixAndSuffix(str1, str2) 返回
 * true，否则返回 false。
 * 
 * 
 * 例如，isPrefixAndSuffix("aba", "ababa") 返回 true，因为 "aba" 既是 "ababa" 的前缀，也是
 * "ababa" 的后缀，但是 isPrefixAndSuffix("abc", "abcd") 返回 false。
 * 
 * 以整数形式，返回满足 i < j 且 isPrefixAndSuffix(words[i], words[j]) 为 true 的下标对 (i, j)
 * 的 数量 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：words = ["a","aba","ababa","aa"]
 * 输出：4
 * 解释：在本示例中，计数的下标对包括：
 * i = 0 且 j = 1 ，因为 isPrefixAndSuffix("a", "aba") 为 true 。
 * i = 0 且 j = 2 ，因为 isPrefixAndSuffix("a", "ababa") 为 true 。
 * i = 0 且 j = 3 ，因为 isPrefixAndSuffix("a", "aa") 为 true 。
 * i = 1 且 j = 2 ，因为 isPrefixAndSuffix("aba", "ababa") 为 true 。
 * 因此，答案是 4 。
 * 
 * 示例 2：
 * 
 * 输入：words = ["pa","papa","ma","mama"]
 * 输出：2
 * 解释：在本示例中，计数的下标对包括：
 * i = 0 且 j = 1 ，因为 isPrefixAndSuffix("pa", "papa") 为 true 。
 * i = 2 且 j = 3 ，因为 isPrefixAndSuffix("ma", "mama") 为 true 。
 * 因此，答案是 2 。
 * 
 * 示例 3：
 * 
 * 输入：words = ["abab","ab"]
 * 输出：0
 * 解释：在本示例中，唯一有效的下标对是 i = 0 且 j = 1 ，但是 isPrefixAndSuffix("abab", "ab") 为 false
 * 。
 * 因此，答案是 0 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= words.length <= 10^5
 * 1 <= words[i].length <= 10^5
 * words[i] 仅由小写英文字母组成。
 * 所有 words[i] 的长度之和不超过 5 * 10^5 。
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
#include <map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
struct Node
{
    map<pair<int, int>, Node*> son;
    int cnt = 0;
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long res = 0;
        Node* root = new Node();
        for (string& word : words) {
            int n = word.length();
            Node* cur = root;
            for (int i = 0; i < n; i++) {
                auto p = make_pair(word[i] - 'a', word[n - 1 - i] - 'a'); 
                if (cur->son[p] == nullptr) {
                    cur->son[p] = new Node();
                }
                cur = cur->son[p];
                res += cur->cnt;
            }
            cur->cnt++;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start  
// ["a","aba","ababa","aa"]\n
// @lcpr case=end

// @lcpr case=start
// ["pa","papa","ma","mama"]\n
// @lcpr case=end

// @lcpr case=start
// ["abab","ab"]\n
// @lcpr case=end

 */

