/*
 * @lc app=leetcode.cn id=3694 lang=cpp
 *
 * [3694] 删除子字符串后不同的终点
 */

// @lc code=start
#include <string>
#include <set>
#include <vector>

using namespace std;


class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();
        set<pair<int, int>> st;
        int x = 0, y = 0;

        for (int i = 0; i < n; i++) {
            switch (s[i])
            {
            case 'U': y++; break;
            case 'D': y--; break;
            case 'L': x--; break;
            case 'R': x++; break;
            }

            int left = i - k + 1;
            if (left < 0) {
                continue;
            }

            st.insert({x, y});

            switch (s[left])
            {
            case 'U': y--; break;
            case 'D': y++; break;
            case 'L': x++; break;
            case 'R': x--; break;
            }
        }

        return st.size();
    }
};
// @lc code=end

