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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;

        if (!root) return ans;
    
        path.push_back(root->val);
        backtrack(ans, path, root, root->val, targetSum);

        return ans;
    }

    void backtrack(vector<vector<int>> &ans, vector<int> &path, TreeNode* root, int sum, int targetSum) {
        if (!root) return;
        print(path);
        // cout << "root val = " << root->val << endl;
        // cout << "sum = " << sum << endl;
        // cout << "targetsum = " << targetSum << endl << endl;
        // if ((targetSum < 0 && sum < targetSum) || (targetSum > 0 && sum > targetSum)) return;
        if (sum == targetSum && (!root->left && !root->right)) {
            ans.push_back(path);
            return;    
        }

        if (root->left) {
            path.push_back(root->left->val);
            backtrack(ans, path, root->left, sum + root->left->val, targetSum);
            path.pop_back();
        }
        if (root->right) {
            path.push_back(root->right->val);
            backtrack(ans, path, root->right, sum + root->right->val, targetSum);
            path.pop_back();
        }
    }

    void print(vector<int> &path) {
        cout << "current path = ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << ", ";
        }
        cout << endl;
    }
};