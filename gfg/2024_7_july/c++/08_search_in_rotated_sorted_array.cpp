// TIME COMPLEXITY
// O(logn)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
  public:
    int find_pivot(vector<int>& arr, int n){
        int l = 0;
        int r = n - 1;
        
        while(l < r){
            int mid = l + (r-l) / 2;
            if(arr[mid] > arr[r]) l = mid + 1;
            else r = mid;
        }
        
        return r;
    }
    int binary_search(int l, int r, vector<int>& arr, int key){
        int ans = -1;
        while(l <= r){
            int mid = l + (r-l) / 2;
            if(arr[mid] == key){
                ans = mid;
                break;
            }
            else if(arr[mid] < key){
                l = mid + 1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
    int search(vector<int>& arr, int key) {
        int n = arr.size();
        int pivot_ind = find_pivot(arr,n);
        
        int ans = binary_search(0,pivot_ind-1,arr,key);
        if(ans != -1) return ans;
        
        ans = binary_search(pivot_ind,n-1,arr,key);
        
        return ans;
    }
};