/*
 * @lc app=leetcode.cn id=面试题 17.05 lang=cpp
 * @lcpr version=
 *
 * [面试题 17.05]  字母与数字
 *
 * https://leetcode.cn/problems/find-longest-subarray-lcci/description/
 *
 * LCCI
 * Medium (47.93%)
 * Likes:    199
 * Dislikes: 0
 * Total Accepted:    36.7K
 * Total Submissions: 76.6K
 * Testcase Example:  '["A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"]'
 *
 * 给定一个放有字母和数字的数组，找到最长的子数组，且包含的字母和数字的个数相同。
 * 
 * 返回该子数组，若存在多个最长子数组，返回左端点下标值最小的子数组。若不存在这样的数组，返回一个空数组。
 * 
 * 示例 1：
 * 
 * 
 * 输入：["A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"]
 * 
 * 输出：["A","1","B","C","D","2","3","4","E","5","F","G","6","7"]
 * 
 * 
 * 示例 2：
 * 
 * 输入：["A","A"]
 * 
 * 输出：[]
 * 
 * 
 * 提示：
 * 
 * 
 * array.length <= 100000
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
    bool is_num(string& s){
        return s[0] - '0' <= 9;
    }
    vector<string> findLongestSubarray(vector<string>& array) {
        vector<int> nums;
        for (string s : array) {
            if (is_num(s)) {
                nums.push_back(-1);
            } else {
                nums.push_back(1);
            }
        }

        int n = array.size();
        vector<int> preSum(n + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }

        unordered_map<int, int> cnt;
        int begin = 0, end = 0;
        for (int i = 0; i < n + 1; i++) {
            auto it = cnt.find(preSum[i]);
            if (it == cnt.end()) {
                cnt[preSum[i]] = i;
            } else if (i - it->second > end - begin) {
                begin = it->second;
                end = i;
            }
        }
        return {array.begin() + begin, array.begin() + end};
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"]\n
// @lcpr case=end

// @lcpr case=start
// ["A","A"]\n
// @lcpr case=end

 */

