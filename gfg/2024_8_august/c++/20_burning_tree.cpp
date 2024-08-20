// TIME COMPEXITY
// O(n)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution {
  public:
  // 1. create mapping
  // 2. find target node
  Node* createMapOfParent(Node* root, int target, map<Node*, Node*> &nodeToParent){
      Node* res = NULL;
      queue<Node*> q;
      q.push(root);
      nodeToParent[root] = NULL;
      while(!q.empty()){
          Node* front = q.front();
          q.pop();
          
          if(front->data == target)
            res = front;
          if(front->left){
              nodeToParent[front->left] = front;
              q.push(front->left);
          }
          if(front->right){
              nodeToParent[front->right] = front;
              q.push(front->right);
          }
      }
      return res;
  }
  
  // 3. burn the tree
  void burnTree(Node* targetNode, map<Node*, Node*> &nodeToParent,int &ans){
    map<Node*, bool> visited;
    queue<Node*> q;
    q.push(targetNode);
    visited[targetNode] = true;
    while(!q.empty()){
        bool flag = 0;
        int size = q.size();
        for(int i = 0; i < size; i++){
            Node* front = q.front();
            q.pop();
            
            // preocess the neighbour nodes left, right, parent
            
            //left
            if(front->left && !visited[front->left]){
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }
            
            // right
            if(front->right && !visited[front->right]){
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }
            
            //parent
            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
            }
        }
        if(flag == 1) ans++;
    }
  }
    int minTime(Node* root, int target) 
    {
        int ans = 0;
        map<Node*, Node*> nodeToParent;
        Node* targetNode = createMapOfParent(root,target,nodeToParent);
        burnTree(targetNode,nodeToParent,ans);
        return ans;
    }
};