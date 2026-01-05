/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 * @lcpr version=30204
 *
 * [1305] 两棵二叉搜索树中的所有元素
 *
 * https://leetcode.cn/problems/all-elements-in-two-binary-search-trees/description/
 *
 * algorithms
 * Medium (78.15%)
 * Likes:    192
 * Dislikes: 0
 * Total Accepted:    56.6K
 * Total Submissions: 72.4K
 * Testcase Example:  '[2,1,4]\n[1,0,3]'
 *
 * 给你 root1 和 root2 这两棵二叉搜索树。请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。.
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：root1 = [2,1,4], root2 = [1,0,3]
 * 输出：[0,1,1,2,3,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：root1 = [1,null,8], root2 = [8,1]
 * 输出：[1,1,8,8]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每棵树的节点数在 [0, 5000] 范围内
 * -10^5 <= Node.val <= 10^5
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
    void inorder(TreeNode* node, vector<int>& res) {
        if (node == nullptr) return;
        inorder(node->left, res);
        res.push_back(node->val);
        inorder(node->right, res);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> nums1, nums2;
        inorder(root1, nums1);
        inorder(root2, nums2);

        vector<int> res;
        auto p1 = nums1.begin(), p2 = nums2.begin();
        while (true) {
            if (p1 == nums1.end()) {
                res.insert(res.end(), p2, nums2.end());
                break;
            }
            if (p2 == nums2.end()) {
                res.insert(res.end(), p1, nums1.end());
                break;
            }
            if (*p1 < *p2) {
                res.push_back(*p1++);
            } else {
                res.push_back(*p2++);
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,4]\n[1,0,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,8]\n[8,1]\n
// @lcpr case=end

 */

