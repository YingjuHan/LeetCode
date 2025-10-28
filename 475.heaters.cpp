/*
 * @lc app=leetcode.cn id=475 lang=cpp
 * @lcpr version=30204
 *
 * [475] 供暖器
 *
 * https://leetcode.cn/problems/heaters/description/
 *
 * algorithms
 * Medium (42.09%)
 * Likes:    516
 * Dislikes: 0
 * Total Accepted:    87.4K
 * Total Submissions: 207.6K
 * Testcase Example:  '[1,2,3]\n[2]'
 *
 * 冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。
 * 
 * 在加热器的加热半径范围内的每个房屋都可以获得供暖。
 * 
 * 现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。
 * 
 * 注意：所有供暖器 heaters 都遵循你的半径标准，加热的半径也一样。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: houses = [1,2,3], heaters = [2]
 * 输出: 1
 * 解释: 仅在位置 2 上有一个供暖器。如果我们将加热半径设为 1，那么所有房屋就都能得到供暖。
 * 
 * 
 * 示例 2:
 * 
 * 输入: houses = [1,2,3,4], heaters = [1,4]
 * 输出: 1
 * 解释: 在位置 1, 4 上有两个供暖器。我们需要将加热半径设为 1，这样所有房屋就都能得到供暖。
 * 
 * 
 * 示例 3：
 * 
 * 输入：houses = [1,5], heaters = [2]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= houses.length, heaters.length <= 3 * 10^4
 * 1 <= houses[i], heaters[i] <= 10^9
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
     * 找到房子和取暖器的距离的最小值，在所有的最小值中求出最大值 
     */
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int n = houses.size();

        int left = 0, right = max(*houses.rbegin(), *heaters.rbegin());

        auto check = [&](int r) -> bool {
            int cur_house_idx = 0;
            for (int heater : heaters) {
                int left_bound = heater - r;
                int right_bound = heater + r;

                while (cur_house_idx < n) {
                    if (houses[cur_house_idx] < left_bound || houses[cur_house_idx] > right_bound) {
                        break;
                    }
                    cur_house_idx++;
                }
                if (cur_house_idx >= n) {
                    return true;
                }
            }
            return cur_house_idx >= n;
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (!check(mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n[1,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,5]\n[2]\n
// @lcpr case=end

 */

