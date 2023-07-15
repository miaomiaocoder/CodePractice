/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
   public:
    bool isPalindrome(string s) {
        string news;
        for (char c : s) {
            if (isalnum(c)) news += tolower(c);
        }
        int l = 0, r = news.size() - 1;
        while (l < r) {
            if (news[l] != news[r]) return false;
            ++l;
            --r;
        }
        return true;
    }
};
// @lc code=end
