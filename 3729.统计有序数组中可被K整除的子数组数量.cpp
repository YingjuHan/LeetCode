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
    long long subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int s = 0;
        long long res = 0;
        for (int x : nums) {
            cnt[s]++;
            s = (s + x % k + k) % k;
            res += cnt[s];
        }
        return res;
    }
    long long numGoodSubarrays(vector<int>& nums, int k) {
        long long ans = subarraysDivByK(nums, k);
        int n = nums.size();
        int start = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (i < n - 1 && x == nums[i + 1]) {
                continue;
            }

            // 遍历到了连续相同元素段的末尾
            int size = i - start + 1; // 这一段的长度
            for (int sz = 1; sz <= size; sz++) {
                if (1LL * x * sz % k == 0) { // 长为 sz 的子数组元素和能被 k 整除
                    ans -= size - sz; // 一共有 size-sz+1 个长为 sz 的子数组，其中有 size-sz 个重复的
                }
            }
            start = i + 1;
        }
        return ans;
    }
};


class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        long long preSum = 0;
        long long res = 0;
        int last_start = 0;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (i > 0 && x != nums[i - 1]) {
                int s = preSum;
                for (int t = i - last_start; t > 0; t--) {
                    cnt[s % k]++;
                    s -= nums[i - 1]; 
                }
                last_start = i;
            }
            preSum += nums[i];
            res += cnt[preSum % k];
        }
        return res;
    }
};
 