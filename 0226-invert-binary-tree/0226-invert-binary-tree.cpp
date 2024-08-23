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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* neww = invert(root);

        return neww;
    }

    TreeNode* invert(TreeNode* root) {
        if(!root) return NULL;

        if(root->left || root->right) {
            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;
        }

        invert(root->left);
        invert(root->right);

        return root;
    }

};