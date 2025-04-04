// CODE

class Solution {
    public:
      bool dfs(int node, int p, vector<vector<int>>& adj, vector<int> & vis){
          vis[node] = 1;
          for(auto it : adj[node]){
              if(!vis[it]){
                  if(dfs(it,node,adj,vis)){
                      return true;
                  }
              }
              else if(it != p){
                  return true;
              }
          }
          return false;
      }
      bool isCycle(int n, vector<vector<int>>& adj) {
          vector<int> vis(n,0);
          for(int i = 0; i < n; i++){
              if(dfs(i,-1,adj,vis)){
                  return true;
              }
          }
          return false;
          
      }
  };