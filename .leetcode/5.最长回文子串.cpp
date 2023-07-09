/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
// 从下到上，从左到右遍历，与647题相似
// 布尔类型的f[i][j]：表示区间范围[i,j] （注意是左闭右闭）的子串是否是回文子串，如果是f[i][j]为true，否则为false。
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
