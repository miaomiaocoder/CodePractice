/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
   public:
    string minWindow(string s, string t) {
        string res;
        unordered_map<char, int> hw, ht;
        for (auto &x : t) ht[x]++;

        int cnt = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            hw[s[i]]++;
            if (hw[s[i]] <= ht[s[i]]) cnt++;
            while (j <= i && hw[s[j]] > ht[s[j]]) hw[s[j++]]--;
            if (cnt == t.size())
                if (res.empty() || i - j + 1 < res.size())
                    res = s.substr(j, i - j + 1);
        }
        return res;
    }
};
// @lc code=end
