/*
 * @lc app=leetcode.cn id=3258 lang=cpp
 * @lcpr version=30204
 *
 * [3258] 统计满足 K 约束的子字符串数量 I
 *
 * https://leetcode.cn/problems/count-substrings-that-satisfy-k-constraint-i/description/
 *
 * algorithms
 * Easy (83.72%)
 * Likes:    61
 * Dislikes: 0
 * Total Accepted:    32.2K
 * Total Submissions: 38.5K
 * Testcase Example:  '"10101"\n1'
 *
 * 给你一个 二进制 字符串 s 和一个整数 k。
 * 
 * 如果一个 二进制字符串 满足以下任一条件，则认为该字符串满足 k 约束：
 * 
 * 
 * 字符串中 0 的数量最多为 k。
 * 字符串中 1 的数量最多为 k。
 * 
 * 
 * 返回一个整数，表示 s 的所有满足 k 约束 的子字符串的数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "10101", k = 1
 * 
 * 输出：12
 * 
 * 解释：
 * 
 * s 的所有子字符串中，除了 "1010"、"10101" 和 "0101" 外，其余子字符串都满足 k 约束。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "1010101", k = 2
 * 
 * 输出：25
 * 
 * 解释：
 * 
 * s 的所有子字符串中，除了长度大于 5 的子字符串外，其余子字符串都满足 k 约束。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "11111", k = 1
 * 
 * 输出：15
 * 
 * 解释：
 * 
 * s 的所有子字符串都满足 k 约束。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 50
 * 1 <= k <= s.length
 * s[i] 是 '0' 或 '1'。
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
    int countKConstraintSubstrings(string s, int k) {
        int res = 0, left = 0, right = 0;
        int cnt[2] {};

        while (right < s.length()) {
            cnt[s[right] & 1]++;
            right++;
            while (cnt[0] > k && cnt[1] > k) { // 最多为k，可以是小于k的（0也行）
                cnt[s[left] & 1]--;
                left++;
            }
            res += right - left; // [l-r]区间的子串数是r-l+1
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "10101"\n1\n
// @lcpr case=end

// @lcpr case=start
// "1010101"\n2\n
// @lcpr case=end

// @lcpr case=start
// "11111"\n1\n
// @lcpr case=end

 */

