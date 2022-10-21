/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
   public:
    bool isValid(string s) {
        stack<int> stk;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '(')
                stk.push(')');
            else if (s[i] == '{')
                stk.push('}');
            else if (s[i] == '[')
                stk.push(']');
            else if (stk.empty() || stk.top() != s[i])
                return false;
            else
                stk.pop();

        return stk.empty();
    }
};
// @lc code=end
