/*
 * @lc app=leetcode.cn id=2707 lang=cpp
 * @lcpr version=30204
 *
 * [2707] 字符串中的额外字符
 *
 * https://leetcode.cn/problems/extra-characters-in-a-string/description/
 *
 * algorithms
 * Medium (65.13%)
 * Likes:    126
 * Dislikes: 0
 * Total Accepted:    26.1K
 * Total Submissions: 40.1K
 * Testcase Example:  '"leetscode"\n["leet","code","leetcode"]'
 *
 * 给你一个下标从 0 开始的字符串 s 和一个单词字典 dictionary 。你需要将 s 分割成若干个 互不重叠 的子字符串，每个子字符串都在
 * dictionary 中出现过。s 中可能会有一些 额外的字符 不在任何子字符串中。
 * 
 * 请你采取最优策略分割 s ，使剩下的字符 最少 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "leetscode", dictionary = ["leet","code","leetcode"]
 * 输出：1
 * 解释：将 s 分成两个子字符串：下标从 0 到 3 的 "leet" 和下标从 5 到 8 的 "code" 。只有 1 个字符没有使用（下标为
 * 4），所以我们返回 1 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "sayhelloworld", dictionary = ["hello","world"]
 * 输出：3
 * 解释：将 s 分成两个子字符串：下标从 3 到 7 的 "hello" 和下标从 8 到 12 的 "world" 。下标为 0 ，1 和 2
 * 的字符没有使用，所以我们返回 3 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 50
 * 1 <= dictionary.length <= 50
 * 1 <= dictionary[i].length <= 50
 * dictionary[i] 和 s 只包含小写英文字母。
 * dictionary 中的单词互不相同。
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
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st;
        for (string& word : dictionary) {
            st.insert(word);
        }
        int n = s.length();

        vector<int> memo(n, -1);

        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i < 0) {
                return 0;
            }
            int &res = memo[i];
            if (res != -1) {
                return res;
            }
            res = dfs(i - 1) + 1;
            for (int j = 0; j < i + 1; j++) {
                if(st.count(s.substr(j, i - j + 1))){
                    res = min(res, dfs(j - 1));
                }
            }
            return res;
        };
        return dfs(n - 1);

    }
};
// @lc code=end



/*
// @lcpr case=start
// "leetscode"\n["leet","code","leetcode"]\n
// @lcpr case=end

// @lcpr case=start
// "sayhelloworld"\n["hello","world"]\n
// @lcpr case=end

 */

