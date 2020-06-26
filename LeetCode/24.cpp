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
        ListNode* answer = new ListNode(0, head);
        ListNode* curr = answer;
        while (curr->next != nullptr && curr->next->next != nullptr) {
            ListNode* tmp_1 = curr->next;
            ListNode* tmp_2 = curr->next->next->next;
            curr->next = curr->next->next;
            curr->next->next = tmp_1;
            tmp_1->next = tmp_2;
            curr = curr->next->next;
        }
        ListNode* tmp = answer;
        answer = answer->next;
        delete tmp;
        return answer;
    }
};
