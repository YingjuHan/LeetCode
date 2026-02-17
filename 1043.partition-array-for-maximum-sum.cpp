/*
 * @lc app=leetcode.cn id=1043 lang=cpp
 * @lcpr version=30204
 *
 * [1043] 分隔数组以得到最大和
 *
 * https://leetcode.cn/problems/partition-array-for-maximum-sum/description/
 *
 * algorithms
 * Medium (75.62%)
 * Likes:    322
 * Dislikes: 0
 * Total Accepted:    39.4K
 * Total Submissions: 52.2K
 * Testcase Example:  '[1,15,7,9,2,5,10]\n3'
 *
 * 给你一个整数数组 arr，请你将该数组分隔为长度 最多 为 k 的一些（连续）子数组。分隔完成后，每个子数组的中的所有值都会变为该子数组中的最大值。
 * 
 * 返回将数组分隔变换后能够得到的元素最大和。本题所用到的测试用例会确保答案是一个 32 位整数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [1,15,7,9,2,5,10], k = 3
 * 输出：84
 * 解释：数组变为 [15,15,15,9,10,10,10]
 * 
 * 示例 2：
 * 
 * 输入：arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
 * 输出：83
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = [1], k = 1
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 500
 * 0 <= arr[i] <= 10^9
 * 1 <= k <= arr.length
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
    int maxSumAfterPartitioning1(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> memo(n, -1);
        function<int(int)> dfs = [&](int i) -> int {
            if (i < 0) {
                return 0;
            }
            int &res = memo[i];
            if (res != -1) {
                return res;
            }
            for (int j = i, mx = 0; j > i - k && j >= 0; j--) {
                mx = max(mx, arr[j]);
                res = max(res, dfs(j - 1) + (i - j + 1) * mx);
            }
            return res;
        };
        return dfs(arr.size() - 1);
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> f(n + 1, 0);
        for (int i = 0; i < n; i++) {
            f[i + 1] = 0;
            for (int j = i, mx = 0; j > i - k && j >= 0; j--) {
                mx = max(mx, arr[j]);
                f[i + 1] = max(f[i + 1], f[j] + (i - j + 1) * mx);
            }
        }
        return f[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,15,7,9,2,5,10]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,4,1,5,7,3,6,1,9,9,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

