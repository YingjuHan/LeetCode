/*
 * @lc app=leetcode.cn id=932 lang=cpp
 * @lcpr version=30204
 *
 * [932] 漂亮数组
 *
 * https://leetcode.cn/problems/beautiful-array/description/
 *
 * algorithms
 * Medium (67.39%)
 * Likes:    243
 * Dislikes: 0
 * Total Accepted:    17.7K
 * Total Submissions: 26.3K
 * Testcase Example:  '4'
 *
 * 如果长度为 n 的数组 nums 满足下述条件，则认为该数组是一个 漂亮数组 ：
 * 
 * 
 * nums 是由范围 [1, n] 的整数组成的一个排列。
 * 对于每个 0 <= i < j < n ，均不存在下标 k（i < k < j）使得 2 * nums[k] == nums[i] + nums[j]
 * 。
 * 
 * 
 * 给你整数 n ，返回长度为 n 的任一 漂亮数组 。本题保证对于给定的 n 至少存在一个有效答案。
 * 
 * 
 * 
 * 示例 1 ：
 * 
 * 输入：n = 4
 * 输出：[2,1,4,3]
 * 
 * 
 * 示例 2 ：
 * 
 * 输入：n = 5
 * 输出：[3,1,2,5,4]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 1000
 * 
 * 
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
    unordered_map<int,vector<int> > mp;
    vector<int> beautifulArray(int N) {
        return f(N);
    }
    vector<int> f(int N) {
        vector<int> ans(N, 0);
        int t = 0;
        if (mp.find(N) != mp.end()) {
            return mp[N];
        }
        if (N != 1) {
            for (auto x : f((N+1)/2)){
                ans[t++]= 2 * x - 1;
            } 
            for (auto x : f(N/2)){
                ans[t++] =  2 * x;
            }
        }else {
            ans[0] = 1;
        }
        mp[N] = ans;
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

 */

