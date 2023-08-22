/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
// substr 如果长度越界那么会被自动截断。
class Solution {
   public:
    int compareVersion(string version1, string version2) {
        for (int i = 0, j = 0; i < version1.size() || j < version2.size();) {
            int a = i, b = j;
            while (a < version1.size() && version1[a] != '.') ++a;
            while (b < version2.size() && version2[b] != '.') ++b;
            int x = a == i ? 0 : stoi(version1.substr(i, a - i));
            int y = b == j ? 0 : stoi(version2.substr(j, b - j));
            if (x > y) return 1;
            if (x < y) return -1;
            i = a + 1, j = b + 1;
        }
        return 0;
    }
};
// @lc code=end
