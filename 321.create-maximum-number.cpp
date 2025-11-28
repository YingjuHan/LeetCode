/*
 * @lc app=leetcode.cn id=321 lang=cpp
 * @lcpr version=30204
 *
 * [321] 拼接最大数
 *
 * https://leetcode.cn/problems/create-maximum-number/description/
 *
 * algorithms
 * Hard (42.79%)
 * Likes:    623
 * Dislikes: 0
 * Total Accepted:    48.1K
 * Total Submissions: 112.2K
 * Testcase Example:  '[3,4,6,5]\n[9,1,2,5,8,3]\n5'
 *
 * 给你两个整数数组 nums1 和 nums2，它们的长度分别为 m 和 n。数组 nums1 和 nums2
 * 分别代表两个数各位上的数字。同时你也会得到一个整数 k。
 * 
 * 请你利用这两个数组中的数字创建一个长度为 k <= m + n 的最大数。同一数组中数字的相对顺序必须保持不变。
 * 
 * 返回代表答案的长度为 k 的数组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
 * 输出：[9,8,6,5,3]
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums1 = [6,7], nums2 = [6,0,4], k = 5
 * 输出：[6,7,6,0,4]
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums1 = [3,9], nums2 = [8,9], k = 3
 * 输出：[9,8,9]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == nums1.length
 * n == nums2.length
 * 1 <= m, n <= 500
 * 0 <= nums1[i], nums2[i] <= 9
 * 1 <= k <= m + n
 * nums1 和 nums2 没有前导 0。
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
     * 假设最大子序列中，包含来自nums1的s个元素和来自nums2的k-s个元素，
     * 那么可以通过反证法证明，
     * 来自nums1的s个元素，构成了nums1的长度为s的最大子序列；来自nums2的k-s个元素，构成了nums2的长度为k-s的最大子序列。
     * 因此，可以首先分别求出nums1中长度为s的最大子序列，和nums2中长度为k-s的最大子序列，然后求它们归并起来的最大子序列的长度，
     * 最后对一切可能的s求最大值。
     */
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
         vector<int> res(k, 0);
        int n = nums1.size(), m = nums2.size();
        // 假设有最大子序列中有s个元素来自nums1，对所有可能的s值遍历
        for (int s=max(0, k-m); s<=min(k, n); s++){
            vector<int> temp;
            int i = 0, j = 0;
            // nums1中长度为s的最大子序列
            vector<int> temp1 = maxKsequence(nums1, s);
            // nums2中长度为k-s的最大子序列
            vector<int> temp2 = maxKsequence(nums2, k-s);
            // 对两个子序列进行归并
            // lexicographical_compare：比较两个序列的字典序大小
            auto iter1 = temp1.begin(), iter2 = temp2.begin();
            while (iter1 != temp1.end() || iter2 != temp2.end()){
                temp.push_back(lexicographical_compare(iter1, temp1.end(), iter2, temp2.end()) ? *iter2++ : *iter1++);
            }
            // 如果归并后的最大子序列大于目前已找到的最大子序列，则更新解
            res = lexicographical_compare(res.begin(), res.end(), temp.begin(), temp.end()) ? temp : res;
        }
        return res;
    }

    // 求数组v的长度为k的最大子序列
    vector<int> maxKsequence(vector<int> v, int k){
        int n = v.size();
        if (n <= k)
            return v;
        vector<int> res;
        int pop = n-k;
        for (int i=0; i<n; i++){
            while(!res.empty() && v[i]>res.back() && pop-->0)
                res.pop_back();
            res.push_back(v[i]);
        }
        res.resize(k);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,4,6,5]\n[9,1,2,5,8,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [6,7]\n[6,0,4]\n5\n
// @lcpr case=end

// @lcpr case=start
// [3,9]\n[8,9]\n3\n
// @lcpr case=end

 */

