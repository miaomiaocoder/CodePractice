/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
class Solution {
   public:
    int minCut(string s) {
        vector<vector<int>> isPlaindrom(s.size(), vector<int>(s.size(), 0));
        for (int i = s.size(); i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (s[i] == s[j] && (j - i <= 1 || isPlaindrom[i + 1][j - 1]))
                    isPlaindrom[i][j] = 1;
            }
        }
        vector<int> f(s.size(), 0);
        for (int i = 0; i < s.size(); ++i) f[i] = i;
        for (int i = 1; i < s.size(); ++i) {
            if (isPlaindrom[0][i]) {
                f[i] = 0;
                continue;
            }
            for (int j = 0; j < i; ++j) {
                if (isPlaindrom[j + 1][i]) {
                    f[i] = min(f[i], f[j] + 1);
                }
            }
        }
        return f[s.size() - 1];
    }
};
// @lc code=end
