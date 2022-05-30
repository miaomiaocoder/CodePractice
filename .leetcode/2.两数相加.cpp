/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* l3 = new ListNode(0);
        ListNode* r = l3;
        int carry = 0;
        int sum = 0;
        while(p!=nullptr || q!=nullptr){
            int x = 0;
            int y = 0;
            x = (p?p->val:0);
            y = (q?q->val:0);
            sum = x + y + carry;
            carry = sum/10;
            r->next = new ListNode(sum%10);
            r = r->next;
            if(q)q = q->next;
            if(p)p = p->next;
        }
        if(carry > 0){
            r->next = new ListNode(carry);
            r = r->next;
        }
        return l3->next;
    }
};
// @lc code=end

