// APPROACH : we will use recursion with memoization to store the minimum cost to reach each stone. At each stone, we have two choices: jump to the next stone or skip one stone and jump to the one after that. We calculate the cost for both choices and take the minimum. Finally, we can also implement a tabulation approach to optimize space.

// TC : (2^n) -> O(n)
// SC : O(n) -> O(1)

// CODE

class Solution {
  public:
    // int solve(int i, vector<int>& h, vector<int>& dp){
    //     if(i == 0) return 0;
    //     if(dp[i] != -1) return dp[i];
    //     // +1
    //     int one = solve(i-1,h,dp) + abs(h[i] - h[i-1]);
    //     // +2
    //     int two = INT_MAX;
    //     if(i > 1){
    //         two = solve(i-2,h,dp) + abs(h[i] - h[i-2]);
    //     }
        
    //     return dp[i] = min(one,two);
    // }
    int minCost(vector<int>& h) {
        int n = h.size();
        // vector<int> dp(n+1,-1);
        // return solve(n-1,h,dp);
        
        vector<int> tab(n+1,0);
        if(n == 1) return 0;
        int p2 = 0;
        int p1 = 0;
        for(int i = 1; i < n; i++){
            // +1
            int one = p1 + abs(h[i] - h[i-1]);
            // +2
            int two = INT_MAX;
            if(i > 1){
                two = p2 + abs(h[i] - h[i-2]);
            }
            
            int curr = min(one,two);
            p2 = p1;
            p1 = curr;
        }
        return p1;
    }
};