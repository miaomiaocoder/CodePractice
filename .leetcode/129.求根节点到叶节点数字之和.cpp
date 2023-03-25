/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
class Solution {
   private:
    int res;
    vector<int> path;
    int vectorToInt(vector<int>& vec) {
        int sum = 0;
        for (int i = 0; i < vec.size(); ++i) {
            sum = sum * 10 + path[i];
        }
        return sum;
    }
    void tranversal(TreeNode* cur) {
        if (!cur->left && !cur->right) {
            res += vectorToInt(path);
            return;
        }

        if (cur->left) {
            path.emplace_back(cur->left->val);
            tranversal(cur->left);
            path.pop_back();
        }
        if (cur->right) {
            path.emplace_back(cur->right->val);
            tranversal(cur->right);
            path.pop_back();
        }
    }

   public:
    int sumNumbers(TreeNode* root) {
        path.clear();
        path.emplace_back(root->val);
        tranversal(root);
        return res;
    }
};
// @lc code=end
