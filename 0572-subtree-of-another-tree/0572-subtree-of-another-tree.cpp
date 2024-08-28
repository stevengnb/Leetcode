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
    bool subtree = false;

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        checkSubtree(root, subRoot);
        return subtree;
    }

    void checkSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return;

        if(!isSameTree(root, subRoot)) {
            checkSubtree(root->left, subRoot);
            checkSubtree(root->right, subRoot);
        } else {
            subtree = true;
        }
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        else if(!p || !q) return false;
        else if(p->val != q->val) return false;

        bool leftSide = isSameTree(p->left, q->left);
        bool rightSide = isSameTree(p->right, q->right);

        return leftSide && rightSide;
    }
};