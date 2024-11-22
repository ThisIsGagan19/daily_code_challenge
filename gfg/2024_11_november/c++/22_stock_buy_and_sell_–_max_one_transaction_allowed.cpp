// CODE

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int mini=INT_MAX,ans=INT_MIN;
        for(int x:prices)
        {
            mini=min(x,mini);
            ans=max(ans,x-mini);
        }
        return ans;
    }
};