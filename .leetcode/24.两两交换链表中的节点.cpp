/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// 递归法
class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* tail = swapPairs(b->next);
        a->next = tail;
        b->next = a;
        return b;
    }
};

// 迭代法
class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        for (ListNode* p = dummy; p->next && p->next->next;) {
            ListNode* a = p->next;
            ListNode* b = p->next->next;
            p->next = b;  // 这一步很关键
            a->next = b->next;
            b->next = a;
            p = a;
        }
        return dummy->next;
    }
};
// @lc code=end
