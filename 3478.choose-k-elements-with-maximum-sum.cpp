/*
 * @lc app=leetcode.cn id=3478 lang=cpp
 * @lcpr version=30204
 *
 * [3478] 选出和最大的 K 个元素
 *
 * https://leetcode.cn/problems/choose-k-elements-with-maximum-sum/description/
 *
 * algorithms
 * Medium (37.87%)
 * Likes:    17
 * Dislikes: 0
 * Total Accepted:    4.4K
 * Total Submissions: 11.7K
 * Testcase Example:  '[4,2,1,5,3]\n[10,20,30,40,50]\n2'
 *
 * 给你两个整数数组，nums1 和 nums2，长度均为 n，以及一个正整数 k 。
 * 
 * 对从 0 到 n - 1 每个下标 i ，执行下述操作：
 * 
 * 
 * 找出所有满足 nums1[j] 小于 nums1[i] 的下标 j 。
 * 从这些下标对应的 nums2[j] 中选出 至多 k 个，并 最大化 这些值的总和作为结果。
 * 
 * 
 * 返回一个长度为 n 的数组 answer ，其中 answer[i] 表示对应下标 i 的结果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [4,2,1,5,3], nums2 = [10,20,30,40,50], k = 2
 * 
 * 输出：[80,30,0,80,50]
 * 
 * 解释：
 * 
 * 
 * 对于 i = 0 ：满足 nums1[j] < nums1[0] 的下标为 [1, 2, 4] ，选出其中值最大的两个，结果为 50 + 30 = 80
 * 。
 * 对于 i = 1 ：满足 nums1[j] < nums1[1] 的下标为 [2] ，只能选择这个值，结果为 30 。
 * 对于 i = 2 ：不存在满足 nums1[j] < nums1[2] 的下标，结果为 0 。
 * 对于 i = 3 ：满足 nums1[j] < nums1[3] 的下标为 [0, 1, 2, 4] ，选出其中值最大的两个，结果为 50 + 30 =
 * 80 。
 * 对于 i = 4 ：满足 nums1[j] < nums1[4] 的下标为 [1, 2] ，选出其中值最大的两个，结果为 30 + 20 = 50
 * 。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [2,2,2,2], nums2 = [3,1,2,3], k = 1
 * 
 * 输出：[0,0,0,0]
 * 
 * 解释：由于 nums1 中的所有元素相等，不存在满足条件 nums1[j] < nums1[i]，所有位置的结果都是 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums1.length == nums2.length
 * 1 <= n <= 10^5
 * 1 <= nums1[i], nums2[i] <= 10^6
 * 1 <= k <= n
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
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<tuple<int, int, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {nums1[i], nums2[i], i};
        }
        sort(a.begin(), a.end());

        vector<long long> ans(n);
        priority_queue<int, vector<int>, greater<>> pq;
        long long s = 0;
        int i = 0;
        while (i < n) {
            int start = i;
            int x = get<0>(a[start]);
            while (i < n && get<0>(a[i]) == x) {
                ans[get<2>(a[i])] = s;
                i++;
            }
            for (int j = start; j < i; j++) {
                int y = get<1>(a[j]);
                s += y;
                pq.push(y);
                if (pq.size() > k) {
                    s -= pq.top();
                    pq.pop();
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,1,5,3]\n[10,20,30,40,50]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2]\n[3,1,2,3]\n1\n
// @lcpr case=end

 */

