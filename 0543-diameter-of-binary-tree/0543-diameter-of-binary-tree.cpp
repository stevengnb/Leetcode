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
    int maxVal = INT_MIN;

    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return maxVal;
    }

    int diameter(TreeNode* root) {
        if(!root) return 0;

        int depthLeft = diameter(root->left);
        int depthRight = diameter(root->right);

        maxVal = max(maxVal, depthLeft + depthRight);
        return 1 + max(depthLeft, depthRight);
    }
};