/*
 * @lc app=leetcode.cn id=1849 lang=cpp
 * @lcpr version=30204
 *
 * [1849] 将字符串拆分为递减的连续值
 *
 * https://leetcode.cn/problems/splitting-a-string-into-descending-consecutive-values/description/
 *
 * algorithms
 * Medium (34.81%)
 * Likes:    52
 * Dislikes: 0
 * Total Accepted:    10.6K
 * Total Submissions: 30.4K
 * Testcase Example:  '"1234"'
 *
 * 给你一个仅由数字组成的字符串 s 。
 * 
 * 请你判断能否将 s 拆分成两个或者多个 非空子字符串 ，使子字符串的 数值 按 降序 排列，且每两个 相邻子字符串 的数值之 差 等于 1
 * 。
 * 
 * 
 * 例如，字符串 s = "0090089" 可以拆分成 ["0090", "089"] ，数值为 [90,89] 。这些数值满足按降序排列，且相邻值相差
 * 1 ，这种拆分方法可行。
 * 另一个例子中，字符串 s = "001" 可以拆分成 ["0", "01"]、["00", "1"] 或 ["0", "0", "1"]
 * 。然而，所有这些拆分方法都不可行，因为对应数值分别是 [0,1]、[0,1] 和 [0,0,1] ，都不满足按降序排列的要求。
 * 
 * 
 * 如果可以按要求拆分 s ，返回 true ；否则，返回 false 。
 * 
 * 子字符串 是字符串中的一个连续字符序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "1234"
 * 输出：false
 * 解释：不存在拆分 s 的可行方法。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "050043"
 * 输出：true
 * 解释：s 可以拆分为 ["05", "004", "3"] ，对应数值为 [5,4,3] 。
 * 满足按降序排列，且相邻值相差 1 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "9080701"
 * 输出：false
 * 解释：不存在拆分 s 的可行方法。
 * 
 * 
 * 示例 4：
 * 
 * 输入：s = "10009998"
 * 输出：true
 * 解释：s 可以拆分为 ["100", "099", "98"] ，对应数值为 [100,99,98] 。
 * 满足按降序排列，且相邻值相差 1 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 20
 * s 仅由数字组成
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
    bool splitString(string s) {
        long long start = 0;
        long long INF = 1e10; // 子串对应数值的上限
        int n = s.size();
        // 枚举第一个子字符串对应的初始值
        // 第一个子字符串不能包含整个字符串
        for (int i = 0; i < n - 1 && start < INF; ++i){
            start = start * 10 + (s[i] - '0');
            // 循环验证当前的初始值是否符合要求
            long long pval = start;
            long long cval = 0;
            int cidx = i + 1;
            for (int j = i + 1; j < n && cval < INF; ++j){
                if (pval == 1){
                    // 如果上一个值为 1，那么剩余字符串对应的数值只能为 0
                    if (all_of(s.begin() + cidx, s.end(), [](char c){ return c == '0'; })){
                        return true;
                    }
                    else{
                        break;
                    }
                }
                cval = cval * 10 + (s[j] - '0');
                if (cval > pval - 1){
                    // 不符合要求，提前结束
                    break;
                }
                else if (cval == pval - 1){
                    if (j + 1 == n){
                        // 已经遍历到末尾
                        return true;
                    }
                    pval = cval;
                    cval = 0;
                    cidx = j + 1;
                }
            }
        }
        return false;
    }
};

// @lc code=end



/*
// @lcpr case=start
// "1234"\n
// @lcpr case=end

// @lcpr case=start
// "050043"\n
// @lcpr case=end

// @lcpr case=start
// "9080701"\n
// @lcpr case=end

// @lcpr case=start
// "10009998"\n
// @lcpr case=end

 */

