/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] N 字形变换
 */

// @lc code=start
// https://leetcode.cn/problems/zigzag-conversion/solution/zzi-xing-bian-huan-by-jyd/
class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;  // 给定行数为 1 时结果与原字符串一样
        vector<string> res(numRows);  // 创建 res 保存每行结果
        int i = 0;                    // 行数标志
        int flag = -1;                // 往上走还是往下走的标志
        for (char &c : s) {           // 遍历 s
            res[i] += c;
            if (i == 0 || i == numRows - 1) {  // 行首行尾变向
                flag = -flag;
            }
            i += flag;
        }
        for (int i = 1; i < numRows; i++) {  // 将每行接起来就是结果
            res[0] += res[i];
        }
        return res[0];
    }
};

class Solution {
   public:
    string convert(string s, int numRows) {
        string res;
        int n = numRows;
        if (n == 1) return s;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || i == n - 1) {
                for (int j = i; j < s.size(); j += 2 * n - 2) res += s[j];
            } else {
                for (int j = i, k = 2 * n - 2 - i; j < s.size() || k < s.size();
                     j += 2 * n - 2, k += 2 * n - 2) {
                    if (j < s.size()) res += s[j];
                    if (k < s.size()) res += s[k];
                }
            }
        }
        return res;
    }
};
// @lc code=end
