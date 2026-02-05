/*
 * @lc app=leetcode.cn id=2902 lang=cpp
 * @lcpr version=30204
 *
 * [2902] 和带限制的子多重集合的数目
 *
 * https://leetcode.cn/problems/count-of-sub-multisets-with-bounded-sum/description/
 *
 * algorithms
 * Hard (32.53%)
 * Likes:    29
 * Dislikes: 0
 * Total Accepted:    3.4K
 * Total Submissions: 10.4K
 * Testcase Example:  '[1,2,2,3]\n6\n6'
 *
 * 给你一个下标从 0 开始的非负整数数组 nums 和两个整数 l 和 r 。
 * 
 * 请你返回 nums 中子多重集合的和在闭区间 [l, r] 之间的 子多重集合的数目 。
 * 
 * 由于答案可能很大，请你将答案对 10^9 + 7 取余后返回。
 * 
 * 子多重集合 指的是从数组中选出一些元素构成的 无序 集合，每个元素 x 出现的次数可以是 0, 1, ..., occ[x] 次，其中 occ[x]
 * 是元素 x 在数组中的出现次数。
 * 
 * 注意：
 * 
 * 
 * 如果两个子多重集合中的元素排序后一模一样，那么它们两个是相同的 子多重集合 。
 * 空 集合的和是 0 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,2,2,3], l = 6, r = 6
 * 输出：1
 * 解释：唯一和为 6 的子集合是 {1, 2, 3} 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [2,1,4,2,7], l = 1, r = 5
 * 输出：7
 * 解释：和在闭区间 [1, 5] 之间的子多重集合为 {1} ，{2} ，{4} ，{2, 2} ，{1, 2} ，{1, 4} 和 {1, 2, 2}
 * 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [1,2,1,3,5,2], l = 3, r = 5
 * 输出：9
 * 解释：和在闭区间 [3, 5] 之间的子多重集合为 {3} ，{5} ，{1, 2} ，{1, 3} ，{2, 2} ，{2, 3} ，{1, 1,
 * 2} ，{1, 1, 3} 和 {1, 2, 2} 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * 0 <= nums[i] <= 2 * 10^4
 * nums 的和不超过 2 * 10^4 。
 * 0 <= l <= r <= 2 * 10^4
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
    int countSubMultisets1(vector<int>& nums, int l, int r) {
        const int MOD = 1e9 + 7;
        int total = 0;
        unordered_map<int, int> cnt;
        for (int x : nums) {
            total += x;
            cnt[x]++;
        }

        if (l > total) {
            return 0;
        }

        int c0 = 0;
        auto it0 = cnt.find(0);
        if (it0 != cnt.end()) {
            c0 = it0->second;
            cnt.erase(0);
        }

        vector<pair<int,int>> items;
        items.reserve(cnt.size());
        for (auto& p : cnt) {
            items.push_back({p.first, p.second});
        }
        int m = items.size();

        r = min(r, total);
        vector<vector<int>> f(m + 1, vector<int>(total + 1, 0));
        f[0][0] = (c0 + 1) % MOD;

        for (int i = 0; i < m; i++) {
            int v = items[i].first, c = items[i].second;
            for (int j = 0; j <= r; j++) {
                long long sum = 0L;
                for (int k = 0; k <= c; k++) {
                    long long t = j - 1LL * k * v;
                    if (t < 0) {
                        break;
                    }
                    sum = (sum + f[i][t]) % MOD;
                }
                f[i + 1][j] = sum;
            }
        }

        int ans = 0;
        for (int j = l; j <= r; j++) {
            ans = (ans + f[m][j]) % MOD;
        }
        return ans;
    }
    int countSubMultisets(vector<int>& nums, int l, int r) {
        const int MOD = 1e9 + 7;

        unordered_map<int, int> cnt;
        int total = 0;
        for (int x : nums) {
            total += x;
            cnt[x]++;
        }
        if (l > total) {
            return 0;
        }
        
        r = min(r, total);
        vector<int> f(r + 1);
        f[0] = cnt[0] + 1;
        cnt.erase(0);

        int sum = 0;
        for (auto& [x, c]: cnt) {
            sum = min(sum + x * c, r);
            for (int j = x; j <= sum; j++) {
                f[j] = (f[j] + f[j - x]) % MOD;
            }
            for (int j = sum; j >= x * (c + 1); j--) {
                f[j] = (f[j] - f[j - x * (c + 1)] + MOD) % MOD; 
            }
        }

        int ans = 0;
        for (int i = l; i <= r; i++) {
            ans = (ans + f[i]) % MOD;
        }
        return ans;
    }
};

// @lc code=end



/*
// @lcpr case=start
// [1,2,2,3]\n6\n6\n
// @lcpr case=end

// @lcpr case=start
// [2,1,4,2,7]\n1\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,3,5,2]\n3\n5\n
// @lcpr case=end

 */

