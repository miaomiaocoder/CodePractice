/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
    stack<int> x_stk;
    stack<int> min_stk;

   public:
    MinStack() { min_stk.emplace(INT_MAX); }

    void push(int val) {
        x_stk.emplace(val);
        min_stk.emplace(min(min_stk.top(), val));
    }

    void pop() {
        x_stk.pop();
        min_stk.pop();
    }

    int top() { return x_stk.top(); }

    int getMin() { return min_stk.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
