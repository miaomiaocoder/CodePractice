/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
   public:
    string reverseWords(string s) {
        int k = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            int j = i, t = k;
            while (j < s.size() && s[j] != ' ') s[t++] = s[j++];
            reverse(s.begin() + k, s.begin() + t);
            s[t++] = ' ';
            k = t, i = j;
        }
        if (k) k--;
        s.erase(s.begin() + k, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
// @lc code=end
