/*
 * @lc app=leetcode.cn id=853 lang=cpp
 * @lcpr version=30204
 *
 * [853] 车队
 *
 * https://leetcode.cn/problems/car-fleet/description/
 *
 * algorithms
 * Medium (43.67%)
 * Likes:    245
 * Dislikes: 0
 * Total Accepted:    31.9K
 * Total Submissions: 68.8K
 * Testcase Example:  '12\n[10,8,0,5,3]\n[2,4,1,1,3]'
 *
 * 在一条单行道上，有 n 辆车开往同一目的地。目的地是几英里以外的 target 。
 * 
 * 给定两个整数数组 position 和 speed ，长度都是 n ，其中 position[i] 是第 i 辆车的位置， speed[i] 是第 i
 * 辆车的速度(单位是英里/小时)。
 * 
 * 一辆车永远不会超过前面的另一辆车，但它可以追上去，并以较慢车的速度在另一辆车旁边行驶。
 * 
 * 车队 是指并排行驶的一辆或几辆汽车。车队的速度是车队中 最慢 的车的速度。
 * 
 * 即便一辆车在 target 才赶上了一个车队，它们仍然会被视作是同一个车队。
 * 
 * 返回到达目的地的车队数量 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
 * 
 * 输出：3
 * 
 * 解释：
 * 
 * 
 * 从 10（速度为 2）和 8（速度为 4）开始的车会组成一个车队，它们在 12 相遇。车队在 target 形成。
 * 从 0（速度为 1）开始的车不会追上其它任何车，所以它自己是一个车队。
 * 从 5（速度为 1） 和 3（速度为 3）开始的车组成一个车队，在 6 相遇。车队以速度 1 移动直到它到达 target。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：target = 10, position = [3], speed = [3]
 * 
 * 输出：1
 * 
 * 解释：
 * 只有一辆车，因此只有一个车队。
 * 
 * 示例 3：
 * 
 * 
 * 输入：target = 100, position = [0,2,4], speed = [4,2,1]
 * 
 * 输出：1
 * 
 * 解释：
 * 
 * 
 * 从 0（速度为 4） 和 2（速度为 2）开始的车组成一个车队，在 4 相遇。从 4 开始的车（速度为 1）移动到了 5。
 * 然后，在 4（速度为 2）的车队和在 5（速度为 1）的车成为一个车队，在 6 相遇。车队以速度 1 移动直到它到达 target。
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == position.length == speed.length
 * 1 <= n <= 10^5
 * 0 < target <= 10^6
 * 0 <= position[i] < target
 * position 中每个值都 不同
 * 0 < speed[i] <= 10^6
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
     * 后车能追上前车，说明前车速度慢，合并成一个车队后最终到达时间以车队最开始位置最靠前的车决定
     * （前车追不上前面的车，后车也一定追不上），因此考虑用单调栈（要先按位置排序），
     * 存储每个车队到达终点的用时。单调栈存储元素个数即最终车队数。
     * 
     * 按位置从前向后遍历
     * 如果后面的元素(位置考前的车)用时长,那么可以追上,弹出栈顶元素,
     * 再将每一辆车入栈(待检验是否可以追上前车)
     */
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int, double> mp;
        stack<double> st;
        for (int i = 0; i < position.size(); i++) {
            mp[position[i]] = (double)(target - position[i]) / speed[i];
        }

        sort(position.begin(),position.end());
        for(int i=0;i<position.size();i++){
            while(!st.empty()&&mp[position[i]]>=st.top())st.pop();
            st.push(mp[position[i]]);
        }
        return st.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// 12\n[10,8,0,5,3]\n[2,4,1,1,3]\n
// @lcpr case=end

// @lcpr case=start
// 10\n[3]\n[3]\n
// @lcpr case=end

// @lcpr case=start
// 100\n[0,2,4]\n[4,2,1]\n
// @lcpr case=end

 */

