/*
 * @lc app=leetcode.cn id=1054 lang=cpp
 * @lcpr version=30204
 *
 * [1054] 距离相等的条形码
 *
 * https://leetcode.cn/problems/distant-barcodes/description/
 *
 * algorithms
 * Medium (45.88%)
 * Likes:    206
 * Dislikes: 0
 * Total Accepted:    30.4K
 * Total Submissions: 66.3K
 * Testcase Example:  '[1,1,1,2,2,2]'
 *
 * 在一个仓库里，有一排条形码，其中第 i 个条形码为 barcodes[i]。
 * 
 * 请你重新排列这些条形码，使其中任意两个相邻的条形码不能相等。 你可以返回任何满足该要求的答案，此题保证存在答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：barcodes = [1,1,1,2,2,2]
 * 输出：[2,1,2,1,2,1]
 * 
 * 
 * 示例 2：
 * 
 * 输入：barcodes = [1,1,1,1,2,2,3,3]
 * 输出：[1,3,1,3,2,1,2,1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= barcodes.length <= 10000
 * 1 <= barcodes[i] <= 10000
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
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        unordered_map<int, int> count;
        for (int barcode : barcodes) {
            count[barcode]++;
        }
        vector<pair<int, int>> a(count.begin(), count.end());
        sort(a.begin(), a.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });

        vector<int> res(n, 0);
        int i = 0;
        for (auto [num, cnt] : a) {
            while (cnt--) {
                res[i] = num;
                i += 2;
                if (i >= n) {
                    i = 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,2,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1,2,2,3,3]\n
// @lcpr case=end

 */

