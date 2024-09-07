class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;
        vector<TreeNode*> vect;
        isIn(head, root, vect);

        if(vect.empty()) return false;
        else {
            for(int i = 0; i < vect.size(); i++) {
                bool sub = isSub(head, vect[i]);
                if(sub) return true;
            }
        }

        return false;
    }

    void isIn(ListNode* head, TreeNode* root, vector<TreeNode*>& vect) {
        if(!root) return;

        if(root->val == head->val) vect.push_back(root);
        isIn(head, root->left, vect);
        isIn(head, root->right, vect);
    }

    bool isSub(ListNode* head, TreeNode* root) {
        if(!head) return true;
        if(!root) return false;

        if(head->val != root->val) return false;

        bool left = isSub(head->next, root->left);
        bool right = isSub(head->next, root->right);

        return left || right;
    }
};