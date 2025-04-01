// CODE

class Solution {
    public:
        long long solve(int i, vector<vector<int>>& questions, int n, vector<long long> &dp){
            if(i >= n) return 0;
            if(dp[i] != -1) return dp[i];
            long long take = questions[i][0] + solve(i+questions[i][1] + 1, questions,n,dp);
            long long notTake = 0 + solve(i+1, questions,n,dp);
    
            return dp[i] = max(take,notTake);
        }
        long long mostPoints(vector<vector<int>>& questions) {
            int n = questions.size();
            // vector<long long> dp(n+1,-1);
            // return solve(0,questions,n,dp);
    
            // tabulation
            if(n == 1) return questions[0][0];
            vector<long long> dp(200001,0);
            // dp[i] = i se leke n - 1 thk ka answer dp[i] me store h
            for(int i = n - 1; i >= 0; i--){
                long long take = questions[i][0] + dp[i+questions[i][1] + 1];
                long long notTake = 0 + dp[i+1];
                dp[i] = max(take,notTake);
            }
            return dp[0];
    
        }
    };