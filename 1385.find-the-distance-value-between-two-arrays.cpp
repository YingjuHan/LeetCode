/*
 * @lc app=leetcode.cn id=1385 lang=cpp
 * @lcpr version=30204
 *
 * [1385] 两个数组间的距离值
 *
 * https://leetcode.cn/problems/find-the-distance-value-between-two-arrays/description/
 *
 * algorithms
 * Easy (66.68%)
 * Likes:    160
 * Dislikes: 0
 * Total Accepted:    62.9K
 * Total Submissions: 94.3K
 * Testcase Example:  '[4,5,8]\n[10,9,1,8]\n2'
 *
 * 给你两个整数数组 arr1 ， arr2 和一个整数 d ，请你返回两个数组之间的 距离值 。
 * 
 * 「距离值」 定义为符合此距离要求的元素数目：对于元素 arr1[i] ，不存在任何元素 arr2[j] 满足 |arr1[i]-arr2[j]| <=
 * d 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
 * 输出：2
 * 解释：
 * 对于 arr1[0]=4 我们有：
 * |4-10|=6 > d=2 
 * |4-9|=5 > d=2 
 * |4-1|=3 > d=2 
 * |4-8|=4 > d=2 
 * 所以 arr1[0]=4 符合距离要求
 * 
 * 对于 arr1[1]=5 我们有：
 * |5-10|=5 > d=2 
 * |5-9|=4 > d=2 
 * |5-1|=4 > d=2 
 * |5-8|=3 > d=2
 * 所以 arr1[1]=5 也符合距离要求
 * 
 * 对于 arr1[2]=8 我们有：
 * |8-10|=2 <= d=2
 * |8-9|=1 <= d=2
 * |8-1|=7 > d=2
 * |8-8|=0 <= d=2
 * 存在距离小于等于 2 的情况，不符合距离要求 
 * 
 * 故而只有 arr1[0]=4 和 arr1[1]=5 两个符合距离要求，距离值为 2
 * 
 * 示例 2：
 * 
 * 输入：arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr1.length, arr2.length <= 500
 * -10^3 <= arr1[i], arr2[j] <= 10^3
 * 0 <= d <= 100
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
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int res = 0;
        for (int num : arr1) {
            auto it = lower_bound(arr2.begin(), arr2.end(), num - d);
            if (it == arr2.end() || *it > num + d) {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,5,8]\n[10,9,1,8]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,4,2,3]\n[-4,-3,6,10,20,30]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1,100,3]\n[-5,-2,10,-3,7]\n6\n
// @lcpr case=end

 */

