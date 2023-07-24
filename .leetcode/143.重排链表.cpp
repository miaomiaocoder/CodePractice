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
// @lc code=end
