/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
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
/*
方法1：层序遍历
*/
/*
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int nums = q.size();
            for (int i = 0; i < nums; i++) {
                Node *tmp = q.front();
                q.pop();
                if (i < nums - 1) tmp->next = q.front();
                if (tmp->left != nullptr) q.push(tmp->left);
                if (tmp->right != nullptr) q.push(tmp->right);
            }
            
        }
        return root;
    }
};
*/
/*
方法2：指针映射
 */
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
        if (root == nullptr) return root;

        Node* leftPTR = root;
        while (leftPTR->left != nullptr) {
            Node* head = leftPTR;
            while (head != nullptr) {
                head->left->next = head->right;
                if (head->next != nullptr) {
                    head->right->next = head->next->left;
                }
                head = head->next;
            }
            leftPTR = leftPTR->left;
        }
        return root;
    }
};
// @lc code=end

