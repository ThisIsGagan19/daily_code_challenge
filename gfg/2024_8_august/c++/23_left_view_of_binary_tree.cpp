// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(n)

// CODE

void solver(Node * root,vector<int> &ans, int lvl){
    if(root == NULL) return ;
    if(lvl == ans.size()){
        ans.push_back(root->data);
    }
    if(root->left){
        solver(root->left,ans,lvl+1);
    }
    if(root->right){
        solver(root->right,ans,lvl+1);
    }
}
vector<int> leftView(Node *root)
{
   vector<int> ans;
   solver(root,ans,0);
   return ans;
}