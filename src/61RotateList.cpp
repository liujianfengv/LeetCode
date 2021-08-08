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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || !head) {
            return head;
        }
        int length = 0;
        ListNode **cur = &head;
        while (*cur) {
            cur = (&(*cur)->next);
            length++;
        }
        (*cur) = head;
        int distance = length - (k % length);
        cur = &head;
        while (distance-- > 0) {
            cur = (&(*cur)->next);
        }
        ListNode *res = *cur;
        *cur = nullptr;
        return res;
    }
};