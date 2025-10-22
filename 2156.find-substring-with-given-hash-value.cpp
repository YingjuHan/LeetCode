/*
 * @lc app=leetcode.cn id=2156 lang=cpp
 * @lcpr version=30204
 *
 * [2156] 查找给定哈希值的子串
 *
 * https://leetcode.cn/problems/find-substring-with-given-hash-value/description/
 *
 * algorithms
 * Hard (30.03%)
 * Likes:    79
 * Dislikes: 0
 * Total Accepted:    11.7K
 * Total Submissions: 38.8K
 * Testcase Example:  '"leetcode"\n7\n20\n2\n0'
 *
 * 给定整数 p 和 m ，一个长度为 k 且下标从 0 开始的字符串 s 的哈希值按照如下函数计算：
 * 
 * 
 * hash(s, p, m) = (val(s[0]) * p^0 + val(s[1]) * p^1 + ... + val(s[k-1]) *
 * p^k-1) mod m.
 * 
 * 
 * 其中 val(s[i]) 表示 s[i] 在字母表中的下标，从 val('a') = 1 到 val('z') = 26 。
 * 
 * 给你一个字符串 s 和整数 power，modulo，k 和 hashValue 。请你返回 s 中 第一个 长度为 k 的 子串 sub ，满足
 * hash(sub, power, modulo) == hashValue 。
 * 
 * 测试数据保证一定 存在 至少一个这样的子串。
 * 
 * 子串 定义为一个字符串中连续非空字符组成的序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "leetcode", power = 7, modulo = 20, k = 2, hashValue = 0
 * 输出："ee"
 * 解释："ee" 的哈希值为 hash("ee", 7, 20) = (5 * 1 + 5 * 7) mod 20 = 40 mod 20 = 0 。
 * "ee" 是长度为 2 的第一个哈希值为 0 的子串，所以我们返回 "ee" 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "fbxzaad", power = 31, modulo = 100, k = 3, hashValue = 32
 * 输出："fbx"
 * 解释："fbx" 的哈希值为 hash("fbx", 31, 100) = (6 * 1 + 2 * 31 + 24 * 31^2) mod 100 =
 * 23132 mod 100 = 32 。
 * "bxz" 的哈希值为 hash("bxz", 31, 100) = (2 * 1 + 24 * 31 + 26 * 31^2) mod 100 =
 * 25732 mod 100 = 32 。
 * "fbx" 是长度为 3 的第一个哈希值为 32 的子串，所以我们返回 "fbx" 。
 * 注意，"bxz" 的哈希值也为 32 ，但是它在字符串中比 "fbx" 更晚出现。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= k <= s.length <= 2 * 10^4
 * 1 <= power, modulo <= 10^9
 * 0 <= hashValue < modulo
 * s 只包含小写英文字母。
 * 测试数据保证一定 存在 满足条件的子串。
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
    string subStrHash(string s, int power, int mod, int k, int hashValue) {
        int n = s.length();

        // 秦九韶算法计算s[n-k:]的哈希值，同时计算pk=power^k
        long long hash = 0, pk = 1;
        for (int i = n - 1; i >= n - k; i--) {
            hash = (hash * power + (s[i] & 31)) % mod;
            pk = pk * power % mod;
        }
        int res = hash == hashValue ? n - k : 0;
        
        // 向左滑窗
        for (int i = n - k - 1; i >= 0; i--) {
            hash = (hash * power + (s[i] & 31) - pk * (s[i + k] & 31) % mod + mod) % mod;
            if (hash == hashValue) {
                res = i;
            }
        }
        return s.substr(res, k);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "leetcode"\n7\n20\n2\n0\n
// @lcpr case=end

// @lcpr case=start
// "fbxzaad"\n31\n100\n3\n32\n
// @lcpr case=end

 */

