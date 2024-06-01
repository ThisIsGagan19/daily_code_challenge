// CODE

#define MOD 1000000007
class Solution {
    public:
    long long sumSubstrings(string s) {
        int n = s.size();
        long long res;
        vector<long long> dp(n, 0);
        
        dp[0] = s[0] - '0';
        res = dp[0];
        
        for(int i = 1; i < n; i++) {
            dp[i] = ((dp[i - 1] * 10) % MOD + ((s[i] - '0') * (i + 1)) % MOD) % MOD;
            res = (res + dp[i]) % MOD;
        }
        
        return res;
    }
};