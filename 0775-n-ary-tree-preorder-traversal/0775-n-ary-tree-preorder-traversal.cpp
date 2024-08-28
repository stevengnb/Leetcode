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
    vector<int> preorder(Node* root) {
        vector<int> vect;
        preOrder(root, vect);

        return vect;
    }

    void preOrder(Node* root, vector<int>& vect) {
        if(!root) return;

        vect.push_back(root->val);
        
        for(Node* node : root->children) {
            preOrder(node, vect);
        }
    }
};