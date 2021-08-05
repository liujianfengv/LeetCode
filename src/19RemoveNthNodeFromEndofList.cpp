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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        ListNode **slow = &head;
        while (n-- > 0) {
            fast = fast->next;
        }
        if (!fast) {
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        while (fast) {
            fast = fast->next;
            slow = &((*slow)->next);
        }
        ListNode *temp = *slow;
        *slow = (*slow)->next;
        delete temp;
        return head;
    }
};