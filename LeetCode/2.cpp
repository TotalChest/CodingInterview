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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum, overflow = 0;
        ListNode *answer = nullptr, *curr = nullptr;
        while (l1 != nullptr && l2 != nullptr) {
            sum = l1->val + l2->val + overflow;
            if (sum >= 10) {
                overflow = 1;
                sum = sum - 10;
            }
            else
                overflow = 0;
            if (answer == nullptr) {
                answer = new ListNode(sum);
                curr = answer;
            }
            else {
                ListNode* tmp = new ListNode(sum);
                curr->next = tmp;
                curr = curr->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
            sum = l1->val + overflow;
             if (sum >= 10) {
                overflow = 1;
                sum = sum - 10;
            }
            else
                overflow = 0;
            ListNode* tmp = new ListNode(sum);
            curr->next = tmp;
            curr = curr->next;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            sum = l2->val + overflow;
             if (sum >= 10) {
                overflow = 1;
                sum = sum - 10;
            }
            else
                overflow = 0;
            ListNode* tmp = new ListNode(sum);
            curr->next = tmp;
            curr = curr->next;
            l2 = l2->next;
        } 
        if (overflow != 0) {
            ListNode* tmp = new ListNode(overflow);
            curr->next = tmp;
            curr = curr->next;
        }
        return answer;
    }
};