/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
   public:
    int countSubstrings(string s) {
        vector<vector<int>> f(s.size(), vector<int>(s.size(), 0));
        int res = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        res++;
                        f[i][j] = 1;
                    } else if (f[i + 1][j - 1] == 1) {
                        res++;
                        f[i][j] = 1;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
