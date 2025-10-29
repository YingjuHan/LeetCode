/*
 * @lc app=leetcode.cn id=1642 lang=cpp
 * @lcpr version=30204
 *
 * [1642] 可以到达的最远建筑
 *
 * https://leetcode.cn/problems/furthest-building-you-can-reach/description/
 *
 * algorithms
 * Medium (50.37%)
 * Likes:    193
 * Dislikes: 0
 * Total Accepted:    19.1K
 * Total Submissions: 37.9K
 * Testcase Example:  '[4,2,7,6,9,14,12]\n5\n1'
 *
 * 给你一个整数数组 heights ，表示建筑物的高度。另有一些砖块 bricks 和梯子 ladders 。
 * 
 * 你从建筑物 0 开始旅程，不断向后面的建筑物移动，期间可能会用到砖块或梯子。
 * 
 * 当从建筑物 i 移动到建筑物 i+1（下标 从 0 开始 ）时：
 * 
 * 
 * 如果当前建筑物的高度 大于或等于 下一建筑物的高度，则不需要梯子或砖块
 * 如果当前建筑的高度 小于 下一个建筑的高度，您可以使用 一架梯子 或 (h[i+1] - h[i]) 个砖块
 * 
 * 如果以最佳方式使用给定的梯子和砖块，返回你可以到达的最远建筑物的下标（下标 从 0 开始 ）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
 * 输出：4
 * 解释：从建筑物 0 出发，你可以按此方案完成旅程：
 * - 不使用砖块或梯子到达建筑物 1 ，因为 4 >= 2
 * - 使用 5 个砖块到达建筑物 2 。你必须使用砖块或梯子，因为 2 < 7
 * - 不使用砖块或梯子到达建筑物 3 ，因为 7 >= 6
 * - 使用唯一的梯子到达建筑物 4 。你必须使用砖块或梯子，因为 6 < 9
 * 无法越过建筑物 4 ，因为没有更多砖块或梯子。
 * 
 * 
 * 示例 2：
 * 
 * 输入：heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
 * 输出：7
 * 
 * 
 * 示例 3：
 * 
 * 输入：heights = [14,3,19,3], bricks = 17, ladders = 0
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= heights.length <= 10^5
 * 1 <= heights[i] <= 10^6
 * 0 <= bricks <= 10^9
 * 0 <= ladders <= heights.length
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
     * 反悔贪心
     * 
     * 当能走尽量向前走，走不了用工具
     * 先用砖块，砖块不行用梯子
     * 反悔使用梯子，贪心的使用在高度差最大的位置
     * 
     * 大顶堆：快速得到走过位置的最大高度差
     * 以为低到高才需要工具，大顶堆只记录h[i] - h[i - 1] > 0的高度差
     * 
     * 所以整体思路就是：
     * 大顶堆维护已经走过的位置使用工具的高度差(即使用砖块的数)
     * 当到达一个位置不能走了bricks < 高度差
     * 那么就要 反悔 了，用一个梯子，用在高度差最大的位置
     * 所以那个位置的砖块又可以加回来了，这就是反悔吧
     * 如果没梯子了说明只能到这个位置不能往后走了
     * 所以梯子就可以看作可以反悔的次数
     * 
     */
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size(); 
        priority_queue<int> pq;
        int i = 0;
        for (; i < n - 1; i++) {
            if (heights[i] < heights[i + 1]) {
                int diff = heights[i + 1] - heights[i]; //高度差
                //要使用工具了
                //先使用砖块
                if (bricks >= diff) {
                    bricks -= diff;
                    pq.push(diff);
                } else if (ladders > 0) {
                    //使用砖块到不了这个位置，必须要用梯子了
                    //要将梯子用在diff最大的位置，也有可能是当前位置到一个位置的diff最大，所以要将当前位置的diff进堆，就不用特殊判断了
                    pq.push(diff);
                    bricks -= diff; 
                    bricks += pq.top(); //反悔 用在高度差最大的位置，那么那个地方的砖块又可以拿回来了
                    pq.pop();
                    ladders--; //使用梯子
                } else {
                    break; //砖块和梯子都不够用了，停止前进
                }
            }
        }
        return i;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,7,6,9,14,12]\n5\n1\n
// @lcpr case=end

// @lcpr case=start
// [4,12,2,7,3,18,20,3,19]\n10\n2\n
// @lcpr case=end

// @lcpr case=start
// [14,3,19,3]\n17\n0\n
// @lcpr case=end

 */

