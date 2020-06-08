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
        ListNode *answer = nullptr, *curr = nullptr;
        while (l1 != nullptr || l2 != nullptr) {
            int val_1 = l1 == nullptr ? 10000000 : l1->val;
            int val_2 = l2 == nullptr ? 10000000 : l2->val;
            if (val_1 < val_2) {
                if (answer == nullptr) {
                    answer = l1;
                    curr = l1;
                     l1 = l1->next;
                }
                else {
                    curr->next = l1;
                    curr = curr->next;
                    l1 = l1->next;
                }
            }
            else {
                if (answer == nullptr) {
                    answer = l2;
                    curr = l2;
                     l2 = l2->next;
                }
                else {
                    curr->next = l2;
                    curr = curr->next;
                    l2 = l2->next;
                }
            }
        }
        return answer;
    }
};
