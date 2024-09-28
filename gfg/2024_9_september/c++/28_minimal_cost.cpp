// CODE

class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,1e9);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=i-k;j<i;j++){
                if(j>=0)
                dp[i]=min(dp[i],dp[j]+abs(arr[i]-arr[j]));
            }
        }
        return dp[n-1];
    }
};