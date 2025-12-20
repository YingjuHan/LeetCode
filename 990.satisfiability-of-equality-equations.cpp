/*
 * @lc app=leetcode.cn id=990 lang=cpp
 * @lcpr version=30204
 *
 * [990] 等式方程的可满足性
 *
 * https://leetcode.cn/problems/satisfiability-of-equality-equations/description/
 *
 * algorithms
 * Medium (54.40%)
 * Likes:    354
 * Dislikes: 0
 * Total Accepted:    69.5K
 * Total Submissions: 127.8K
 * Testcase Example:  '["a==b","b!=a"]'
 *
 * 给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或
 * "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。
 * 
 * 只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。 
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：["a==b","b!=a"]
 * 输出：false
 * 解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。
 * 
 * 
 * 示例 2：
 * 
 * 输入：["b==a","a==b"]
 * 输出：true
 * 解释：我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。
 * 
 * 
 * 示例 3：
 * 
 * 输入：["a==b","b==c","a==c"]
 * 输出：true
 * 
 * 
 * 示例 4：
 * 
 * 输入：["a==b","b!=c","c==a"]
 * 输出：false
 * 
 * 
 * 示例 5：
 * 
 * 输入：["c==c","b==d","x!=z"]
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= equations.length <= 500
 * equations[i].length == 4
 * equations[i][0] 和 equations[i][3] 是小写字母
 * equations[i][1] 要么是 '='，要么是 '!'
 * equations[i][2] 是 '='
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
private:
    vector<int> parent;
public:
    UnionFind() {
        parent.resize(26);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
    }

    int Find(int index) {
        if (parent[index] != index) {
            parent[index] = Find(parent[index]);
        }
        return parent[index];
    }

    void Union(int index1, int index2) {
        parent[Find(index1)] = parent[Find(index2)];
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf;
        for (const string& str : equations) {
            if (str[1] == '=') {
                int index1 = str[0] - 'a';
                int index2 = str[3] - 'a';
                uf.Union(index1, index2);
            }
        }

        for (const string& str : equations) {
            if (str[1] == '!') {
                int index1 = str[0] - 'a';
                int index2 = str[3] - 'a';
                if (uf.Find(index1) == uf.Find(index2)) {
                    return false;
                }
            }
        }

        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// b"\na"]\n
// @lcpr case=end

// @lcpr case=start
// a"\nb"]\n
// @lcpr case=end

// @lcpr case=start
// b"\nc"\nc"]\n
// @lcpr case=end

// @lcpr case=start
// b"\nc"\na"]\n
// @lcpr case=end

// @lcpr case=start
// c"\nd"\nz"]\n
// @lcpr case=end

 */

