/*
 * @lc app=leetcode.cn id=1534 lang=cpp
 * @lcpr version=30204
 *
 * [1534] 统计好三元组
 *
 * https://leetcode.cn/problems/count-good-triplets/description/
 *
 * algorithms
 * Easy (76.39%)
 * Likes:    178
 * Dislikes: 0
 * Total Accepted:    100.7K
 * Total Submissions: 132K
 * Testcase Example:  '[3,0,1,1,9,7]\n7\n2\n3'
 *
 * 给你一个整数数组 arr ，以及 a、b 、c 三个整数。请你统计其中好三元组的数量。
 * 
 * 如果三元组 (arr[i], arr[j], arr[k]) 满足下列全部条件，则认为它是一个 好三元组 。
 * 
 * 
 * 0 <= i < j < k < arr.length
 * |arr[i] - arr[j]| <= a
 * |arr[j] - arr[k]| <= b
 * |arr[i] - arr[k]| <= c
 * 
 * 
 * 其中 |x| 表示 x 的绝对值。
 * 
 * 返回 好三元组的数量 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
 * 输出：4
 * 解释：一共有 4 个好三元组：[(3,0,1), (3,0,1), (3,1,1), (0,1,1)] 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [1,1,2,2,3], a = 0, b = 0, c = 1
 * 输出：0
 * 解释：不存在满足所有条件的三元组。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= arr.length <= 100
 * 0 <= arr[i] <= 1000
 * 0 <= a, b, c <= 1000
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
    /**
     * 1. 暴力枚举
     */
    /*
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size(), anss = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
    */

    /**
     * 3. 
     */
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {

    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,0,1,1,9,7]\n7\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,2,3]\n0\n0\n1\n
// @lcpr case=end

 */

