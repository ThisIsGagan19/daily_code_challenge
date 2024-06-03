// CODE

class Solution {
public:   
    int minValue(Node* root) {
        if(!root) return -1;
        if(!root -> left) return root -> data;
        return minValue(root -> left);
    }
};