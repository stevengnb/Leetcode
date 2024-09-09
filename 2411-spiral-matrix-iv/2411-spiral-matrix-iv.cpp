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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> vect(m, vector<int>(n, -1));
        if(!head) return vect;
        int bound = 0;

        ListNode* curr = head;
        while(curr) {
            for(int i = bound; i < n - bound && curr; i++) {
                vect[bound][i] = curr->val;
                curr = curr->next;
            }

            for(int i = bound + 1; i < m - bound && curr; i++) {
                vect[i][n - bound - 1] = curr->val;
                curr = curr->next;
            }

            for(int i = n - 2 - bound; i >= bound && curr; i--) {
                vect[m - bound - 1][i] = curr->val;
                curr = curr->next;
            }

            for(int i = m - bound - 2; i > bound && curr; i--) {
                vect[i][bound] = curr->val;
                curr = curr->next;
            }   

            bound++;
        }

        return vect;
    }
};