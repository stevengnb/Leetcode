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
    int maxLevelSum(TreeNode* root) {
        int level = INT_MAX;
        int maxSum = INT_MIN;
        int levelCurr = 1;

        queue<TreeNode*> que;

        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            int sumPerLevel = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = que.front();
                que.pop();

                sumPerLevel += curr->val;

                if (curr->left) que.push(curr->left);
                if (curr->right) que.push(curr->right);
            }
            if (sumPerLevel > maxSum) {
                maxSum = sumPerLevel;
                level = levelCurr;
            }

            levelCurr++;
        }

        return level;
    }
};