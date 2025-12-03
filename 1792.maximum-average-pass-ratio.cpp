/*
 * @lc app=leetcode.cn id=1792 lang=cpp
 * @lcpr version=30204
 *
 * [1792] 最大平均通过率
 *
 * https://leetcode.cn/problems/maximum-average-pass-ratio/description/
 *
 * algorithms
 * Medium (61.50%)
 * Likes:    198
 * Dislikes: 0
 * Total Accepted:    39.1K
 * Total Submissions: 63.5K
 * Testcase Example:  '[[1,2],[3,5],[2,2]]\n2'
 *
 * 一所学校里有一些班级，每个班级里有一些学生，现在每个班都会进行一场期末考试。给你一个二维数组
 * classes ，其中 classes[i] = [passi,
 * totali] ，表示你提前知道了第 i 个班级总共有 totali 个学生，其中只有 passi 个学生可以通过考试。
 *
 * 给你一个整数 extraStudents ，表示额外有 extraStudents 个聪明的学生，他们
 * 一定 能通过任何班级的期末考。你需要给这
 * extraStudents 个学生每人都安排一个班级，使得 所有 班级的 平均 通过率 最大 。
 *
 * 一个班级的 通过率 等于这个班级通过考试的学生人数除以这个班级的总人数。平均通过率 是所有班级的通过率之和除以班级数目。
 *
 * 请你返回在安排这 extraStudents 个学生去对应班级后的
 * 最大 平均通过率。与标准答案误差范围在 10^-5 以内的结果都会视为正确结果。
 *
 *
 *
 * 示例 1：
 *
 * 输入：classes = [[1,2],[3,5],[2,2]], extraStudents = 2
 * 输出：0.78333
 * 解释：你可以将额外的两个学生都安排到第一个班级，平均通过率为 (3/4 + 3/5 +
 * 2/2) / 3 = 0.78333 。
 *
 *
 * 示例 2：
 *
 * 输入：classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
 * 输出：0.53485
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= classes.length <= 10^5
 * classes[i].length == 2
 * 1 <= passi <= totali <= 10^5
 * 1 <= extraStudents <= 10^5
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
  struct Ratio {
    int pass, total;
    bool operator<(const Ratio &oth) const {
      return (long long)(oth.total + 1) * oth.total * (total - pass) <
             (long long)(total + 1) * total * (oth.total - oth.pass);
    }
  };

  double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
    priority_queue<Ratio> q;
    for (auto& c : classes) {
        q.push({c[0], c[1]});
    }

    for (int i = 0; i < extraStudents; i++) {
        auto [pass, total] = q.top();
        q.pop();
        q.push({pass + 1, total + 1});
    }

    double res = 0;
    for (int i = 0; i < classes.size(); i++) {
        auto [pass, total] = q.top();
        q.pop();
        res += 1.0f * pass / total;
    }
    return res / classes.size();
  }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2],[3,5],[2,2]]\n2\n
// @lcpr case=end

// @lcpr case=start
// [[2,4],[3,9],[4,5],[2,10]]\n4\n
// @lcpr case=end

 */
