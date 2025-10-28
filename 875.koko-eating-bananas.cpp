/*
 * @lc app=leetcode.cn id=875 lang=cpp
 * @lcpr version=30204
 *
 * [875] 爱吃香蕉的珂珂
 *
 * https://leetcode.cn/problems/koko-eating-bananas/description/
 *
 * algorithms
 * Medium (50.23%)
 * Likes:    715
 * Dislikes: 0
 * Total Accepted:    194.1K
 * Total Submissions: 386.5K
 * Testcase Example:  '[3,6,7,11]\n8'
 *
 * 珂珂喜欢吃香蕉。这里有 n 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 h 小时后回来。
 * 
 * 珂珂可以决定她吃香蕉的速度 k （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 k 根。如果这堆香蕉少于 k
 * 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  
 * 
 * 珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。
 * 
 * 返回她可以在 h 小时内吃掉所有香蕉的最小速度 k（k 为整数）。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：piles = [3,6,7,11], h = 8
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 输入：piles = [30,11,23,4,20], h = 5
 * 输出：30
 * 
 * 
 * 示例 3：
 * 
 * 输入：piles = [30,11,23,4,20], h = 6
 * 输出：23
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= piles.length <= 10^4
 * piles.length <= h <= 10^9
 * 1 <= piles[i] <= 10^9
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
    bool check(vector<int>& piles, int h, int x) {
        int sum = piles.size();
        for (int pile : piles) {
            sum += (pile - 1) / x;
            if (sum > h) {
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(piles, h, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,6,7,11]\n8\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n5\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n6\n
// @lcpr case=end

 */

