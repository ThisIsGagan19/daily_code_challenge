// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
  public:
    bool solve(Node *root, int target){
        if(root == NULL) return false;
        
        // leaf node compare with target
        if(root->left == NULL && root->right == NULL) return (root->data == target);
        
        // if not leaf updarte target
        int tar = target - root->data;
        
        bool left = solve(root->left, tar);
        bool right = solve(root->right, tar);
        
        
        if(left) return left;
        return right;
    }
    bool hasPathSum(Node *root, int target) {
        // Your code here
        return solve(root,target);
        
    }
};