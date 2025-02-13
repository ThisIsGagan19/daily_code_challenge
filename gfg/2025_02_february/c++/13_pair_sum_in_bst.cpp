// TC : O(N)
// SC : O(N)

// CODE

class Solution {
  public:
    void solve(Node* root, vector<int> &inorder){
        if(root == NULL) return ;
        solve(root->left, inorder);
        inorder.push_back(root->data);
        solve(root->right, inorder);
    }
    bool findTarget(Node *root, int tar) {
        vector<int> inorder;
        solve(root,inorder);
        int n = inorder.size();
        int st = 0;
        int end = n-1;
        int cnt = 0;
        int sum = 0;
        while(st < end){
            sum = inorder[st] + inorder[end];
            if(sum > tar) end--;
            if(sum < tar) st++;
            if(sum == tar){
                return true;
            }
        }
        return false;
    }
};