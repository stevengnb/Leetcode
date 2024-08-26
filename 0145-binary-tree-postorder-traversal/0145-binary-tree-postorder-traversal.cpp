/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vect;
        postOrder(root, vect);
        return vect;
    }

    void postOrder(TreeNode* root, vector<int>& vect) {
        if(!root) return;
        
        postOrder(root->left, vect);
        postOrder(root->right, vect);
        vect.push_back(root->val);
    }
};