 /*
 * @lc app=leetcode.cn id=3493 lang=cpp
 * @lcpr version=30204
 *
 * [3493] 属性图
 *
 * https://leetcode.cn/problems/properties-graph/description/
 *
 * algorithms
 * Medium (53.20%)
 * Likes:    14
 * Dislikes: 0
 * Total Accepted:    5.2K
 * Total Submissions: 9.7K
 * Testcase Example:  '[[1,2],[1,1],[3,4],[4,5],[5,6],[7,7]]\n1'
 *
 * 给你一个二维整数数组 properties，其维度为 n x m，以及一个整数 k。
 * 
 * 定义一个函数 intersect(a, b)，它返回数组 a 和 b 中 共有的不同整数的数量 。
 * 
 * 构造一个 无向图，其中每个索引 i 对应 properties[i]。如果且仅当 intersect(properties[i],
 * properties[j]) >= k（其中 i 和 j 的范围为 [0, n - 1] 且 i != j），节点 i 和节点 j 之间有一条边。
 * 
 * 返回结果图中 连通分量 的数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： properties = [[1,2],[1,1],[3,4],[4,5],[5,6],[7,7]], k = 1
 * 
 * 输出： 3
 * 
 * 解释：
 * 
 * 生成的图有 3 个连通分量：
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： properties = [[1,2,3],[2,3,4],[4,3,5]], k = 2
 * 
 * 输出： 1
 * 
 * 解释：
 * 
 * 生成的图有 1 个连通分量：
 * 
 * 
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入： properties = [[1,1],[1,1]], k = 2
 * 
 * 输出： 2
 * 
 * 解释：
 * 
 * intersect(properties[0], properties[1]) = 1，小于 k。因此在图中 properties[0] 和
 * properties[1] 之间没有边。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n == properties.length <= 100
 * 1 <= m == properties[i].length <= 100
 * 1 <= properties[i][j] <= 100
 * 1 <= k <= m
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
class UnionFind {
    vector<int> fa;

public:
    int cc;

    UnionFind(int n) : fa(n), cc(n) {
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }

    int find(int x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }

    void merge(int from, int to) {
        int x = find(from), y = find(to);
        if (x == y) {
            return;
        }
        fa[x] = y;
        cc--;
    }
};

class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        vector<unordered_set<int>> sets(n);
        for (int i = 0; i < n; i++) {
            sets[i] = unordered_set(properties[i].begin(), properties[i].end());
        }

        UnionFind uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int cnt = 0;
                for (int x : sets[j]) {
                    if (sets[i].contains(x)) {
                        cnt++;
                    }
                }
                if (cnt >= k) {
                    uf.merge(i, j);
                }
            }
        } 
        return uf.cc;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[1,1],[3,4],[4,5],[5,6],[7,7]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[2,3,4],[4,3,5]]\n2\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[1,1]]\n2\n
// @lcpr case=end

 */

