/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
   public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> f(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= t.size(); ++j) {
                if (s[i - 1] == t[j - 1])
                    f[i][j] = f[i - 1][j - 1] + 1;
                else
                    f[i][j] = f[i][j - 1];
            }
        }
        if (f[s.size()][t.size()] == s.size()) return true;
        return false;
    }
};
// @lc code=end
