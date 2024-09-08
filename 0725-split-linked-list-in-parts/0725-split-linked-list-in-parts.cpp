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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> vect(k, nullptr);
        if(!head) return vect;

        ListNode* curr = head, *temp = nullptr;
        int total = 0, counter = 0, remainder = 0, average = 0, idx = 0;

        while(curr) {
            total++;
            curr = curr->next;
        }

        remainder = total%k;
        average = total/k;
        curr = head;
        
        while(curr) {
            ListNode* next = curr->next;
            counter++;
            if(counter == 1) vect[idx++] = curr;

            if(remainder > 0 && (counter / (average + 1) == 1)) {
                remainder--;
                counter = 0;
                curr->next = nullptr;
            } else if(remainder == 0 && counter / average == 1) {
                counter = 0;
                curr->next = nullptr;
            }

            curr = next;
        } 

        return vect;
    }
};