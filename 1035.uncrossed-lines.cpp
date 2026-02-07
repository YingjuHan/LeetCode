/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 * @lcpr version=30204
 *
 * [1035] 不相交的线
 *
 * https://leetcode.cn/problems/uncrossed-lines/description/
 *
 * algorithms
 * Medium (75.14%)
 * Likes:    669
 * Dislikes: 0
 * Total Accepted:    165.5K
 * Total Submissions: 220.1K
 * Testcase Example:  '[1,4,2]\n[1,2,4]'
 *
 * 在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数。
 * 
 * 现在，可以绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足：
 * 
 * 
 * nums1[i] == nums2[j]
 * 且绘制的直线不与任何其他连线（非水平线）相交。
 * 
 * 
 * 请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。
 * 
 * 以这种方法绘制线条，并返回可以绘制的最大连线数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums1 = [1,4,2], nums2 = [1,2,4]
 * 输出：2
 * 解释：可以画出两条不交叉的线，如上图所示。 
 * 但无法画出第三条不相交的直线，因为从 nums1[1]=4 到 nums2[2]=4 的直线将与从 nums1[2]=2 到 nums2[1]=2
 * 的直线相交。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
 * 输出：3
 * 
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
 * 输出：2
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 500
 * 1 <= nums1[i], nums2[j] <= 2000
 * 
 * 
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
    int maxUncrossedLines1(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i < 0 || j < 0) {
                return 0;
            }
            int &res = memo[i][j];
            if (res != -1) {
                return res;
            }

            if (nums1[i] == nums2[j]) {
                res = dfs(i - 1, j - 1) + 1;
                return res;
            }
            res = max(dfs(i - 1, j), dfs(i, j - 1));
            return res;
        };

        return dfs(n - 1, m - 1);
    }

    int maxUncrossedLines2(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                f[i + 1][j + 1] = nums1[i] == nums2[j] ? f[i][j] + 1 : max(f[i + 1][j], f[i][j + 1]);
            }
        }
        return f[n][m];
    }

    int maxUncrossedLines(vector<int>& s, vector<int>& t) {
        int m = t.size();
        vector<int> f(m + 1);
        for (int x : s) {
            int pre = 0; // f[0]
            for (int j = 0; j < m; j++) {
                int tmp = f[j + 1];
                f[j + 1] = x == t[j] ? pre + 1 : max(f[j + 1], f[j]);
                pre = tmp;
            }
        }
        return f[m];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,4,2]\n[1,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,5,1,2,5]\n[10,5,2,1,5,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,7,1,7,5]\n[1,9,2,5,1]\n
// @lcpr case=end

 */

