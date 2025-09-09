// TC = O(N^2)
// SC = O(N)

// CODE

class Solution {
public:
    int mod = 1e9+7;
    int dp[1001];
    int solve(int day, int n, int delay, int forget){
        if(day >= n) return 1; // doubt why?
        int ans = 1;
        if(dp[day] != -1) return dp[day];
        for(int i = day + delay; i <= min(day+forget,n); i++){
            if(i == day+forget){
                ans--;
                break;
            }
            ans = (ans + solve(i,n,delay,forget)) % mod;
        }
        return dp[day] = ans;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        memset(dp,-1,sizeof(dp));
        return solve(1,n,delay,forget);
    }
};