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
    int temp = 0;

    int goodNodes(TreeNode* root) {
        good(root, root->val);
        return temp;
    }

    void good(TreeNode* root, int maxVal) {
        if(!root) return;
        if(temp == 0) temp++;
        else if(root->val >= maxVal) temp++;

        good(root->left, max(root->val, maxVal));
        good(root->right, max(root->val, maxVal));
    }
};