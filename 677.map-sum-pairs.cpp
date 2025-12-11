/*
 * @lc app=leetcode.cn id=677 lang=cpp
 * @lcpr version=30204
 *
 * [677] 键值映射
 *
 * https://leetcode.cn/problems/map-sum-pairs/description/
 *
 * algorithms
 * Medium (65.19%)
 * Likes:    265
 * Dislikes: 0
 * Total Accepted:    55.5K
 * Total Submissions: 85.1K
 * Testcase Example:  '["MapSum","insert","sum","insert","sum"]\n' +
  '[[],["apple",3],["ap"],["app",2],["ap"]]'
 *
 * 设计一个 map ，满足以下几点:
 * 
 * 
 * 字符串表示键，整数表示值
 * 返回具有前缀等于给定字符串的键的值的总和
 * 
 * 
 * 实现一个 MapSum 类：
 * 
 * 
 * MapSum() 初始化 MapSum 对象
 * void insert(String key, int val) 插入 key-val 键值对，字符串表示键 key ，整数表示值 val 。如果键
 * key 已经存在，那么原来的键值对 key-value 将被替代成新的键值对。
 * int sum(string prefix) 返回所有以该前缀 prefix 开头的键 key 的值的总和。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * ["MapSum", "insert", "sum", "insert", "sum"]
 * [[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
 * 输出：
 * [null, null, 3, null, 5]
 * 
 * 解释：
 * MapSum mapSum = new MapSum();
 * mapSum.insert("apple", 3);  
 * mapSum.sum("ap");           // 返回 3 (apple = 3)
 * mapSum.insert("app", 2);    
 * mapSum.sum("ap");           // 返回 5 (apple + app = 3 + 2 = 5)
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= key.length, prefix.length <= 50
 * key 和 prefix 仅由小写英文字母组成
 * 1 <= val <= 1000
 * 最多调用 50 次 insert 和 sum
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
struct Node {
    int val = 0;
    Node* son[26]{};
};
class MapSum {
public:
    MapSum() {
        this->root = new Node();
    }
    
    void insert(string key, int val) {
        int delta = val;

        // 如果键 key 已经存在，那么原来的键值对 key-value 将被替代成新的键值对
        // 存在的话,就要减去value,然后使用新的value替代
        if (cnt.count(key)) {
            delta -= cnt[key];
        }

        cnt[key] = val;
        Node* cur = root;
        for (char c : key) {
            if (cur->son[c - 'a'] == nullptr) {
                cur->son[c - 'a'] = new Node();
            }
            cur = cur->son[c - 'a'];
            cur->val += delta;
        }
    }
    
    int sum(string prefix) {
        Node* cur = root;
        for (char c : prefix) {
            if (cur->son[c - 'a'] == nullptr) {
                return 0;
            } else {
                cur = cur->son[c - 'a'];
            }
        }
        return cur->val;
    }
private:
    Node* root;
    unordered_map<string, int> cnt;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end



/*
// @lcpr case=start
// ["MapSum", "insert", "sum", "insert", "sum"][[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]\n
// @lcpr case=end

 */

