// CODE

class Solution {
    public:
      // Function to detect cycle in a directed graph.
      bool dfs(int node, int vis[], int pathVis[], vector<vector<int>> &adj){
          vis[node] = 1;
          pathVis[node] = 1;
          for(auto it : adj[node]){
              if(!vis[it]){
                  if(dfs(it,vis,pathVis,adj)) return true;
              }
              else if(pathVis[it]) return true;
          }
          pathVis[node] = 0;
          return false;
      }
      bool isCyclic(int n, vector<vector<int>> &edges) {
          
          vector<vector<int>> adj(n);
          for(auto it : edges){
              int u = it[0];
              int v = it[1];
              adj[u].push_back(v);
          }
          
          int vis[n] = {0};
          int pathVis[n] = {0};
          
          for(int i = 0; i < n; i++){
              if(!vis[i]){
                  if(dfs(i,vis,pathVis,adj)) return true;
              }
          }
          return false;
      }
};