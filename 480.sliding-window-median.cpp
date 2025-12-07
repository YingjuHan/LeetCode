/*
 * @lc app=leetcode.cn id=480 lang=cpp
 * @lcpr version=30204
 *
 * [480] 滑动窗口中位数
 *
 * https://leetcode.cn/problems/sliding-window-median/description/
 *
 * algorithms
 * Hard (40.78%)
 * Likes:    520
 * Dislikes: 0
 * Total Accepted:    51.3K
 * Total Submissions: 125.5K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 中位数是有序序列最中间的那个数。如果序列的长度是偶数，则没有最中间的数；此时中位数是最中间的两个数的平均数。
 * 
 * 例如：
 * 
 * 
 * [2,3,4]，中位数是 3
 * [2,3]，中位数是 (2 + 3) / 2 = 2.5
 * 
 * 
 * 给你一个数组 nums，有一个长度为 k 的窗口从最左端滑动到最右端。窗口中有 k 个数，每次窗口向右移动 1
 * 位。你的任务是找出每次窗口移动后得到的新窗口中元素的中位数，并输出由它们组成的数组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给出 nums = [1,3,-1,-3,5,3,6,7]，以及 k = 3。
 * 
 * 窗口位置                      中位数
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       1
 * ⁠1 [3  -1  -3] 5  3  6  7      -1
 * ⁠1  3 [-1  -3  5] 3  6  7      -1
 * ⁠1  3  -1 [-3  5  3] 6  7       3
 * ⁠1  3  -1  -3 [5  3  6] 7       5
 * ⁠1  3  -1  -3  5 [3  6  7]      6
 * 
 * 
 * 因此，返回该滑动窗口的中位数数组 [1,-1,-1,3,5,6]。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 你可以假设 k 始终有效，即：k 始终小于等于输入的非空数组的元素个数。
 * 与真实值误差在 10 ^ -5 以内的答案将被视作正确答案。
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
template<typename T, typename Compare = less<T>>
class LazyHeap {
    priority_queue<T, vector<T>, Compare> pq;
    unordered_map<T, int> remove_cnt;
    size_t sz = 0;

    void apply_remove() {
        while (!pq.empty() && remove_cnt[pq.top()] > 0) {
            remove_cnt[pq.top()]--;
            pq.pop();
        }
    }

public:
    size_t size() {
        return sz;
    }

    void remove(T x) {
        remove_cnt[x]++;
        sz--;
    }

    T top() {
        apply_remove();
        return pq.top();
    }

    T pop() {
        apply_remove();
        sz--;
        T x = pq.top();
        pq.pop();
        return x;
    }

    void push(T x) {
        pq.push(x);
        sz++;
    }

    // push(x) 然后pop()
    T push_pop(T x) {
        if (sz > 0 && Compare()(x, top())) {
            pq.push(x);
            x = pq.top();
            pq.pop();
        }
        return x;
    }
};
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> ans(n - k + 1);
        LazyHeap<int> left; // 最大堆
        LazyHeap<int, greater<int>> right; // 最小堆

        for (int i = 0; i < n; i++) {
            // 1. 进入窗口
            int in = nums[i];
            if (left.size() == right.size()) {
                left.push(right.push_pop(in));
            } else {
                right.push(left.push_pop(in));
            }

            int l = i + 1 - k;
            if (l < 0) {
                continue;
            }

            // 2. 计算答案
            if (k % 2) {
                ans[l] = left.top();
            } else {
                ans[l] = ((long long) left.top() + right.top()) / 2.0;
            }

            // 3. 离开窗口
            int out = nums[l];
            if (out <= left.top()) {
                left.remove(out);
                if (left.size() < right.size()) {
                    left.push(right.pop());
                }
            } else {
                right.remove(out);
                if (left.size() > right.size() + 1) {
                    right.push(left.pop());
                }
            }
        }
        return ans;
    }
};
// @lc code=end



