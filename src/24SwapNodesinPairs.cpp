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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *cur = head;
        ListNode *res;
        ListNode **newList = &res;
        while (head && head->next) {
            *newList = new ListNode(head->next->val);
            (*newList)-> next = new ListNode(head->val);
            newList = &((*newList)->next->next);
            head = head->next->next;
        }
        if (head) {
            *newList = new ListNode(head->val);
        }
        return res;
    }
};