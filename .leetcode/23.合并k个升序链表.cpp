/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    struct Cmp {
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };

   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> heap;
        for (auto l : lists)
            if (l) heap.emplace(l);
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            cur = cur->next = t;
            if (t->next) heap.emplace(t->next);
        }
        return dummy->next;
    }
};
// @lc code=end
