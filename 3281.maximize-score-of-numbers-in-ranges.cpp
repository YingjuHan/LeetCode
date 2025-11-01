/*
 * @lc app=leetcode.cn id=3281 lang=cpp
 * @lcpr version=30204
 *
 * [3281] 范围内整数的最大得分
 *
 * https://leetcode.cn/problems/maximize-score-of-numbers-in-ranges/description/
 *
 * algorithms
 * Medium (39.67%)
 * Likes:    28
 * Dislikes: 0
 * Total Accepted:    7.5K
 * Total Submissions: 18.8K
 * Testcase Example:  '[6,0,3]\n2'
 *
 * 给你一个整数数组 start 和一个整数 d，代表 n 个区间 [start[i], start[i] + d]。
 * 
 * 你需要选择 n 个整数，其中第 i 个整数必须属于第 i 个区间。所选整数的 得分 定义为所选整数两两之间的 最小 绝对差。
 * 
 * 返回所选整数的 最大可能得分 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： start = [6,0,3], d = 2
 * 
 * 输出： 4
 * 
 * 解释：
 * 
 * 可以选择整数 8, 0 和 4 获得最大可能得分，得分为 min(|8 - 0|, |8 - 4|, |0 - 4|)，等于 4。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： start = [2,6,13,13], d = 5
 * 
 * 输出： 5
 * 
 * 解释：
 * 
 * 可以选择整数 2, 7, 13 和 18 获得最大可能得分，得分为 min(|2 - 7|, |2 - 13|, |2 - 18|, |7 - 13|,
 * |7 - 18|, |13 - 18|)，等于 5。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= start.length <= 10^5
 * 0 <= start[i] <= 10^9
 * 0 <= d <= 10^9
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
     * 二分答案：最大化最小值
     * 题意：给你 n 个一样长的区间，每个区间选一个数，最大化得分。得分即所选数字中的任意两数之差的最小值。
     * 
     * 假设得分为score
     * 把区间按照左端点排序，这样只考虑相邻区间所选数字之差
     * 设从第一个区间选数组x，那么下一个区间为x+score
     * 得分越大，所选数字越不可能在下一个区间中，存在单调性，可以二分
     * 
     * 贪心：
     * 转换问题为：给定score，能否从每个区间选一个数，是的任意两数之差的最小值至少为score
     * ***这里是至少，不是恰好，两数之差的最小值可以不等于 score。由于二分会不断缩小范围，最终一定会缩小到任意两数之差的最小值恰好等于 score 的位置上***
     * 
     * 把区间按照左端点排序。第一个数选谁？
     * 贪心地想，第一个数越小，第二个数就越能在区间内，所以第一个数要选 x0 = start[0]
     * 如果第二个数 x1=x0+score 超过了区间右端点 start[1]+d，那么 score 太大了，应当减小二分的右边界 right。
     * 如果 x1≤start[1]+d，我们还需要保证 x1 大于等于区间左端点 start[1]，所以最终x1=max(x0+score,start[1])
     * 依此类推，第 i 个区间所选的数为xi=max(xi-1 + scorei, start[i])
     * 
     * 满足xi <= start[i] + d
     * 如果所有选的数都满足上式，那么增大二分的左边界 left。
     * 
     * mx为得分
     * 开区间左端点初始值：0。一定可以选出 n 个数，两两之差都大于等于 0。
     * 开区间右端点初始值：start[n - 1] + d >= start[0] + (n - 1) * mx 或者认为最小值不会大于平均值
     * 
     */
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());

        auto check = [&](int mx) -> bool {
            long long x = LLONG_MIN;
            for (int s : start) {
                x = max(x + mx, (long long)s); // x 必须大于等于左端点s
                if (x > s + d) {
                    return false;
                }
            }
            return true;
        };

        int left = 0, right = (start.back() + d) / (start.size() - 1) + 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [6,0,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,6,13,13]\n5\n
// @lcpr case=end

 */

