/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> vect;
        postOrder(root, vect);
        reverse(vect.begin(), vect.end());

        return vect;
    }

    void postOrder(Node* root, vector<int>& vect) {
        if(!root) return;

        vect.push_back(root->val);
        
        for(int i = root->children.size()-1; i >= 0; i--) {
            postOrder(root->children[i], vect);
        }
    }
};