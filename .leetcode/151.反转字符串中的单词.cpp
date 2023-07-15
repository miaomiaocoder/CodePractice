/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
// 先反转单词，再反转整个字符串，注意要消除空格
class Solution {
   public:
    string reverseWords(string s) {
        int k = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') continue;
            int j = i, t = k;
            while (j < s.size() && s[j] != ' ') s[t++] = s[j++];
            reverse(s.begin() + k, s.begin() + t);
            s[t++] = ' ';
            k = t, i = j;
        }
        // 消除多余的空格
        if (k) --k;
        s.erase(s.begin() + k, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
// @lc code=end
