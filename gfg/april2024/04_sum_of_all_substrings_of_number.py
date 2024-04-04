# CODE

MOD = 10**9 + 7
class Solution:
    def sumSubstrings(self, s: str) -> int:
        n = len(s)
        dp = [0] * n
        dp[0] = int(s[0])
        res = dp[0]
        for i in range(1, n):
            dp[i] = ((dp[i - 1] * 10) % MOD + ((int(s[i]) * (i + 1)) % MOD)) % MOD
            res = (res + dp[i]) % MOD
        return res