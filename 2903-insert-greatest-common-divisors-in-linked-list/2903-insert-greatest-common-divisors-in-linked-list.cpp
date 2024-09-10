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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head) return head;

        ListNode* curr = head;

        while(curr->next) {
            ListNode* newNode = new ListNode(gcd(curr->val, curr->next->val));
            ListNode* next = curr->next;
            
            curr->next = newNode;
            newNode->next = next;
            curr = next;
        }

        return head;
    }

    int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
};