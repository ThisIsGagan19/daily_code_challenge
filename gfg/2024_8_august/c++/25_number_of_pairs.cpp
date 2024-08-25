// TIME COMPEXITY
// O((n+m)logm)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
  public:
    int BS(int tar, vector<int> &brr){
        int st = 0;
        int end = brr.size()-1;
        int mid;
        int ind = -1;
        while(st <= end){
            mid = st + (end-st) / 2;
            if(brr[mid] <= tar){
                ind = mid;
                st = mid + 1;
            }
            else{
                end = mid-1;
            }
        }
        return ind;
    }
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        long long ans = 0;
        long long cnt_1 = 0;
        long long cnt_2 = 0;
        long long cnt_34 = 0;
        
        // sort kr second ko
        sort(brr.begin(), brr.end());
        for(auto it : brr){
            if(it == 1) cnt_1++;
            else if(it == 2) cnt_2++;
            else if(it == 3 || it == 4) cnt_34++;
            
        }
        
        for(auto it : arr){
            if(it != 1){
                ans += cnt_1;
                if(it == 2) ans -= cnt_34;
                if(it == 3) ans += cnt_2;
                
                int ind = BS(it,brr);
                ans += (brr.size() - ind - 1);
            }
        }
        
        return ans;
    }
};