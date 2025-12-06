/*
 * @lc app=leetcode.cn id=LCP 30 lang=cpp
 * @lcpr version=30204
 *
 * [LCP 30] 魔塔游戏
 *
 * https://leetcode.cn/problems/p0NxJO/description/
 *
 * algorithms
 * Medium (46.37%)
 * Likes:    128
 * Dislikes: 0
 * Total Accepted:    27.5K
 * Total Submissions: 59.3K
 * Testcase Example:  '[100,100,100,-250,-60,-140,-50,-50,100,150]'
 *
 * 小扣当前位于魔塔游戏第一层，共有 `N` 个房间，编号为 `0 ~ N-1`。每个房间的补血道具/怪物对于血量影响记于数组
 * `nums`，其中正数表示道具补血数值，即血量增加对应数值；负数表示怪物造成伤害值，即血量减少对应数值；`0` 表示房间对血量无影响。
 * 
 * **小扣初始血量为
 * 1，且无上限**。假定小扣原计划按房间编号升序访问所有房间补血/打怪，**为保证血量始终为正值**，小扣需对房间访问顺序进行调整，**每次仅能将一个怪物房间（负数的房间）调整至访问顺序末尾**。请返回小扣最少需要调整几次，才能顺利访问所有房间。若调整顺序也无法访问完全部房间，请返回
 * -1。
 * 
 * 
 * **示例 1：**
 * >输入：`nums = [100,100,100,-250,-60,-140,-50,-50,100,150]`
 * >
 * >输出：`1`
 * >
 * >解释：初始血量为 1。至少需要将 nums[3] 调整至访问顺序末尾以满足要求。
 * 
 * **示例 2：**
 * >输入：`nums = [-200,-300,400,0]`
 * >
 * >输出：`-1`
 * >
 * >解释：调整访问顺序也无法完成全部房间的访问。
 * 
 * **提示：**
 * - `1 <= nums.length <= 10^5`
 * - `-10^5 <= nums[i] <= 10^5`
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
class Solution {
public:
    int magicTower(vector<int>& nums) {
        if (accumulate(nums.begin(), nums.end(), 0LL) < 0) {
            return -1;
        }

        int res = 0;
        long long hp = 1;
        priority_queue<int, vector<int>, less<int>> pq;
        for (int num : nums) {
            if (num < 0) {
                pq.push(-num);
            }
            hp += num;
            if (hp < 1) {
                hp += pq.top(); // 实际上不需要真的移到末尾，因为我们保证了数组元素和非负，最后血量必然是正数，所以无需再次遍历移到数组末尾的数字
                pq.pop();
                res++;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [100,100,100,-250,-60,-140,-50,-50,100,150]`>\n
// @lcpr case=end

// @lcpr case=start
// [-200,-300,400,0]`>\n
// @lcpr case=end

 */

