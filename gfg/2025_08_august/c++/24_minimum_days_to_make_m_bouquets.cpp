// TC : O(Nlog(MaxElement))
// SC : O(1)

// CODE

class Solution {
  public:
    bool hoPayega(vector<int>& arr, int m, int k, int days){
        int b = 0;
        int f = 0;
        
        for(int it : arr){
            if(it <= days){
                f++;
                if(f == k){
                    b++;
                    f = 0;
                }
            }
            else{
                f = 0;
            }
        }
        return b >= m;
    }
    int minDaysBloom(vector<int>& arr, int k, int m) {
        int n = arr.size();
        if(m*k > n) return -1;
        
        int l = INT_MAX;
        int r = INT_MIN;
        
        for(int it : arr){
            l = min(l,it);
            r = max(r,it);
        }
        int ans = -1;
        while(l <= r){
            int mid = l + (r-l) / 2;
            if(hoPayega(arr,m,k,mid)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        
        return ans;
    }
};