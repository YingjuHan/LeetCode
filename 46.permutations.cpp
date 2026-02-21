/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30204
 *
 * [46] 全排列
 *
 * https://leetcode.cn/problems/permutations/description/
 *
 * algorithms
 * Medium (80.48%)
 * Likes:    3237
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 2M
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [1]
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * nums 中的所有整数 互不相同
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
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> path(n); // 所有排列的长度都是一样的 n
        vector<int8_t> on_path(n);
        vector<vector<int>> ans;

        // 枚举 path[i] 填 nums 的哪个数
        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }

            for (int j = 0; j < n; j++) {
                if (!on_path[j]) {
                    path[i] = nums[j]; // 从没有选的数字中选一个
                    on_path[j] = true; // 已选上
                    dfs(i + 1);
                    on_path[j] = false; // 恢复现场
                    // 注意 path 无需恢复现场，因为排列长度固定，直接覆盖就行
                }
            }
        };

        dfs(0);
        return ans;
    }
};

// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

