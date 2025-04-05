// CODE

class Solution {
    public:
      void bfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>>& grid){
          int n = grid.size();
          int m = grid[0].size();
          vis[i][j] = 1;
          queue<pair<int,int>> q;
          q.push({i,j});
          while(!q.empty()){
              int first = q.front().first;
              int second = q.front().second;
              q.pop();
              // traverse neighbour this time kinda different go all acroos direction
              for(int row = -1; row <= 1; row++){
                  for(int col = -1; col <= 1; col++){
                      int new_i = first + row;
                      int new_j = second + col;
                      if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && vis[new_i][new_j] == 0 && grid[new_i][new_j] == 'L'){
                          vis[new_i][new_j] = 1;
                          q.push({new_i,new_j});
                      }
                  }
              }
          }
      }
      int countIslands(vector<vector<char>>& grid) {
          int n = grid.size();
          int m = grid[0].size();
          vector<vector<int>> vis(n,vector<int>(m,0));
          int cnt = 0;
          for(int i = 0; i < n; i++){
              for(int j = 0; j < m; j++){
                  if(grid[i][j] == 'L' && !vis[i][j]){
                      cnt++;
                      bfs(i,j,vis,grid);
                  }
              }
          }
          return cnt;
      }
  };