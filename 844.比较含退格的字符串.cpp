/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
public:
    void changeString(string& s) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex<s.size();fastIndex++) {
            if (s[fastIndex] != '#') {
                s[slowIndex] = s[fastIndex];
                slowIndex++;
            } else if (slowIndex != 0) {
                slowIndex--;
            }
        }
        s.resize(slowIndex);
    }
    bool backspaceCompare(string s, string t) {
        changeString(s);
        changeString(t);
        return s == t;
    }
};
// @lc code=end

