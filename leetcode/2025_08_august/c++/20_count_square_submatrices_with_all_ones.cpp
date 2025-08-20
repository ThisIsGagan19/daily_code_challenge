// TC : O(N*M)
// SC : O(N*M)

class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int j = 0; j < m; j++) dp[0][j] = mat[0][j]; // first row copy
        for(int i = 0; i < n; i++) dp[i][0] = mat[i][0]; // first col copy

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(mat[i][j] == 0) dp[i][j] = 0; // case when 0 is present
                else{ // case where 1 is present
                    dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + 1;
                }
            }
        }

        // till this dp is filled fully
        // now just summ all the elements
        int sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                sum += dp[i][j];
            }
        }
        return sum;
    }
};