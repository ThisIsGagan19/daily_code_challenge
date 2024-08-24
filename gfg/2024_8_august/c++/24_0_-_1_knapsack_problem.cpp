// TIME COMPEXITY
// O(n * w)

// SPACE COMPEXITY
// O(n * w)

// CODE

class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    
    int solve(int ind, int W, vector<int>& wt, vector<int>& val, vector<vector<int> > &dp){
        if(ind == 0){
            if(wt[0] <= W) return val[0];
            else return 0;
        }
        
        if(dp[ind][W] != -1) return dp[ind][W];
        
        int include = 0;
        if(wt[ind] <= W){
            include = val[ind] + solve(ind-1,W-wt[ind],wt,val,dp);
        }
        int exclude = solve(ind-1,W,wt,val,dp);
        
        return dp[ind][W] = max(include,exclude);
    }
    
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        vector<vector<int> > dp(n, vector<int> (W+1,-1));
        return solve(n-1,W,wt,val,dp);
    }
};