// TC = O(N^2) -> O(N)
// SC = O(N)

// CODE

class Solution {
public:
    int mod = 1e9+7;
    // int dp[1001];
    // int solve(int day, int n, int delay, int forget){
    //     if(day >= n) return 1; // doubt why?
    //     int ans = 1;
    //     if(dp[day] != -1) return dp[day];
    //     for(int i = day + delay; i <= min(day+forget,n); i++){
    //         if(i == day+forget){
    //             ans--;
    //             break;
    //         }
    //         ans = (ans + solve(i,n,delay,forget)) % mod;
    //     }
    //     return dp[day] = ans;
    // }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        // memset(dp,-1,sizeof(dp));
        // return solve(1,n,delay,forget);

        vector<int>dp(n+1,-1);

        dp[1] = 1;

        // dp array fill kr liya
        long long cnt = 0;
        for(int day = 2; day <= n; day++){
            // long long cnt = 0;
            // for(int prev = day-forget+1; prev <= day-delay; prev++){
            //     if(prev > 0){
            //         cnt = (cnt + dp[prev]) % mod;
            //     }
            // }
            // dp[day] = cnt;

            // optimised way of doing that for loop
            if(day-delay > 0){
                cnt = (cnt + dp[day-delay]) % mod;
            }
            if(day-forget > 0){
                cnt = (cnt - dp[day-forget] + mod) % mod;
            }

            dp[day] = cnt;
        }

        int res = 0;
        for(int i = n-forget+1; i <= n; i++){
            if(i > 0){
                res = (res + dp[i]) % mod;
            }
        }
        return res;
    }
};