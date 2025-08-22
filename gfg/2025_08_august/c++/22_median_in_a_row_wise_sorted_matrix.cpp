// TC : O(log(10^9) * N * log(M))
// SC : O(1)

class Solution {
  public:
    int UB(vector<int>& arr, int val, int m){
        int l = 0;
        int h = m-1;
        int ans = m;
        
        while(l <= h){
            int mid = l+(h-l) / 2;
            if(arr[mid] > val){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
    int cntSmallEqual(vector<vector<int>> &mat, int n, int m, int val){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += UB(mat[i],val,m);
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int l = INT_MAX;
        int h = INT_MIN;
        for(int i = 0; i < n; i++){
            l = min(l,mat[i][0]);
            h = max(h,mat[i][m-1]);
        }
        // low n high ki range pata lag gyi h BS apply kr
        int req = n*m / 2;
        while(l <= h){
            int mid = l + (h-l)/ 2;
            int smallEqual = cntSmallEqual(mat,n,m,mid);
            if(smallEqual <= req){
               l = mid + 1;
            }else{
                h = mid - 1;
            }
        }
        return l;
    }
};
