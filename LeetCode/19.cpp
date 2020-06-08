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
        ListNode *first = head, *second = head;
        for (int i = 0; i < n; ++i)
            second = second->next;
        if (second == nullptr) {
            ListNode *tmp = head->next;
            delete head;
            return tmp;
        }
        while (second->next != nullptr) {
            second = second->next;
            first = first->next;
        }
        ListNode *tmp = first->next;
        first->next = first->next->next;
        delete tmp;
        return head;
    }
};
