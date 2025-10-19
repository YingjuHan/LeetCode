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
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
            case 'D':
                y--;
                break;
            case 'U':
                y++;
                break;
            default:
                return 0;
            }

            int left = i - k + 1;
            if (left < 0) {
                continue;
            }

            st.insert({x, y});

            switch (s[left])
            {
            case 'L':
                x++;
                break;
            case 'R':
                x--;
                break;
            case 'D':
                y++;
                break;
            case 'U':
                y--;
                break;
            default:
                return 0;
            }
        }
        return st.size();
    }
};