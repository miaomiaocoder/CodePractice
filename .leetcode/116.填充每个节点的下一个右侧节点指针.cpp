/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
   public:
    Node* connect(Node* root) {
        if (!root) return root;
        Node* cur = root;
        while (cur->left) {
            for (Node* p = cur; p; p = p->next) {
                p->left->next = p->right;
                if (p->next) p->right->next = p->next->left;
            }
            cur = cur->left;
        }
        return root;
    }
};

// 层序遍历
class Solution {
   public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (!root) return root;
        q.push(root);
        while (q.size()) {
            int len = q.size();
            vector<Node*> vec;
            while (len--) {
                Node* t = q.front();
                q.pop();
                vec.push_back(t);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            for (int i = 0; i < vec.size() - 1; i++) vec[i]->next = vec[i + 1];
            vec[vec.size() - 1]->next = nullptr;
        }
        return root;
    }
};
// @lc code=end
