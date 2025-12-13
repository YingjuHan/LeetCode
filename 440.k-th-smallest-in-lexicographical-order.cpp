/*
 * @lc app=leetcode.cn id=440 lang=cpp
 * @lcpr version=30204
 *
 * [440] 字典序的第K小数字
 *
 * https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/description/
 *
 * algorithms
 * Hard (42.95%)
 * Likes:    650
 * Dislikes: 0
 * Total Accepted:    65.8K
 * Total Submissions: 153.1K
 * Testcase Example:  '13\n2'
 *
 * 给定整数 n 和 k，返回  [1, n] 中字典序第 k 小的数字。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: n = 13, k = 2
 * 输出: 10
 * 解释: 字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，所以第二小的数字是 10。
 * 
 * 
 * 示例 2:
 * 
 * 输入: n = 1, k = 1
 * 输出: 1
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= k <= n <= 10^9
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
    int findKthNumber(int n, int k) { 
        auto count_subtree_size = [&](int node) {
            int size = 0;
            long long left = node, right = node + 1;
            while (left <= n) {
                size += min(right, n + 1LL) - left;
                left *= 10;
                right *= 10;
            }
            return size;
        };
        int node = 1;
        k--; // 访问节点 node
        while (k > 0) {
            int size = count_subtree_size(node);
            if (size <= k) { // 向右，跳过 node 子树
                node++; // 访问 node 右侧兄弟节点
                k -= size; // 访问子树中的每个节点，以及新的 node 节点
            } else { // 向下，深入 node 子树
                node *= 10; // 访问 node 的第一个儿子
                k--; // 访问新的 node 节点
            }
        }
        return node;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 13\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */

