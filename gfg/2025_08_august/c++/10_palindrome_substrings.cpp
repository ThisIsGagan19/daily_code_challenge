// TC : O(N^2)
// SC : O(N^2)

// CODE

class Solution {
  public:
    int countPS(string &s) {
        int n = s.length();
        int ans = 0;
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        for(int g = 0; g < n; g++){
            for(int i = 0, j = g; j < n; i++,j++){
                if(g == 0){
                    dp[i][j] = true;
                }
                else if(g == 1){
                    if(s[i] == s[j]){
                        dp[i][j] = true;
                        ans++;
                    }
                }
                else{
                    if(s[i] == s[j] && dp[i+1][j-1]){
                        dp[i][j] = true;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};