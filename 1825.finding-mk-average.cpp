/*
 * @lc app=leetcode.cn id=1825 lang=cpp
 * @lcpr version=30204
 *
 * [1825] 求出 MK 平均值
 *
 * https://leetcode.cn/problems/finding-mk-average/description/
 *
 * algorithms
 * Hard (43.46%)
 * Likes:    111
 * Dislikes: 0
 * Total Accepted:    14.6K
 * Total Submissions: 33.5K
 * Testcase Example:  '["MKAverage","addElement","addElement","calculateMKAverage","addElement","calculateMKAverage","addElement","addElement","addElement","calculateMKAverage"]\n' +
  '[[3,1],[3],[1],[],[10],[],[5],[5],[5],[]]'
 *
 * 给你两个整数 m 和 k ，以及数据流形式的若干整数。你需要实现一个数据结构，计算这个数据流的 MK 平均值 。
 * 
 * MK 平均值 按照如下步骤计算：
 * 
 * 
 * 如果数据流中的整数少于 m 个，MK 平均值 为 -1 ，否则将数据流中最后 m 个元素拷贝到一个独立的容器中。
 * 从这个容器中删除最小的 k 个数和最大的 k 个数。
 * 计算剩余元素的平均值，并 向下取整到最近的整数 。
 * 
 * 
 * 请你实现 MKAverage 类：
 * 
 * 
 * MKAverage(int m, int k) 用一个空的数据流和两个整数 m 和 k 初始化 MKAverage 对象。
 * void addElement(int num) 往数据流中插入一个新的元素 num 。
 * int calculateMKAverage() 对当前的数据流计算并返回 MK 平均数 ，结果需 向下取整到最近的整数 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * ["MKAverage", "addElement", "addElement", "calculateMKAverage",
 * "addElement", "calculateMKAverage", "addElement", "addElement",
 * "addElement", "calculateMKAverage"]
 * [[3, 1], [3], [1], [], [10], [], [5], [5], [5], []]
 * 输出：
 * [null, null, null, -1, null, 3, null, null, null, 5]
 * 
 * 解释：
 * MKAverage obj = new MKAverage(3, 1); 
 * obj.addElement(3);        // 当前元素为 [3]
 * obj.addElement(1);        // 当前元素为 [3,1]
 * obj.calculateMKAverage(); // 返回 -1 ，因为 m = 3 ，但数据流中只有 2 个元素
 * obj.addElement(10);       // 当前元素为 [3,1,10]
 * obj.calculateMKAverage(); // 最后 3 个元素为 [3,1,10]
 * ⁠                         // 删除最小以及最大的 1 个元素后，容器为 [3]
 * ⁠                         // [3] 的平均值等于 3/1 = 3 ，故返回 3
 * obj.addElement(5);        // 当前元素为 [3,1,10,5]
 * obj.addElement(5);        // 当前元素为 [3,1,10,5,5]
 * obj.addElement(5);        // 当前元素为 [3,1,10,5,5,5]
 * obj.calculateMKAverage(); // 最后 3 个元素为 [5,5,5]
 * ⁠                         // 删除最小以及最大的 1 个元素后，容器为 [5]
 * ⁠                         // [5] 的平均值等于 5/1 = 5 ，故返回 5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= m <= 10^5
 * 1 <= k*2 < m
 * 1 <= num <= 10^5
 * addElement 与 calculateMKAverage 总操作次数不超过 10^5 次。
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
#include <set>
// @lcpr-template-end
// @lc code=start
class MKAverage {
private:
    int m, k;
    queue<int> q;
    multiset<int> s1, s2, s3;
    long long sum2;
public:
    MKAverage(int m, int k) : m(m), k(k) {
        sum2 = 0;
    }

    void addElement(int num) {
        q.push(num);
        if (q.size() <= m) {
            s2.insert(num);
            sum2 += num;
            if (q.size() == m) {
                while (s1.size() < k) {
                    s1.insert(*s2.begin());
                    sum2 -= *s2.begin();
                    s2.erase(s2.begin());
                }
                while (s3.size() < k) {
                    s3.insert(*s2.rbegin());
                    sum2 -= *s2.rbegin();
                    s2.erase(prev(s2.end()));
                }
            }
            return;
        }

        if (num < *s1.rbegin()) {
            s1.insert(num);
            s2.insert(*s1.rbegin());
            sum2 += *s1.rbegin();
            s1.erase(prev(s1.end()));
        } else if (num > *s3.begin()) {
            s3.insert(num);
            s2.insert(*s3.begin());
            sum2 += *s3.begin();
            s3.erase(s3.begin());
        } else {
            s2.insert(num);
            sum2 += num;
        }

        int x = q.front();
        q.pop();
        if (s1.count(x) > 0) {
            s1.erase(s1.find(x));
            s1.insert(*s2.begin());
            sum2 -= *s2.begin();
            s2.erase(s2.begin());
        } else if (s3.count(x) > 0) {
            s3.erase(s3.find(x));
            s3.insert(*s2.rbegin());
            sum2 -= *s2.rbegin();
            s2.erase(prev(s2.end()));
        } else {
            s2.erase(s2.find(x));
            sum2 -= x;
        }
    }

    int calculateMKAverage() {
        if (q.size() < m) {
            return -1;
        }
        return sum2 / (m - 2 * k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MKAverage", "addElement", "addElement", "calculateMKAverage", "addElement", "calculateMKAverage", "addElement","addElement", "addElement", "calculateMKAverage"][[3, 1], [3], [1], [], [10], [], [5], [5], [5], []]\n
// @lcpr case=end

 */

