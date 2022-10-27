/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
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
        for (auto& x : root->children) dfs(x);
        res.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        dfs(root);
        return res;
    }
};

// 迭代法
class Solution {
   public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<Node*> stk;
        if (!root) return res;
        stk.push(root);
        while (stk.size()) {
            Node* t = stk.top();
            stk.pop();
            res.push_back(t->val);
            for (auto& x : t->children) stk.push(x);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
