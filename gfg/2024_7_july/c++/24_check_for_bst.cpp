// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    void solve(Node* root,vector<int> &ans){
        if(root == NULL) return ;
        
        solve(root->left,ans);
        ans.push_back(root->data);
        solve(root->right,ans);
    }
    bool isBST(Node* root) {
        vector<int> ans;
        solve(root,ans);
        for(int i = 1; i < ans.size(); i++){
            if(ans[i] <= ans[i-1]) return false;
        }
        return true;
    }
};