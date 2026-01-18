/*
 * @lc app=leetcode.cn id=1593 lang=cpp
 * @lcpr version=30204
 *
 * [1593] 拆分字符串使唯一子字符串的数目最大
 *
 * https://leetcode.cn/problems/split-a-string-into-the-max-number-of-unique-substrings/description/
 *
 * algorithms
 * Medium (62.51%)
 * Likes:    69
 * Dislikes: 0
 * Total Accepted:    14K
 * Total Submissions: 22.3K
 * Testcase Example:  '"ababccc"'
 *
 * 给你一个字符串 s ，请你拆分该字符串，并返回拆分后唯一子字符串的最大数目。
 * 
 * 字符串 s 拆分后可以得到若干 非空子字符串 ，这些子字符串连接后应当能够还原为原字符串。但是拆分出来的每个子字符串都必须是 唯一的 。
 * 
 * 注意：子字符串 是字符串中的一个连续字符序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "ababccc"
 * 输出：5
 * 解释：一种最大拆分方法为 ['a', 'b', 'ab', 'c', 'cc'] 。像 ['a', 'b', 'a', 'b', 'c', 'cc']
 * 这样拆分不满足题目要求，因为其中的 'a' 和 'b' 都出现了不止一次。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "aba"
 * 输出：2
 * 解释：一种最大拆分方法为 ['a', 'ba'] 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "aa"
 * 输出：1
 * 解释：无法进一步拆分字符串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 1 <= s.length <= 16
 * 
 * 
 * s 仅包含小写英文字母
 * 
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
    int maxSplit;
    void dfs(int index, int split, string& s, unordered_set<string>& us) {
        int length = s.size();
        if (index >= length) {
            maxSplit = max(maxSplit, split);
            return;
        }

        for (int i = index; i < length; i++) {
            string substr = s.substr(index, i - index + 1);
            if (us.find(substr) == us.end()) {
                us.insert(substr);
                dfs(i + 1, split + 1, s, us);
                us.erase(substr);
            }
        }
    }
    int maxUniqueSplit(string s) {
        maxSplit = 1;
        unordered_set<string> us;
        dfs(0, 0, s, us);
        return maxSplit;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ababccc"\n
// @lcpr case=end

// @lcpr case=start
// "aba"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n
// @lcpr case=end

 */

