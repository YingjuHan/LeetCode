/*
 * @lc app=leetcode.cn id=1286 lang=cpp
 * @lcpr version=
 *
 * [1286] 字母组合迭代器
 *
 * https://leetcode.cn/problems/iterator-for-combination/description/
 *
 * algorithms
 * Medium (67.59%)
 * Likes:    83
 * Dislikes: 0
 * Total Accepted:    9.9K
 * Total Submissions: 14.5K
 * Testcase Example:  '["CombinationIterator","next","hasNext","next","hasNext","next","hasNext"]\n' +
  '[["abc",2],[],[],[],[],[],[]]'
 *
 * 请你设计一个迭代器类 CombinationIterator ，包括以下内容：
 * 
 * 
 * CombinationIterator(string characters, int combinationLength)
 * 一个构造函数，输入参数包括：用一个 有序且字符唯一 的字符串 characters（该字符串只包含小写英文字母）和一个数字
 * combinationLength 。
 * 函数 next() ，按 字典序 返回长度为 combinationLength 的下一个字母组合。
 * 函数 hasNext() ，只有存在长度为 combinationLength 的下一个字母组合时，才返回 true
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入:
 * ["CombinationIterator", "next", "hasNext", "next", "hasNext", "next",
 * "hasNext"]
 * [["abc", 2], [], [], [], [], [], []]
 * 输出：
 * [null, "ab", true, "ac", true, "bc", false]
 * 解释：
 * CombinationIterator iterator = new CombinationIterator("abc", 2); // 创建迭代器
 * iterator
 * iterator.next(); // 返回 "ab"
 * iterator.hasNext(); // 返回 true
 * iterator.next(); // 返回 "ac"
 * iterator.hasNext(); // 返回 true
 * iterator.next(); // 返回 "bc"
 * iterator.hasNext(); // 返回 false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= combinationLength <= characters.length <= 15
 * characters 中每个字符都 不同
 * 每组测试数据最多对 next 和 hasNext 调用 10^4次
 * 题目保证每次调用函数 next 时都存在下一个字母组合。
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
class CombinationIterator {
public:
    vector<string> vt;
    string temp;
    int index;
    int count;
    void dfs(string characters, int combinationLength, int k) {
        if (count > 10000) return;
        if (temp.size() == combinationLength) {
            vt.emplace_back(temp);
        }
        for (int i = k; i < characters.size(); i++) {
            if (count > 1000) return;
            temp += characters[i];
            dfs(characters, combinationLength, i + 1);
            temp.erase(temp.end() - 1);
        }
    }
    CombinationIterator(string characters, int combinationLength) {
        dfs(characters, combinationLength, 0);
        index = 0;
        count = 0;
    }
    
    string next() {
        return vt[index++];
    }
    
    bool hasNext() {
        return index < vt.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end



/*
// @lcpr case=start
// ["CombinationIterator", "next", "hasNext", "next", "hasNext", "next", "hasNext"][["abc", 2], [], [], [], [], [], []]\n
// @lcpr case=end

 */

