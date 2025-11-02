// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=面试题 16.24 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 16.24] 数对和
 *
 * https://leetcode.cn/problems/pairs-with-sum-lcci/description/
 *
 * LCCI
 * Medium (48.42%)
 * Likes:    62
 * Dislikes: 0
 * Total Accepted:    25.4K
 * Total Submissions: 51.3K
 * Testcase Example:  '[5]\n1'
 *
 * 设计一个算法，找出数组中两数之和为指定值的所有整数对。一个数只能属于一个数对。
 * 
 * 示例 1：
 * 
 * 输入：nums = [5,6,5], target = 11
 * 输出：[[5,6]]
 * 
 * 示例 2：
 * 
 * 输入：nums = [5,6,5,6], target = 11
 * 输出：[[5,6],[5,6]]
 * 
 * 提示：
 * 
 * 
 * nums.length <= 100000
 * -10^5 <= nums[i], target <= 10^5
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
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<vector<int>> res;
        for (int num : nums) {
            if (mp.count(target - num)) {
                mp[target - num]--;
                res.emplace_back(target - num, num);
                if (mp[target - num] == 0) {
                    mp.erase(target - num);
                }
            } else {
                mp[num]++;
            }
        }
        return res;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=pairSums
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [5,6,5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [5,6,5,6]\n11\n
// @lcpr case=end

 */

