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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> root1Val;
        vector<int> root2Val;

        dfs(root1, root1Val);
        dfs(root2, root2Val);

        int len = root1Val.size();
        int len2 = root2Val.size();

        if (len != len2) return false;
        for (int i = 0; i < len; i++) if (root1Val[i] != root2Val[i]) return false;
        return true;
    }

    void dfs(TreeNode* root, vector<int>& rootVal) {
        if (!root) return;

        if (!root->left && !root->right) {
            rootVal.push_back(root->val);
        }

        dfs(root->left, rootVal);
        dfs(root->right, rootVal);
    }
};