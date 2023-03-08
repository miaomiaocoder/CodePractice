/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
   public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> f(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); ++i) f[i][0] = i;
        for (int j = 0; j <= word2.size(); ++j) f[0][j] = j;
        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                if (word1[i - 1] == word2[j - 1])
                    f[i][j] = f[i - 1][j - 1];
                else
                    f[i][j] = min(f[i - 1][j] + 1, min(f[i][j - 1] + 1, f[i - 1][j - 1] + 1));
            }
        }
        return f[word1.size()][word2.size()];
    }
};
// @lc code=end
