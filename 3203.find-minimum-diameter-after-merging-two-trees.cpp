/*
 * @lc app=leetcode.cn id=3203 lang=cpp
 * @lcpr version=30204
 *
 * [3203] 合并两棵树后的最小直径
 *
 * https://leetcode.cn/problems/find-minimum-diameter-after-merging-two-trees/description/
 *
 * algorithms
 * Hard (36.49%)
 * Likes:    26
 * Dislikes: 0
 * Total Accepted:    4.9K
 * Total Submissions: 13.5K
 * Testcase Example:  '[[0,1],[0,2],[0,3]]\n[[0,1]]'
 *
 * 给你两棵 无向 树，分别有 n 和 m 个节点，节点编号分别为 0 到 n - 1 和 0 到 m - 1 。给你两个二维整数数组 edges1 和
 * edges2 ，长度分别为 n - 1 和 m - 1 ，其中 edges1[i] = [ai, bi] 表示在第一棵树中节点 ai 和 bi
 * 之间有一条边，edges2[i] = [ui, vi] 表示在第二棵树中节点 ui 和 vi 之间有一条边。
 * 
 * 你必须在第一棵树和第二棵树中分别选一个节点，并用一条边连接它们。
 * 
 * 请你返回添加边后得到的树中，最小直径 为多少。
 * 
 * 一棵树的 直径 指的是树中任意两个节点之间的最长路径长度。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：edges1 = [[0,1],[0,2],[0,3]], edges2 = [[0,1]]
 * 
 * 输出：3
 * 
 * 解释：
 * 
 * 将第一棵树中的节点 0 与第二棵树中的任意节点连接，得到一棵直径为 3 的树。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：edges1 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]], edges2 =
 * [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]
 * 
 * 输出：5
 * 
 * 解释：
 * 
 * 将第一棵树中的节点 0 和第二棵树中的节点 0 连接，可以得到一棵直径为 5 的树。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n, m <= 10^5
 * edges1.length == n - 1
 * edges2.length == m - 1
 * edges1[i].length == edges2[i].length == 2
 * edges1[i] = [ai, bi]
 * 0 <= ai, bi < n
 * edges2[i] = [ui, vi]
 * 0 <= ui, vi < m
 * 输入保证 edges1 和 edges2 分别表示一棵合法的树。
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
    int diameter(vector<vector<int>>& edges) {
        vector<vector<int>> g(edges.size() + 1);
        for (auto& edge : edges) {
            int x = edge[0], y = edge[1];
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }

        int res = 0;
        function<int(int, int)> dfs = [&](int x, int fa) {
            int max_len = 0;
            for (int y : g[x]) {
                if (y != fa) {
                    int sub_len = dfs(y, x) + 1;
                    res = max(res, max_len + sub_len);
                    max_len = max(max_len, sub_len);
                }
            }
            return max_len;
        };
        dfs(0, -1);
        return res;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = diameter(edges1);
        int d2 = diameter(edges2);
        return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1],[0,2],[0,3]]\n[[0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]\n[[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]\n
// @lcpr case=end

 */

