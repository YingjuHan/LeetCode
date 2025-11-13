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
class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        long long sum = 0, res = 0;
        map<pair<int, long long>, int> cnt; // <<capacity[i], sum>, count>
        for (int r = 1; r < n; r++) {
            res += cnt[{capacity[r], sum}];
            cnt[{capacity[r - 1], sum + capacity[r - 1]}]++;
            sum += capacity[r];
        }
        return res;
    }
};