/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> f(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        int res = 0;
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        return f[text1.size()][text2.size()];
    }
};
// @lc code=end
