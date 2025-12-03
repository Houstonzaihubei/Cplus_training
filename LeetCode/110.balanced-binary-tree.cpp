/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if (leftHeight - rightHeight > 1 || rightHeight - leftHeight > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
// @lc code=end

