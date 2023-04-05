/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
   public:
    string longestPalindrome(string s) {
        vector<vector<int>> f(s.size(), vector<int>(s.size(), 0));
        int maxlenth = 0;
        int left = 0, right = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (s[i] == s[j] && (j - i <= 1 || f[i + 1][j - 1])) {
                    f[i][j] = 1;
                }
                if (f[i][j] && j - i + 1 > maxlenth) {
                    maxlenth = j - i + 1;
                    left = i;
                    right = j;
                }
            }
        }
        return s.substr(left, right - left + 1);
    }
};
// @lc code=end
