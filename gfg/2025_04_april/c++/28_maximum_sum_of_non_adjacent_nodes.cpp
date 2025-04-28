// CODE

class Solution {
    public:
      // Function to return the maximum sum of non-adjacent nodes.
      pair<int,int> solve(Node* root){
          if(!root) return {0,0};
          auto l = solve(root->left);
          auto r = solve(root->right);
          
          int inc = root->data + l.second + r.second;
          int exc = max(l.first, l.second) + max(r.first, r.second);
          return {inc,exc};
      }
      int getMaxSum(Node *root) {
          auto ans = solve(root);
          return max(ans.first, ans.second);
          
      }
};