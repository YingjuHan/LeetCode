/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 * @lcpr version=30204
 *
 * [1018] 可被 5 整除的二进制前缀
 *
 * https://leetcode.cn/problems/binary-prefix-divisible-by-5/description/
 *
 * algorithms
 * Easy (50.20%)
 * Likes:    166
 * Dislikes: 0
 * Total Accepted:    58.3K
 * Total Submissions: 115.6K
 * Testcase Example:  '[0,1,1]'
 *
 * 给定一个二进制数组 nums ( 索引从0开始 )。
 * 
 * 我们将xi 定义为其二进制表示形式为子数组 nums[0..i] (从最高有效位到最低有效位)。
 * 
 * 
 * 例如，如果 nums =[1,0,1] ，那么 x0 = 1, x1 = 2, 和 x2 = 5。
 * 
 * 
 * 返回布尔值列表 answer，只有当 xi 可以被 5 整除时，答案 answer[i] 为 true，否则为 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [0,1,1]
 * 输出：[true,false,false]
 * 解释：
 * 输入数字为 0, 01, 011；也就是十进制中的 0, 1, 3 。只有第一个数可以被 5 整除，因此 answer[0] 为 true 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,1,1]
 * 输出：[false,false,false]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5^ 
 * nums[i] 仅为 0 或 1
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
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> res(n, false);
        int x = 0;
        for (int i = 0; i < n; i++) {
            x = (x << 1 | nums[i]) % 5;
            res[i] = x == 0;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n
// @lcpr case=end

 */

