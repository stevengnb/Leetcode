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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* curr = NULL;
        ListNode* curr2;


        while(head->next) {
            ListNode* next = head->next;
            head->next = curr;
            curr = head;
            curr2 = head;
            head = next;
        }

        head->next = curr;

        return head;
    }
};