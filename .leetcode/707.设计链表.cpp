/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
   public:
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    } * head;

    MyLinkedList() { head = nullptr; }

    int get(int index) {
        if (index < 0) return -1;
        Node* p = head;
        for (int i = 0; i < index && p; i++) p = p->next;
        if (!p) return -1;
        return p->val;
    }

    void addAtHead(int val) {
        Node* cur = new Node(val);
        cur->next = head;
        head = cur;
    }

    void addAtTail(int val) {
        if (!head)
            head = new Node(val);
        else {
            Node* p = head;
            while (p->next) p = p->next;
            p->next = new Node(val);
        }
    }

    void addAtIndex(int index, int val) {
        if (index <= 0)
            addAtHead(val);
        else {
            int len = 0;
            for (Node* p = head; p; p = p->next) len++;
            if (index == len)
                addAtTail(val);
            else if (index < len) {
                Node* p = head;
                for (int i = 0; i < index - 1; i++) p = p->next;
                Node* cur = new Node(val);
                cur->next = p->next;
                p->next = cur;
            }
        }
    }

    void deleteAtIndex(int index) {
        int len = 0;
        for (Node* p = head; p; p = p->next) len++;
        if (index >= 0 && index < len) {
            if (!index)
                head = head->next;
            else {
                Node* p = head;
                for (int i = 0; i < index - 1; i++) p = p->next;
                p->next = p->next->next;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
