// CODE

class Solution {
    public:
    void inorder(Node *root, int &res, int& prev) {
        if(!root) return;
        inorder(root -> left, res, prev);
        if(prev != -1) res = min(res, abs(root -> data - prev));
        prev = root -> data;
        inorder(root -> right, res, prev);
    }
    
    int absolute_diff(Node *root) {
        int res = INT_MAX;
        int prev = -1;
        inorder(root, res, prev);
        return res;
    }
};