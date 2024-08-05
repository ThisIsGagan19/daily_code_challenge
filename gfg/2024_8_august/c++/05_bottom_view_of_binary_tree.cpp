// TIME COMPEXITY
// O(nlogn)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution {
  public:
    vector <int> bottomView(Node *root) {
       vector<int> ans;
       if(root == NULL) return ans;
       map<int,int> node;
       queue<pair<Node*, int>> q;
       q.push(make_pair(root,0));
       
       while(!q.empty()){
           pair<Node*, int> temp = q.front();
           q.pop();
           
           Node* frontNode = temp.first;
           int Hd = temp.second;
           
           // kuch mat kro bas daalte jao
            node[Hd] = frontNode->data;
           
           if(frontNode->left){
               q.push(make_pair(frontNode->left,Hd - 1));
           }
           if(frontNode->right){
               q.push(make_pair(frontNode->right,Hd + 1));
           }
           
       }
       for(auto it : node){
           ans.push_back(it.second);
       }
       return ans;
    }
};