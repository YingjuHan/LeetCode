/*
 * @lc app=leetcode.cn id=3597 lang=cpp
 * @lcpr version=30204
 *
 * [3597] 分割字符串
 *
 * https://leetcode.cn/problems/partition-string/description/
 *
 * algorithms
 * Medium (67.39%)
 * Likes:    6
 * Dislikes: 0
 * Total Accepted:    4K
 * Total Submissions: 5.9K
 * Testcase Example:  '"abbccccd"'
 *
 * 给你一个字符串 s，按照以下步骤将其分割为 互不相同的段 ：
 * 
 * 
 * 从下标 0 开始构建一个段。
 * 逐字符扩展当前段，直到该段之前未曾出现过。
 * 只要当前段是唯一的，就将其加入段列表，标记为已经出现过，并从下一个下标开始构建新的段。
 * 重复上述步骤，直到处理完整个字符串 s。
 * 
 * 
 * 返回字符串数组 segments，其中 segments[i] 表示创建的第 i 段。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： s = "abbccccd"
 * 
 * 输出： ["a","b","bc","c","cc","d"]
 * 
 * 解释：
 * 
 * 
 * 
 * 
 * 下标
 * 添加后的段
 * 已经出现过的段
 * 当前段是否已经出现过？
 * 新段
 * 更新后已经出现过的段
 * 
 * 
 * 0
 * "a"
 * []
 * 否
 * ""
 * ["a"]
 * 
 * 
 * 1
 * "b"
 * ["a"]
 * 否
 * ""
 * ["a", "b"]
 * 
 * 
 * 2
 * "b"
 * ["a", "b"]
 * 是
 * "b"
 * ["a", "b"]
 * 
 * 
 * 3
 * "bc"
 * ["a", "b"]
 * 否
 * ""
 * ["a", "b", "bc"]
 * 
 * 
 * 4
 * "c"
 * ["a", "b", "bc"]
 * 否
 * ""
 * ["a", "b", "bc", "c"]
 * 
 * 
 * 5
 * "c"
 * ["a", "b", "bc", "c"]
 * 是
 * "c"
 * ["a", "b", "bc", "c"]
 * 
 * 
 * 6
 * "cc"
 * ["a", "b", "bc", "c"]
 * 否
 * ""
 * ["a", "b", "bc", "c", "cc"]
 * 
 * 
 * 7
 * "d"
 * ["a", "b", "bc", "c", "cc"]
 * 否
 * ""
 * ["a", "b", "bc", "c", "cc", "d"]
 * 
 * 
 * 
 * 
 * 因此，最终输出为 ["a", "b", "bc", "c", "cc", "d"]。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： s = "aaaa"
 * 
 * 输出： ["a","aa"]
 * 
 * 解释：
 * 
 * 
 * 
 * 
 * 下标
 * 添加后的段
 * 已经出现过的段
 * 当前段是否已经出现过？
 * 新段
 * 更新后已经出现过的段
 * 
 * 
 * 0
 * "a"
 * []
 * 否
 * ""
 * ["a"]
 * 
 * 
 * 1
 * "a"
 * ["a"]
 * 是
 * "a"
 * ["a"]
 * 
 * 
 * 2
 * "aa"
 * ["a"]
 * 否
 * ""
 * ["a", "aa"]
 * 
 * 
 * 3
 * "a"
 * ["a", "aa"]
 * 是
 * "a"
 * ["a", "aa"]
 * 
 * 
 * 
 * 
 * 因此，最终输出为 ["a", "aa"]。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s 仅包含小写英文字母。
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
};
class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string> res;
        Node* root = new Node();
        Node* cur = root;
        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (cur->son[c] == nullptr) {
                cur->son[c] = new Node();
                res.push_back(s.substr(left, i - left + 1));
                left = i + 1;
                cur = root;
            } else {
                cur = cur->son[c];
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abbccccd"\n
// @lcpr case=end

// @lcpr case=start
// "aaaa"\n
// @lcpr case=end

 */

