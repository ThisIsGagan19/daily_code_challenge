// CODE

class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,-1);
        
        for(int i=0; i<n; i++){
            
            if(arr[i]<0){
                continue;
            }
            
            ans[arr[i]] = arr[i]; 
            
        }
        
        return ans;
    }
};