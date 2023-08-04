/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
   public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
        string res = "";
        while (i >= 0 || j >= 0 || add != 0) {
            int x = 0, y = 0;
            if (i >= 0) x = num1[i] - '0';
            if (j >= 0) y = num2[j] - '0';
            int tmp = x + y + add;
            res += '0' + tmp % 10;
            add = tmp / 10;
            i -= 1;
            j -= 1;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1;
        int t = 0;
        string res = "";
        while (i >= 0 || j >= 0 || t > 0) {
            int a = 0, b = 0;
            if (i >= 0) a = num1[i] - '0';
            if (j >= 0) b = num2[j] - '0';
            int num = a + b + t;
            t = num / 10; 
            res += to_string(num % 10);
            --i;
            --j;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
