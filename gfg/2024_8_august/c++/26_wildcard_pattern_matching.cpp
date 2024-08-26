// TIME COMPEXITY
// O(n * m)

// SPACE COMPEXITY
// O(n * m)

// CODE

class Solution {
  public:
    /*You are required to complete this method*/
    bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return true;
        if(i >= 0 && j == 0) return false;
        if(i == 0 && j >= 0){
            for(int k = 1; k <= j; k++){
                if(p[k-1] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        // match ho gya 2 cases
        if(s[i-1] == p[j-1] || p[j-1] == '?'){
            return dp[i][j] = solve(s,p,i-1,j-1,dp);
        }
        else if(p[j-1] == '*'){
            return dp[i][j] = (solve(s,p,i,j-1,dp) || solve(s,p,i-1,j,dp));
        }
        else return false;
    }
    int wildCard(string pattern, string str) {
        vector<vector<int>> dp(str.length()+1, vector<int> (pattern.length()+1, -1));
        return solve(str,pattern,str.length(),pattern.length(),dp);
    }
};