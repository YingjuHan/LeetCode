/*
 * @lc app=leetcode.cn id=2327 lang=cpp
 * @lcpr version=30204
 *
 * [2327] 知道秘密的人数
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
    int peopleAwareOfSecret(int n, int delay, int forget) {
        deque<pair<int, int>> knowDeque;
        deque<pair<int, int>> shareDeque;

        // 1st day
        knowDeque.emplace_back(make_pair(1, 1));
        int knowCount = 1;
        int shareCount = 0;

        for (int i = 2; i <= n; i++)
        {
            if (!knowDeque.empty() && knowDeque.front().first == i - delay)
            {
                knowCount = (knowCount - knowDeque.front().second + mod) % mod;
                shareCount = (shareCount + knowDeque.front().second) % mod;
                shareDeque.push_back(knowDeque.front());
                knowDeque.pop_front();
            }
            if (!shareDeque.empty() && shareDeque.front().first == i - forget)
            {
                shareCount = (shareCount - shareDeque.front().second + mod) % mod;
                shareDeque.pop_front();
            }
            if (!shareDeque.empty())
            {
                knowCount = (knowCount + shareCount) % mod;
                knowDeque.emplace_back(make_pair(i, shareCount));
            }
        }
        return (knowCount + shareCount) % mod;
    }
private:
    static constexpr int mod = 1000000007;
};
// @lc code=end



/*
// @lcpr case=start
// 6\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// 4\n1\n3\n
// @lcpr case=end

 */

