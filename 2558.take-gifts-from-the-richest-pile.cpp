/*
 * @lc app=leetcode.cn id=2558 lang=cpp
 * @lcpr version=30204
 *
 * [2558] 从数量最多的堆取走礼物
 *
 * https://leetcode.cn/problems/take-gifts-from-the-richest-pile/description/
 *
 * algorithms
 * Easy (71.44%)
 * Likes:    67
 * Dislikes: 0
 * Total Accepted:    36.6K
 * Total Submissions: 51.2K
 * Testcase Example:  '[25,64,9,4,100]\n4'
 *
 * 给你一个整数数组 gifts ，表示各堆礼物的数量。每一秒，你需要执行以下操作：
 * 
 * 
 * 选择礼物数量最多的那一堆。
 * 如果不止一堆都符合礼物数量最多，从中选择任一堆即可。
 * 将堆中的礼物数量减少到堆中原来礼物数量的平方根，向下取整。
 * 
 * 
 * 返回在 k 秒后剩下的礼物数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：gifts = [25,64,9,4,100], k = 4
 * 输出：29
 * 解释： 
 * 按下述方式取走礼物：
 * - 在第一秒，选中最后一堆，剩下 10 个礼物。
 * - 接着第二秒选中第二堆礼物，剩下 8 个礼物。
 * - 然后选中第一堆礼物，剩下 5 个礼物。
 * - 最后，再次选中最后一堆礼物，剩下 3 个礼物。
 * 最后剩下的礼物数量分别是 [5,8,9,4,3] ，所以，剩下礼物的总数量是 29 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：gifts = [1,1,1,1], k = 4
 * 输出：4
 * 解释：
 * 在本例中，不管选中哪一堆礼物，都必须剩下 1 个礼物。 
 * 也就是说，你无法获取任一堆中的礼物。 
 * 所以，剩下礼物的总数量是 4 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= gifts.length <= 10^3
 * 1 <= gifts[i] <= 10^9
 * 1 <= k <= 10^3
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
    long long pickGifts(vector<int>& gifts, int k) {
        make_heap(gifts.begin(), gifts.end());
        while (k-- && gifts[0] > 1) {
            // pop_heap()用于将堆的第零个元素与最后一个元素交换位置，
            // 然后针对前n - 1个元素调用make_heap()函数，它也有三个参数，
            // 参数意义与make_heap()相同，第三个参数应与make_heap时的第三个参数保持一致
            pop_heap(gifts.begin(), gifts.end());

            // 修改原栈顶元素(现在是栈底)
            gifts.back() = sqrt(gifts.back());

            // 在使用push_heap()前，请确保已经把数据通过q.push_back()传入q中，
            // 而不是在push_heap()后再使用q.push_back(t)
            push_heap(gifts.begin(), gifts.end());
        }
        return accumulate(gifts.begin(), gifts.end(), 0LL);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [25,64,9,4,100]\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n4\n
// @lcpr case=end

 */

