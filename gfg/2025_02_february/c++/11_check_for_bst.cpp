// TC : O(N)
// SC : O(N)

// CODE

class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    void solve(Node* root, vector<int> &inorder){
        if(root == NULL) return ;
        solve(root->left, inorder);
        inorder.push_back(root->data);
        solve(root->right, inorder);
    }
    bool isBST(Node* root) {
        vector<int> inorder;
        solve(root,inorder);
        for(int i = 1; i < inorder.size(); i++){
            if(inorder[i] < inorder[i-1]) return false;
        }
        return true;
    }
};