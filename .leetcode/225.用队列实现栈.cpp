/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
   public:
    queue<int> q, w;
    MyStack() {}

    void push(int x) { q.push(x); }

    int pop() {
        while (q.size() > 1) w.push(q.front()), q.pop();
        int t = q.front();
        q.pop();
        while (w.size()) q.push(w.front()), w.pop();
        return t;
    }

    int top() {
        while (q.size() > 1) w.push(q.front()), q.pop();
        int t = q.front();
        q.pop();
        while (w.size()) q.push(w.front()), w.pop();
        q.push(t);
        return t;
    }

    bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
