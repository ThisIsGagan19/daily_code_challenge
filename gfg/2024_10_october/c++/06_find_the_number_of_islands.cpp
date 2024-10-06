// CODE

class Solution {
  public:
  
    void dfs(int i, int j, int n, int m, vector<int> &dr, vector<int> &dc, vector<vector<int>> &vis, vector<vector<char>> &grid) {
        vis[i][j] = 1;
        
        for(int a = 0; a < 8; a++) {
            int newRow = i + dr[a];
            int newCol = j + dc[a];
            
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == '1' && !vis[newRow][newCol]) {
                dfs(newRow, newCol, n, m, dr, dc, vis, grid);
            }
        }
        
    }
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int ans = 0;
        
        // up, right, down, left, upleft, upright, downright, downleft
        vector<int> dr = {-1, 0, 1, 0, -1, -1, 1, 1};
        vector<int> dc = {0, 1, 0, -1, -1, 1, 1, -1};
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    ans++;
                    dfs(i, j, n, m, dr, dc, vis, grid);
                }
            }
        }
        
        return ans;
    }
};