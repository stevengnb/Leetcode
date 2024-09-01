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
    int idx = 0;
    int res = -1;

    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return res;
    }

    void inOrder(TreeNode* root, int k) {
        if(!root) return;
        
        inOrder(root->left, k);
        if(++idx == k) {
            res = root->val;
            return;
        }
        inOrder(root->right, k);
    }
};