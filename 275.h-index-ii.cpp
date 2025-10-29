/*
 * @lc app=leetcode.cn id=275 lang=cpp
 * @lcpr version=30204
 *
 * [275] H 指数 II
 *
 * https://leetcode.cn/problems/h-index-ii/description/
 *
 * algorithms
 * Medium (44.62%)
 * Likes:    384
 * Dislikes: 0
 * Total Accepted:    131.8K
 * Total Submissions: 295.4K
 * Testcase Example:  '[0,1,3,5,6]'
 *
 * 给你一个整数数组 citations ，其中 citations[i] 表示研究者的第 i 篇论文被引用的次数，citations 已经按照 非降序排列
 * 。计算并返回该研究者的 h 指数。
 * 
 * h 指数的定义：h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （n 篇论文中）至少 有 h
 * 篇论文分别被引用了至少 h 次。
 * 
 * 请你设计并实现对数时间复杂度的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：citations = [0,1,3,5,6]
 * 输出：3
 * 解释：给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 0, 1, 3, 5, 6 次。
 * 由于研究者有3篇论文每篇 至少 被引用了 3 次，其余两篇论文每篇被引用 不多于 3 次，所以她的 h 指数是 3 。
 * 
 * 示例 2：
 * 
 * 输入：citations = [1,2,100]
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == citations.length
 * 1 <= n <= 10^5
 * 0 <= citations[i] <= 1000
 * citations 按 升序排列
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
    /**
     * 二分h
     * 如果h满足，那么h-1也满足，单调性
     * 
     * 贪心
     * citations[i] >= n - i = h
     * citations[n - h] >= h
     * 
     * h:[0, n]
     */
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        auto check = [&](int h) -> bool {
            if (h == 0) {
                return true;
            }
            return citations[n - h] >= h; // 引用次数最多的 h 篇论文，引用次数均 >= h
        };

        int left = 0, right = n;
        while (left <= right) {
            // 循环不变量：
            // left - 1 的回答为是
            // right + 1的回答为否
            int h  = left + (right - left) / 2;
            if (check(h)) {
                left = h + 1;
            } else {
                right = h - 1;
            }
        }
        // 循环结束后 right 等于 left-1，回答一定为「是」
        // 根据循环不变量，right 现在是最大的回答为「是」的数
        return right;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,3,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,100]\n
// @lcpr case=end

 */

