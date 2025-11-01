/*
 * @lc app=leetcode.cn id=3370 lang=cpp
 * @lcpr version=30204
 *
 * [3370] 仅含置位位的最小整数
 *
 * https://leetcode.cn/problems/smallest-number-with-all-set-bits/description/
 *
 * algorithms
 * Easy (81.89%)
 * Likes:    8
 * Dislikes: 0
 * Total Accepted:    12.2K
 * Total Submissions: 14.7K
 * Testcase Example:  '5'
 *
 * 给你一个正整数 n。
 * 
 * 返回 大于等于 n 且二进制表示仅包含 置位 位的 最小 整数 x 。
 * 
 * 置位 位指的是二进制表示中值为 1 的位。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： n = 5
 * 
 * 输出： 7
 * 
 * 解释：
 * 
 * 7 的二进制表示是 "111"。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： n = 10
 * 
 * 输出： 15
 * 
 * 解释：
 * 
 * 15 的二进制表示是 "1111"。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入： n = 3
 * 
 * 输出： 3
 * 
 * 解释：
 * 
 * 3 的二进制表示是 "11"。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 1000
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
    int smallestNumber(int n) {
        int x = 1;
        while (x < n) {
            x = x * 2 + 1;
        }
        return x;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */

