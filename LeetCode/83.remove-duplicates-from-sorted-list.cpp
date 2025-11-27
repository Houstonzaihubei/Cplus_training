/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* root = head;
        ListNode* tmp = nullptr;
        while (head != nullptr && head->next != nullptr) {
            tmp = head->next;
            if (head->val == tmp->val) {
                head->next = head->next->next;
            } else {
                head = head->next;
            }
        }
        return root;
    }
};
// @lc code=end

