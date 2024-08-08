// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution {
  public:
    pair<bool,int> solve(Node * root){
        if(root == NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        if(root->left == NULL && root->right == NULL){
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int> left = solve(root->left);
        pair<bool,int> right = solve(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool condition = (root->data == left.second + right.second);
        
        pair<bool,int> ans;
        if(leftAns && rightAns && condition){
            ans.first = true;
            ans.second = 2 * root->data;
        }
        else{
            ans.first = 0;
        }
        
        return ans;
    }
    bool isSumTree(Node* root) {
        return solve(root).first;
    }
};