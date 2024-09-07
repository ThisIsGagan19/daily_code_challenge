// TIME COMPEXITY
// O(n * m)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution {
public:
    vector<TreeNode*> arr;
    void fillList(ListNode* head, TreeNode* root){
        if(head == NULL || root == NULL) return ;
        if(head->val == root->val){
            arr.push_back(root);
        }
        fillList(head,root->left);
        fillList(head,root->right);
    }
    bool findPath(ListNode* head, TreeNode* root){
        if(head == NULL) return true;
        if(root == NULL) return false;

        if(head->val == root->val){
            return (findPath(head->next, root->left) || findPath(head->next, root->right));
        }
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        fillList(head,root);
        for(TreeNode* it : arr){
            if(findPath(head,it)){
                return true;
            }
        }
        return false;
    }
};