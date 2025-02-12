// TC : O(N)
// SC : O(N)

// CODE

class Solution {
  public:
    // Return the Kth smallest element in the given BST
    void solve(Node* root, vector<int> &inorder){
        if(root == NULL) return ;
        solve(root->left, inorder);
        inorder.push_back(root->data);
        solve(root->right, inorder);
    }
    int kthSmallest(Node *root, int k) {
        vector<int> inorder;
        solve(root,inorder);
        if(inorder.size() < k) return -1;
        return inorder[k-1];
    }
};