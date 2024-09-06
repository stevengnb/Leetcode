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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* newHead = new ListNode(0);
        ListNode* curr = newHead;
        unordered_set<int> set{nums.begin(), nums.end()};;

        while(head) {
            if(!(set.find(head->val) != set.end())) {
                curr->next = new ListNode(head->val);
                curr = curr->next;
            }
            head = head->next;
        }
    
        return newHead->next;
    }
};