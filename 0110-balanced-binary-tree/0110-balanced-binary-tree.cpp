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
    bool balance = true;

    bool isBalanced(TreeNode* root) {
        heightTree(root);
        return balance;
    }

    int heightTree(TreeNode* root) {
        if(!root) return 0;

        int depthLeft = heightTree(root->left);
        int depthRight = heightTree(root->right);

        if(abs(depthLeft - depthRight) > 1) balance = false;

        return 1 + max(depthLeft, depthRight);
    }
};