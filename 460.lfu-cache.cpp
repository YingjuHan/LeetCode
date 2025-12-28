/*
 * @lc app=leetcode.cn id=460 lang=cpp
 * @lcpr version=30204
 *
 * [460] LFU 缓存
 *
 * https://leetcode.cn/problems/lfu-cache/description/
 *
 * algorithms
 * Hard (48.83%)
 * Likes:    896
 * Dislikes: 0
 * Total Accepted:    105K
 * Total Submissions: 214.8K
 * Testcase Example:  '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
 *
 * 请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。
 * 
 * 实现 LFUCache 类：
 * 
 * 
 * LFUCache(int capacity) - 用数据结构的容量 capacity 初始化对象
 * int get(int key) - 如果键 key 存在于缓存中，则获取键的值，否则返回 -1 。
 * void put(int key, int value) - 如果键 key 已存在，则变更其值；如果键不存在，请插入键值对。当缓存达到其容量
 * capacity 时，则应该在插入新项之前，移除最不经常使用的项。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除 最久未使用
 * 的键。
 * 
 * 
 * 为了确定最不常使用的键，可以为缓存中的每个键维护一个 使用计数器 。使用计数最小的键是最久未使用的键。
 * 
 * 当一个键首次插入到缓存中时，它的使用计数器被设置为 1 (由于 put 操作)。对缓存中的键执行 get 或 put 操作，使用计数器的值将会递增。
 * 
 * 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：
 * ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get",
 * "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
 * 输出：
 * [null, null, null, 1, null, -1, 3, null, -1, 3, 4]
 * 
 * 解释：
 * // cnt(x) = 键 x 的使用计数
 * // cache=[] 将显示最后一次使用的顺序（最左边的元素是最近的）
 * LFUCache lfu = new LFUCache(2);
 * lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
 * lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
 * lfu.get(1);      // 返回 1
 * ⁠                // cache=[1,2], cnt(2)=1, cnt(1)=2
 * lfu.put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
 * ⁠                // cache=[3,1], cnt(3)=1, cnt(1)=2
 * lfu.get(2);      // 返回 -1（未找到）
 * lfu.get(3);      // 返回 3
 * ⁠                // cache=[3,1], cnt(3)=2, cnt(1)=2
 * lfu.put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
 * ⁠                // cache=[4,3], cnt(4)=1, cnt(3)=2
 * lfu.get(1);      // 返回 -1（未找到）
 * lfu.get(3);      // 返回 3
 * ⁠                // cache=[3,4], cnt(4)=1, cnt(3)=3
 * lfu.get(4);      // 返回 4
 * ⁠                // cache=[3,4], cnt(4)=2, cnt(3)=3
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= capacity <= 10^4
 * 0 <= key <= 10^5
 * 0 <= value <= 10^9
 * 最多调用 2 * 10^5 次 get 和 put 方法
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
struct Node
{
    int key;
    int value;
    int freq = 1;
    Node* prev;
    Node* next;

    Node(int k = 0, int v = 0) : key(k), value(v) {}
};

class LFUCache {
public:
    LFUCache(int capacity) : myCapacity(capacity) {
        
    }
    
    int get(int key) {
        Node* node = GetNode(key);
        return node ? node->value : -1;
    }
    
    void put(int key, int value) {
        if (myCapacity == 0) {
            return;
        }
        Node* node = GetNode(key);
        if (node) {
            node->value = value;
            return;
        }

        if (myKeyToNode.size() == myCapacity) {
            Node* dummy = myFreqToDummy[myMinFreq];
            Node* backNode = dummy->prev;
            myKeyToNode.erase(backNode->key);
            Remove(backNode);
            delete backNode;
            if (dummy->prev == dummy) {
                myFreqToDummy.erase(myMinFreq);
                delete dummy;
            }
        }
        myKeyToNode[key] = node = new Node(key, value);
        PushFront(1, node);
        myMinFreq = 1;
    }
private:
    Node* NewList() {
        Node* dummy = new Node();
        dummy->prev = dummy;
        dummy->next = dummy;
        return dummy;
    }
    void PushFront(int freq, Node* x) {
        auto it = myFreqToDummy.find(freq);
        if (it == myFreqToDummy.end()) {
            it = myFreqToDummy.emplace(freq, NewList()).first;
        }
        Node* dummy = it->second;
        x->prev = dummy;
        x->next = dummy->next;
        x->prev->next = x;
        x->next->prev = x;
    }
    void Remove(Node* x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }
    Node* GetNode(int key) {
        auto it = myKeyToNode.find(key);
        if (it == myKeyToNode.end()) {
            return nullptr;
        }

        Node* node = it->second;
        Remove(node);
        Node* dummy = myFreqToDummy[node->freq];
        if (dummy->prev == dummy) {
            myFreqToDummy.erase(node->freq);
            delete dummy;
            if (myMinFreq == node->freq) {
                myMinFreq++;
            }
        }
        node->freq++;
        PushFront(node->freq, node);
        return node;
    }


private:
    int myCapacity;
    int myMinFreq;
    unordered_map<int, Node*> myKeyToNode;
    unordered_map<int, Node*> myFreqToDummy;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end



/*
// @lcpr case=start
// ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"][[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]\n
// @lcpr case=end

 */

