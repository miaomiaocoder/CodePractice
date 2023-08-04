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

class MyQueue {
   public:
    stack<int> stIn;
    stack<int> stOut;
    /** Initialize your data structure here. */
    MyQueue() {}
    /** Push element x to the back of queue. */
    void push(int x) { stIn.push(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // 只有当stOut为空的时候，再从stIn里导入数据（导入stIn全部数据）
        if (stOut.empty()) {
            // 从stIn导入数据直到stIn为空
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    /** Get the front element. */
    int peek() {
        int res = this->pop();  // 直接使用已有的pop函数
        stOut.push(res);  // 因为pop函数弹出了元素res，所以再添加回去
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() { return stIn.empty() && stOut.empty(); }
};

class MyQueue {
    stack<int> in;
    stack<int> out;

   public:
    MyQueue() {}

    void push(int x) { in.emplace(x); }

    int pop() {
        if (out.empty()) {
            if (!in.empty()) {
                while (!in.empty()) {
                    out.emplace(in.top());
                    in.pop();
                }
            }
        }
        int tmp = out.top();
        out.pop();
        return tmp;
    }

    int peek() {
        if (out.empty()) {
            if (!in.empty()) {
                while (!in.empty()) {
                    out.emplace(in.top());
                    in.pop();
                }
            }
        }
        return out.top();
    }

    bool empty() { return in.empty() && out.empty(); }
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
