/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
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
// 递归
class Solution {
   public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        int res = 0;
        for (auto& x : root->children) res = max(res, maxDepth(x));
        return res + 1;
    }
};

// dfs
class Solution {
   public:
    int maxd = 0;
    void dfs(Node* root, int d) {
        if (!root) return;
        maxd = max(maxd, d);
        for (auto& x : root->children) dfs(x, d + 1);
    }
    int maxDepth(Node* root) {
        dfs(root, 1);
        return maxd;
    }
};

// 层序遍历
class Solution {
   public:
    int maxDepth(Node* root) {
        int d = 0;
        queue<Node*> q;
        if (!root) return 0;
        q.push(root);
        while (q.size()) {
            int len = q.size();
            d++;
            while (len--) {
                Node* t = q.front();
                q.pop();
                for (auto& x : t->children) q.push(x);
            }
        }
        return d;
    }
};
// @lc code=end
