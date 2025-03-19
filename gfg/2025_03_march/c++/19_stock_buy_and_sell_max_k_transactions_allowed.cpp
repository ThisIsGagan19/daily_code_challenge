// CODE

class Solution {
    public:
    // memo
      int solve(int idx, int trac,vector<int>& prices, int n, int k, 
      vector<vector<int>> &dp){
          if(idx == n || trac == 2*k) return 0;
          if(dp[idx][trac] != 0) return dp[idx][trac];
          if(trac % 2 == 0){ // buy case
              return dp[idx][trac] = max(-prices[idx] + solve(idx+1,trac+1,prices,n,k,dp) , 
                         0 + solve(idx+1,trac,prices,n,k,dp));
          }
          else{ // sell case
              return dp[idx][trac] = max(prices[idx] + solve(idx+1,trac+1,prices,n,k,dp) , 
                         0 + solve(idx+1,trac,prices,n,k,dp));
          }
      }
      
      
      // tabulation
      int solve_2(vector<int>& prices, int n, int k, 
      vector<vector<int>> &dp){
          for(int idx = n-1; idx >= 0; idx--){
              for(int trac = 2*k - 1; trac >= 0; trac--){
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
      
      
      int maxProfit(vector<int>& prices, int k) {
          int n = prices.size();
          vector<vector<int>> dp(n+1, vector<int> (2*k+1,0));
          // return solve(0,0,prices,n,k,dp);
          return solve_2(prices,n,k,dp);
          
          
      }
      
      
      
  };