/*
 * @lc app=leetcode.cn id=1441 lang=cpp
 * @lcpr version=30204
 *
 * [1441] 用栈操作构建数组
 *
 * https://leetcode.cn/problems/build-an-array-with-stack-operations/description/
 *
 * algorithms
 * Medium (72.06%)
 * Likes:    137
 * Dislikes: 0
 * Total Accepted:    59.9K
 * Total Submissions: 82.1K
 * Testcase Example:  '[1,3]\n3'
 *
 * 给你一个数组 target 和一个整数 n。
 *
 * 给你一个空栈和两种操作：
 *
 *
 * "Push"：将一个整数加到栈顶。
 * "Pop"：从栈顶删除一个整数。
 *
 *
 * 同时给定一个范围 [1, n] 中的整数流。
 *
 * 使用两个栈操作使栈中的数字（从底部到顶部）等于 target。你应该遵循以下规则：
 *
 *
 * 如果整数流不为空，从流中选取下一个整数并将其推送到栈顶。
 * 如果栈不为空，弹出栈顶的整数。
 * 如果，在任何时刻，栈中的元素（从底部到顶部）等于
 * target，则不要从流中读取新的整数，也不要对栈进行更多操作。
 *
 *
 * 请返回遵循上述规则构建 target 所用的操作序列。如果存在多个合法答案，返回 任一
 * 即可。
 *
 *
 *
 * 示例 1：
 *
 * 输入：target = [1,3], n = 3
 * 输出：["Push","Push","Pop","Push"]
 * 解释：一开始栈为空。最后一个元素是栈顶。
 * 从流中读取 1 并推入数组。s = [1]。
 * 从流中读取 2 并推入数组。s = [1,2]。
 * 从栈顶删除整数。s = [1]。
 * 从流中读取 3 并推入数组。s = [1,3]。
 *
 *
 * 示例 2：
 *
 * 输入：target = [1,2,3], n = 3
 * 输出：["Push","Push","Push"]
 * 解释：一开始栈为空。最后一个元素是栈顶。
 * 从流中读取 1 并推入数组。s = [1]。
 * 从流中读取 2 并推入数组。s = [1,2]。
 * 从流中读取 3 并推入数组。s = [1,2,3]。
 *
 *
 * 示例 3：
 *
 * 输入：target = [1,2], n = 4
 * 输出：["Push","Push"]
 * 解释：一开始栈为空。最后一个元素是栈顶。
 * 从流中读取 1 并推入数组。s = [1]。
 * 从流中读取 2 并推入数组。s = [1,2]。
 * 由于栈（从底部到顶部）等于 target，我们停止栈操作。
 * 从流中读取整数 3 的答案不被接受。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= target.length <= 100
 * 1 <= n <= 100
 * 1 <= target[i] <= n
 * target 严格递增
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
class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> res;
        int mx = target.back();
        int i = 0;
        for (int x = 1; x <= mx; x++)
        {
            res.push_back("Push");
            if (x == target[i])
            {
                i++;
            }
            else
            {
                res.push_back("Pop");
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n4\n
// @lcpr case=end

 */
