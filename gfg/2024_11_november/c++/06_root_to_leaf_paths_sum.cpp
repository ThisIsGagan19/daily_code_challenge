// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
  public:
    int ans = 0;
    void solve(Node *root, int val){
        if(root == NULL) return;
        val = 10 * val + root->data;
        if(root->left == NULL && root->right == NULL){
            ans += val;
        }
        solve(root->left,val);
        solve(root->right,val);
    }
    int treePathsSum(Node *root) {
        solve(root,0);
        return ans;
    }
};