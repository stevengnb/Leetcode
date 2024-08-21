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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *neww = new ListNode(-101);
        ListNode *temp = neww;

        if(!list1 && !list2) return list1;
        else if(!list1) return list2;
        else if(!list2) return list1;

        while(list1 || list2) {
            if(!list1) {
                neww->next = list2;
                list2 = list2->next;
            } else if(!list2) {
                neww->next = list1;
                list1 = list1->next;
            } else {
                if(list1->val <= list2->val) {
                    neww->next = list1;
                    list1 = list1->next;
                } else {
                    neww->next = list2;
                    list2 = list2->next;
                }
            }
            neww = neww->next;
        }

        return temp->next;
    }
};