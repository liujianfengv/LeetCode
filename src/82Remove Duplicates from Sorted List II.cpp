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
        if(!head || !head->next) {
            return head;
        }
        ListNode *pre = new ListNode(-101, head);
        ListNode **cur = &pre;
        while ((*cur) && (*cur)->next) {
            if ((*cur)->val != (*cur)->next->val) {
                cur = &((*cur)->next);
            } else {
                ListNode *target = (*cur)->next;
                int v = target->val;
                while (target && v == target->val) {
                    ListNode* temp = target;
                    target = target->next;
                    delete temp;
                }
                (*cur) = target;
            }
        }
        ListNode *res = pre->next;
        delete pre;
        return res;
    }
};