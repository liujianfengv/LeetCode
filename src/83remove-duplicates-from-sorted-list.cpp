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
        if (!head || !head->next) {
            return head;
        }
        ListNode *cur = head;
        while (cur) {
            ListNode *dup = cur->next;
            while (dup && dup->val == cur->val) {
                ListNode *temp = dup;
                dup = dup->next;
                delete temp;
            }
            cur->next = dup;
            cur = cur->next;
        }
        return head;
    }
};