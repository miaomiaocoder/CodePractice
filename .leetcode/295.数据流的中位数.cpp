/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
// 下面大顶堆，上面小顶堆。使得大顶堆比小顶堆多一个
class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> up;
    priority_queue<int> down;

   public:
    MedianFinder() {}

    void addNum(int num) {
        if (down.empty() || num < down.top()) {
            down.push(num);
            if (down.size() > up.size() + 1) {
                up.push(down.top());
                down.pop();
            }
        } else {
            up.push(num);
            if (up.size() > down.size()) {
                down.push(up.top());
                up.pop();
            }
        }
    }

    double findMedian() {
        if ((down.size() + up.size()) % 2 != 0)
            return down.top();
        else
            return (down.top() + up.top()) / 2.0;
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
