// CODE

class Solution {
    public:
      void DFS(int node, vector<vector<int>>& adj, vector<int> &vis, vector<int> &ans){
          vis[node] = 1;
          ans.push_back(node);
          for(auto it : adj[node]){
              if(!vis[it]){
                  DFS(it,adj,vis,ans);
              }
          }
      }
      vector<int> dfs(vector<vector<int>>& adj) {
          int n = adj.size();
          vector<int> vis(n,0);
          vector<int> ans;
          DFS(0,adj,vis,ans);
          return ans;
          
      }
  };