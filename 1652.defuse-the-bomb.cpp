/*
 * @lc app=leetcode.cn id=1652 lang=cpp
 * @lcpr version=30204
 *
 * [1652] 拆炸弹
 *
 * https://leetcode.cn/problems/defuse-the-bomb/description/
 *
 * algorithms
 * Easy (71.48%)
 * Likes:    206
 * Dislikes: 0
 * Total Accepted:    77K
 * Total Submissions: 107.8K
 * Testcase Example:  '[5,7,1,4]\n3'
 *
 * 你有一个炸弹需要拆除，时间紧迫！你的情报员会给你一个长度为 n 的 循环 数组 code 以及一个密钥 k 。
 * 
 * 为了获得正确的密码，你需要替换掉每一个数字。所有数字会 同时 被替换。
 * 
 * 
 * 如果 k > 0 ，将第 i 个数字用 接下来 k 个数字之和替换。
 * 如果 k < 0 ，将第 i 个数字用 之前 k 个数字之和替换。
 * 如果 k == 0 ，将第 i 个数字用 0 替换。
 * 
 * 
 * 由于 code 是循环的， code[n-1] 下一个元素是 code[0] ，且 code[0] 前一个元素是 code[n-1] 。
 * 
 * 给你 循环 数组 code 和整数密钥 k ，请你返回解密后的结果来拆除炸弹！
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：code = [5,7,1,4], k = 3
 * 输出：[12,10,16,13]
 * 解释：每个数字都被接下来 3 个数字之和替换。解密后的密码为 [7+1+4, 1+4+5, 4+5+7, 5+7+1]。注意到数组是循环连接的。
 * 
 * 
 * 示例 2：
 * 
 * 输入：code = [1,2,3,4], k = 0
 * 输出：[0,0,0,0]
 * 解释：当 k 为 0 时，所有数字都被 0 替换。
 * 
 * 
 * 示例 3：
 * 
 * 输入：code = [2,4,9,3], k = -2
 * 输出：[12,5,6,13]
 * 解释：解密后的密码为 [3+9, 2+3, 4+2, 9+4] 。注意到数组是循环连接的。如果 k 是负数，那么和为 之前 的数字。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == code.length
 * 1 <= n <= 100
 * 1 <= code[i] <= 100
 * -(n - 1) <= k <= n - 1
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
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        
        int r = k > 0 ? k + 1 : n;
        k = abs(k);

        int s = reduce(code.begin() + r - k, code.begin() + r);

        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            res[i] = s;
            s += code[r % n] - code[(r - k) % n];
            r++;
        }

        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,7,1,4]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,4,9,3]\n-2\n
// @lcpr case=end

 */

