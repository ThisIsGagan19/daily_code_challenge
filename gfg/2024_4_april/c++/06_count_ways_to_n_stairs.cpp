// CODE

class Solution {
    public:
    long long countWays(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++)
            dp[i] = dp[i - 2] + 1;
        return dp[n];
    }
};