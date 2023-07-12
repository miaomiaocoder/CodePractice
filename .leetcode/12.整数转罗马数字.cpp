/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
   public:
    string intToRoman(int num) {
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50,
                              40,   10,  9,   5,   4,   1};
        vector<string> rom = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                              "XL", "X",  "IX", "V",  "IV", "I"};

        string res = "";

        for (int i = 0; i < 13; ++i) {
            while (num >= values[i]) {
                res += rom[i];
                num -= values[i];
            }
        }

        return res;
    }
};
// @lc code=end
