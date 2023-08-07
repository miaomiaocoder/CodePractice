/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
class Solution {
   public:
    ListNode* sortList(ListNode* head) {
        int n = 0;
        for (auto p = head; p; p = p->next) n++;

        for (int i = 1; i < n; i *= 2) {
            auto dummy = new ListNode(-1), cur = dummy;
            for (int j = 1; j <= n; j += i * 2) {
                auto p = head, q = p;
                for (int k = 0; k < i && q; k++) q = q->next;
                auto o = q;
                for (int k = 0; k < i && o; k++) o = o->next;
                int l = 0, r = 0;
                while (l < i && r < i && p && q) {
                    if (p->val < q->val)
                        cur = cur->next = p, p = p->next, l++;
                    else
                        cur = cur->next = q, q = q->next, r++;
                }
                while (l < i && p) cur = cur->next = p, p = p->next, l++;
                while (r < i && q) cur = cur->next = q, q = q->next, r++;
                head = o;
            }
            cur->next = nullptr;
            head = dummy->next;
        }

        return head;
    }
};

class Solution {
   public:
    ListNode* sortList(ListNode* head) {
        int n = 0;
        for (auto p = head; p; p = p->next) ++n;

        for (int i = 1; i <= n; i *= 2) {
            auto dummy = new ListNode(-1), cur = dummy;
            for (int j = 1; j <= n; j += i * 2) {
                auto p = head, q = p;
                for (int k = 0; k < i && q; ++k) q = q->next;
                auto o = q;
                for (int k = 0; k < i && o; ++k) o = o->next;
                int l = 0, r = 0;
                while (l < i && r < i && p && q) {
                    if (p->val < q->val)
                        cur = cur->next = p, p = p->next, ++l;
                    else
                        cur = cur->next = q, q = q->next, ++r;
                }
                while (l < i && p) cur = cur->next = p, p = p->next, ++l;
                while (r < i && q) cur = cur->next = q, q = q->next, ++r;
                head = o;
            }
            cur->next = nullptr;
            head = dummy->next;
        }
        return head;
    }
};

// @lc code=end
