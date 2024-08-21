// TIME COMPEXITY
// O(n^3)

// SPACE COMPEXITY
// O(n^2)

// CODE

class Solution {
public:
    int solve(int l, int r, string &s, vector<vector<int> > &dp){
        if(l == r) return 1;
        if(l > r) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        int i = l + 1;
        while(i <= r && s[i] == s[l]) i++;

        int basic = 1 + solve(i,r,s,dp);
        int greedy = INT_MAX;
        for(int j = i; j <= r; j++){
            if(s[j] == s[l]){
                int ans = solve(i,j-1,s,dp) + solve(j,r,s,dp);
                greedy = min(greedy,ans);
            }
        }
        return dp[l][r] = min(greedy,basic);
    }
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int> > dp(n+1, vector<int> (n+1, -1));
        return solve(0,n-1,s,dp);
    }
};