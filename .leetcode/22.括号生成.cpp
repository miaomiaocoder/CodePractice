/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
// 括号序列两个条件(充分必要条件)
// 1. 任意前缀中左括号数量大于等于右括号数量
// 2. 左括号数量等于右括号数量
class Solution {
    vector<string> ans;

   public:
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return ans;
    }

    void dfs(int n, int lCount, int rCount, string seq) {
        if (lCount == n && rCount == n)
            ans.emplace_back(seq);
        else {
            if (lCount < n) dfs(n, lCount + 1, rCount, seq + '(');
            if (rCount < n && rCount < lCount)
                dfs(n, lCount, rCount + 1, seq + ')');
        }
    }
};

class Solution {
    vector<string> res;
    void dfs(int n, int l, int r, string seq) {
        if (n == l && n == r) res.emplace_back(seq);
        if (l < n) dfs(n, l + 1, r, seq + "(");
        if (r < n && r < l) dfs(n, l, r + 1, seq + ")");
    }

   public:
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return res;
    }
};
// @lc code=end
