/*
 * @lc app=leetcode.cn id=3318 lang=cpp
 * @lcpr version=30204
 *
 * [3318] 计算子数组的 x-sum I
 *
 * https://leetcode.cn/problems/find-x-sum-of-all-k-long-subarrays-i/description/
 *
 * algorithms
 * Easy (66.65%)
 * Likes:    18
 * Dislikes: 0
 * Total Accepted:    9.6K
 * Total Submissions: 13.5K
 * Testcase Example:  '[1,1,2,2,3,4,2,3]\n6\n2'
 *
 * 给你一个由 n 个整数组成的数组 nums，以及两个整数 k 和 x。
 * 
 * 数组的 x-sum 计算按照以下步骤进行：
 * 
 * 
 * 统计数组中所有元素的出现次数。
 * 仅保留出现次数最多的前 x 个元素的每次出现。如果两个元素的出现次数相同，则数值 较大 的元素被认为出现次数更多。
 * 计算结果数组的和。
 * 
 * 
 * 注意，如果数组中的不同元素少于 x 个，则其 x-sum 是数组的元素总和。
 * 
 * 返回一个长度为 n - k + 1 的整数数组 answer，其中 answer[i] 是 子数组 nums[i..i + k - 1] 的
 * x-sum。
 * 
 * 子数组 是数组内的一个连续 非空 的元素序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,2,2,3,4,2,3], k = 6, x = 2
 * 
 * 输出：[6,10,12]
 * 
 * 解释：
 * 
 * 
 * 对于子数组 [1, 1, 2, 2, 3, 4]，只保留元素 1 和 2。因此，answer[0] = 1 + 1 + 2 + 2。
 * 对于子数组 [1, 2, 2, 3, 4, 2]，只保留元素 2 和 4。因此，answer[1] = 2 + 2 + 2 + 4。注意 4
 * 被保留是因为其数值大于出现其他出现次数相同的元素（3 和 1）。
 * 对于子数组 [2, 2, 3, 4, 2, 3]，只保留元素 2 和 3。因此，answer[2] = 2 + 2 + 2 + 3 + 3。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,8,7,8,7,5], k = 2, x = 2
 * 
 * 输出：[11,15,15,15,12]
 * 
 * 解释：
 * 
 * 由于 k == x，answer[i] 等于子数组 nums[i..i + k - 1] 的总和。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n == nums.length <= 50
 * 1 <= nums[i] <= 50
 * 1 <= x <= k <= nums.length
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
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int,int> mapNums;
        map<int,int> mapSums;
        int n = nums.size();
        vector<int> xSums;
        for(int i = 0;i<n;i++)
        {
            int num = nums[i];
            int pre = (mapNums[num]<<8 )+num;
            if(mapSums.count(pre))
            {
                mapSums.erase(pre);
            }
            mapNums[num]++;
            int key = (mapNums[num]<<8 )+ num;
            mapSums[key] = mapNums[num] * num;
            if(i<k-1)
            {
              continue;
            }
            int sum = 0;
            auto sumIt = mapSums.rbegin();
            for(int j= 0;j < x;j++)
            {
                if(sumIt == mapSums.rend())
                {
                   break;
                }
                sum += sumIt->second;
                sumIt++;
            }
            xSums.push_back(sum);
            int left = i -k +1;
            int numLeft = nums[left];
            pre = (mapNums[numLeft]<<8 )+ nums[left];
            mapSums.erase(pre);
            mapNums[numLeft]--;
            if(mapNums[numLeft]== 0)
            {
                mapNums.erase(numLeft);
            }
            else
            {
                key = (mapNums[numLeft]<<8 )+ numLeft;
                mapSums[key] = mapNums[numLeft] * numLeft;
            }
        }
        return xSums;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2,2,3,4,2,3]\n6\n2\n
// @lcpr case=end

// @lcpr case=start
// [3,8,7,8,7,5]\n2\n2\n
// @lcpr case=end

 */

