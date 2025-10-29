/*
 * @lc app=leetcode.cn id=LCP 78 lang=cpp
 * @lcpr version=30204
 *
 * [LCP 78] 城墙防线
 *
 * https://leetcode.cn/problems/Nsibyl/description/
 *
 * algorithms
 * Medium (48.58%)
 * Likes:    10
 * Dislikes: 0
 * Total Accepted:    2.4K
 * Total Submissions: 5K
 * Testcase Example:  '[[0,3],[4,5],[7,9]]'
 *
 * 
 * 在探险营地间，小扣意外发现了一片城墙遗迹，在探索期间，却不巧遇到迁徙中的兽群向他迎面冲来。情急之下小扣吹响了他的苍蓝笛，随着笛声响起，遗迹中的城墙逐渐发生了横向膨胀。
 * 已知 `rampart[i] = [x,y]` 表示第 `i` 段城墙的初始所在区间。当城墙发生膨胀时，将遵循以下规则：
 * - 所有的城墙会同时膨胀相等的长度；
 * - 每个城墙可以向左、向右或向两个方向膨胀。
 * 
 * 小扣为了确保自身的安全，需要在所有城墙均无重叠的情况下，让城墙尽可能的膨胀。请返回城墙可以膨胀的 **最大值** 。
 * 
 * **注意：**
 * - 初始情况下，所有城墙均不重叠，且 `rampart` 中的元素升序排列；
 * - 两侧的城墙可以向外无限膨胀。
 * 
 * **示例 1：**
 * >输入：`rampart = [[0,3],[4,5],[7,9]]`
 * >
 * >输出：`3`
 * >
 * >解释：如下图所示：
 * >`rampart[0]` 向左侧膨胀 3 个单位；
 * >`rampart[2]` 向右侧膨胀 3 个单位；
 * >`rampart[1]` 向左侧膨胀 1 个单位，向右膨胀 2 个单位。
 * >不存在膨胀更多的方案，返回 3。
 * 
 * ![image.png](https://pic.leetcode.cn/1681717918-tWywrp-image.png){:width=750px}
 * 
 * **示例 2：**
 * >输入：`rampart = [[1,2],[5,8],[11,15],[18,25]]`
 * >
 * >输出：`4`
 * 
 * **提示：**
 * - `3 <= rampart.length <= 10^4`
 * - `rampart[i].length == 2`
 * - `0 <= rampart[i][0] < rampart[i][1] <= rampart[i+1][0] <= 10^8`
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
    // 膨胀长度越短，越能满足要求（不重叠）；膨胀长度越长，越不能满足要求（重叠）
    int rampartDefensiveLine(vector<vector<int>>& rampart) {
        int n = rampart.size();

        auto check = [&](int k) -> bool {
            int pre_r = INT_MIN / 2;
            for (int i = 0; i < n - 1 ; i++) {
                int l = rampart[i][0], r = rampart[i][1];
                int space = k - (l - pre_r);
                if (space > 0) {
                    r += space;
                    if (r > rampart[i + 1][0]) {
                        return false;
                    }
                }
                pre_r = r;
            }
            return true;
        };
        int s = 0;
        for (int i = 0; i + 1 < n; i++) {
            s += rampart[i + 1][0] - rampart[i][1];
        }
        int left = 0, right = s / (n - 2) + 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            (check(mid) ? left : right) = mid;
        }
        return left;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,3],[4,5],[7,9]]`>\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[5,8],[11,15],[18,25]]`>\n
// @lcpr case=end

 */

