/*
 * @lc app=leetcode.cn id=3234 lang=cpp
 * @lcpr version=30204
 *
 * [3234] 统计 1 显著的字符串的数量
 *
 * https://leetcode.cn/problems/count-the-number-of-substrings-with-dominant-ones/description/
 *
 * algorithms
 * Medium (29.76%)
 * Likes:    35
 * Dislikes: 0
 * Total Accepted:    7.3K
 * Total Submissions: 20.6K
 * Testcase Example:  '"00011"'
 *
 * 给你一个二进制字符串 s。
 *
 * 请你统计并返回其中 1 显著  的 子字符串 的数量。
 *
 * 如果字符串中 1 的数量 大于或等于 0 的数量的 平方，则认为该字符串是一个 1 显著
 * 的字符串 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "00011"
 *
 * 输出：5
 *
 * 解释：
 *
 * 1 显著的子字符串如下表所示。
 *
 *
 *
 *
 *
 * i
 * j
 * s[i..j]
 * 0 的数量
 * 1 的数量
 *
 *
 *
 *
 * 3
 * 3
 * 1
 * 0
 * 1
 *
 *
 * 4
 * 4
 * 1
 * 0
 * 1
 *
 *
 * 2
 * 3
 * 01
 * 1
 * 1
 *
 *
 * 3
 * 4
 * 11
 * 0
 * 2
 *
 *
 * 2
 * 4
 * 011
 * 1
 * 2
 *
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "101101"
 *
 * 输出：16
 *
 * 解释：
 *
 * 1 不显著的子字符串如下表所示。
 *
 * 总共有 21 个子字符串，其中 5 个是 1 不显著字符串，因此有 16 个 1
 * 显著子字符串。
 *
 *
 *
 *
 *
 * i
 * j
 * s[i..j]
 * 0 的数量
 * 1 的数量
 *
 *
 *
 *
 * 1
 * 1
 * 0
 * 1
 * 0
 *
 *
 * 4
 * 4
 * 0
 * 1
 * 0
 *
 *
 * 1
 * 4
 * 0110
 * 2
 * 2
 *
 *
 * 0
 * 4
 * 10110
 * 2
 * 3
 *
 *
 * 1
 * 5
 * 01101
 * 2
 * 3
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 4 * 10^4
 * s 仅包含字符 '0' 和 '1'。
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
  int numberOfSubstrings(string s) {
    vector<int> pos0 = {-1};
    int total1 = 0;
    int res = 0;
    for (int r = 0; r < s.length(); r++) {
      if (s[r] == '0') {
        pos0.push_back(r);
      } else {
        total1++;
        res += r - pos0.back();
      }

      int m = pos0.size();
      for (int i = m - 1; i > 0 && (m - i) * (m - i) <= total1; i--) {
        int p = pos0[i - 1], q = pos0[i];
        int cnt0 = m - i;
        int cnt1 = r - q + 1 - cnt0;
        res += max(q - max(cnt0 * cnt0 - cnt1, 0) - p, 0);
      }
    }

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "00011"\n
// @lcpr case=end

// @lcpr case=start
// "101101"\n
// @lcpr case=end

 */
