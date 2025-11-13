/*
 * @lc app=leetcode.cn id=1442 lang=cpp
 * @lcpr version=
 *
 * [1442] 形成两个异或相等数组的三元组数目
 *
 * https://leetcode.cn/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/
 *
 * algorithms
 * Medium (80.04%)
 * Likes:    255
 * Dislikes: 0
 * Total Accepted:    44.5K
 * Total Submissions: 55.5K
 * Testcase Example:  '[2,3,1,6,7]'
 *
 * 给你一个整数数组 arr 。
 * 
 * 现需要从数组中取三个下标 i、j 和 k ，其中 (0 <= i < j <= k < arr.length) 。
 * 
 * a 和 b 定义如下：
 * 
 * 
 * a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
 * b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
 * 
 * 
 * 注意：^ 表示 按位异或 操作。
 * 
 * 请返回能够令 a == b 成立的三元组 (i, j , k) 的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [2,3,1,6,7]
 * 输出：4
 * 解释：满足题意的三元组分别是 (0,1,2), (0,2,2), (2,3,4) 以及 (2,4,4)
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [1,1,1,1,1]
 * 输出：10
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = [2,3]
 * 输出：0
 * 
 * 
 * 示例 4：
 * 
 * 输入：arr = [1,3,5,7,9]
 * 输出：3
 * 
 * 
 * 示例 5：
 * 
 * 输入：arr = [7,11,12,9,5,2,7,17,22]
 * 输出：8
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 300
 * 1 <= arr[i] <= 10^8
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
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] ^ arr[i];
        }

        int res = 0;

        // 三重循环
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         for (int k = j; k < n; k++) {
        //             if (s[i] == s[k + 1]) {
        //                 res++;
        //             }
        //         }
        //     }
        // }

        // 二重循环
        // 当等式 Si=Sk+1成立时，[i+1,k] 的范围内的任意 j 都是符合要求的，
        // 对应的三元组个数为 k−i。因此我们只需枚举下标 i 和 k
        // for (int i = 0; i < n; i++) {
        //     for (int k = i + 1; k < n; k++) {
        //         if (s[i] == s[k + 1]) {
        //         res += k - i;
        //     }
        // }

        unordered_map<int, int> cnt, total;
        for (int k = 0; k < n; ++k) {
            if (cnt.count(s[k + 1])) {
                res += cnt[s[k + 1]] * k - total[s[k + 1]];
            }
            ++cnt[s[k]];
            total[s[k]] += k;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,6,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,7,9]\n
// @lcpr case=end

// @lcpr case=start
// [7,11,12,9,5,2,7,17,22]\n
// @lcpr case=end

 */

