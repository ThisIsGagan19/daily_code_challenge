// CODE

class Solution {
    public:
      void floydWarshall(vector<vector<int>> &dist) {
          int n = dist.size();
          for(int node = 0; node < n; node++){
              for(int i = 0; i < n; i++){
                  for(int j = 0; j < n; j++){
                      if(dist[i][node] != 100000000 && dist[node][j] != 100000000 && dist[i][j] > dist[i][node] + dist[node][j]){
                          dist[i][j] = dist[i][node] + dist[node][j];
                      }
                  }
              }
          }
      }
};