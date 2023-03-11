/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> res(temperatures.size(), 0);
        stk.push(0);
        for (int i = 1; i < temperatures.size(); ++i) {
            if (temperatures[i] < temperatures[stk.top()]) {
                stk.push(i);
            } else if (temperatures[i] == temperatures[stk.top()]) {
                stk.push(i);
            } else {
                while (!stk.empty() &&
                       temperatures[i] > temperatures[stk.top()]) {
                    res[stk.top()] = i - stk.top();
                    stk.pop();
                }
                stk.push(i);
            }
        }
        return res;
    }
};

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> res(temperatures.size(), 0);
        stk.push(0);
        for (int i = 1; i < res.size(); ++i) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                res[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};
// @lc code=end
