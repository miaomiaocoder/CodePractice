/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// 记录中序遍历上一个节点值
class Solution {
   public:
    int ans = INT_MAX;
    int last;
    bool isFirst = true;

    void dfs(TreeNode* root) {
        if (!root) return;

        dfs(root->left);
        if (isFirst)
            isFirst = false;
        else
            ans = min(ans, abs(root->val - last));
        last = root->val;
        dfs(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

// 中序遍历
class Solution {
   public:
    vector<int> res;
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        int ans = abs(res[0] - res[1]);
        for (int i = 1; i < res.size() - 1; i++)
            ans = min(ans, abs(res[i] - res[i + 1]));
        return ans;
    }
};
// @lc code=end
