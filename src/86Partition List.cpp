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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *pre_node = new ListNode(-101, head);
        ListNode **less = &(pre_node->next);
        ListNode *pre_greater = new ListNode ();
        ListNode *greater = pre_greater;
        
        while ((*less)) {
            if ((*less)->val >= x) {
                greater->next = *less;
                greater = greater->next;
                *less = (*less)->next;
            } else {
                less = &((*less))->next;
            }
        }
        greater->next = nullptr;
        *less = pre_greater->next;
        delete pre_greater;
        ListNode * res = pre_node->next;
        delete pre_node;
        return res;
    } 
};