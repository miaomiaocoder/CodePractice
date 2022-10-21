/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
   public:
    stack<int> a, b;
    MyQueue() {}

    void push(int x) { a.push(x); }

    int pop() {
        while (a.size() > 1) b.push(a.top()), a.pop();
        int t = a.top();
        a.pop();
        while (b.size() > 0) a.push(b.top()), b.pop();
        return t;
    }

    int peek() {
        while (a.size() > 1) b.push(a.top()), a.pop();
        int t = a.top();
        while (b.size() > 0) a.push(b.top()), b.pop();
        return t;
    }

    bool empty() { return a.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
