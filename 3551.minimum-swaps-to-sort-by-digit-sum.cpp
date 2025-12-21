/*
 * @lc app=leetcode.cn id=3551 lang=cpp
 * @lcpr version=30204
 *
 * [3551] 数位和排序需要的最小交换次数
 *
 * https://leetcode.cn/problems/minimum-swaps-to-sort-by-digit-sum/description/
 *
 * algorithms
 * Medium (51.25%)
 * Likes:    19
 * Dislikes: 0
 * Total Accepted:    4K
 * Total Submissions: 7.7K
 * Testcase Example:  '[37,100]'
 *
 * 给你一个由 互不相同 的正整数组成的数组 nums，需要根据每个数字的数位和（即每一位数字相加求和）按 升序
 * 对数组进行排序。如果两个数字的数位和相等，则较小的数字排在前面。
 * 
 * 返回将 nums 排列为上述排序顺序所需的 最小 交换次数。
 * 
 * 一次 交换 定义为交换数组中两个不同位置的值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: nums = [37,100]
 * 
 * 输出: 1
 * 
 * 解释:
 * 
 * 
 * 计算每个整数的数位和：[3 + 7 = 10, 1 + 0 + 0 = 1] → [10, 1]
 * 根据数位和排序：[100, 37]。将 37 与 100 交换，得到排序后的数组。
 * 因此，将 nums 排列为排序顺序所需的最小交换次数为 1。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入: nums = [22,14,33,7]
 * 
 * 输出: 0
 * 
 * 解释:
 * 
 * 
 * 计算每个整数的数位和：[2 + 2 = 4, 1 + 4 = 5, 3 + 3 = 6, 7 = 7] → [4, 5, 6, 7]
 * 根据数位和排序：[22, 14, 33, 7]。数组已经是排序好的。
 * 因此，将 nums 排列为排序顺序所需的最小交换次数为 0。
 * 
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入: nums = [18,43,34,16]
 * 
 * 输出: 2
 * 
 * 解释:
 * 
 * 
 * 计算每个整数的数位和：[1 + 8 = 9, 4 + 3 = 7, 3 + 4 = 7, 1 + 6 = 7] → [9, 7, 7, 7]
 * 根据数位和排序：[16, 34, 43, 18]。将 18 与 16 交换，再将 43 与 34 交换，得到排序后的数组。
 * 因此，将 nums 排列为排序顺序所需的最小交换次数为 2。
 * 
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * nums 由 互不相同 的正整数组成。
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class UnionFind {
    vector<int> fa;
public:
    int cc;

    UnionFind(int n) : fa(n), cc(n) {
        iota(fa.begin(), fa.end(), 0);
    }

    int Find(int x) {
        if (fa[x] != x) {
            fa[x] = Find(fa[x]);
        }
        return fa[x];
    }

    void merge(int from, int to) {
        int x = Find(from), y = Find(to);
        if (x == y) {
            return;
        }

        fa[x] = y;
        cc--;
    }
};
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<array<int, 3>> a(n);
        for (int i = 0; i < n; i++) {
            int s = 0;
            for (int x = nums[i]; x > 0; x /= 10) {
                s += x % 10;
            }
            a[i] = {s, nums[i], i};
        }

        sort(a.begin(), a.end());

        UnionFind u(n);
        for (int i = 0; i < n; i++) {
            u.merge(i, a[i][2]);
        }
        return n - u.cc;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [37,100]\n
// @lcpr case=end

// @lcpr case=start
// [22,14,33,7]\n
// @lcpr case=end

// @lcpr case=start
// [18,43,34,16]\n
// @lcpr case=end

 */

