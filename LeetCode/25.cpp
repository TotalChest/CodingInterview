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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *K = head;
        for (int i = 0; i < k; ++i)
            if (K)
                K = K->next;
            else
                return head;
        ListNode *tmp = reverseKGroup(K, k);
        ListNode *prev = head, *curr, *next;
        if (prev->next)
            curr = prev->next;
        else 
            return head;
        next = curr->next;    
        int c = 0;
        while (++c < k) {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (curr)
                next = curr->next;
        }
        head->next = tmp;
        return prev;
    }
};
