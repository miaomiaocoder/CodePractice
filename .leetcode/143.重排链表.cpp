/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        vector<ListNode*> vec;
        ListNode* cur = head;
        if (!cur) return;
        // 注意这条件是cur
        while (cur != nullptr) {
            vec.emplace_back(cur);
            cur = cur->next;
        }

        int i = 1;
        int j = vec.size() - 1;
        int count = 0;
        cur = head;
        while (i <= j) {
            if (count % 2 == 0) {
                cur->next = vec[j];
                --j;
            } else {
                cur->next = vec[i];
                ++i;
            }
            ++count;
            cur = cur->next;
        }
        // 不要忘记处理末尾
        cur->next = nullptr;
    }
};

class Solution {
   public:
    void reorderList(ListNode* head) {
        deque<ListNode*> deq;
        ListNode* cur = head;
        if (!cur) return;
        // 注意这条件是cur->next
        while (cur->next) {
            deq.emplace_back(cur->next);
            cur = cur->next;
        }
        cur = head;
        int cnt = 0;
        while (deq.size()) {
            if (cnt % 2 == 0) {
                cur->next = deq.back();
                deq.pop_back();
            } else {
                cur->next = deq.front();
                deq.pop_front();
            }
            ++cnt;
            cur = cur->next;
        }
        // 不要忘记处理末尾
        cur->next = nullptr;
    }
};

// 寻找链表中点 + 链表逆序 + 合并链表  O(1)
class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* tail = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;
    }
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow;
        ListNode* cur1 = head;
        ListNode* cur2 = reverseList(mid->next);
        // 注意取反之后这个地方要置为空
        mid->next = nullptr;
        while (cur1 && cur2) {
            ListNode* tmp1 = cur1->next;
            ListNode* tmp2 = cur2->next;

            cur1->next = cur2;
            cur1 = tmp1;

            cur2->next = cur1;
            cur2 = tmp2;
        }
    }
};
// @lc code=end
