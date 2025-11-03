/*
 * @lc app=leetcode.cn id=3267 lang=cpp
 * @lcpr version=30204
 *
 * [3267] 统计近似相等数对 II
 *
 * https://leetcode.cn/problems/count-almost-equal-pairs-ii/description/
 *
 * algorithms
 * Hard (41.17%)
 * Likes:    10
 * Dislikes: 0
 * Total Accepted:    3K
 * Total Submissions: 7.4K
 * Testcase Example:  '[1023,2310,2130,213]'
 *
 * 注意：在这个问题中，操作次数增加为至多 两次 。
 * 
 * 给你一个正整数数组 nums 。
 * 
 * 如果我们执行以下操作 至多两次 可以让两个整数 x 和 y 相等，那么我们称这个数对是 近似相等 的：
 * 
 * 
 * 选择 x 或者 y  之一，将这个数字中的两个数位交换。
 * 
 * 
 * 请你返回 nums 中，下标 i 和 j 满足 i < j 且 nums[i] 和 nums[j] 近似相等 的数对数目。
 * 
 * 注意 ，执行操作后得到的整数可以有前导 0 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1023,2310,2130,213]
 * 
 * 输出：4
 * 
 * 解释：
 * 
 * 近似相等数对包括：
 * 
 * 
 * 1023 和 2310 。交换 1023 中数位 1 和 2 ，然后交换数位 0 和 3 ，得到 2310 。
 * 1023 和 213 。交换 1023 中数位 1 和 0 ，然后交换数位 1 和 2 ，得到 0213 ，也就是 213 。
 * 2310 和 213 。交换 2310 中数位 2 和 0 ，然后交换数位 3 和 2 ，得到 0213 ，也就是 213 。
 * 2310 和 2130 。交换 2310 中数位 3 和 1 ，得到 2130 。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,10,100]
 * 
 * 输出：3
 * 
 * 解释：
 * 
 * 近似相等数对包括：
 * 
 * 
 * 1 和 10 。交换 10 中数位 1 和 0 ，得到 01 ，也就是 1 。
 * 1 和 100 。交换 100 中数位 1 和从左往右的第二个 0 ，得到 001 ，也就是 1 。
 * 10 和 100 。交换 100 中数位 1 和从左往右的第一个 0 ，得到 010 ，也就是 10 。
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= nums.length <= 5000
 * 1 <= nums[i] < 10^7
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
    /**
     * 核心思想：枚举右（nums[j]），维护左（nums[i]）
     * 枚举j, 并暴力交换nums[j]数位，设交换后的数字为x，统计左边右多少个nums[i]等于x
     * 用一个哈希集合记录交换后的数字，再去遍历哈希集合中的元素 x，统计左边有多少个 nums[i] 等于 x
     * 如果 100 这样的数在左边，我们枚举的 1 这样的数在右边，就没法找到近似相等的数对。
     * 把 nums 按照数字长度从小到大排序（也就是元素值从小到大排序），即可解决此问题。
     * 
     * 
     */
    int countPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            // 转换为字符串（负数的负号会被计入长度，如 -99 长度为 3，需去负号则加 abs()）
            string s1 = to_string(abs(a));  // abs(a) 去除负号影响（按需选择）
            string s2 = to_string(abs(b));
            if (s1.size() != s2.size()) {
                return s1.size() < s2.size();  // 长度不同：短的在前
            } else {
                return a < b;  // 长度相同：按数值升序（可选，也可保留原顺序）
        }
        });
        int res = 0;
        unordered_map<int, int> cnt;
        for (int x : nums) {
            unordered_set<int> st = {x}; // 第一个元素是不交换
            string s = to_string(x);
            int m = s.length();
            for (int i = 0; i < m; i++) {
                for (int j = i + 1; j < m; j++) {
                    swap(s[i], s[j]); // 交换ij
                    st.insert(stoi(s)); // 交换一次
                    for (int p = i + 1; p < m; p++) {
                        for (int q = p + 1; q < m; q++) {
                            swap(s[p], s[q]); // 交换pq
                            st.insert(stoi(s)); // 交换两次
                            swap(s[p], s[q]); // 复原pq
                        }
                    }
                    swap(s[i], s[j]); // 复原ij
                }
            }
            for (int v : st) {
                res += cnt.count(v) > 0 ? cnt[v] : 0;
            }
            cnt[x]++;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1023,2310,2130,213]\n
// @lcpr case=end

// @lcpr case=start
// [1,10,100]\n
// @lcpr case=end

 */

