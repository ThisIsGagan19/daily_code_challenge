// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node == NULL) return ;
        swap(node->left, node->right);
        mirror(node->left);
        mirror(node->right);
    }
};