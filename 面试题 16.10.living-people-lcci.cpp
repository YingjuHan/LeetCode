/*
 * @lc app=leetcode.cn id=面试题 16.10 lang=cpp
 * @lcpr version=
 *
 * [面试题 16.10] 生存人数
 *
 * https://leetcode.cn/problems/living-people-lcci/description/
 *
 * LCCI
 * Medium (66.35%)
 * Likes:    73
 * Dislikes: 0
 * Total Accepted:    20.8K
 * Total Submissions: 31.3K
 * Testcase Example:  '[1900,1901,1950]\n[1948,1951,2000]'
 *
 * 给定 N 个人的出生年份和死亡年份，第 i 个人的出生年份为 birth[i]，死亡年份为 death[i]，实现一个方法以计算生存人数最多的年份。
 * 
 * 你可以假设所有人都出生于 1900 年至 2000 年（含 1900 和 2000
 * ）之间。如果一个人在某一年的任意时期处于生存状态，那么他应该被纳入那一年的统计中。例如，生于 1908 年、死于 1909 年的人应当被列入 1908
 * 年和 1909 年的计数。
 * 
 * 如果有多个年份生存人数相同且均为最大值，输出其中最小的年份。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：
 * birth = [1900, 1901, 1950]
 * death = [1948, 1951, 2000]
 * 输出： 1901
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 < birth.length == death.length <= 10000
 * birth[i] <= death[i]
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
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        int start = 1900, end = 2000;
        vector<int> diff(end - start + 2);
        for (int i = 0; i < birth.size(); i++) {
            diff[birth[i] - start]++;
            diff[death[i] - start + 1]--;
        }
        int mx = 0, curr = 0, res = 0;
        for (int i = 0; i < end - start + 1; i++) {
            curr += diff[i];
            if (curr > mx) {
                mx = curr;
                res = i;
            }
        }
        return res + start;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1900, 1901\n[1948, 1951, 2000]\n
// @lcpr case=end

 */

