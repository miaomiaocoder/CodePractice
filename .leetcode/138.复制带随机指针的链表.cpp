/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
   public:
    Node* copyRandomList(Node* head) {
        // 复制一个小弟
        for (auto p = head; p; p = p->next->next) {
            auto q = new Node(p->val);
            q->next = p->next;
            p->next = q;
        }

        // 复制random指针
        for (auto p = head; p; p = p->next->next)
            if (p->random) p->next->random = p->random->next;

        // 拆分两个链表
        auto dummy = new Node(-1), cur = dummy;
        for (auto p = head; p; p = p->next) {
            auto q = p->next;
            cur = cur->next = q;
            p->next = q->next;
        }
        return dummy->next;
    }
};
// @lc code=end
