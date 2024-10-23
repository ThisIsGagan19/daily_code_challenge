// CODE

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* dummy = root;
        root->val = 0;
        q.push(dummy);
        while(!q.empty()){
            queue<TreeNode*> temp;
            map<TreeNode* , int> mp;
            while(!q.empty()){
                TreeNode* node = q.front();
                if(node->left != NULL){
                    temp.push(node->left);
                    mp[node] += node->left->val; 
                }
                if(node->right != NULL){
                    temp.push(node->right);
                    mp[node] += node->right->val; 
                }
                q.pop();
            }

            int sum = 0;
            for(auto it : mp){
                sum += it.second;
            }

            for(auto it : mp){
                int temp2 = 0;
                if(it.first->left != NULL){
                    temp2 += it.first->left->val;
                }
                if(it.first->right != NULL){
                    temp2 += it.first->right->val;
                }

                temp2 = sum - temp2;

                if(it.first->left != NULL){
                    it.first->left->val = temp2;
                }
                if(it.first->right != NULL){
                    it.first->right->val = temp2;
                }
            }
            q = temp;
        }
        return root;
    }
};