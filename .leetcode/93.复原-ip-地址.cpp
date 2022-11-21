/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
   private:
    vector<string> res;

    void dfs(const string& s, int start, int num, string path) {
        if (start == s.size()) {
            if (num == 4) {
                path.pop_back();
                res.emplace_back(path);
            }
            return;
        }
        if (num == 4) return;

        for (int i = start, t = 0; i < s.size(); i++) {
            if (i > start && s[start] == '0') break;  // 有前导0
            t = t * 10 + s[i] - '0';
            if (t <= 255)
                dfs(s, i + 1, num + 1, path + to_string(t) + '.');
            else
                break;
        }
    }

   public:
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0, "");
        return res;
    }
};
// @lc code=end
