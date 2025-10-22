/*
 * @lc app=leetcode.cn id=2011 lang=cpp
 * @lcpr version=30204
 *
 * [2011] 执行操作后的变量值
 *
 * https://leetcode.cn/problems/final-value-of-variable-after-performing-operations/description/
 *
 * algorithms
 * Easy (86.33%)
 * Likes:    81
 * Dislikes: 0
 * Total Accepted:    71.5K
 * Total Submissions: 82.1K
 * Testcase Example:  '["--X","X++","X++"]'
 *
 * 存在一种仅支持 4 种操作和 1 个变量 X 的编程语言：
 * 
 * 
 * ++X 和 X++ 使变量 X 的值 加 1
 * --X 和 X-- 使变量 X 的值 减 1
 * 
 * 
 * 最初，X 的值是 0
 * 
 * 给你一个字符串数组 operations ，这是由操作组成的一个列表，返回执行所有操作后， X 的 最终值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：operations = ["--X","X++","X++"]
 * 输出：1
 * 解释：操作按下述步骤执行：
 * 最初，X = 0
 * --X：X 减 1 ，X =  0 - 1 = -1
 * X++：X 加 1 ，X = -1 + 1 =  0
 * X++：X 加 1 ，X =  0 + 1 =  1
 * 
 * 
 * 示例 2：
 * 
 * 输入：operations = ["++X","++X","X++"]
 * 输出：3
 * 解释：操作按下述步骤执行： 
 * 最初，X = 0
 * ++X：X 加 1 ，X = 0 + 1 = 1
 * ++X：X 加 1 ，X = 1 + 1 = 2
 * X++：X 加 1 ，X = 2 + 1 = 3
 * 
 * 
 * 示例 3：
 * 
 * 输入：operations = ["X++","++X","--X","X--"]
 * 输出：0
 * 解释：操作按下述步骤执行：
 * 最初，X = 0
 * X++：X 加 1 ，X = 0 + 1 = 1
 * ++X：X 加 1 ，X = 1 + 1 = 2
 * --X：X 减 1 ，X = 2 - 1 = 1
 * X--：X 减 1 ，X = 1 - 1 = 0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= operations.length <= 100
 * operations[i] 将会是 "++X"、"X++"、"--X" 或 "X--"
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
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (string operation : operations) {
            if (operation == "X++" || operation == "++X") {
                x++;
            } else if (operation == "X--" || operation == "--X") {
                x--;
            }
        }
        return x;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["--X","X++","X++"]\n
// @lcpr case=end

// @lcpr case=start
// ["++X","++X","X++"]\n
// @lcpr case=end

// @lcpr case=start
// ["X++","++X","--X","X--"]\n
// @lcpr case=end

 */

