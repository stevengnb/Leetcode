/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        queue<pair<Node*, int>> que;
        int index = 1;

        que.push(make_pair(root, 1));

        while(!que.empty()) {
            pair<Node*, int> curr = que.front();
            curr.first->next = nullptr;

            if (curr.first->left) que.push(make_pair(curr.first->left, curr.second+1));
            if (curr.first->right) que.push(make_pair(curr.first->right, curr.second+1));

            que.pop();
            if (!que.empty() && que.front().second == curr.second) curr.first->next = que.front().first;
        }

        return root;
    }
};