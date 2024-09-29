// CODE

class Solution {
  public:
    int totalCount(int k, vector<int>& arr) {
        // code here
         int ans = 0;
        for(int i=0;i<arr.size();i++){
            int q = arr[i]/k;
            int rem = arr[i]%k;
            ans += q;
            if(rem > 0) ans++;
        }
        return ans;
    }
};