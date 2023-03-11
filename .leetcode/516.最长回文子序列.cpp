/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> f(s.size() + 1, vector<int>(s.size() + 1, 0));
        for (int i = 0; i < s.size(); i++) f[i][i] = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    f[i][j] = f[i + 1][j - 1] + 2;
                } else {
                    f[i][j] = max(f[i + 1][j], f[i][j - 1]);
                }
            }
        }
        return f[0][s.size() - 1];
    }
};

// @lc code=end
