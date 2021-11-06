/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> ht, hs;
        for (char c : t)
        {
            ht[c]++;
        }
        string res;
        int count = 0;
        for (int i = 0, j = 0; i < s.size(); i++)
        {
            hs[s[i]]++;
            if (hs[s[i]] <= ht[s[i]])
            {
                count++;
            }
            while (hs[s[j]] > ht[s[j]])
            {
                hs[s[j++]]--;
            }
            if (count == t.size())
            {
                if (res.empty() || i - j + 1 < res.size())
                {
                    res = s.substr(j, i - j + 1);
                }
            }
        }
        return res;
    }
};
// @lc code=end
