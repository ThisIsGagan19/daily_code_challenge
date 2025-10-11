// TC = O(N)
// SC = O(N)

// CODE

class Solution {
  public:
    int maxSum;
    int solve(Node* root){
        if(root == NULL) return 0;
        
        int l = solve(root->left);
        int r = solve(root->right);
        
        int neeche_wala_he_answer = l + r + root->data;
        int only_single_better = max(l,r) + root->data;
        int only_root_better = root->data;
        
        maxSum = max({maxSum,neeche_wala_he_answer,only_single_better,only_root_better});
        
        return max(only_single_better,only_root_better);
    }
    int findMaxSum(Node *root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
        
    }
};