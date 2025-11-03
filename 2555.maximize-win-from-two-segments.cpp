/*
 * @lc app=leetcode.cn id=2555 lang=cpp
 * @lcpr version=30204
 *
 * [2555] 两个线段获得的最多奖品
 *
 * https://leetcode.cn/problems/maximize-win-from-two-segments/description/
 *
 * algorithms
 * Medium (53.30%)
 * Likes:    128
 * Dislikes: 0
 * Total Accepted:    20.3K
 * Total Submissions: 38.1K
 * Testcase Example:  '[1,1,2,2,3,3,5]\n2'
 *
 * 在 X轴 上有一些奖品。给你一个整数数组 prizePositions ，它按照 非递减 顺序排列，其中 prizePositions[i] 是第 i
 * 件奖品的位置。数轴上一个位置可能会有多件奖品。再给你一个整数 k 。
 * 
 * 你可以同时选择两个端点为整数的线段。每个线段的长度都必须是 k
 * 。你可以获得位置在任一线段上的所有奖品（包括线段的两个端点）。注意，两个线段可能会有相交。
 * 
 * 
 * 比方说 k = 2 ，你可以选择线段 [1, 3] 和 [2, 4] ，你可以获得满足 1 <= prizePositions[i] <= 3 或者 2
 * <= prizePositions[i] <= 4 的所有奖品 i 。
 * 
 * 
 * 请你返回在选择两个最优线段的前提下，可以获得的 最多 奖品数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：prizePositions = [1,1,2,2,3,3,5], k = 2
 * 输出：7
 * 解释：这个例子中，你可以选择线段 [1, 3] 和 [3, 5] ，获得 7 个奖品。
 * 
 * 
 * 示例 2：
 * 
 * 输入：prizePositions = [1,2,3,4], k = 0
 * 输出：2
 * 解释：这个例子中，一个选择是选择线段 [3, 3] 和 [4, 4] ，获得 2 个奖品。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= prizePositions.length <= 10^5
 * 1 <= prizePositions[i] <= 10^9
 * 0 <= k <= 10^9 
 * prizePositions 有序非递减。
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
     * 枚举第二个线段，看第一条线最多可以覆盖多少个点
     */
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        if (k * 2 + 1 >= prizePositions[n - 1] - prizePositions[0]) {
            return n;
        }

        int res = 0, left = 0;
        vector<int> pre(n + 1);
        for (int right = 0; right < n; right++) {
            while (prizePositions[right] - prizePositions[left] > k) {
                left++;
            }
            res = max(res, right - left + 1 + pre[left]);
            pre[right + 1] = max(pre[right], right - left + 1);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2,2,3,3,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n0\n
// @lcpr case=end

 */

