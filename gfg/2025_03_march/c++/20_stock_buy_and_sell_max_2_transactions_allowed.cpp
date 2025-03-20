// CODE

class Solution {
    public:
    
      int solve_2(vector<int>& prices, int n, 
      vector<vector<int>> &dp){
          for(int idx = n-1; idx >= 0; idx--){
              for(int trac = 2*2 - 1; trac >= 0; trac--){
                  if(trac % 2 == 0){ // buy case
                      dp[idx][trac] = max(-prices[idx] + dp[idx+1][trac+1], 0 + dp[idx+1][trac]);
                  }
                  else{ // sell case
                      dp[idx][trac] = max(prices[idx] + dp[idx+1][trac+1], 0 + dp[idx+1][trac]);
                  }
              }
          }
          return dp[0][0];
      }
      int maxProfit(vector<int> &prices) {
          int n = prices.size();
          vector<vector<int>> dp(n+1, vector<int> (2*2+1,0));
          return solve_2(prices,n,dp);
          
      }
  };

