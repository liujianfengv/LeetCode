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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head->next || left == right) {
            return head;
        }
        ListNode *pre_node = new ListNode(0, head);
        ListNode *pre = pre_node;
        ListNode *cur = head;
        
        int dis1 = left;
        int dis2 = right - left;
        while (dis1-- > 1) {
            pre = pre->next;
            cur = cur->next;
        }
        ListNode *leftNode = cur;
        while (dis2-- > 0) {
            cur = cur->next;
        }
        ListNode *rightNode = cur;
        ListNode *last = cur->next;
        reverse(leftNode, rightNode);
        leftNode->next = last;
        pre->next = rightNode;
        ListNode *res = pre_node->next;
        delete pre_node;
        return res;
    }
private:
    void reverse(ListNode *left, ListNode *right) {
        if (left == right) {
            return;
        }
        ListNode *cur = left->next;
        ListNode *pre = left;
        while (cur != right) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        right->next = pre;
    }
};