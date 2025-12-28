/*
 * @lc app=leetcode.cn id=432 lang=cpp
 * @lcpr version=30204
 *
 * [432] 全 O(1) 的数据结构
 *
 * https://leetcode.cn/problems/all-oone-data-structure/description/
 *
 * algorithms
 * Hard (46.24%)
 * Likes:    343
 * Dislikes: 0
 * Total Accepted:    33.9K
 * Total Submissions: 73.3K
 * Testcase Example:  '["AllOne","inc","inc","getMaxKey","getMinKey","inc","getMaxKey","getMinKey"]\n' +
  '[[],["hello"],["hello"],[],[],["leet"],[],[]]'
 *
 * 请你设计一个用于存储字符串计数的数据结构，并能够返回计数最小和最大的字符串。
 * 
 * 实现 AllOne 类：
 * 
 * 
 * AllOne() 初始化数据结构的对象。
 * inc(String key) 字符串 key 的计数增加 1 。如果数据结构中尚不存在 key ，那么插入计数为 1 的 key 。
 * dec(String key) 字符串 key 的计数减少 1 。如果 key 的计数在减少后为 0 ，那么需要将这个 key
 * 从数据结构中删除。测试用例保证：在减少计数前，key 存在于数据结构中。
 * getMaxKey() 返回任意一个计数最大的字符串。如果没有元素存在，返回一个空字符串 "" 。
 * getMinKey() 返回任意一个计数最小的字符串。如果没有元素存在，返回一个空字符串 "" 。
 * 
 * 
 * 注意：每个函数都应当满足 O(1) 平均时间复杂度。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入
 * ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey",
 * "getMinKey"]
 * [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
 * 输出
 * [null, null, null, "hello", "hello", null, "hello", "leet"]
 * 
 * 解释
 * AllOne allOne = new AllOne();
 * allOne.inc("hello");
 * allOne.inc("hello");
 * allOne.getMaxKey(); // 返回 "hello"
 * allOne.getMinKey(); // 返回 "hello"
 * allOne.inc("leet");
 * allOne.getMaxKey(); // 返回 "hello"
 * allOne.getMinKey(); // 返回 "leet"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= key.length <= 10
 * key 由小写英文字母组成
 * 测试用例保证：在每次调用 dec 时，数据结构中总存在 key
 * 最多调用 inc、dec、getMaxKey 和 getMinKey 方法 5 * 10^4 次
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
struct DLinkNode{
private:
    void spliceSelf(){
        if(prev){
            prev->next=next;
        }
        if(next){
            next->prev=prev;
        }
    }
public:
    string key;
    DLinkNode *prev,*next;

    DLinkNode():key(""),prev(nullptr),next(nullptr){}
    DLinkNode(string key):key(key),prev(nullptr),next(nullptr){}

    void moveBehindOf(DLinkNode *target){
        spliceSelf();
        
        prev=target;
        if(target->next){
            next=target->next;
        }

        prev->next=this;
        if(next){
            next->prev=this;
        }
    }

    void moveFrontOf(DLinkNode *target){
        spliceSelf();
        
        next=target;
        if(target->prev){
            prev=target->prev;
        }
        
        next->prev=this;
        if(prev){
            prev->next=this;
        }
    }

    void remove(){
        spliceSelf();
        delete this;
    }
};
void printDLinkNode(DLinkNode *head){
    cout<<"DLinkNode:-----------------------------------"<<endl;
    for(DLinkNode *node=head;node;node=node->next){
        cout<<node->key<<" -> ";
    }
    cout<<" end"<<endl;
}
class AllOne {
private:
    DLinkNode *dummy_head,*dummy_tail;
    unordered_map<string,DLinkNode*> keyToNode;
    unordered_map<string,int> keyToCount;
    unordered_map<int,pair<DLinkNode*,DLinkNode*>> countToNode;
public:
    AllOne() {
        dummy_head=new DLinkNode();
        dummy_tail=new DLinkNode();
        dummy_head->next=dummy_tail;
        dummy_tail->prev=dummy_head;
    }

    void insertNode(string key){
        DLinkNode *node = new DLinkNode(key);
        keyToNode[key] = node;
        keyToCount[key] = 1;
        if(countToNode.contains(1)){
            node->moveBehindOf(countToNode[1].second);
            countToNode[1].second=node;
        }else{
            node->moveBehindOf(dummy_head);
            countToNode[1]={node,node};
        }
    }

    void moveToNext(string key){
        DLinkNode *node=keyToNode[key];
        int &count = keyToCount[key];

        auto &[bottom,top] = countToNode[count];

        if(node==top&&node==bottom){
            countToNode.erase(count);
        }else if(node==top){
            top=node->prev;
        }else if(node==bottom){
            bottom=node->next;
            node->moveBehindOf(top);
        }else{
            node->moveBehindOf(top);
        }

        if(countToNode.contains(count+1)){
            auto &[bottom,top] = countToNode[count+1];
            bottom=node;
        }else{
            countToNode[count+1]={node,node};
        }
        
        count++;
    }
    
    void removeKey(string key){
        DLinkNode *node=keyToNode[key];
        int &count = keyToCount[key];

        auto &[bottom,top] = countToNode[count];

        if(node==top&&node==bottom){
            countToNode.erase(count);
        }else if(node==top){
            top=node->prev;
        }else if(node==bottom){
            bottom=node->next;
        }
        node->remove();
        keyToNode.erase(key);
        keyToCount.erase(key);
    }

    void moveToPrev(string key){
        DLinkNode *node=keyToNode[key];
        int &count = keyToCount[key];

        auto &[bottom,top] = countToNode[count];

        if(node==top&&node==bottom){
            countToNode.erase(count);
        }else if(node==top){
            top=node->prev;
            node->moveFrontOf(bottom);
        }else if(node==bottom){
            bottom=node->next;
        }else{
            node->moveFrontOf(bottom);
        }

        if(countToNode.contains(count-1)){
            auto &[bottom,top] = countToNode[count-1];
            top=node;
        }else{
            countToNode[count-1]={node,node};
        }

        count--;
    }
    
    void inc(string key) {
        if(keyToNode.contains(key)){
            moveToNext(key);
        }else{
            insertNode(key);
        }
        // printDLinkNode(dummy_head);
    }
    
    void dec(string key) {
        if(keyToCount[key]==1){
            removeKey(key);
        }else{
            moveToPrev(key);
        }
        // printDLinkNode(dummy_head);
    }

    string getMaxKey() {
        return dummy_tail->prev->key;
    }
    
    string getMinKey() {
        return dummy_head->next->key;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end



