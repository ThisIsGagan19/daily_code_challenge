// CODE

class Solution {
    public:
      int orangesRotting(vector<vector<int>>& grid) {
          int n = grid.size();
          int m = grid[0].size();
          vector<vector<int>> vis(n,vector<int>(m,0));
          queue<pair<pair<int,int>,int>> q;
          
          for(int i = 0; i < n; i++){
              for(int j = 0; j < m; j++){
                  if(grid[i][j] == 2){
                      vis[i][j] = 2;
                      q.push({{i,j},0});
                  }
                  else{
                      vis[i][j] = 0;
                  }
              }
          }
          
          int max_t = 0;
          
          while(!q.empty()){
              int r = q.front().first.first;
              int c = q.front().first.second;
              int t = q.front().second;
              q.pop();
              max_t = max(max_t,t);
              // traversing the nodes or you can directions
              for(int row = -1; row <= 1; row++){
                  for(int col = -1; col <= 1; col++){
                      if (row && col) continue;
                      int new_i = r + row;
                      int new_j = c + col;
                      if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && vis[new_i][new_j] != 2 && grid[new_i][new_j] == 1){
                          vis[new_i][new_j] = 2;
                          q.push({{new_i,new_j},t + 1});
                      }
                  }
              }
          }
          for(int i = 0; i < n; i++){
              for(int j = 0; j < m; j++){
                  if(vis[i][j] != 2 && grid[i][j] == 1) {
                      return -1;
                  }
              }
          }
          return max_t;
          
      }
  };