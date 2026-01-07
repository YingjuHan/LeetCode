/*
 * @lc app=leetcode.cn id=2471 lang=cpp
 * @lcpr version=30204
 *
 * [2471] 逐层排序二叉树所需的最少操作数目
 *
 * https://leetcode.cn/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/
 *
 * algorithms
 * Medium (59.32%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    9.8K
 * Total Submissions: 16.4K
 * Testcase Example:  '[1,4,3,7,6,8,5,null,null,null,null,9,null,10]'
 *
 * 给你一个 值互不相同 的二叉树的根节点 root 。
 * 
 * 在一步操作中，你可以选择 同一层 上任意两个节点，交换这两个节点的值。
 * 
 * 返回每一层按 严格递增顺序 排序所需的最少操作数目。
 * 
 * 节点的 层数 是该节点和根节点之间的路径的边数。
 * 
 * 
 * 
 * 示例 1 ：
 * 
 * 输入：root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
 * 输出：3
 * 解释：
 * - 交换 4 和 3 。第 2 层变为 [3,4] 。
 * - 交换 7 和 5 。第 3 层变为 [5,6,8,7] 。
 * - 交换 8 和 7 。第 3 层变为 [5,6,7,8] 。
 * 共计用了 3 步操作，所以返回 3 。
 * 可以证明 3 是需要的最少操作数目。
 * 
 * 
 * 示例 2 ：
 * 
 * 输入：root = [1,3,2,7,6,5,4]
 * 输出：3
 * 解释：
 * - 交换 3 和 2 。第 2 层变为 [2,3] 。 
 * - 交换 7 和 4 。第 3 层变为 [4,6,5,7] 。 
 * - 交换 6 和 5 。第 3 层变为 [4,5,6,7] 。
 * 共计用了 3 步操作，所以返回 3 。 
 * 可以证明 3 是需要的最少操作数目。
 * 
 * 
 * 示例 3 ：
 * 
 * 输入：root = [1,2,3,4,5,6]
 * 输出：0
 * 解释：每一层已经按递增顺序排序，所以返回 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目在范围 [1, 10^5] 。
 * 1 <= Node.val <= 10^5
 * 树中的所有值 互不相同 。
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
    int getMinSwaps(vector<int>& nums) {
        vector<int> nums1(nums);
        sort(nums1.begin(), nums1.end());
        unordered_map<int, int> m;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            m[nums1[i]] = i;
        }

        int loops = 0;
        vector<bool> flag(len, false);
        for (int i = 0; i < len; i++) {
            if (!flag[i]) {
                int j = i;
                while (!flag[j]) {
                    flag[j] = true;
                    j = m[nums[j]];
                }
                loops++;
            }
        }
        return len - loops;
    }
    int minimumOperations(TreeNode* root) {
        if (root == nullptr) return 0;
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> vals;
            for (int n = q.size(); n--;) {
                auto node = q.front();
                q.pop();
                vals.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(vals);
        }
        int o = 0;
        for (auto& v : res) {\
            o += getMinSwaps(v);
        }
        return o;
    }

    
};
// @lc code=end



/*
// @lcpr case=start
// [1,4,3,7,6,8,5,null,null,null,null,9,null,10]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,7,6,5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6]\n
// @lcpr case=end

 */

