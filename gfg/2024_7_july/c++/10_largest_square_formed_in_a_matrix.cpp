// TIME COMPLEXITY
// O(n*m)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
  public:
    int solve(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp){
        if(i >= mat.size() || j >= mat[0].size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int right = solve(mat,i,j+1,maxi,dp);
        int diagonal = solve(mat,i+1,j+1,maxi,dp);
        int down = solve(mat,i+1,j,maxi,dp);
        if(mat[i][j] == 1){
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi = max(dp[i][j],maxi);
            return dp[i][j];
        }
        else return dp[i][j] = 0;
    }
    int solveTab(vector<vector<int>> &mat,int &maxi){
        int row = mat.size();
        int col = mat[0].size();
        
        vector<vector<int>> dp(row+1, vector<int>(col+1,0));
        
        for(int i = row-1; i >= 0; i--){
            for(int j = col-1; j >= 0; j--){
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];
                if(mat[i][j] == 1){
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(dp[i][j],maxi);
                }
                else  dp[i][j] = 0;
                
            }
        }
        // kuchbe return kr do hme toh maxi se mtlb h
        return dp[0][0];
        
    }
    
    int solveSpaceOpt(vector<vector<int>> &mat,int &maxi){
        int row = mat.size();
        int col = mat[0].size();
        
        
        vector<int> curr(col+1,0); // [i]
        vector<int> next(col+1,0); // [i+1]
        
        for(int i = row-1; i >= 0; i--){
            for(int j = col-1; j >= 0; j--){
                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];
                if(mat[i][j] == 1){
                    curr[j] = 1 + min(right, min(diagonal, down));
                    maxi = max(curr[j],maxi);
                }
                else  curr[j] = 0;
                
            }
            next = curr;
        }
        // kuchbe return kr do hme toh maxi se mtlb h
        return next[0];
        
    }
    
    int solveSpaceOptUltraProMaxPlus(vector<vector<int>> &mat){
        int row = mat.size();
        int col = mat[0].size();
        
        int maxi = 0;
        
        for(int i = row-1; i >= 0; i--){
            for(int j = col-1; j >= 0; j--){
                int right = 0,diagonal = 0,down = 0;
                if(i < row-1) down = mat[i+1][j];
                if(j < col-1) right = mat[i][j+1];
                if(i < row-1 && j < col-1) diagonal = mat[i+1][j+1];
                
                if(mat[i][j] == 1){
                    mat[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi,mat[i][j]);
                }
            }
        }
        // kuchbe return kr do hme toh maxi se mtlb h
        return maxi;
        
    }
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // vector<vector<int>> dp(n,vector<int> (m,-1));
        // int maxi = 0;
        // int ans = solve(mat,0,0,maxi,dp);
        // return maxi;
        
        // int maxi = 0;
        // int ans = solveTab(mat,maxi);
        // return maxi;
        
        // int maxi = 0;
        // int ans = solveSpaceOpt(mat,maxi);
        // return maxi;
        

        return solveSpaceOptUltraProMaxPlus(mat);
        
        
        
    }
};