// CODE

class Solution {
    public:
      vector<int> bellmanFord(int n, vector<vector<int>>& edges, int src) {
          vector<int>dist(n,1e8);
          dist[src] = 0;
          // n-1 times relaxation kr diya edges ko
          for(int i = 0; i < n; i++){
              for(auto it : edges){
                  int u = it[0];
                  int v = it[1];
                  int w = it[2];
                  
                  if(dist[u] != 1e8 && dist[u] + w < dist[v]){
                      dist[v] = dist[u] + w;
                  }
              }
          }
          
          // nth time relaxation kro - agar relax ho jati h toh negative cycle h
          for(auto it : edges){
              int u = it[0];
              int v = it[1];
              int w = it[2];
              
              if(dist[u] != 1e8 && dist[u] + w < dist[v]){
                  // dist[v] = dist[u] + w;  kro mt direct return negative cycle h
                  return {-1};
              }
          }
          return dist;
      }
};