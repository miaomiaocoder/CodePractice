/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
   public:
    string decodeString(string s) {
        // 两个栈来保存，类似实现分配率计算器
        string res = "";
        stack<int> nums;
        stack<string> strs;
        int num = 0;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                // 有可能为三位数字
                num = num * 10 + s[i] - '0';
            }  // 将‘[’前的数字压入nums栈内，字母字符串压入strs栈内
            else if (s[i] == '[') {
                nums.emplace(num);
                // 注意清空num临时变量
                num = 0;
                strs.emplace(res);
                // 注意清空字符串临时变量
                res = "";
            }  // 遇到‘]’时，操作与之相配的‘[’之间的字符，使用分配律
            else if (s[i] == ']') {
                int times = nums.top();
                // 保存数字的次数也要出栈
                nums.pop();
                // 这里循环添加k次
                for (int j = 0; j < times; ++j) strs.top() += res;
                // 之后若还是字母，就会直接加到res之后，因为它们是同一级的运算
                // 若是左括号，res会被压入strs栈，作为上一层的运算
                res = strs.top();
                // 字符已经被循环加过了，要出栈
                strs.pop();
            } else {
                res += s[i];
            }
        }
        return res;
    }
};
// @lc code=end
