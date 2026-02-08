/*
 * @lc app=leetcode.cn id=3290 lang=cpp
 * @lcpr version=30204
 *
 * [3290] 最高乘法得分
 *
 * https://leetcode.cn/problems/maximum-multiplication-score/description/
 *
 * algorithms
 * Medium (43.65%)
 * Likes:    27
 * Dislikes: 0
 * Total Accepted:    8.6K
 * Total Submissions: 19.6K
 * Testcase Example:  '[3,2,5,6]\n[2,-6,4,-5,-3,2,-7]'
 *
 * 给你一个大小为 4 的整数数组 a 和一个大小 至少为 4 的整数数组 b。
 * 
 * 你需要从数组 b 中选择四个下标 i0, i1, i2, 和 i3，并满足 i0 < i1 < i2 < i3。你的得分将是 a[0] * b[i0]
 * + a[1] * b[i1] + a[2] * b[i2] + a[3] * b[i3] 的值。
 * 
 * 返回你能够获得的 最大 得分。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： a = [3,2,5,6], b = [2,-6,4,-5,-3,2,-7]
 * 
 * 输出： 26
 * 
 * 解释：
 * 选择下标 0, 1, 2 和 5。得分为 3 * 2 + 2 * (-6) + 5 * 4 + 6 * 2 = 26。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： a = [-1,4,5,-2], b = [-5,-1,-3,-2,-4]
 * 
 * 输出： -1
 * 
 * 解释：
 * 选择下标 0, 1, 3 和 4。得分为 (-1) * (-5) + 4 * (-1) + 5 * (-2) + (-2) * (-4) =
 * -1。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * a.length == 4
 * 4 <= b.length <= 10^5
 * -10^5 <= a[i], b[i] <= 10^5
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
    long long maxScore1(vector<int>& a, vector<int>& b) {
        int n = b.size();
        std::vector<std::array<long long, 4>> memo(n, std::array<long long, 4>{LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN});
        
        auto dfs = [&](this auto&& dfs, int i, int j) -> long long {
            if (j < 0) {
                return 0;
            }
            if (i < 0) {
                return LLONG_MIN / 2;
            }
            auto& res = memo[i][j];
            if (res != LLONG_MIN) {
                return res;
            }
            res = max(dfs(i - 1, j), dfs(i - 1, j - 1) + (long long) a[j] * b[i]);
            return res;
        };
        return dfs(n - 1, 3);
    }

    long long maxScore2(vector<int>& a, vector<int>& b) {
        int n = b.size();
        std::vector<std::array<long long, 5>> f(n + 1);
        for (int j = 1; j < 5; j++) {
            f[0][j] = LLONG_MIN / 2;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                f[i + 1][j + 1] = max(f[i][j + 1], f[i][j] + (long long) a[j] * b[i]);
            }
        }
        return f[n][4];
    }

    long long maxScore(vector<int>& a, vector<int>& b) {
        long long f[5]{};
        fill(f + 1, f + 5, LLONG_MIN / 2);
        for (int y : b) {
            for (int j = 3; j >= 0; j--) {
                f[j + 1] = max(f[j + 1], f[j] + (long long) a[j] * y);
            }
        }
        return f[4];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,5,6]\n[2,-6,4,-5,-3,2,-7]\n
// @lcpr case=end

// @lcpr case=start
// [-1,4,5,-2]\n[-5,-1,-3,-2,-4]\n
// @lcpr case=end

 */

