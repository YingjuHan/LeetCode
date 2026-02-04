/*
 * @lc app=leetcode.cn id=956 lang=cpp
 * @lcpr version=30204
 *
 * [956] 最高的广告牌
 *
 * https://leetcode.cn/problems/tallest-billboard/description/
 *
 * algorithms
 * Hard (49.93%)
 * Likes:    208
 * Dislikes: 0
 * Total Accepted:    11.4K
 * Total Submissions: 22.8K
 * Testcase Example:  '[1,2,3,6]'
 *
 * 你正在安装一个广告牌，并希望它高度最大。这块广告牌将有两个钢制支架，两边各一个。每个钢支架的高度必须相等。
 * 
 * 你有一堆可以焊接在一起的钢筋 rods。举个例子，如果钢筋的长度为 1、2 和 3，则可以将它们焊接在一起形成长度为 6 的支架。
 * 
 * 返回 广告牌的最大可能安装高度 。如果没法安装广告牌，请返回 0 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,2,3,6]
 * 输出：6
 * 解释：我们有两个不相交的子集 {1,2,3} 和 {6}，它们具有相同的和 sum = 6。
 * 
 * 
 * 示例 2：
 * 
 * 输入：[1,2,3,4,5,6]
 * 输出：10
 * 解释：我们有两个不相交的子集 {2,3,5} 和 {4,6}，它们具有相同的和 sum = 10。
 * 
 * 示例 3：
 * 
 * 输入：[1,2]
 * 输出：0
 * 解释：没法安装广告牌，所以返回 0。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= rods.length <= 20
 * 1 <= rods[i] <= 1000
 * sum(rods[i]) <= 5000
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int N = rods.size();
        int K = accumulate(rods.begin(), rods.end(), 0);
        // f[i][j]代表前i个钢筋组成的两个框架高度差为j的时候的长度之和
        // 由于考察到第i个钢筋的时候，其结果仅取决于上一个钢筋的结果，因此可以进行状态压缩为一维的f。
        vector<int> f(K + 1, 0);
        for (int i = 1; i <= N; i++) {
            auto f1 = f;
            for (int j = 0; j <= K; j++) {
                if (f[j] < j) continue;
                int x = rods[i - 1];
                int k = j + x;
                f1[k] = max(f1[k], f[j] + x);
                k = abs(j - x);
                f1[k] = max(f1[k], f[j] + x);
            }
            f = std::move(f1);
        }
        return f[0] / 2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

