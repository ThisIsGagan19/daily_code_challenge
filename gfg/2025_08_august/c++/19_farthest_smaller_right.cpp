// TC : O(NlogN)
// SC : O(N)

class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,-1);
        vector<int> suffix(n);
        suffix[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--){
            suffix[i] = min(arr[i], suffix[i+1]);
        }
        
        for(int i = 0; i < n; i++){
            int res = -1;
            int l = i+1;
            int r = n-1;
            while(l <= r){
                int m = l + (r-l) / 2;
                if(suffix[m] < arr[i]){
                    res = m;
                    l = m+1;
                }
                else{
                    r = m - 1;
                }
            }
            ans[i] = res;
        }
        return ans;
    }
};