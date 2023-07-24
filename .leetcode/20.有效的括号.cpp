/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
// 最后一定要看看栈是不是空的!!
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
        // 最后一定要看看栈是不是空的
        return stk.empty();
    }
};

class Solution {
   public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                stk.emplace(')');
            else if (s[i] == '{')
                stk.emplace('}');
            else if (s[i] == '[')
                stk.emplace(']');
            else if (stk.size() && s[i] == stk.top())
                stk.pop();
            else
                return false;
        }
        // 最后一定要看看栈是不是空的
        return stk.empty();
    }
};
// @lc code=end
