// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
  public:
    Node* prev = NULL;

    void populateNext(Node *root) {
        // code here
        if(root==NULL) return;
        populateNext(root->left);
        if(prev!=NULL){
            prev->next = root;
        }
        prev = root;
        populateNext(root->right);
    }
};