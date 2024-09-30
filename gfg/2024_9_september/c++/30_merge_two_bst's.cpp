// CODE

class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
   void findAns(Node *root1, Node *root2, vector<int> &ans){
        if(root1== NULL && root2 == NULL){
            return;
        }
        if(root1 == NULL && root2!=NULL){
            findAns(root1,root2->left,ans);
            ans.push_back(root2->data);
            findAns(root1,root2->right,ans);
        }else if(root2 == NULL && root1!=NULL){
            findAns(root1->left,root2,ans);
            ans.push_back(root1->data);
            findAns(root1->right,root2,ans);
        }else{
            findAns(root1->left,root2->left,ans);
             ans.push_back(root1->data);
             ans.push_back(root2->data);
             findAns(root1->right,root2->right,ans);
            
        }
        
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> ans;
         findAns(root1,root2,ans);
         sort(ans.begin(),ans.end());
         return ans;
    }
};