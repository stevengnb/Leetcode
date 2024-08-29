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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vect;
        inOrder(root, 1, vect);
        return vect;
    }

    void inOrder(TreeNode* root, int level, vector<vector<int>>& vect) {
        if(!root) return;
        int row = level-1;

        if (vect.size() <= row) vect.resize(row + 1);
        vect[row].push_back(root->val);

        inOrder(root->left, level+1, vect);
        inOrder(root->right, level+1, vect);
    }
};