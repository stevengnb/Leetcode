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
    int sumRootToLeaf(TreeNode* root) {
        vector<int> ans;
        int sum = 0;
        iterateTree(root, ans, "");
        for (int i : ans) sum += i;
        return sum;
    }

    void iterateTree(TreeNode* root, vector<int>& ans, string curr) {
        if (!root) return;
        string cr = curr + to_string(root->val);

        if (!root->left && !root->right) {
            int sum = 0;
            int len = cr.size();

            for (int i = 0; i < len; i++) if (cr[i] == '1') sum += pow(2, len-i-1);
            ans.push_back(sum);
        }

        iterateTree(root->left, ans, cr);
        iterateTree(root->right, ans, cr);
    }
};