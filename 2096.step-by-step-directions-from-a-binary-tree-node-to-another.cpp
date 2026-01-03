/*
 * @lc app=leetcode.cn id=2096 lang=cpp
 * @lcpr version=30204
 *
 * [2096] 从二叉树一个节点到另一个节点每一步的方向
 *
 * https://leetcode.cn/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/
 *
 * algorithms
 * Medium (48.76%)
 * Likes:    118
 * Dislikes: 0
 * Total Accepted:    14.3K
 * Total Submissions: 29.2K
 * Testcase Example:  '[5,1,2,3,null,6,4]\n3\n6'
 *
 * 给你一棵 二叉树 的根节点 root ，这棵二叉树总共有 n 个节点。每个节点的值为 1 到 n 中的一个整数，且互不相同。给你一个整数
 * startValue ，表示起点节点 s 的值，和另一个不同的整数 destValue ，表示终点节点 t 的值。
 * 
 * 请找到从节点 s 到节点 t 的 最短路径 ，并以字符串的形式返回每一步的方向。每一步用 大写 字母 'L' ，'R' 和 'U'
 * 分别表示一种方向：
 * 
 * 
 * 'L' 表示从一个节点前往它的 左孩子 节点。
 * 'R' 表示从一个节点前往它的 右孩子 节点。
 * 'U' 表示从一个节点前往它的 父 节点。
 * 
 * 
 * 请你返回从 s 到 t 最短路径 每一步的方向。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
 * 输出："UURL"
 * 解释：最短路径为：3 → 1 → 5 → 2 → 6 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：root = [2,1], startValue = 2, destValue = 1
 * 输出："L"
 * 解释：最短路径为：2 → 1 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目为 n 。
 * 2 <= n <= 10^5
 * 1 <= Node.val <= n
 * 树中所有节点的值 互不相同 。
 * 1 <= startValue, destValue <= n
 * startValue != destValue
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path;
        function<bool(TreeNode*, int)> dfs = [&](TreeNode* node, int target) {
            if (node == nullptr) return false;

            if (node->val == target) return true;

            path += 'L';
            if (dfs(node->left, target)) return true;

            path.back() = 'R';
            if (dfs(node->right, target)) return true;

            path.pop_back();
            return false;
        };

        dfs(root, startValue);
        string path_to_start = path;

        path.clear();

        dfs(root, destValue);
        string path_to_dest = move(path);
        
        int i = 0;
        while (i < min(path_to_start.size(), path_to_dest.size()) && path_to_start[i] == path_to_dest[i]) {
            i++;
        }
        return string (path_to_start.size() - i, 'U') + path_to_dest.substr(i);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,1,2,3,null,6,4]\n3\n6\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n1\n
// @lcpr case=end

 */

