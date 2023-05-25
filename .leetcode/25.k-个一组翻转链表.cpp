/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        for (auto p = dummy;;) {
            auto cur = p->next;
            for (int i = 0; i < k - 1 && cur; ++i) cur = cur->next;
            if (!cur) break;
            auto a = p->next, b = p->next->next;
            for (int i = 0; i < k - 1; ++i) {
                auto temp = b->next;
                b->next = a;
                a = b, b = temp;
            }
            auto c = p->next;
            p->next = a;
            c->next = b;
            p = c;
        }
        return dummy->next;
    }
};
// @lc code=end
