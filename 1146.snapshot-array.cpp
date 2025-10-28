/*
 * @lc app=leetcode.cn id=1146 lang=cpp
 * @lcpr version=30204
 *
 * [1146] 快照数组
 *
 * https://leetcode.cn/problems/snapshot-array/description/
 *
 * algorithms
 * Medium (38.34%)
 * Likes:    221
 * Dislikes: 0
 * Total Accepted:    32.8K
 * Total Submissions: 85.5K
 * Testcase Example:  '["SnapshotArray","set","snap","set","get"]\n[[3],[0,5],[],[0,6],[0,0]]'
 *
 * 实现支持下列接口的「快照数组」- SnapshotArray：
 * 
 * 
 * SnapshotArray(int length) - 初始化一个与指定长度相等的 类数组 的数据结构。初始时，每个元素都等于 0。
 * void set(index, val) - 会将指定索引 index 处的元素设置为 val。
 * int snap() - 获取该数组的快照，并返回快照的编号 snap_id（快照号是调用 snap() 的总次数减去 1）。
 * int get(index, snap_id) - 根据指定的 snap_id 选择快照，并返回该快照指定索引 index 的值。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：["SnapshotArray","set","snap","set","get"]
 * ⁠    [[3],[0,5],[],[0,6],[0,0]]
 * 输出：[null,null,0,null,5]
 * 解释：
 * SnapshotArray snapshotArr = new SnapshotArray(3); // 初始化一个长度为 3 的快照数组
 * snapshotArr.set(0,5);  // 令 array[0] = 5
 * snapshotArr.snap();  // 获取快照，返回 snap_id = 0
 * snapshotArr.set(0,6);
 * snapshotArr.get(0,0);  // 获取 snap_id = 0 的快照中 array[0] 的值，返回 5
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= length <= 50000
 * 题目最多进行50000 次set，snap，和 get的调用 。
 * 0 <= index < length
 * 0 <= snap_id < 我们调用 snap() 的总次数
 * 0 <= val <= 10^9
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
#include <numeric>
// @lcpr-template-end
// @lc code=start

/**
 * 不能在set时复制数组，因为内存不足
 * 在调用set(index, val)时，不修改数组而是在index的历史修改记录的末尾添加一条数据：(快照号， val)
 */
class SnapshotArray {
public:
    SnapshotArray(int length) {
        (void) length;
    }
    
    void set(int index, int val) {
        history[index].emplace_back(cur_snap_id, val);
    }
    
    int snap() {
        return cur_snap_id++;
    }
    
    int get(int index, int snap_id) {
        vector<pair<int, int>>& h = history[index];
        // 获取<=snap_id的最后一次修改记录，等价于获取快照号>=snap_id + 1的第一个修改记录，上一个记录就是snap_id对应的
        int j = lower_bound(h.begin(), h.end(), pair(snap_id + 1, 0)) - h.begin() - 1;
        return j >= 0 ? h[j].second : 0;
    }
private:
    int cur_snap_id = 0;
    unordered_map<int, vector<pair<int, int>>> history; // <index, [<snap_id, val> ...]>
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end



/*
// @lcpr case=start
// ["SnapshotArray","set","snap","set","get"][[3],[0,5],[],[0,6],[0,0]]\n
// @lcpr case=end

 */

