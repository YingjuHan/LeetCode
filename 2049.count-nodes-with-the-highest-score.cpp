/*
 * @lc app=leetcode.cn id=2049 lang=cpp
 * @lcpr version=30204
 *
 * [2049] 统计最高分的节点数目
 *
 * https://leetcode.cn/problems/count-nodes-with-the-highest-score/description/
 *
 * algorithms
 * Medium (51.85%)
 * Likes:    171
 * Dislikes: 0
 * Total Accepted:    30.4K
 * Total Submissions: 58.6K
 * Testcase Example:  '[-1,2,0,2,0]'
 *
 * 给你一棵根节点为 0 的 二叉树 ，它总共有 n 个节点，节点编号为 0 到 n - 1 。同时给你一个下标从 0 开始的整数数组 parents
 * 表示这棵树，其中 parents[i] 是节点 i 的父节点。由于节点 0 是根，所以 parents[0] == -1 。
 * 
 * 一个子树的 大小 为这个子树内节点的数目。每个节点都有一个与之关联的 分数 。求出某个节点分数的方法是，将这个节点和与它相连的边全部 删除
 * ，剩余部分是若干个 非空 子树，这个节点的 分数 为所有这些子树 大小的乘积 。
 * 
 * 请你返回有 最高得分 节点的 数目 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 输入：parents = [-1,2,0,2,0]
 * 输出：3
 * 解释：
 * - 节点 0 的分数为：3 * 1 = 3
 * - 节点 1 的分数为：4 = 4
 * - 节点 2 的分数为：1 * 1 * 2 = 2
 * - 节点 3 的分数为：4 = 4
 * - 节点 4 的分数为：4 = 4
 * 最高得分为 4 ，有三个节点得分为 4 （分别是节点 1，3 和 4 ）。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：parents = [-1,2,0]
 * 输出：2
 * 解释：
 * - 节点 0 的分数为：2 = 2
 * - 节点 1 的分数为：2 = 2
 * - 节点 2 的分数为：1 * 1 = 1
 * 最高分数为 2 ，有两个节点分数为 2 （分别为节点 0 和 1 ）。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == parents.length
 * 2 <= n <= 10^5
 * parents[0] == -1
 * 对于 i != 0 ，有 0 <= parents[i] <= n - 1
 * parents 表示一棵二叉树。
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
    vector<vector<int>> tree;
    int n;
    long long best = 0;
    int res = 0;
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        tree.resize(n, vector<int>());
        for (int i = 1; i < n; i++) {
            tree[parents[i]].push_back(i);
        }
        nodes(0);
        return res;
    }

    /**
     * 返回节点i下所有节点数量,计算每个节点的得分
     */
    int nodes(int i) {
        long long score = 1;
        int cnt = 0;

        for (auto child : tree[i]) {
            // 计算每个子树的节点数量
            int branch = nodes(child);
            // 每个子树的节点数量为得分做出了贡献
            score *= branch;
            // 累计每个子树节点数量和
            cnt += branch;
        }

        if (i) score *= n - cnt - 1;

        if (score > best) {
            res = 1;
            best = score;
        } else if (score == best) {
            res++;
        }
        return cnt + 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,2,0,2,0]\n
// @lcpr case=end

// @lcpr case=start
// [-1,2,0]\n
// @lcpr case=end

 */

