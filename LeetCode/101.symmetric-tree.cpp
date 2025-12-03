/*
 * @Author: OBKoro1
 * @Date: 2025-12-03 18:20:47
 * @FilePath: \LeetCode\101.symmetric-tree.cpp
 * @Description: 
 */
/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
/*
方法1：递归
*/
/*
class Solution {
public:
    bool check(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && check(p->left, q->right) && check(q->left, p->right);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};
*/

/*
方法2：迭代
*/
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
    bool check(TreeNode* left, TreeNode* right) {
        queue<TreeNode*> q;
        q.push(left);
        q.push(right);
        while (!q.empty()) {
            left = q.front();
            q.pop();
            right = q.front();
            q.pop();
            if (!left && !right) continue;
            if ((!left || !right) || (left->val != right->val)) return false;
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};
// @lc code=end

