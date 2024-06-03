# CODE

class Solution:
    def numberOfConsecutiveOnes(ob, n):
        MOD = 1000000007
        
        dp = [0] * (n + 1)
        dp[0] = 0
        dp[1] = 0
        dp[2] = 1
        
        if(n < 3):
            return dp[n]
        
        a = 0
        b = 1
        for i in range(3, n + 1):
            c = (a + b) % MOD
            dp[i] = ((dp[i - 1] + dp[i - 1]) % MOD + c % MOD) % MOD
            a = b
            b = c
        
        return dp[n]