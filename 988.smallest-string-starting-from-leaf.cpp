/*
 * @lc app=leetcode.cn id=988 lang=cpp
 * @lcpr version=30204
 *
 * [988] 从叶结点开始的最小字符串
 *
 * https://leetcode.cn/problems/smallest-string-starting-from-leaf/description/
 *
 * algorithms
 * Medium (55.15%)
 * Likes:    139
 * Dislikes: 0
 * Total Accepted:    26.3K
 * Total Submissions: 47.6K
 * Testcase Example:  '[0,1,2,3,4,3,4]'
 *
 * 给定一颗根结点为 root 的二叉树，树中的每一个结点都有一个 [0, 25] 范围内的值，分别代表字母 'a' 到 'z'。
 * 
 * 返回 按字典序最小 的字符串，该字符串从这棵树的一个叶结点开始，到根结点结束。
 * 
 * 
 * 注：字符串中任何较短的前缀在 字典序上 都是 较小 的：
 * 
 * 
 * 例如，在字典序上 "ab" 比 "aba" 要小。叶结点是指没有子结点的结点。 
 * 
 * 
 * 
 * 节点的叶节点是没有子节点的节点。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：root = [0,1,2,3,4,3,4]
 * 输出："dba"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：root = [25,1,3,1,3,0,2]
 * 输出："adz"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：root = [2,2,1,null,1,0,null,0]
 * 输出："abc"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定树的结点数在 [1, 8500] 范围内
 * 0 <= Node.val <= 25
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    string minPath = "";
    void cmpPath(TreeNode* root, string path) {
        if (!root) return;
        path = char(root->val + 'a') + path;
        if (!root->left && !root->right) {
            if (minPath.empty() || minPath > path) {
                minPath = path;
            }
        }
        cmpPath(root->left, path);
        cmpPath(root->right, path);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        if (!root) return "";
        cmpPath(root, "");
        return minPath;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,2,3,4,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [25,1,3,1,3,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,1,null,1,0,null,0]\n
// @lcpr case=end

 */

