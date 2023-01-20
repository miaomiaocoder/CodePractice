/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution {
   public:
    int monotoneIncreasingDigits(int n) {
        string str = to_string(n);
        int k = 0;
        while (k < str.size() && str[k] <= str[k + 1]) k++;
        if (k == str.size() - 1) return n;
        while (k && str[k] == str[k - 1]) k--;
        str[k]--;
        for (int i = k + 1; i < str.size(); i++) str[i] = '9';
        return stoi(str);
    }
};
// @lc code=end
