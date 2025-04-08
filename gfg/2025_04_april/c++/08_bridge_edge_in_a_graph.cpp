// CODE

class Solution {
    public:
      void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int c, int d){
          vis[node] = 1;
          for(auto it : adj[node]){
              if(!vis[it] && !(node == c && it == d)){
                  dfs(it,adj,vis,c,d);
              }
          }
      }
      bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
          // aacha tareka h yeh be 
          // c se start kro dfs traversal and d thk pocha ja shakta h bina c-----d wali edge ka use kre toh bridge nhi h, varna h
          // !(node == c && it == d)   -> (main condition) ignore kro c-----d wali edge ko
          // agar d visted then false no bridge
          // agar d not visted then true bridge is there
          vector<vector<int>> adj(V);
          // adjacency list
          for(auto it : edges){
              int u = it[0];
              int v = it[1];
              adj[u].push_back(v);
              adj[v].push_back(u);
          }
          
          vector<int> vis(V,0);
          dfs(c,adj,vis,c,d);
          if(vis[d]) return false;
          return true;
          
      }
  };