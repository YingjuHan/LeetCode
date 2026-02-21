/*
 * @lc app=leetcode.cn id=207 lang=cpp
 * @lcpr version=30204
 *
 * [207] 课程表
 *
 * https://leetcode.cn/problems/course-schedule/description/
 *
 * algorithms
 * Medium (56.40%)
 * Likes:    2302
 * Dislikes: 0
 * Total Accepted:    698.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
 * 
 * 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi]
 * ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
 * 
 * 
 * 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
 * 
 * 
 * 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：numCourses = 2, prerequisites = [[1,0]]
 * 输出：true
 * 解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
 * 
 * 示例 2：
 * 
 * 输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
 * 输出：false
 * 解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * prerequisites[i] 中的所有课程对 互不相同
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for (auto& p : prerequisites) {
            g[p[1]].push_back(p[0]);
        }

        vector<int> colors(numCourses);
        // 返回 true 表示找到了环
        auto dfs = [&](this auto&& dfs, int x) -> bool {
            colors[x] = 1; // x 正在访问中
            for (int y : g[x]) {
                // 情况一：colors[y] == 1，表示发生循环依赖，找到了环
                // 情况二：colors[y] == 0，未知，继续递归 y 获取信息
                // 情况三：colors[y] == 2，继续递归 y 只会重蹈覆辙，和之前一样无法找到环
                if (colors[y] == 1 || colors[y] == 0 && dfs(y)) {
                    return true; // 找到了环
                }
            }
            colors[x] = 2; // x 完全访问完毕，从 x 出发无法找到环
            return false; // 没有找到环
        };

        for (int i = 0; i < numCourses; i++) {
            if (colors[i] == 0 && dfs(i)) {
                return false; // 有环
            }
        }
        return true; // 没有环
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0],[0,1]]\n
// @lcpr case=end

 */

