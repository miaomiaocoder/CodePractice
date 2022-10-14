/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
// 使用c++库函数
class Solution {
   public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k)
            if (i + k <= s.size())
                reverse(s.begin() + i, s.begin() + i + k);
            else
                reverse(s.begin() + i, s.end());
        return s;
    }
};

// 使用c++库函数
class Solution {
   public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            // s.size() 返回的是无符号数，调用 min()
            // 进行比较时需要转换为有符号数
            int l = i, r = min(i + k, (int)s.size());
            reverse(s.begin() + l, s.begin() + r);
        }
        return s;
    }
};

// 自己实现reverse函数
class Solution {
   public:
    void reverseString(string &s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) swap(s[i], s[j]);
    }
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k))
            if (i + k <= s.size())
                reverseString(s, i, i + k - 1);
            else
                reverseString(s, i, s.size() - 1);
        return s;
    }
};
// @lc code=end
