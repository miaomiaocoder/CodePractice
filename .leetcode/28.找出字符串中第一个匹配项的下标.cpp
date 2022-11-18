/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
   public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        string s = " " + haystack, p = " " + needle;

        vector<int> next(m + 1);
        for (int i = 2, j = 0; i <= m; i++) {
            while (j && p[i] != p[j + 1]) j = next[j];
            if (p[i] == p[j + 1]) j++;
            next[i] = j;
        }

        for (int i = 1, j = 0; i <= n; i++) {
            while (j && s[i] != p[j + 1]) j = next[j];
            if (s[i] == p[j + 1]) j++;
            if (j == m) return i - m;
        }

        return -1;
    }
};
// @lc code=end
