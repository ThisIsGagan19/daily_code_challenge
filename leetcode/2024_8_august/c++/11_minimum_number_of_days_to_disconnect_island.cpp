// TIME COMPEXITY
// O((n * m) ^ 2)

// SPACE COMPEXITY
// O(n * m)

// CODE

class Solution {
public:
    int n,m;
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool> > &vis){
        if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || grid[i][j] == 0) return ;

        vis[i][j] = true;
        dfs(grid,i+1,j,vis);
        dfs(grid,i-1,j,vis);
        dfs(grid,i,j+1,vis);
        dfs(grid,i,j-1,vis);
    }
    int countf(vector<vector<int>>& grid){
        int cnt = 0;
        vector<vector<bool> > vis(n,vector<bool>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    dfs(grid,i,j,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int cnt = countf(grid);

        if(cnt > 1 || cnt == 0) return 0;
        else{
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(grid[i][j] == 1){
                        grid[i][j] = 0;
                        cnt = countf(grid);
                        if(cnt > 1 || cnt == 0) return 1;
                        grid[i][j] = 1;
                    }
                }
            }
        }
        return 2;
    }
};