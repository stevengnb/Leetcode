/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;

        ListNode *curr1 = head;
        ListNode *curr2 = head->next;

        while(curr1->next && curr2->next && curr2->next->next) {
            if(curr1 == curr2) {
                return true;
            }

            curr1 = curr1->next;
            curr2 = curr2->next->next;
        }

        return false;
    }
};