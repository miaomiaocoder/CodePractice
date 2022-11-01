/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
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
class Solution {
   public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> q;
        if (!root) return res;
        q.push(root);
        while (q.size()) {
            int len = q.size();
            vector<int> vec;
            while (len--) {
                Node* t = q.front();
                q.pop();
                vec.push_back(t->val);
                for (auto& x : t->children) q.push(x);
            }
            res.push_back(vec);
        }
        return res;
    }
};
// @lc code=end
