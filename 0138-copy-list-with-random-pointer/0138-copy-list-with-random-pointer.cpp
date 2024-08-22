/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;

        Node *newHead = new Node(head->val);
        Node *temp = newHead;

        unordered_map<Node*, Node*> randomOriginalList;
        unordered_map<Node*, Node*> randomCopyList;
        randomOriginalList[newHead] = head->random;
        randomCopyList[head] = newHead;

        while(head) {
            head = head->next;

            if(head){
                temp->next = new Node(head->val);
                temp = temp->next;
                randomOriginalList[temp] = head->random;
                randomCopyList[head] = temp;
            }
        }

        temp = newHead;
        while(temp) {
            temp->random = randomCopyList[randomOriginalList[temp]];
            temp = temp->next;
        }

        return newHead;
    }
};