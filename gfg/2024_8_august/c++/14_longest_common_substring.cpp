// TIME COMPEXITY
// O(n * m)

// SPACE COMPEXITY
// O(n * m)

// CODE

class Solution {
  public:
    int solve(string str1, string str2){
        int ans = 0;
        int n = str1.length();
        int m = str2.length();
        
        vector<vector<int> > dp(n+1, vector<int> (m+1,0));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
    int longestCommonSubstr(string str1, string str2) {
        return solve(str1, str2);
    }
};