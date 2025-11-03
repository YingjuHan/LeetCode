/*
 * @lc app=leetcode.cn id=2506 lang=cpp
 * @lcpr version=30204
 *
 * [2506] 统计相似字符串对的数目
 *
 * https://leetcode.cn/problems/count-pairs-of-similar-strings/description/
 *
 * algorithms
 * Easy (84.10%)
 * Likes:    67
 * Dislikes: 0
 * Total Accepted:    31.4K
 * Total Submissions: 37.4K
 * Testcase Example:  '["aba","aabb","abcd","bac","aabc"]'
 *
 * 给你一个下标从 0 开始的字符串数组 words 。
 * 
 * 如果两个字符串由相同的字符组成，则认为这两个字符串 相似 。
 * 
 * 
 * 例如，"abca" 和 "cba" 相似，因为它们都由字符 'a'、'b'、'c' 组成。
 * 然而，"abacba" 和 "bcfd" 不相似，因为它们不是相同字符组成的。
 * 
 * 
 * 请你找出满足字符串 words[i] 和 words[j] 相似的下标对 (i, j) ，并返回下标对的数目，其中 0 <= i < j <=
 * words.length - 1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：words = ["aba","aabb","abcd","bac","aabc"]
 * 输出：2
 * 解释：共有 2 对满足条件：
 * - i = 0 且 j = 1 ：words[0] 和 words[1] 只由字符 'a' 和 'b' 组成。 
 * - i = 3 且 j = 4 ：words[3] 和 words[4] 只由字符 'a'、'b' 和 'c' 。 
 * 
 * 
 * 示例 2：
 * 
 * 输入：words = ["aabb","ab","ba"]
 * 输出：3
 * 解释：共有 3 对满足条件：
 * - i = 0 且 j = 1 ：words[0] 和 words[1] 只由字符 'a' 和 'b' 组成。 
 * - i = 0 且 j = 2 ：words[0] 和 words[2] 只由字符 'a' 和 'b' 组成。 
 * - i = 1 且 j = 2 ：words[1] 和 words[2] 只由字符 'a' 和 'b' 组成。 
 * 
 * 
 * 示例 3：
 * 
 * 输入：words = ["nba","cba","dba"]
 * 输出：0
 * 解释：不存在满足条件的下标对，返回 0 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 100
 * words[i] 仅由小写英文字母组成
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
#include <set>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int, int> mp;
        int res = 0;
        for (string& word : words) {
            int state = 0;
            for (char c : word) {
                state |= 1 << (c - 'a');
            }

            res += mp[state];
            mp[state]++;
        }
        return res;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["aba","aabb","abcd","bac","aabc"]\n
// @lcpr case=end

// @lcpr case=start
// ["aabb","ab","ba"]\n
// @lcpr case=end

// @lcpr case=start
// ["nba","cba","dba"]\n
// @lcpr case=end

 */

