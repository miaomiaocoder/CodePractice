/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
   public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        for (string& str : strs) {
            int zeroNum = 0, oneNum = 0;
            for (char& c : str)
                if (c == '0')
                    zeroNum++;
                else
                    oneNum++;
            for (int i = m; i >= zeroNum; i--)
                for (int j = n; j >= oneNum; j--)
                    f[i][j] = max(f[i][j], f[i - zeroNum][j - oneNum] + 1);
        }
        return f[m][n];
    }
};
// @lc code=end
