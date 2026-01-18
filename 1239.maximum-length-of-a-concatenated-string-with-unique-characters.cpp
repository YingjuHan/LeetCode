/*
 * @lc app=leetcode.cn id=1239 lang=cpp
 * @lcpr version=30204
 *
 * [1239] 串联字符串的最大长度
 *
 * https://leetcode.cn/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/
 *
 * algorithms
 * Medium (49.65%)
 * Likes:    255
 * Dislikes: 0
 * Total Accepted:    48.5K
 * Total Submissions: 97.7K
 * Testcase Example:  '["un","iq","ue"]'
 *
 * 给定一个字符串数组 arr，字符串 s 是将 arr 的含有 不同字母 的 子序列 字符串 连接 所得的字符串。
 * 
 * 请返回所有可行解 s 中最长长度。
 * 
 * 子序列 是一种可以从另一个数组派生而来的数组，通过删除某些元素或不删除元素而不改变其余元素的顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = ["un","iq","ue"]
 * 输出：4
 * 解释：所有可能的串联组合是：
 * - ""
 * - "un"
 * - "iq"
 * - "ue"
 * - "uniq" ("un" + "iq")
 * - "ique" ("iq" + "ue")
 * 最大长度为 4。
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = ["cha","r","act","ers"]
 * 输出：6
 * 解释：可能的解答有 "chaers" 和 "acters"。
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = ["abcdefghijklmnopqrstuvwxyz"]
 * 输出：26
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 16
 * 1 <= arr[i].length <= 26
 * arr[i] 中只含有小写英文字母
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
    int finalMax = 0;
    vector<string> chosen;

    bool isAlphaSame(string& a, string& b) {
        for (char c1 : a) {
            for (char c2 : b) {
                if (c1 == c2) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isSameSelf(string& s) {
        for (char c : s) {
            if (count(s.begin(), s.end(), c) > 1) {
                return false;
            }
        }
        return true;
    }

    void dfs(vector<string>& arr, int i) {
        int tempMax = 0;
        for (int j = 0; j < chosen.size(); j++) {
            tempMax += chosen[j].length();
        }
        finalMax = max(finalMax, tempMax);

        if (i == arr.size()) {
            return;
        }

        dfs(arr, i + 1);

        // 当前字符串arr[i]自身无重复字符（isSameself(arr[i])返回true）；
        // 当前字符串与chosen中已选的所有字符串无重复字符（遍历chosen，调用isAlphasame验证）。
        if (isSameSelf(arr[i])) {
            for (int j = 0; j < chosen.size(); j++) {
                if (!isAlphaSame(chosen[j], arr[i])) {
                    return;
                }
            }
            chosen.push_back(arr[i]);
            dfs(arr, i + 1);
            chosen.pop_back();
        }
    }

    int maxLength(vector<string>& arr) {
        dfs(arr, 0);
        return finalMax;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["un","iq","ue"]\n
// @lcpr case=end

// @lcpr case=start
// ["cha","r","act","ers"]\n
// @lcpr case=end

// @lcpr case=start
// ["abcdefghijklmnopqrstuvwxyz"]\n
// @lcpr case=end

 */

