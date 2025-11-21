/*
 * @lc app=leetcode.cn id=2751 lang=cpp
 * @lcpr version=30204
 *
 * [2751] 机器人碰撞
 *
 * https://leetcode.cn/problems/robot-collisions/description/
 *
 * algorithms
 * Hard (49.58%)
 * Likes:    22
 * Dislikes: 0
 * Total Accepted:    4K
 * Total Submissions: 7.9K
 * Testcase Example:  '[5,4,3,2,1]\n[2,17,9,15,10]\n"RRRRR"'
 *
 * 现有 n 个机器人，编号从 1 开始，每个机器人包含在路线上的位置、健康度和移动方向。
 * 
 * 给你下标从 0 开始的两个整数数组 positions、healths 和一个字符串 directions（directions[i] 为 'L' 表示
 * 向左 或 'R' 表示 向右）。 positions 中的所有整数 互不相同 。
 * 
 * 所有机器人以 相同速度 同时 沿给定方向在路线上移动。如果两个机器人移动到相同位置，则会发生 碰撞 。
 * 
 * 如果两个机器人发生碰撞，则将 健康度较低 的机器人从路线中 移除 ，并且另一个机器人的健康度 减少 1 。幸存下来的机器人将会继续沿着与之前 相同
 * 的方向前进。如果两个机器人的健康度相同，则将二者都从路线中移除。
 * 
 * 请你确定全部碰撞后幸存下的所有机器人的 健康度 ，并按照原来机器人编号的顺序排列。即机器人 1 （如果幸存）的最终健康度，机器人 2
 * （如果幸存）的最终健康度等。 如果不存在幸存的机器人，则返回空数组。
 * 
 * 在不再发生任何碰撞后，请你以数组形式，返回所有剩余机器人的健康度（按机器人输入中的编号顺序）。
 * 
 * 注意：位置  positions 可能是乱序的。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
 * 输出：[2,17,9,15,10]
 * 解释：在本例中不存在碰撞，因为所有机器人向同一方向移动。所以，从第一个机器人开始依序返回健康度，[2, 17, 9, 15, 10] 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
 * 输出：[14]
 * 解释：本例中发生 2 次碰撞。首先，机器人 1 和机器人 2 将会碰撞，因为二者健康度相同，二者都将被从路线中移除。接下来，机器人 3 和机器人 4
 * 将会发生碰撞，由于机器人 4 的健康度更小，则它会被移除，而机器人 3 的健康度变为 15 - 1 = 14 。仅剩机器人 3 ，所以返回 [14]
 * 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：positions = [1,2,5,6], healths = [10,10,11,11], directions = "RLRL"
 * 输出：[]
 * 解释：机器人 1 和机器人 2 将会碰撞，因为二者健康度相同，二者都将被从路线中移除。机器人 3 和机器人 4
 * 将会碰撞，因为二者健康度相同，二者都将被从路线中移除。所以返回空数组 [] 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= positions.length == healths.length == directions.length == n <=
 * 10^5
 * 1 <= positions[i], healths[i] <= 10^9
 * directions[i] == 'L' 或 directions[i] == 'R'
 * positions 中的所有值互不相同
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
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h, string d) {
        int n = p.size();
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](const int i, const int j) {
            return p[i] < p[j];
        });
        stack<int> st;
        for (int i : id) {
            if (d[i] == 'R') { // 向右的都入栈
                st.push(i);
                continue;
            }

            while (!st.empty()) {
                int top = st.top();
                if (h[top] > h[i]) { // 栈顶的健康度大
                    h[top]--;
                    h[i] = 0;
                    break;
                }
                if (h[top] == h[i]) {
                    h[top] = 0;
                    st.pop();
                    h[i] = 0;
                    break;
                }
                
                if (h[top] < h[i]) {
                    h[top] = 0;
                    st.pop();
                    h[i]--;
                }
            }
        }

        h.erase(remove(h.begin(), h.end(), 0), h.end());
        return h;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,3,2,1]\n[2,17,9,15,10]\n"RRRRR"\n
// @lcpr case=end

// @lcpr case=start
// [3,5,2,6]\n[10,10,15,12]\n"RLRL"\n
// @lcpr case=end

// @lcpr case=start
// [1,2,5,6]\n[10,10,11,11]\n"RLRL"\n
// @lcpr case=end

 */

