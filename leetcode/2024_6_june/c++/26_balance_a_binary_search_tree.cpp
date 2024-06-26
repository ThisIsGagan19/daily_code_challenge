// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
public:
    void buildInorder(TreeNode* root, vector<int> &inorder){
        if(root == NULL){
            return ;
        }
        if(root->left) buildInorder(root->left, inorder);
        inorder.push_back(root->val);
        if(root->right) buildInorder(root->right, inorder);
    }


    TreeNode* buildBalancedBst(vector<int> &inorder, int st, int end){
        if(st > end) return NULL;

        int mid = st + (end - st) / 2;

        TreeNode * middle = new TreeNode(inorder[mid]);
        middle->left = buildBalancedBst(inorder,st,mid-1);
        middle->right = buildBalancedBst(inorder,mid + 1,end);

        return middle;
    }

    TreeNode* balanceBST(TreeNode* root) {

        vector<int> inorder;
        if(root == NULL) return NULL;

        buildInorder(root, inorder);

        int start = 0;
        int end = inorder.size() - 1;

        return buildBalancedBst(inorder, start, end);
    }
};