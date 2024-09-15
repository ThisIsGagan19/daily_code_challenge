// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution {
  public:
    Node* prev = NULL;
    Node* head = NULL;
    void solve(Node* root){
        if(root == NULL) return ;
        solve(root->left);
        if(prev == NULL) head = root;
        else{
            root->left = prev;
            prev->right = root;
            
        }
        prev = root;
        solve(root->right);
    }
    Node* bToDLL(Node* root) {
        solve(root);
        return head;
    }
    
};