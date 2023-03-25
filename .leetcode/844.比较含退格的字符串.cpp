/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
   public:
    string get(string& s) const {
        string res;
        for (int i = 0; i <= s.length(); i++) {
            if (s[i] == '#') {
                if (res.size()) res.pop_back();
            } else
                res += s[i];
        }
        return res;
    }
    bool backspaceCompare(string s, string t) { return get(s) == get(t); }
};
// @lc code=end
