/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        while (p != q) {
            p = p ? p->next : headB;
            q = q ? q->next : headA;
        }
        return p;
    }
};

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        while (p != q) {
            if (p)
                p = p->next;
            else
                p = headB;

            if (q)
                q = q->next;
            else
                q = headA;
        }
        return p;
    }
};

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *cur1 = headA, *cur2 = headB;
        while (cur1 && cur2) {
            if (cur1 == cur2) return cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;
            if (cur1 == cur2) return cur1;
            if (!cur1) cur1 = headB;
            if (!cur2) cur2 = headA;
        }
        return nullptr;
    }
};
// @lc code=end
