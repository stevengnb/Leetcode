class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vect;
        if(!root) return vect;

        queue<TreeNode*> que;
        que.push(root);
        vect.push_back(root->val);

        while(!que.empty()) {
            int size = que.size();
            int temp = -101;

            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();

                if(!node) break;

                if(i == size-1 && node->val != vect[0]) temp = node->val;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }

            if(temp != -101) vect.push_back(temp);
        }

        return vect;
    }
};