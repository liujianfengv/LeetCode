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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 != nullptr) {
            return l2;
        } else if (l1 != nullptr && l2 == nullptr) {
            return l1;
        } else if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }
        ListNode *result = new ListNode();
        ListNode *current = result;
        ListNode *previous;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                current->val = l1->val;
                l1 = l1->next;
            } else {
                current->val = l2->val;
                l2 = l2->next;
            }
            current->next = new ListNode();
            previous = current;
            current = current->next;
        }
        if (l1 == nullptr) {
            previous->next = l2;
        } else {
            previous->next = l1;
        }
        return result;
    }
};