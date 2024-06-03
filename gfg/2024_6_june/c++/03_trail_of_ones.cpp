// CODE

class Solution {
  public:
    #define mod 1000000007
    int numberOfConsecutiveOnes(int n) {
        vector<long long> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        long long a = 0;
        long long b = 1;
        for(int i = 3; i < n + 1; i++){
            long long c = (a+b) % mod;
            dp[i] = ((dp[i-1] + dp[i-1]) % mod + c % mod) % mod;
            a = b;
            b = c;
        }
        return dp[n];
    }
};