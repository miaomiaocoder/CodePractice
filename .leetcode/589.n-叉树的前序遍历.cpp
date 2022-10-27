/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// 递归法
class Solution {
   public:
    vector<int> res;
    void dfs(Node* root) {
        if (!root) return;
        res.push_back(root->val);
        for (auto& x : root->children) dfs(x);
    }
    vector<int> preorder(Node* root) {
        dfs(root);
        return res;
    }
};

// 迭代法
class Solution {
   public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node*> stk;
        if (!root) return res;
        stk.push(root);
        while (stk.size()) {
            Node* t = stk.top();
            stk.pop();
            res.push_back(t->val);
            for (int i = t->children.size() - 1; i >= 0; i--)
                stk.push(t->children[i]);
        }
        return res;
    }
};
// @lc code=end
