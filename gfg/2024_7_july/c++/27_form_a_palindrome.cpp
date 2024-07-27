// TIME COMPLEXITY
// O(n^2)

// SPACE COMPLEXITY
// O(n^2)

// CODE

class Solution{
  public:
    int LCS(int i, int j, string &s, string &p, vector<vector<int> > &dp){
        if(i == s.length() || j == p.length()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == p[j]) return dp[i][j] = 1 + LCS(i+1, j+1, s,p,dp);
        return dp[i][j] = max(LCS(i, j+1, s,p,dp), LCS(i+1, j, s,p,dp));
    }
    int countMin(string str){
        string rev_str = str;
        reverse(rev_str.begin(), rev_str.end());
        if(rev_str == str) return 0;
        int n = str.length();
        vector<vector<int> > dp(n+1,vector<int>(n+1,-1)); 
        int lcs = LCS(0,0,str,rev_str,dp);
        return n-lcs;
    }
};