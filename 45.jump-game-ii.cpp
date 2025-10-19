/*
 * @lc app=leetcode.cn id=45 lang=cpp
 * @lcpr version=30204
 *
 * [45] 跳跃游戏 II
 *
 * https://leetcode.cn/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (45.19%)
 * Likes:    2904
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2.4M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给定一个长度为 n 的 0 索引整数数组 nums。初始位置在下标 0。
 * 
 * 每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。换句话说，如果你在索引 i 处，你可以跳转到任意 (i + j) 处：
 * 
 * 
 * 0 <= j <= nums[i] 且
 * i + j < n
 * 
 * 
 * 返回到达 n - 1 的最小跳跃次数。测试用例保证可以到达 n - 1。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: nums = [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。
 * 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [2,3,0,1,4]
 * 输出: 2
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 1000
 * 题目保证可以到达 n - 1
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
    int jump(vector<int>& nums) {
        int res = 0;
        int cur_right = 0; // 以建造的桥的右端点
        int next_right = 0; // 下一座桥的右端点的最大值
        for (int i = 0; i < nums.size() -1; ++i) {
            // 遍历过程中，记录下一座桥的最远点
            next_right = max(next_right, i + nums[i]);
            if (i == cur_right) { // 没有前进的路，需要一个新桥
                cur_right = next_right; // 建一座新桥作为当前的桥，更新当前桥的最远点
                res++; // 桥数量+1
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,0,1,4]\n
// @lcpr case=end

 */

