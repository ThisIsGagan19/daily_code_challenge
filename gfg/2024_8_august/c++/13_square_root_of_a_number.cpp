// TIME COMPEXITY
// O(logn)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
  public:
    long long int floorSqrt(long long int n) {
        long long int st = 0;
        long long int end = n; 
        long long int ans = 0;
         while(st <= end){
            long long int mid = st + (end - st) / 2;
            if(n == mid * mid) return mid;
            else if(n > mid * mid) {
                ans = mid;
                st = mid + 1;
                
            }
            else{
                end = mid-1;
            }
         }
         return ans;
    }
};