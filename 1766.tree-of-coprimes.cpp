/*
 * @lc app=leetcode.cn id=1766 lang=cpp
 * @lcpr version=30204
 *
 * [1766] 互质树
 *
 * https://leetcode.cn/problems/tree-of-coprimes/description/
 *
 * algorithms
 * Hard (50.86%)
 * Likes:    73
 * Dislikes: 0
 * Total Accepted:    14.2K
 * Total Submissions: 27.9K
 * Testcase Example:  '[2,3,3,2]\n[[0,1],[1,2],[1,3]]'
 *
 * 给你一个 n 个节点的树（也就是一个无环连通无向图），节点编号从 0 到 n - 1 ，且恰好有 n - 1 条边，每个节点有一个值。树的 根节点 为
 * 0 号点。
 * 
 * 给你一个整数数组 nums 和一个二维数组 edges 来表示这棵树。nums[i] 表示第 i 个点的值，edges[j] = [uj, vj]
 * 表示节点 uj 和节点 vj 在树中有一条边。
 * 
 * 当 gcd(x, y) == 1 ，我们称两个数 x 和 y 是 互质的 ，其中 gcd(x, y) 是 x 和 y 的 最大公约数 。
 * 
 * 从节点 i 到 根 最短路径上的点都是节点 i 的祖先节点。一个节点 不是 它自己的祖先节点。
 * 
 * 请你返回一个大小为 n 的数组 ans ，其中 ans[i]是离节点 i 最近的祖先节点且满足 nums[i] 和 nums[ans[i]] 是 互质的
 * ，如果不存在这样的祖先节点，ans[i] 为 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：nums = [2,3,3,2], edges = [[0,1],[1,2],[1,3]]
 * 输出：[-1,0,0,1]
 * 解释：上图中，每个节点的值在括号中表示。
 * - 节点 0 没有互质祖先。
 * - 节点 1 只有一个祖先节点 0 。它们的值是互质的（gcd(2,3) == 1）。
 * - 节点 2 有两个祖先节点，分别是节点 1 和节点 0 。节点 1 的值与它的值不是互质的（gcd(3,3) == 3）但节点 0
 * 的值是互质的(gcd(2,3) == 1)，所以节点 0 是最近的符合要求的祖先节点。
 * - 节点 3 有两个祖先节点，分别是节点 1 和节点 0 。它与节点 1 互质（gcd(3,2) == 1），所以节点 1
 * 是离它最近的符合要求的祖先节点。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：nums = [5,6,10,2,3,6,15], edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
 * 输出：[-1,0,-1,0,0,0,-1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums.length == n
 * 1 <= nums[i] <= 50
 * 1 <= n <= 10^5
 * edges.length == n - 1
 * edges[j].length == 2
 * 0 <= uj, vj < n
 * uj != vj
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
const int MX = 51;
vector<int> coprime[MX];

auto init = [] {
    // 预处理：coprime[i] 保存 [1, MX) 中与 i 互质的所有元素
    for (int i = 1; i < MX; i++) {
        for (int j = 1; j < MX; j++) {
            if (gcd(i, j) == 1) {
                coprime[i].push_back(j);
            }
        }
    }
    return 0;
}();

class Solution {
public:
    vector<vector<int>> g;
    vector<int> ans;
    pair<int, int> val_depth_id[MX];
    void dfs (int x, int fa, int depth, vector<int>& nums) {
        int val = nums[x];
        int max_depth = 0;
        for (int j : coprime[val]) {
            auto [depth, id] = val_depth_id[j];
            if (depth > max_depth) {
                max_depth = depth;
                ans[x] = id;
            }
        }

        auto tmp = val_depth_id[val];
        val_depth_id[val] = {depth, x};
        for (int y : g[x]) {
            if (y != fa) {
                dfs(y, x, depth + 1, nums);
            }
        }
        val_depth_id[val] = tmp;
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        g.resize(n);
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        ans.resize(n, -1);
        dfs(0, -1, 1, nums);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,3,2]\n[[0,1],[1,2],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// [5,6,10,2,3,6,15]\n[[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]\n
// @lcpr case=end

 */

