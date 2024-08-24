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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxVal = INT_MIN;
        diameter(root, maxVal);
        return maxVal;
    }

    void diameter(TreeNode* root, int &maxVal) {
        if(!root) return;

        int depth = maxDepth(root->right) + maxDepth(root->left);
        if(depth > maxVal) maxVal = depth;

        diameter(root->left, maxVal);
        diameter(root->right, maxVal);
    }

    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        else return max(maxDepth(root->right) + 1, maxDepth(root->left) + 1);
    }
};