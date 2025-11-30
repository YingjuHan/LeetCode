/*
 * @lc app=leetcode.cn id=LCR 184 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 184] 设计自助结算系统
 *
 * https://leetcode.cn/problems/dui-lie-de-zui-da-zhi-lcof/description/
 *
 * algorithms
 * Medium (47.96%)
 * Likes:    535
 * Dislikes: 0
 * Total Accepted:    190.6K
 * Total Submissions: 397.4K
 * Testcase Example:  '["Checkout","add","add","get_max","remove","get_max"]\n[[],[4],[7],[],[],[]]'
 *
 * 请设计一个自助结账系统，该系统需要通过一个队列来模拟顾客通过购物车的结算过程，需要实现的功能有：
 * 
 * 
 * get_max()：获取结算商品中的最高价格，如果队列为空，则返回 -1
 * add(value)：将价格为 value 的商品加入待结算商品队列的尾部
 * remove()：移除第一个待结算的商品价格，如果队列为空，则返回 -1
 * 
 * 
 * 注意，为保证该系统运转高效性，以上函数的均摊时间复杂度均为 O(1)
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: 
 * ["Checkout","add","add","get_max","remove","get_max"]
 * [[],[4],[7],[],[],[]]
 * 
 * 输出: [null,null,null,7,4,7]
 * 
 * 
 * 示例 2：
 * 
 * 输入: 
 * ["Checkout","remove","get_max"]
 * [[],[],[]]
 * 
 * 输出: [null,-1,-1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= get_max, add, remove 的总操作数 <= 10000
 * 1 <= value <= 10^5
 * 
 * 
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
class Checkout {
    deque<int> q;
public:
    Checkout() {
        
    }
    
    int get_max() {
        if (q.empty()) {
            return -1;
        }
        return *max_element(q.begin(), q.end());
    }
    
    void add(int value) {
        q.push_back(value);
    }
    
    int remove() {
        if (q.empty()) {
            return -1;
        }
        int pop = q.front();
        q.pop_front();
        return pop;
    }
};

/**
 * Your Checkout object will be instantiated and called as such:
 * Checkout* obj = new Checkout();
 * int param_1 = obj->get_max();
 * obj->add(value);
 * int param_3 = obj->remove();
 */
// @lc code=end



/*
// @lcpr case=start
// ["Checkout","add","add","get_max","remove","get_max"][[],[4],[7],[],[],[]]\n
// @lcpr case=end

// @lcpr case=start
// ["Checkout","remove","get_max"][[],[],[]]\n
// @lcpr case=end

 */

