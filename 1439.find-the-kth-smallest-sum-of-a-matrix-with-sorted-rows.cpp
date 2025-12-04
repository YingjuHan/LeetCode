/*
 * @lc app=leetcode.cn id=1439 lang=cpp
 * @lcpr version=30204
 *
 * [1439] 有序矩阵中的第 k 个最小数组和
 *
 * https://leetcode.cn/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/description/
 *
 * algorithms
 * Hard (66.48%)
 * Likes:    199
 * Dislikes: 0
 * Total Accepted:    19.6K
 * Total Submissions: 29.4K
 * Testcase Example:  '[[1,3,11],[2,4,6]]\n5'
 *
 * 给你一个 m * n 的矩阵 mat，以及一个整数 k ，矩阵中的每一行都以非递减的顺序排列。
 * 
 * 你可以从每一行中选出 1 个元素形成一个数组。返回所有可能数组中的第 k 个 最小 数组和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：mat = [[1,3,11],[2,4,6]], k = 5
 * 输出：7
 * 解释：从每一行中选出一个元素，前 k 个和最小的数组分别是：
 * [1,2], [1,4], [3,2], [3,4], [1,6]。其中第 5 个的和是 7 。  
 * 
 * 示例 2：
 * 
 * 输入：mat = [[1,3,11],[2,4,6]], k = 9
 * 输出：17
 * 
 * 
 * 示例 3：
 * 
 * 输入：mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
 * 输出：9
 * 解释：从每一行中选出一个元素，前 k 个和最小的数组分别是：
 * [1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]。其中第 7 个的和是 9
 * 。 
 * 
 * 
 * 示例 4：
 * 
 * 输入：mat = [[1,1,10],[2,2,9]], k = 7
 * 输出：12
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == mat.length
 * n == mat.length[i]
 * 1 <= m, n <= 40
 * 1 <= k <= min(200, n ^ m)
 * 1 <= mat[i][j] <= 5000
 * mat[i] 是一个非递减数组
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
    vector<int> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({nums1[0] + nums2[0], 0, 0});
        vector<int> res;
        while (!pq.empty() && res.size() < k) {
            auto [_, i, j] = pq.top();
            pq.pop();
            res.push_back(nums1[i] + nums2[j]);
            if (j == 0 && i + 1 < n) {
                pq.emplace(nums1[i + 1] + nums2[j], i + 1, j);
            }
            if (j + 1 < m) {
                pq.emplace(nums1[i] + nums2[j + 1], i, j + 1);
            }
        }
        return res;
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> a = {0};
        for (auto& row : mat) {
            a = kSmallestPairs(row, a, k);
        }
        return a.back();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3,11],[2,4,6]]\n5\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,11],[2,4,6]]\n9\n
// @lcpr case=end

// @lcpr case=start
// [[1,10,10],[1,4,5],[2,3,6]]\n7\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,10],[2,2,9]]\n7\n
// @lcpr case=end

 */

