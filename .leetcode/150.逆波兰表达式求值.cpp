/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
   public:
    stack<long long> stk;
    void eval(string s) {  //用当前运算符算序列最后两个的值
        long long b = stk.top();
        stk.pop();
        long long a = stk.top();
        stk.pop();
        if (s == "+")
            stk.push(a + b);
        else if (s == "-")
            stk.push(a - b);
        else if (s == "*")
            stk.push(a * b);
        else
            stk.push(a / b);
    }
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> S{"+", "-", "*", "/"};
        for (auto& s : tokens)  //枚举所有表达式
            if (S.count(s))
                eval(s);  //当前表达式是运算符，调用eval函数
            else
                stk.push(stoi(s));  //当前数字插入栈里
        return stk.top();           //栈顶元素是最终结果
    }
};
// @lc code=end
