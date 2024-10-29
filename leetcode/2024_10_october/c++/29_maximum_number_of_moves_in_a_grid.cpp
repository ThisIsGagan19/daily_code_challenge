// CODE

class Solution {
public:
    const int dx[3] = {-1, 1, 0};
    const int dy[3] = {1, 1, 1};

    int dfs(int i, int j, vector<vector<int>>& g, vector<vector<int>>& memo, int r, int c) {
        if (memo[i][j] != -1) return memo[i][j];
        
        int maxi = 0;
        
        for (int x = 0; x < 3; ++x) {
            int newi = i + dx[x];
            int newj = j + dy[x];
            
            if (newi >= 0 && newi < r && newj >= 0 && newj < c && g[newi][newj] > g[i][j]) {
                int score = 1 + dfs(newi, newj, g, memo, r, c);
                maxi = max(maxi, score);
            }
        }
        
        memo[i][j] = maxi;
        return maxi;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int maxi = 0;
        vector<vector<int>> memo(r, vector<int>(c, -1));  // Memoization table
        
        for (int i = 0; i < r; ++i) {
            maxi = max(dfs(i, 0, grid, memo, r, c), maxi);
        }
        
        return maxi;
    }
};