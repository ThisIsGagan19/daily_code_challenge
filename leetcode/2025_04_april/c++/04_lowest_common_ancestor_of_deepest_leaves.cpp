// CODE

class Solution {
    public:
        int max_depth = 0;
        unordered_map<int,int> mp;
        TreeNode* lca(TreeNode* root){
            if(root == NULL || mp[root->val] == max_depth){
                return root;
            }
            TreeNode* left = lca(root->left);
            TreeNode* right = lca(root->right);
    
            if(left && right){
                return root;
            }
            return left != NULL ? left : right;
        }
        void depth(TreeNode* root, int d){
            if(!root) return ;
            max_depth = max(max_depth,d);
            mp[root->val] = d;
            depth(root->left,d+1);
            depth(root->right,d+1);
        }
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            depth(root,0);
            return lca(root);
        }
    };