/*
 * @lc app=leetcode.cn id=1707 lang=cpp
 * @lcpr version=30204
 *
 * [1707] 与数组中元素的最大异或值
 *
 * https://leetcode.cn/problems/maximum-xor-with-an-element-from-array/description/
 *
 * algorithms
 * Hard (51.43%)
 * Likes:    157
 * Dislikes: 0
 * Total Accepted:    18.5K
 * Total Submissions: 35.9K
 * Testcase Example:  '[0,1,2,3,4]\n[[3,1],[1,3],[5,6]]'
 *
 * 给你一个由非负整数组成的数组 nums 。另有一个查询数组 queries ，其中 queries[i] = [xi, mi] 。
 * 
 * 第 i 个查询的答案是 xi 和任何 nums 数组中不超过 mi 的元素按位异或（XOR）得到的最大值。换句话说，答案是 max(nums[j]
 * XOR xi) ，其中所有 j 均满足 nums[j] <= mi 。如果 nums 中的所有元素都大于 mi，最终答案就是 -1 。
 * 
 * 返回一个整数数组 answer 作为查询的答案，其中 answer.length == queries.length 且 answer[i] 是第 i
 * 个查询的答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
 * 输出：[3,3,7]
 * 解释：
 * 1) 0 和 1 是仅有的两个不超过 1 的整数。0 XOR 3 = 3 而 1 XOR 3 = 2 。二者中的更大值是 3 。
 * 2) 1 XOR 2 = 3.
 * 3) 5 XOR 2 = 7.
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
 * 输出：[15,-1,5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length, queries.length <= 10^5
 * queries[i].length == 2
 * 0 <= nums[j], xi, mi <= 10^9
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
class Trie {
private:
    const int L = 30;
    Trie *next[2] = {nullptr};
public:
    Trie(){}

    ~Trie() {
        delete this->next[0];
        delete this->next[1];
    }

    void insert(int num) {
        Trie *root = this;
        // 2^30 = 1,073,741,824 > 1e9
        for(int i = L-1; i >= 0; i--) {
            int val = (num >> i) & 1;
            if(root->next[val] == nullptr)
                root->next[val] = new Trie();
            root = root->next[val];
        }
    }

    int getMaxXor(int num) {
        Trie *root = this;
        int ans = 0;
        for(int i = L-1; i >= 0; i--) {
            int val = (num >> i) & 1;
            if(root->next[1-val] != nullptr) {
                ans |= 1 << i;
                val = 1-val;
            }
            root = root->next[val];
        }
        return ans;
    }

};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < queries.size(); i++)
            queries[i].push_back(i);
        sort(queries.begin(), queries.end(), [](const auto &query1, const auto &query2) {
            return query1[1] < query2[1];
        });

        vector<int> ans(queries.size());
        Trie *t = new Trie();
        int idx = 0, n = nums.size();
        for(auto &q : queries) {
            int x = q[0], limit = q[1], qid = q[2];
            while(idx < n && nums[idx] <= limit)
                t->insert(nums[idx++]);
            if(idx == 0)
                ans[qid] = -1;
            else
                ans[qid] = t->getMaxXor(x);
        }
        return ans;
    }
};

// @lc code=end



/*
// @lcpr case=start
// [0,1,2,3,4]\n[[3,1],[1,3],[5,6]]\n
// @lcpr case=end

// @lcpr case=start
// [5,2,4,6,6,3]\n[[12,4],[8,1],[6,3]]\n
// @lcpr case=end

 */

