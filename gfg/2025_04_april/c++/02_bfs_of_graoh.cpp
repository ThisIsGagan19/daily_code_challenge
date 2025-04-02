// CODE

class Solution {
    public:
      // Function to return Breadth First Traversal of given graph.
      vector<int> bfs(vector<vector<int>> &adj) {
          int n = adj.size();
          vector<int> ans;
          vector<int> vis(n,0);
          vis[0] = 1;
          queue<int> q;
          q.push(0);
          while(!q.empty()){
              int node = q.front();
              q.pop();
              ans.push_back(node);
              for(auto it : adj[node]){
                  if(!vis[it]){
                      vis[it] = 1;
                      q.push(it);
                  }
              }
          }
          return ans;
      }
};
