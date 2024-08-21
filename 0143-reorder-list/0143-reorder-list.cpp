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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        stack<ListNode*> stack;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while(slow->next && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *temp = slow;
        ListNode *last;

        while(slow->next) {
            slow = slow->next;
            stack.push(slow);
        }

        temp->next = NULL;

        while(head && !stack.empty()) {
            ListNode *realNext = head->next;
            head->next = stack.top();
            stack.pop();
            head->next->next = realNext;
            last = head;
            head = realNext;
        }

        if(last->next && !stack.empty()) {
            last->next->next = stack.top();
            last->next->next->next = NULL;
        }

    }
};