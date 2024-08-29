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
        ListNode *copy = nullptr;
        if(lists.empty()) return copy;

        ListNode* temp;
        copy = lists[0];
        ListNode *curr = copy;

        for(int i = 1; i < lists.size(); i++) {
            if(!lists[i]) continue;
            ListNode* newHead = new ListNode(0);
            ListNode* copy2 = newHead;
            ListNode *testingCurr;

            ListNode *curr2 = lists[i];
            // cout << "LOOP KE - " << i << endl;
            // cout << "CURR" << endl;
            // testingCurr = curr;
            // while(testingCurr) {
            //     cout << testingCurr->val << "->";
            //     testingCurr = testingCurr->next;
            // }
            // cout << endl;

            // cout << "CURR2" << endl;
            // testingCurr = curr2;
            // while(testingCurr) {
            //     cout << testingCurr->val << "->";
            //     testingCurr = testingCurr->next;
            // }
            // cout << endl;

            while(curr && curr2) {
                // cout << "curr val = " << curr->val  << ", curr2 val = " << curr2->val << endl;

                if(curr->val > curr2->val) {
                    newHead->next = curr2;
                    newHead = newHead->next;
                    curr2 = curr2->next;
                } else {
                    newHead->next = curr;
                    newHead = newHead->next;
                    curr = curr->next;
                }
            }

            while(curr) {
                newHead->next = curr;
                newHead = newHead->next;
                curr = curr->next;
            }

            while(curr2) {
                newHead->next = curr2;
                newHead = newHead->next;
                curr2 = curr2->next;
            }

            // cout << "NEWHEAD" << endl;
            // testingCurr = copy2;
            // while(testingCurr) {
            //     cout << testingCurr->val << "->";
            //     testingCurr = testingCurr->next;
            // }
            // cout << endl;

            curr = copy2->next;
            temp = copy2->next;
        }

        if(temp) return temp;
        else return lists[0];
    }
};