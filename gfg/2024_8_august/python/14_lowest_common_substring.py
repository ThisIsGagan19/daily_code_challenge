# CODE

class Solution:
    def longestCommonSubstr(self, S1, S2):
        m = len(S2)
        n = len(S1)
        dp=[[0 for i in range(m+1)]for j in range(n+1)]
        ans=0
        for i in range(1,n+1):
            for j in range(1,m+1):
                if S1[i-1]==S2[j-1]:
                    dp[i][j]=dp[i-1][j-1]+1
                    ans=max(ans,dp[i][j])
                else:
                    dp[i][j]=0
        return ans