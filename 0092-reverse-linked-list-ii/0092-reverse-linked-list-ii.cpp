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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || (left == right)) return head;

        ListNode *tempFirst = nullptr, *tempLast, *temp = head, *curr, *prev;
        int idx = 1;

        while(head && idx <= right) {
            ListNode* next = head->next;
            if(idx+1 == left) tempFirst = head;

            if(idx == left) {
                curr = head->next;
                prev = head; 
                tempLast = prev;
            } else if(idx > left) {
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            idx++;
            head = next;
        }

        tempLast->next = curr; 
        if(tempFirst) {
            tempFirst->next = prev;
            return temp;
        }

        return prev;
    }
};