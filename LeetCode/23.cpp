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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *answer = nullptr, *curr = nullptr;
        multiset<pair<int, ListNode*>> SET;
        int k = lists.size();
        for (int i = 0; i < k; ++i)
            if (lists[i] != nullptr)
                SET.insert(make_pair(lists[i]->val, lists[i]));
        while (!SET.empty()) {
            auto tmp = *(SET.begin());
            SET.erase(SET.begin());
            if (tmp.second->next != nullptr)
                SET.insert(make_pair(tmp.second->next->val, tmp.second->next));
            if (answer == nullptr) {
                answer = tmp.second;
                curr = answer;
            }            
            else {
                curr->next = tmp.second;
                curr = curr->next;
            }
        }
        return answer;
    }
};
