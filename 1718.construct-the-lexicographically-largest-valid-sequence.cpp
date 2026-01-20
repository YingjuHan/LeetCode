/*
 * @lc app=leetcode.cn id=1718 lang=cpp
 * @lcpr version=30204
 *
 * [1718] 构建字典序最大的可行序列
 *
 * https://leetcode.cn/problems/construct-the-lexicographically-largest-valid-sequence/description/
 *
 * algorithms
 * Medium (53.57%)
 * Likes:    51
 * Dislikes: 0
 * Total Accepted:    5K
 * Total Submissions: 9.3K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，请你找到满足下面条件的一个序列：
 * 
 * 
 * 整数 1 在序列中只出现一次。
 * 2 到 n 之间每个整数都恰好出现两次。
 * 对于每个 2 到 n 之间的整数 i ，两个 i 之间出现的距离恰好为 i 。
 * 
 * 
 * 序列里面两个数 a[i] 和 a[j] 之间的 距离 ，我们定义为它们下标绝对值之差 |j - i| 。
 * 
 * 请你返回满足上述条件中 字典序最大 的序列。题目保证在给定限制条件下，一定存在解。
 * 
 * 一个序列 a 被认为比序列 b （两者长度相同）字典序更大的条件是： a 和 b 中第一个不一样的数字处，a 序列的数字比 b
 * 序列的数字大。比方说，[0,1,9,0] 比 [0,1,5,6] 字典序更大，因为第一个不同的位置是第三个数字，且 9 比 5 大。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 3
 * 输出：[3,1,2,3,2]
 * 解释：[2,3,2,1,3] 也是一个可行的序列，但是 [3,1,2,3,2] 是字典序最大的序列。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 5
 * 输出：[5,3,1,4,3,5,2,4,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 20
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
    bool dfs(int index, int n, vector<uint8_t>& used, vector<int>& res) {
        while (index < res.size() && res[index] != 0) {
            index++;
        }

        if (index == res.size()) {
            return true;
        }

        for (int i = n; i >= 1; i--) {
            if (used[i]) {
                continue;
            }
            if (i == 1) {
                // 1 只放一次
                res[index] = 1;
                used[1] = 1;
                if (dfs(index + 1, n, used, res)) return true;
                used[1] = 0;
                res[index] = 0;
            } else {
                int secondPos = index + i;
                if (secondPos < (int)res.size() && res[secondPos] == 0) {
                    res[index] = i;
                    res[secondPos] = i;
                    used[i] = 1;

                    if (dfs(index + 1, n, used, res)) return true;

                    used[i] = 0;
                    res[index] = 0;
                    res[secondPos] = 0;
                }
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        int len = 2 * n - 1;
        vector<int> res(len, 0);
        vector<uint8_t> used(n + 1, 0); // used从0开始n+1个时最大下标才是n
        dfs(0, n, used, res);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

 */

