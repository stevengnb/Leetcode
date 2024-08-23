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
        int val = l1->val + l2->val;
        int temp = 0;
        int temp2 = 0;
        ListNode *neww = new ListNode(0);
        ListNode *head = neww;

        while(l1 || l2) {
            if(!l1) {
               val = l2->val;
               temp2 = (val+temp) % 10;
            } else if(!l2) {
               val = l1->val;
               temp2 = (val+temp) % 10;
            } else {
               val = l1->val + l2->val;
               temp2 = val % 10;
            }

            if(val >= 10 || val + temp >= 10) {
                neww->next = new ListNode((val-10) + temp);
                temp = 1;
            } else {
                neww->next = new ListNode(val + temp);
                temp = 0;
            }
            neww = neww->next;
            
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        if(temp != 0 && val + temp >= 10) {
            neww->next = new ListNode(temp);
            neww->next->next = NULL;
        } else {
            neww->next = NULL;
        }

        return head->next;
    }
};