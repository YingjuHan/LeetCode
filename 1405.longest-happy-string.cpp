/*
 * @lc app=leetcode.cn id=1405 lang=cpp
 * @lcpr version=30204
 *
 * [1405] 最长快乐字符串
 *
 * https://leetcode.cn/problems/longest-happy-string/description/
 *
 * algorithms
 * Medium (63.39%)
 * Likes:    241
 * Dislikes: 0
 * Total Accepted:    32.9K
 * Total Submissions: 51.9K
 * Testcase Example:  '1\n1\n7'
 *
 * 如果字符串中不含有任何 'aaa'，'bbb' 或 'ccc' 这样的字符串作为子串，那么该字符串就是一个「快乐字符串」。
 * 
 * 给你三个整数 a，b ，c，请你返回 任意一个 满足下列全部条件的字符串 s：
 * 
 * 
 * s 是一个尽可能长的快乐字符串。
 * s 中 最多 有a 个字母 'a'、b 个字母 'b'、c 个字母 'c' 。
 * s 中只含有 'a'、'b' 、'c' 三种字母。
 * 
 * 
 * 如果不存在这样的字符串 s ，请返回一个空字符串 ""。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：a = 1, b = 1, c = 7
 * 输出："ccaccbcc"
 * 解释："ccbccacc" 也是一种正确答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：a = 2, b = 2, c = 1
 * 输出："aabbc"
 * 
 * 
 * 示例 3：
 * 
 * 输入：a = 7, b = 1, c = 0
 * 输出："aabaa"
 * 解释：这是该测试用例的唯一正确答案。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= a, b, c <= 100
 * a + b + c > 0
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
    string longestDiverseString(int a, int b, int c) {
        string ans;
        while (a  + b + c > 0) {
            char choose = '-';
            int chlen = 0;
            int xsize = ans.size();
            if (a > chlen && (xsize < 2 || ans[xsize-1] != 'a' || ans[xsize-2] != 'a')) {
                chlen = a;
                choose = 'a';
            }
            if (b > chlen && (xsize < 2 || ans[xsize-1] != 'b' || ans[xsize-2] != 'b')) {
                chlen = b;
                choose = 'b';
            }
            if (c > chlen && (xsize < 2 || ans[xsize-1] != 'c' || ans[xsize-2] != 'c')) {
                chlen = c;
                choose = 'c';
            }
            if (choose == '-') break;
            ans.append(1, choose);
            if (choose == 'a') a--;
            else if (choose == 'b') b--;
            else if (choose == 'c') c--;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n1\n7\n
// @lcpr case=end

// @lcpr case=start
// 2\n2\n1\n
// @lcpr case=end

// @lcpr case=start
// 7\n1\n0\n
// @lcpr case=end

 */

