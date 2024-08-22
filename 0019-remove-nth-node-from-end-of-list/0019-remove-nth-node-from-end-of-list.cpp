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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;
        ListNode *temp;

        for(int i = 0; i < n-1; i++) {
            if(fast->next) fast = fast->next;
        }

        while(fast->next) {
            prev = slow;
            fast = fast->next;
            slow = slow->next;
        }

        // if(prev) cout << "rpev = " << prev->val << endl;
        // cout << "fast = " << fast->val << endl;
        // cout << "slow = " << slow->val << endl;

        if(prev) {
            // cout << "prev->next = " << prev->next->val << endl;
            // if(slow->next) cout << "slow->next = " << slow->next->val << endl;
            // cout << "head = " << head->val << endl;
            prev->next = slow->next;
            slow->next = NULL;
        } else {
            if(slow->next) head = slow->next;
            else return NULL;
        }

        return head;
    }
};