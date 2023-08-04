/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
// 与25题处理类似，引入头节点可以给解决问题带来方便
class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* l = head;
        ListNode *dummy = new ListNode(-1), *p = dummy;
        dummy->next = head;
        for (int i = 0; i < left - 1; ++i) p = p->next, l = l->next;
        ListNode *a = l, *b = l->next;
        for (int i = 0; i < right - left; ++i) {
            ListNode* tmp = b->next;
            b->next = a;
            a = b;
            b = tmp;
        }
        auto c = p->next;
        c->next = b;
        p->next = a;
        return dummy->next;
    }
};
// @lc code=end
