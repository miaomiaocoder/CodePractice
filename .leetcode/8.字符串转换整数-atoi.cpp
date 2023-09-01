/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
   public:
    int myAtoi(string s) {
        int res = 0;
        int i = 0;
        int flag = 1;
        // 处理空格
        while (s[i] == ' ') ++i;
        // 处理符号
        if (s[i] == '-') flag = -1;
        if (s[i] == '+' || s[i] == '-') ++i;
        while (i < s.size() && isdigit(s[i])) {
            int r = s[i] - '0';
            // 处理溢出，INT_MAX == 2147483647
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7))
                return flag > 0 ? INT_MAX : INT_MIN;
            res = res * 10 + r;
            ++i;
        }
        return flag > 0 ? res : -res;
    }
};

// 这个解法有问题，32位环境
class Solution {
   public:
    int myAtoi(string s) {
        long long res = 0;
        int i = 0;
        int flag = 1;
        while (s[i] == ' ') ++i;
        if (s[i] == '-') flag = -1;
        if (s[i] == '+' || s[i] == '-') ++i;
        while (i < s.size() && isdigit(s[i])) {
            int r = s[i] - '0';
            res = res * 10 + r;
            ++i;
            if (res > INT_MAX) return flag > 0 ? INT_MAX : INT_MIN;
        }
        return flag > 0 ? res : -res;
    }
};
// @lc code=end
