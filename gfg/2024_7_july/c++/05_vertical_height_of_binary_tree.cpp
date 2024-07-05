// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    void solve(Node *root, int &mini, int &maxi, int posi){
        if(root == NULL) return ;
        mini = min(mini, posi);
        maxi = max(maxi, posi);
        
        solve(root->left,mini,maxi,posi - 1);
        solve(root->right,mini,maxi,posi + 1);
    }
    int verticalWidth(Node* root) {
        if(root == NULL) return 0;
        int mini = 0;
        int maxi = 0;
        solve(root,mini,maxi,0);
        
        return maxi + abs(mini) + 1;
    }
};