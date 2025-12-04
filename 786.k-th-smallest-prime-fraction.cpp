/*
 * @lc app=leetcode.cn id=786 lang=cpp
 * @lcpr version=30204
 *
 * [786] 第 K 个最小的质数分数
 *
 * https://leetcode.cn/problems/k-th-smallest-prime-fraction/description/
 *
 * algorithms
 * Medium (68.00%)
 * Likes:    307
 * Dislikes: 0
 * Total Accepted:    39K
 * Total Submissions: 57.3K
 * Testcase Example:  '[1,2,3,5]\n3'
 *
 * 给你一个按递增顺序排序的数组 arr 和一个整数 k 。数组 arr 由 1 和若干 质数 组成，且其中所有整数互不相同。
 * 
 * 对于每对满足 0 <= i < j < arr.length 的 i 和 j ，可以得到分数 arr[i] / arr[j] 。
 * 
 * 那么第 k 个最小的分数是多少呢?  以长度为 2 的整数数组返回你的答案, 这里 answer[0] == arr[i] 且 answer[1] ==
 * arr[j] 。
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [1,2,3,5], k = 3
 * 输出：[2,5]
 * 解释：已构造好的分数,排序后如下所示: 
 * 1/5, 1/3, 2/5, 1/2, 3/5, 2/3
 * 很明显第三个最小的分数是 2/5
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [1,7], k = 1
 * 输出：[1,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= arr.length <= 1000
 * 1 <= arr[i] <= 3 * 10^4
 * arr[0] == 1
 * arr[i] 是一个 质数 ，i > 0
 * arr 中的所有数字 互不相同 ，且按 严格递增 排序
 * 1 <= k <= arr.length * (arr.length - 1) / 2
 * 
 * 
 * 
 * 
 * 进阶：你可以设计并实现时间复杂度小于 O(n^2) 的算法解决此问题吗？
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
    struct PrimePair {
        const vector<int>* arr;  // 指向原数组，避免整体拷贝
        int i, j;                // 分子索引 i，分母索引 j

        PrimePair(const vector<int>& a, int i_, int j_)
            : arr(&a), i(i_), j(j_) {}

        // 为了配合 std::greater<PrimePair>，这里重载 >
        bool operator>(const PrimePair& rho) const {
            // 比较 a[i]/a[j] 和 a[rho.i]/a[rho.j]
            // 使用 long long 防止溢出
            long long a1 = (*arr)[i];
            long long b1 = (*arr)[j];
            long long a2 = (*rho.arr)[rho.i];
            long long b2 = (*rho.arr)[rho.j];
            return a1 * b2 > a2 * b1;  // > 表示当前分数更大
        }
    };
    
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        // priority_queue 的模板参数：元素类型，底层容器类型，比较器类型
        priority_queue<PrimePair, vector<PrimePair>, std::greater<PrimePair>> pq;

        // 初始化：所有 (0, j)
        for (int j = 1; j < n; j++) {
            pq.emplace(arr, 0, j);
        }

        // 弹出 k-1 次
        for (int t = 1; t < k; ++t) {
            PrimePair cur = pq.top();
            pq.pop();
            int i = cur.i, j = cur.j;
            // 把 (i+1, j) 推入堆
            if (i + 1 < j) {
                pq.emplace(arr, i + 1, j);
            }
        }

        PrimePair ans = pq.top();
        return { (*ans.arr)[ans.i], (*ans.arr)[ans.j] };
    }
};

// @lc code=end



/*
// @lcpr case=start
// [1,2,3,5]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,7]\n1\n
// @lcpr case=end

 */

