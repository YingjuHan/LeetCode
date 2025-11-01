/*
 * @lc app=leetcode.cn id=2517 lang=cpp
 * @lcpr version=30204
 *
 * [2517] 礼盒的最大甜蜜度
 *
 * https://leetcode.cn/problems/maximum-tastiness-of-candy-basket/description/
 *
 * algorithms
 * Medium (72.94%)
 * Likes:    195
 * Dislikes: 0
 * Total Accepted:    31.2K
 * Total Submissions: 42.8K
 * Testcase Example:  '[13,5,1,8,21,2]\n3'
 *
 * 给你一个正整数数组 price ，其中 price[i] 表示第 i 类糖果的价格，另给你一个正整数 k 。
 * 
 * 商店组合 k 类 不同 糖果打包成礼盒出售。礼盒的 甜蜜度 是礼盒中任意两种糖果 价格 绝对差的最小值。
 * 
 * 返回礼盒的 最大 甜蜜度。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：price = [13,5,1,8,21,2], k = 3
 * 输出：8
 * 解释：选出价格分别为 [13,5,21] 的三类糖果。
 * 礼盒的甜蜜度为 min(|13 - 5|, |13 - 21|, |5 - 21|) = min(8, 8, 16) = 8 。
 * 可以证明能够取得的最大甜蜜度就是 8 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：price = [1,3,1], k = 2
 * 输出：2
 * 解释：选出价格分别为 [1,3] 的两类糖果。 
 * 礼盒的甜蜜度为 min(|1 - 3|) = min(2) = 2 。
 * 可以证明能够取得的最大甜蜜度就是 2 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：price = [7,7,7,7], k = 2
 * 输出：0
 * 解释：从现有的糖果中任选两类糖果，甜蜜度都会是 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= k <= price.length <= 10^5
 * 1 <= price[i] <= 10^9
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
    int maximumTastiness(vector<int>& price, int k) {
        // 「任意两种糖果价格绝对差的最小值」等价于「排序后，任意两种相邻糖果价格绝对差的最小值」。
        int n = price.size();
        sort(price.begin(), price.end());
        auto check = [&](int mx) -> bool {
            int cnt = 1;
            int pre = price[0];
            for (int i = 1; i < n; i++) {
                if (price[i] - pre >= mx) {
                    cnt++;
                    pre = price[i];
                }
            }
            return cnt >= k;
        };
        int left = -1, right = (price.back() - price[0]) / (k - 1) + 1;
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
// [13,5,1,8,21,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,3,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7]\n2\n
// @lcpr case=end

 */

